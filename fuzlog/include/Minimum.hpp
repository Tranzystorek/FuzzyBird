#ifndef MINIMUM_HPP
#define MINIMUM_HPP

#include "fuzlog.h"

#include "Norm.hpp"

namespace flogic {

class Minimum : public TNorm
{
public:
    Minimum();

    Scalar compute(Scalar a, Scalar b);
};

}

#endif // MINIMUM_HPP
