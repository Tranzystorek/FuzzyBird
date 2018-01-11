#ifndef BISECTOR_HPP
#define BISECTOR_HPP

#include "fuzlog.h"

#include "Defuzzifier.hpp"

namespace flogic {

class Bisector : public Defuzzifier
{
public:
    Bisector(int res);

    Scalar defuzzify(const TermObject &term, const Range& r);

private:
    int resolution_;
};

}

#endif // BISECTOR_HPP
