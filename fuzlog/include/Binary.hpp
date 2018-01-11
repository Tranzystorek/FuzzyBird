#ifndef BINARY_HPP
#define BINARY_HPP

#include "fuzlog.h"

#include "Term.hpp"

namespace flogic {

class Binary : public Term
{
public:
    enum Direction {LEFT, RIGHT};
    enum Inclusivity {INCLUSIVE, EXCLUSIVE};

public:
    Binary(const std::string& name, Scalar xslope, Scalar h, Direction dir, Inclusivity incl = Inclusivity::INCLUSIVE);

    Scalar membership(Scalar x);

private:
    Scalar membership_incl(Scalar x);
    Scalar membership_excl(Scalar x);

private:
    Scalar xslope_;
    Scalar height_;

    Direction dir_;
    Inclusivity incl_;
};

}

#endif // BINARY_HPP
