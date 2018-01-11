#include "Binary.hpp"

using namespace flogic;

Binary::Binary(const std::string& name, Scalar xslope, Scalar h, Binary::Direction dir, Binary::Inclusivity incl)
    : Term(name),
      xslope_(xslope),
      height_(h),
      dir_(dir),
      incl_(incl)
{

}

Scalar Binary::membership(Scalar x)
{
    switch(incl_)
    {
    case INCLUSIVE:
        return membership_incl(x);

    case EXCLUSIVE:
        return membership_excl(x);
    }
}

Scalar Binary::membership_incl(Scalar x)
{
    switch(dir_)
    {
    case LEFT:
        if(x > xslope_)
            return 0.;
        else
            return height_;

    case RIGHT:
        if(x < xslope_)
            return 0.;
        else
            return height_;
    }
}

Scalar Binary::membership_excl(Scalar x)
{
    switch(dir_)
    {
    case LEFT:
        if(x < xslope_)
            return height_;
        else
            return 0.;

    case RIGHT:
        if(x > xslope_)
            return height_;
        else
            return 0.;
    }
}
