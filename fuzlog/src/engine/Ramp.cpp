#include "Ramp.hpp"

using namespace flogic;

Ramp::Ramp(const std::string& name, Scalar xmin, Scalar xmax, Scalar h, Ramp::Direction dir)
    : Term(name),
      xmin_(xmin),
      xmax_(xmax),
      height_(h),
      width_(xmax - xmin),
      dir_(dir)
{

}

Scalar Ramp::membership(Scalar x)
{
    switch(dir_)
    {
    case LEFT:
        if(x < xmin_)
            return height_;
        else if(x > xmax_)
            return 0.;
        else
            return ((xmax_ - x) / width_) * height_;
        break;

    case RIGHT:
        if(x < xmin_)
            return 0.;
        else if(x > xmax_)
            return height_;
        else
            return ((x - xmin_) / width_) * height_;
        break;
    }
}
