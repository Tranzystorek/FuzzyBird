#include "Trapezoid.hpp"

using namespace flogic;

Trapezoid::Trapezoid(const std::string& name, Scalar xmin, Scalar xmax, Scalar xpl, Scalar xpr, Scalar h)
    : Term(name),
      xmin_(xmin),
      xmax_(xmax),
      xpleft_(xpl),
      xpright_(xpr),
      height_(h),
      left_(xpl - xmin),
      right_(xmax - xpr)
{

}

Scalar Trapezoid::membership(Scalar x)
{
    if(x < xmin_ || x > xmax_)
        return 0.;
    else if(x < xpleft_)
        return ((x - xmin_) / left_) * height_;
    else if(x > xpright_)
        return ((xmax_ - x) / right_) * height_;
    else
        return height_;
}
