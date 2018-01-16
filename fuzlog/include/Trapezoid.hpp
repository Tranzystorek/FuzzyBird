#ifndef TRAPEZOID_HPP
#define TRAPEZOID_HPP

#include "fuzlog.h"

#include "Term.hpp"

namespace flogic {

class Trapezoid : public Term
{
public:
    Trapezoid(const std::string& name, Scalar xmin, Scalar xmax, Scalar xpl, Scalar xpr, Scalar h);

    Scalar membership(Scalar x) const;

private:
    Scalar xmin_;
    Scalar xmax_;
    Scalar xpleft_;
    Scalar xpright_;

    Scalar height_;

    Scalar left_;
    Scalar right_;
};

}

#endif // TRAPEZOID_HPP
