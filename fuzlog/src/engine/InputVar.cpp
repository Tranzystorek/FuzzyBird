#include "InputVar.hpp"

#include <utility>
#include <algorithm>

using namespace flogic;

InputVar::InputVar(const std::string& name, const Range& r, std::vector<TermObject>&& terms)
    : name_(name),
      terms_(std::forward<std::vector<TermObject>>(terms)),
      range_(r),
      xin_(0.)
{
    int i = 0;

    for(auto& t : terms_)
        tnames_.emplace(t->getName(), i++);
}

std::vector<Scalar> InputVar::getActivationValues() const
{
    std::vector<Scalar> ret(terms_.size());

    std::transform(terms_.begin(), terms_.end(),
                   ret.begin(),
                   [this](const TermObject& t){return t->membership(xin_);});

    return ret;
}

void InputVar::setInput(Scalar input)
{
    xin_ = input;
}

Scalar InputVar::getInput() const
{
    return xin_;
}

const TermObject& InputVar::getTerm(const std::string& name) const
{
    return terms_[tnames_.at(name)];
}
