#ifndef ALGEBRAICPRODUCT_HPP
#define ALGEBRAICPRODUCT_HPP

#include "fuzlog.h"

#include "Norm.hpp"

namespace flogic {

class AlgebraicProduct : public TNorm
{
public:
    AlgebraicProduct();

    Scalar compute(Scalar a, Scalar b);
};

}

#endif // ALGEBRAICPRODUCT_HPP
