#include "Rectangle.hpp"

using namespace flogic;

Rectangle::Rectangle(const std::string& name, Scalar xmin, Scalar xmax, Scalar h)
    : Term(name),
      xmin_(xmin),
      xmax_(xmax),
      height_(h)
{

}

Scalar Rectangle::membership(Scalar x)
{
    if(Op::isLt(x, xmin_) || Op::isGt(x, xmax_))
        return 0.;
    else
        return height_;
}
