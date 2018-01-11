#ifndef MAXIMUM_HPP
#define MAXIMUM_HPP

#include "fuzlog.h"

#include "Norm.hpp"

namespace flogic {

class Maximum : public SNorm
{
public:
    Maximum();

    Scalar compute(Scalar a, Scalar b);
};

}

#endif // MAXIMUM_HPP
