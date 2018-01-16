#ifndef RAMP_HPP
#define RAMP_HPP

#include "fuzlog.h"

#include "Term.hpp"

namespace flogic {

class Ramp : public Term
{
public:
    enum Direction {LEFT, RIGHT};

public:
    Ramp(const std::string& name, Scalar xmin, Scalar xmax, Scalar h, Direction dir);

    Scalar membership(Scalar x) const;

private:
    Scalar xmin_;
    Scalar xmax_;

    Scalar height_;

    Scalar width_;

    Direction dir_;
};

}

#endif // RAMP_HPP
