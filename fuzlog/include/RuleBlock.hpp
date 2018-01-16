#ifndef RULEBLOCK_HPP
#define RULEBLOCK_HPP

#include "fuzlog.h"

#include <vector>

#include "Aggregator.hpp"

namespace flogic {

struct Rule
{
    Rule(int act, int out) : activ_index(act), outterm(out) {}

    int activ_index;
    int outterm;
};

class RuleBlock
{
public:
    RuleBlock();
    RuleBlock(SNorm* snorm, std::vector<Implicator>&& rules);

    //const std::vector<Implicator>& getRules() const;

    void setActivations(const std::vector<Scalar>& acts);

    const Aggregator& getAggregator() const;

private:
    Aggregator aggr_;
};

}

#endif // RULEBLOCK_HPP
