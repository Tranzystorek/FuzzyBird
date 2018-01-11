#include "Triangle.hpp"

using namespace flogic;

Triangle::Triangle(const std::string& name, Scalar xmin, Scalar xmax, Scalar xpeak, Scalar h)
    : Term(name),
      xmin_(xmin),
      xmax_(xmax),
      xpeak_(xpeak),
      height_(h),
      left_(xpeak - xmin),
      right_(xmax - xpeak)
{

}

Scalar Triangle::membership(Scalar x)
{
    if(x < xmin_ || x > xmax_)
        return 0.;
    else if(x < xpeak_)
        return ((x - xmin_) / left_) * height_;
    else if(x > xpeak_)
        return ((xmax_ - x) / right_) * height_;
    else
        return height_;
}
