/*
 * spline.h
 *
 * simple cubic spline interpolation library without external
 * dependencies
 *
 * ---------------------------------------------------------------------
 * Copyright (C) 2011, 2014 Tino Kluge (ttk448 at gmail.com)
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * ---------------------------------------------------------------------
 *
 */


#ifndef TK_SPLINE_H
#define TK_SPLINE_H

#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>

// Band matrix solver
class BandMatrix
{
private:
    std::vector<std::vector<double>> mUpper;   // upper band
    std::vector<std::vector<double>> mLower;   // lower band
public:
    BandMatrix() {}                            // constructor
    BandMatrix(unsigned long dim, unsigned long n_u, unsigned long n_l);     // constructor
    ~BandMatrix() {}                           // destructor
    void resize(unsigned long dim, unsigned long n_u, unsigned long n_l);    // init with dim,n_u,n_l
    int dim() const;                           // matrix dimension
    int num_upper() const { return static_cast<int>(mUpper.size()-1); }
    int num_lower() const { return static_cast<int>(mLower.size()-1); }
    // access operator
    double & operator () (int i, int j);       // write
    double   operator () (int i, int j) const; // read
    // we can store an additional diogonal (in m_lower)
    double& saved_diag(int i);
    double  saved_diag(int i) const;
    void luDecompose();
    std::vector<double> rSolve(const std::vector<double>& b) const;
    std::vector<double> lSolve(const std::vector<double>& b) const;
    std::vector<double> lu_solve(const std::vector<double>& b,
                                 bool is_lu_decomposed=false);
};

// spline interpolation
class Spline
{
public:
    enum BdType {
        FirstDeriv = 1,
        SecondDeriv = 2
    };

private:
    std::vector<double> mX, mY;         // x,y coordinates of points
    // interpolation parameters
    // f(x) = a*(x-x_i)^3 + b*(x-x_i)^2 + c*(x-x_i) + y_i
    std::vector<double> mA, mB, mC;     // spline coefficients
    double mB0, mC0;                    // for left extrapol
    BdType mLeft, mRight;
    double mLeftValue, mRightValue;
    bool mForceLinearExtrapolation;

public:
    // set default boundary condition to be zero curvature at both ends
    Spline():
        mLeft(SecondDeriv),
        mRight(SecondDeriv),
        mLeftValue(0.0),
        mRightValue(0.0),
        mForceLinearExtrapolation(false)
    { }

    // optional, but if called it has to come be before set_points()
    void setBoundary(BdType left, double leftValue,
                      BdType right, double rightValue,
                      bool force_linear_extrapolation = false);
    void setPoints(const std::vector<double>& x,
                    const std::vector<double>& y, bool cubicSpline = true);
    double operator() (double x) const;
};

#endif /* TK_SPLINE_H */
