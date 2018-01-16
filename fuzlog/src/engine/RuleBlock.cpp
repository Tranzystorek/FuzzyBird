#include "RuleBlock.hpp"

#include <utility>

using namespace flogic;

RuleBlock::RuleBlock()
{

}

RuleBlock::RuleBlock(SNorm* snorm, std::vector<Implicator>&& rules)
    : aggr_(snorm,
            std::forward<std::vector<Implicator>>(rules))
{

}

//const std::vector<Implicator>& RuleBlock::getRules() const
//{
//    return rules_;
//}

void RuleBlock::setActivations(const std::vector<Scalar>& acts)
{
    aggr_.setActivations(acts);
}

const Aggregator& RuleBlock::getAggregator() const
{
    return aggr_;
}
