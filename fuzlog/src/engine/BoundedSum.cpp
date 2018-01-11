#include "BoundedSum.hpp"

#include "utility.h"

using namespace flogic;

BoundedSum::BoundedSum()
{

}

Scalar BoundedSum::compute(Scalar a, Scalar b)
{
    return Op::min(1., a + b);
}
