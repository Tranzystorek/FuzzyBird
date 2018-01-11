#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "fuzlog.h"

#include "Term.hpp"

namespace flogic {

class Triangle : public Term
{
public:
    Triangle(const std::string& name, Scalar xmin, Scalar xmax, Scalar xpeak, Scalar h);

    Scalar membership(Scalar x);

private:
    Scalar xmin_;
    Scalar xmax_;
    Scalar xpeak_;
    Scalar height_;

    Scalar left_;
    Scalar right_;
};

}

#endif // TRIANGLE_HPP
