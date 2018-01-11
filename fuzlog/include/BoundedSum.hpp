#ifndef BOUNDEDSUM_HPP
#define BOUNDEDSUM_HPP

#include "fuzlog.h"

#include "Norm.hpp"

namespace flogic {

class BoundedSum : public SNorm
{
public:
    BoundedSum();

    Scalar compute(Scalar a, Scalar b);
};

}

#endif // BOUNDEDSUM_HPP
