#ifndef NORM_HPP
#define NORM_HPP

#include "fuzlog.h"

#include <memory>

namespace flogic {

class Norm;
using NormObject = std::unique_ptr<Norm>;

class TNorm;
using TNormObject = std::unique_ptr<TNorm>;

class SNorm;
using SNormObject = std::unique_ptr<SNorm>;

class Norm
{
public:
    Norm() {}
    virtual ~Norm() {}

    virtual Scalar compute(Scalar a, Scalar b) = 0;
};

class TNorm : public Norm
{
public:
    TNorm() {}
    virtual ~TNorm() {}
};

class SNorm : public Norm
{
public:
    SNorm() {}
    virtual ~SNorm() {}
};

}

#endif // NORM_HPP
