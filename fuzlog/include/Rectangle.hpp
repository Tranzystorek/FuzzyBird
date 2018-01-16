#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "fuzlog.h"

#include "Term.hpp"

namespace flogic {

class Rectangle : public Term
{
public:
    Rectangle(const std::string& name, Scalar xmin, Scalar xmax, Scalar h);

    Scalar membership(Scalar x) const;

private:
    Scalar xmin_;
    Scalar xmax_;
    Scalar height_;
};

}

#endif // RECTANGLE_HPP
