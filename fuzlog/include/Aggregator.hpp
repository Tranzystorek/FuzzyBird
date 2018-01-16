#ifndef AGGREGATOR_HPP
#define AGGREGATOR_HPP

#include "fuzlog.h"

#include "Term.hpp"
#include "Norm.hpp"
#include "Implicator.hpp"

namespace flogic {

class Aggregator : public Term
{
public:
    Aggregator();
    Aggregator(SNorm* snorm, std::vector<Implicator>&& impls);

    Scalar membership(Scalar x) const;

    void setActivations(const std::vector<Scalar>& acts);

private:
    SNormObject snorm_;

    std::vector<Implicator> implications_;
};

}

#endif // AGGREGATOR_HPP
