#include "Aggregator.hpp"

#include <algorithm>
#include <utility>

using namespace flogic;

Aggregator::Aggregator()
    : Term("aggregate")
{

}

Aggregator::Aggregator(SNorm* snorm, std::vector<Implicator>&& impls)
    : Term("aggregate"),
      snorm_(snorm),
      implications_(std::forward<std::vector<Implicator>>(impls))
{

}

Scalar Aggregator::membership(Scalar x) const
{
    Scalar ret = 0.;

    for(auto& implication : implications_)
        ret = snorm_->compute(ret, implication.membership(x));

    return ret;
}

void Aggregator::setActivations(const std::vector<Scalar>& acts)
{
    auto iter = implications_.begin();

    for(auto& activation : acts)
    {
        iter->setActivation(activation);
        ++iter;
    }
}
