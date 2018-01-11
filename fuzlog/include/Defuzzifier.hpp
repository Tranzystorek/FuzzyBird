#ifndef DEFUZZIFIER_HPP
#define DEFUZZIFIER_HPP

#include "fuzlog.h"

#include "Term.hpp"

namespace flogic {

class Defuzzifier
{
public:
    Defuzzifier() {}
    virtual ~Defuzzifier() {}

    virtual Scalar defuzzify(const TermObject& term, const Range& r) = 0;
};

}

#endif // DEFUZZIFIER_HPP
