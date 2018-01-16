#include "Binary.hpp"

#include "utility.h"

using namespace flogic;

Binary::Binary(const std::string& name, Scalar xslope, Scalar h, Binary::Direction dir, Binary::Inclusivity incl)
    : Term(name),
      xslope_(xslope),
      height_(h),
      dir_(dir),
      incl_(incl)
{

}

Scalar Binary::membership(Scalar x) const
{
    switch(incl_)
    {
    case INCLUSIVE:
        return membership_incl(x);

    case EXCLUSIVE:
        return membership_excl(x);
    }
}

Scalar Binary::membership_incl(Scalar x) const
{
    switch(dir_)
    {
    case LEFT:
        if(Op::isGt(x, xslope_))
            return 0.;
        else
            return height_;

    case RIGHT:
        if(Op::isLt(x, xslope_))
            return 0.;
        else
            return height_;
    }
}

Scalar Binary::membership_excl(Scalar x) const
{
    switch(dir_)
    {
    case LEFT:
        if(Op::isLt(x, xslope_))
            return height_;
        else
            return 0.;

    case RIGHT:
        if(Op::isGt(x, xslope_))
            return height_;
        else
            return 0.;
    }
}
