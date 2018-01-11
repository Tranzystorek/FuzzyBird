#ifndef CENTROID_HPP
#define CENTROID_HPP

#include "fuzlog.h"

#include "Defuzzifier.hpp"

namespace flogic {

class Centroid : public Defuzzifier
{
public:
    Centroid(int res);

    Scalar defuzzify(const TermObject &term, const Range &r);

private:
    int resolution_;
};

}

#endif // CENTROID_HPP
