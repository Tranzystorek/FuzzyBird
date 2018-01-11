#ifndef UTILITY_H
#define UTILITY_H

#include "fuzlog.h"

#include <cmath>
#include <limits>

namespace flogic {

namespace Op {

const Scalar EPSILON = std::numeric_limits<Scalar>::epsilon();

inline bool isEq(Scalar a, Scalar b)
{
    return a == b || fabs(a - b) < EPSILON;
}

inline bool isLE(Scalar a, Scalar b)
{
    return a == b || fabs(a - b) < EPSILON || a < b;
}

inline bool isLt(Scalar a, Scalar b)
{
    return a != b && fabs(a - b) >= EPSILON && a < b;
}

inline bool isGE(Scalar a, Scalar b)
{
    return a == b || fabs(a - b) < EPSILON || a > b;
}

inline bool isGt(Scalar a, Scalar b)
{
    return a != b && fabs(a - b) >= EPSILON && a > b;
}

inline Scalar max(Scalar a, Scalar b)
{
    return fmax(a, b);
}

inline Scalar min(Scalar a, Scalar b)
{
    return fmin(a, b);
}

}//Operation

}

#endif // UTILITY_H
