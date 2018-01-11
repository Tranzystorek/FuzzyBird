#ifndef AGGREGATOR_HPP
#define AGGREGATOR_HPP

#include "fuzlog.h"

#include "Term.hpp"

namespace flogic {

class Aggregator : public Term
{
public:
    Aggregator();

    Scalar membership(Scalar x);

private:
};

}

#endif // AGGREGATOR_HPP
