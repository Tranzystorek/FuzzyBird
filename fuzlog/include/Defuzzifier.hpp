#ifndef DEFUZZIFIER_HPP
#define DEFUZZIFIER_HPP

#include "fuzlog.h"

#include <memory>

#include "Aggregator.hpp"

namespace flogic {

class Defuzzifier;
using DefuzzifierObject = std::unique_ptr<Defuzzifier>;

class Defuzzifier
{
public:
    Defuzzifier() {}
    virtual ~Defuzzifier() {}

    virtual Scalar defuzzify(const Aggregator& term, const Range& r) = 0;
};

}

#endif // DEFUZZIFIER_HPP
