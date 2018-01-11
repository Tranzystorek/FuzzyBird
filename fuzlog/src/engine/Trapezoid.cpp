#include "Trapezoid.hpp"

#include "utility.h"

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
    if(Op::isLt(x, xmin_) || Op::isGt(x, xmax_))
        return 0.;
    else if(Op::isLt(x, xpleft_))
        return ((x - xmin_) / left_) * height_;
    else if(Op::isGt(x, xpright_))
        return ((xmax_ - x) / right_) * height_;
    else
        return height_;
}
