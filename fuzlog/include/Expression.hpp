#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include "fuzlog.h"

namespace flogic {

class Expression
{
public:
    Expression() {}
    virtual ~Expression() {}

    virtual Scalar evaluate() = 0;
};

}

#endif // EXPRESSION_HPP
