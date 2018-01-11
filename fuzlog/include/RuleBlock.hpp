#ifndef RULEBLOCK_HPP
#define RULEBLOCK_HPP

#include "fuzlog.h"

#include <vector>

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
    RuleBlock(const std::vector<Rule>& rules);

    const std::vector<Rule>& getRules() const;

private:
    std::vector<Rule> rules_;
};

}

#endif // RULEBLOCK_HPP
