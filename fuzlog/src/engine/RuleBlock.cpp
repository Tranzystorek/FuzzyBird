#include "RuleBlock.hpp"

using namespace flogic;

RuleBlock::RuleBlock(const std::vector<Rule>& rules)
    : rules_(rules)
{

}

const std::vector<Rule>& RuleBlock::getRules() const
{
    return rules_;
}
