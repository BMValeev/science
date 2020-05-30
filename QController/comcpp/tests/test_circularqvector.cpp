#include "test_circularqvector.h"
#include "comcpp/circularqvector.h"

test_circularqvector::test_circularqvector()
{
    CircularQVector<double> vec(3,2,0.5);

    vec.append(0);
    vec.append(1);
    vec.append(2);

    QVector<double> vec1 = vec.toVector();

    //vec.linearize(); // correct error first!

    vec.append(3);
    vec.append(4);

    QVector<double> vec2 = vec.toVector();

    vec.append(5);
    vec.append(6);

    QVector<double> vec3 = vec.toVector();

    double a = vec[0];
    a = vec[1];
    a = vec[2];

    vec.append(7);

}
