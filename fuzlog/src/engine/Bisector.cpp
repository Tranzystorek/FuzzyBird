#include "Bisector.hpp"

#include "utility.h"

using namespace flogic;

Bisector::Bisector(int res)
    : resolution_(res)
{

}

Scalar Bisector::defuzzify(const Aggregator& term, const Range& r)
{
    Scalar xRight = r.higher;
    Scalar xLeft = r.lower;
    Scalar step = (xRight - xLeft) / resolution_;

    Scalar leftA = 0.;
    Scalar rightA = 0.;

    while(Op::isLt(xLeft, xRight))
    {
        if(Op::isLt(leftA, rightA))
        {
            xLeft += step;
            leftA += term.membership(xLeft);
        }
        else
        {
            xRight -= step;
            rightA += term.membership(xRight);
        }
    }

    //return weighted average
    return (xLeft * leftA + xRight * rightA) / (leftA + rightA);
}
