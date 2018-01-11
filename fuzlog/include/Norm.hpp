#ifndef NORM_HPP
#define NORM_HPP

#include "fuzlog.h"

#include <memory>

#include "Engine.hpp"

namespace flogic {

class Norm;
using NormObject = std::unique_ptr<Norm>;

class Norm
{
public:
    Norm() {}
    virtual ~Norm() {}

    virtual Scalar compute(Scalar a, Scalar b) = 0;
};

class TNorm : Norm
{};

class SNorm : Norm
{};

}

#endif // NORM_HPP
