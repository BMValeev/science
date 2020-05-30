#include "spline.h"

// band_matrix implementation
// -------------------------

BandMatrix::BandMatrix(unsigned long dim, unsigned long nU, unsigned long nL)
{
    resize(dim, nU, nL);
}

void BandMatrix::resize(unsigned long dim, unsigned long nU, unsigned long nL)
{
    assert(dim > 0);

    mUpper.resize(nU + 1);
    mLower.resize(nL + 1);
    for(size_t i = 0; i < mUpper.size(); i++) {
        mUpper[i].resize(dim);
    }
    for(size_t i = 0; i < mLower.size(); i++) {
        mLower[i].resize(dim);
    }
}

int BandMatrix::dim() const
{
    if(mUpper.size() > 0) {
        return static_cast<int>(mUpper[0].size());
    } else {
        return 0;
    }
}

// defines the new operator (), so that we can access the elements
// by A(i,j), index going from i=0,...,dim()-1
double &BandMatrix::operator() (int i, int j)
{
    assert((i >= 0) && (i < dim()) && (j >= 0) && (j < dim()));

    int k = j-i;       // what band is the entry
    assert((-num_lower() <= k) && (k <= num_upper()));

    // k=0 -> diogonal, k<0 lower left part, k>0 upper right part
    if (k >= 0)
        return mUpper[k][i];
    else
        return mLower[-k][i];
}

double BandMatrix::operator ()(int i, int j) const
{
    assert( (i >= 0) && (i < dim()) && (j >= 0) && (j < dim()) );

    int k=j-i;       // what band is the entry
    assert( (-num_lower() <= k) && (k <= num_upper()) );

    // k=0 -> diogonal, k<0 lower left part, k>0 upper right part
    if (k >= 0)
        return mUpper[k][i];
    else
        return mLower[-k][i];
}

// second diag (used in LU decomposition), saved in m_lower
double BandMatrix::saved_diag(int i) const
{
    assert( (i >= 0) && (i < dim()) );
    return mLower[0][i];
}

double &BandMatrix::saved_diag(int i)
{
    assert( (i >= 0) && (i < dim()) );
    return mLower[0][i];
}

// LR-Decomposition of a band matrix
void BandMatrix::luDecompose()
{
    int  i_max,j_max;
    int  j_min;
    double x;

    // preconditioning
    // normalize column i so that a_ii=1
    for(int i=0; i<this->dim(); i++) {
        assert(this->operator()(i,i)!=0.0);
        this->saved_diag(i)=1.0/this->operator()(i,i);
        j_min=std::max(0,i-this->num_lower());
        j_max=std::min(this->dim()-1,i+this->num_upper());
        for(int j=j_min; j<=j_max; j++) {
            this->operator()(i,j) *= this->saved_diag(i);
        }
        this->operator()(i,i)=1.0;          // prevents rounding errors
    }

    // Gauss LR-Decomposition
    for(int k=0; k<this->dim(); k++) {
        i_max=std::min(this->dim()-1,k+this->num_lower());  // num_lower not a mistake!
        for(int i=k+1; i<=i_max; i++) {
            assert(this->operator()(k,k)!=0.0);
            x=-this->operator()(i,k)/this->operator()(k,k);
            this->operator()(i,k)=-x;                         // assembly part of L
            j_max=std::min(this->dim()-1,k+this->num_upper());
            for(int j=k+1; j<=j_max; j++) {
                // assembly part of R
                this->operator()(i,j)=this->operator()(i,j)+x*this->operator()(k,j);
            }
        }
    }
}

// solves Ly=b
std::vector<double> BandMatrix::lSolve(const std::vector<double> &b) const
{
    assert( this->dim() == static_cast<int>(b.size()) );
    std::vector<double> x(this->dim());
    int j_start;
    double sum;
    for(int i=0; i<this->dim(); i++) {
        sum=0;
        j_start=std::max(0,i-this->num_lower());
        for(int j = j_start; j < i; j++) sum += this->operator()(i,j)*x[j];
        x[i] = (b[i]*this->saved_diag(i)) - sum;
    }
    return x;
}

// solves Rx=y
std::vector<double> BandMatrix::rSolve(const std::vector<double> &b) const
{
    assert( this->dim()==(int)b.size() );
    std::vector<double> x(this->dim());
    int j_stop;
    double sum;
    for(int i=this->dim()-1; i>=0; i--) {
        sum=0;
        j_stop=std::min(this->dim()-1,i+this->num_upper());
        for(int j=i+1; j<=j_stop; j++) sum += this->operator()(i,j)*x[j];
        x[i]=( b[i] - sum ) / this->operator()(i,i);
    }
    return x;
}

std::vector<double> BandMatrix::lu_solve(const std::vector<double> &b, bool isLuDecomposed)
{
    assert(this->dim() == static_cast<int>(b.size()));
    std::vector<double>  x, y;
    if(isLuDecomposed==false) {
        this->luDecompose();
    }
    y=this->lSolve(b);
    x=this->rSolve(y);
    return x;
}

// spline implementation
// -----------------------
void Spline::setBoundary(Spline::BdType left, double leftValue, Spline::BdType right, double rightValue, bool force_linear_extrapolation)
{
    assert(mX.size() == 0);          // set_points() must not have happened yet
    mLeft = left;
    mRight = right;
    mLeftValue = leftValue;
    mRightValue = rightValue;
    mForceLinearExtrapolation = force_linear_extrapolation;
}

