#include "Maximum.hpp"

#include "utility.h"

using namespace flogic;

Maximum::Maximum()
{

}

Scalar Maximum::compute(Scalar a, Scalar b)
{
    return Op::max(a, b);
}
