#include "Centroid.hpp"

using namespace flogic;

Centroid::Centroid(int res)
    : resolution_(res)
{

}

Scalar Centroid::defuzzify(const TermObject& term, const Range& r)
{
    Scalar step = (r.higher - r.lower) / resolution_;
    Scalar x = r.lower + step;

    Scalar area = 0.;
    Scalar xcentroid = 0.;

    for(int i=0; i < resolution_; ++i, x += step)
    {
        const Scalar val = term->membership(x);

        area += val;
        xcentroid += x * val;
    }

    return xcentroid / area;
}