void Spline::setPoints(const std::vector<double> &x, const std::vector<double> &y, bool cubic_spline)
{
    assert(x.size() == y.size());
    assert(x.size() > 2);
    mX = x;
    mY = y;
    size_t n=x.size();
    // TODO: maybe sort x and y, rather than returning an error
    for(size_t i=0; i < n-1; i++) {
        assert(mX[i] < mX[i+1]);
    }

    if(cubic_spline == true) { // cubic spline interpolation
        // setting up the matrix and right hand side of the equation system
        // for the parameters b[]
        BandMatrix A(n, 1, 1);
        std::vector<double>  rhs(n);
        for(size_t i=1; i < n-1; i++) {
            A(i, i-1) = 1.0 / 3.0 * (x[i] - x[i-1]);
            A(i, i)   = 2.0 / 3.0 * (x[i+1] - x[i-1]);
            A(i, i+1) = 1.0 / 3.0 * (x[i+1] - x[i]);
            rhs[i]    = (y[i+1]-y[i]) / (x[i+1]-x[i]) - (y[i] - y[i-1]) / (x[i]-x[i-1]);
        }
        // boundary conditions
        if(mLeft == Spline::SecondDeriv) {
            // 2*b[0] = f''
            A(0,0) = 2.0;
            A(0,1) = 0.0;
            rhs[0] = mLeftValue;
        } else if(mLeft == Spline::FirstDeriv) {
            // c[0] = f', needs to be re-expressed in terms of b:
            // (2b[0]+b[1])(x[1]-x[0]) = 3 ((y[1]-y[0])/(x[1]-x[0]) - f')
            A(0,0) = 2.0 * (x[1] - x[0]);
            A(0,1) = 1.0 * (x[1] - x[0]);
            rhs[0] = 3.0 * ((y[1] - y[0]) / (x[1] - x[0]) - mLeftValue);
        } else {
            assert(false);
        }
        if(mRight == Spline::SecondDeriv) {
            // 2*b[n-1] = f''
            A(n-1, n-1) = 2.0;
            A(n-1, n-2) = 0.0;
            rhs[n-1] = mRightValue;
        } else if(mRight == Spline::FirstDeriv) {
            // c[n-1] = f', needs to be re-expressed in terms of b:
            // (b[n-2]+2b[n-1])(x[n-1]-x[n-2])
            // = 3 (f' - (y[n-1]-y[n-2])/(x[n-1]-x[n-2]))
            A(n-1,n-1)=2.0*(x[n-1]-x[n-2]);
            A(n-1,n-2)=1.0*(x[n-1]-x[n-2]);
            rhs[n-1]=3.0*(mRightValue-(y[n-1]-y[n-2])/(x[n-1]-x[n-2]));
        } else {
            assert(false);
        }

        // solve the equation system to obtain the parameters b[]
        mB=A.lu_solve(rhs);

        // calculate parameters a[] and c[] based on b[]
        mA.resize(n);
        mC.resize(n);
        for(unsigned long i=0; i<n-1; i++) {
            mA[i] = 1.0 / 3.0 * (mB[i+1] - mB[i]) / (x[i+1] - x[i]);
            mC[i] = (y[i+1] - y[i]) / (x[i+1] - x[i])
                    - 1.0/3.0 * (2.0 * mB[i] + mB[i+1]) * (x[i+1] - x[i]);
        }
    } else { // linear interpolation
        mA.resize(n);
        mB.resize(n);
        mC.resize(n);
        for(size_t i=0; i<n-1; i++) {
            mA[i] = 0.0;
            mB[i] = 0.0;
            mC[i] = (mY[i+1] - mY[i]) / (mX[i+1] - mX[i]);
        }
    }

    // for left extrapolation coefficients
    mB0 = (mForceLinearExtrapolation==false) ? mB[0] : 0.0;
    mC0 = mC[0];

    // for the right extrapolation coefficients
    // f_{n-1}(x) = b*(x-x_{n-1})^2 + c*(x-x_{n-1}) + y_{n-1}
    double h = x[n-1]-x[n-2];
    // m_b[n-1] is determined by the boundary condition
    mA[n-1] = 0.0;
    mC[n-1] = 3.0 * mA[n-2] * h * h + 2.0 * mB[n-2] * h + mC[n-2];   // = f'_{n-2}(x_{n-1})
    if(mForceLinearExtrapolation==true)
        mB[n-1]=0.0;
}

double Spline::operator()(double x) const
{
    if (mX.size() < 3)
        return 0;

    size_t n = mX.size();

    // find the closest point m_x[idx] < x, idx=0 even if x<m_x[0]
    std::vector<double>::const_iterator it;
    it = std::lower_bound(mX.begin(), mX.end(), x);
    unsigned long idx = static_cast<unsigned long>(std::max(int(it - mX.begin()) - 1, 0));

    double h = x - mX[idx];
    double interpol;
    if(x < mX[0]) {
        // extrapolation to the left
        interpol = (mB0*h + mC0)*h + mY[0];
    } else if(x > mX[n-1]) {
        // extrapolation to the right
        interpol = (mB[n-1]*h + mC[n-1])*h + mY[n-1];
    } else {
        // interpolation
        interpol = ((mA[idx]*h + mB[idx])*h + mC[idx])*h + mY[idx];
    }
    return interpol;
}
