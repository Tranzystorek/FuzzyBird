#include "OutputVar.hpp"

using namespace flogic;

OutputVar::OutputVar()
{

}

OutputVar::OutputVar(const std::string& name, const Range& r, std::vector<TermObject>&& terms)
    : name_(name),
      terms_(std::forward<std::vector<TermObject>>(terms)),
      range_(r),
      xout_(0.)
{
    int i = 0;

    for(auto& t : terms_)
        tnames_.emplace(t->getName(), i++);
}

const Range&OutputVar::getRange() const
{
    return range_;
}

void OutputVar::setOutput(Scalar xout)
{
    xout_ = xout;
}

Scalar OutputVar::getOutput() const
{
    return xout_;
}

const TermObject& OutputVar::getTerm(const std::string& name) const
{
    return terms_[tnames_.at(name)];
}
