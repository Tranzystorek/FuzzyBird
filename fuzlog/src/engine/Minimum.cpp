#include "Minimum.hpp"

#include "utility.h"

using namespace flogic;

Minimum::Minimum()
{

}

Scalar Minimum::compute(Scalar a, Scalar b)
{
    return Op::min(a, b);
}
