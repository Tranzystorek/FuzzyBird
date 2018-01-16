#ifndef INPUTVAR_HPP
#define INPUTVAR_HPP

#include "fuzlog.h"

#include <vector>
#include <unordered_map>
#include <string>

#include "Term.hpp"

namespace flogic {

class InputVar
{
public:
    InputVar(const std::string& name, const Range& r, std::vector<TermObject>&& terms);

    std::vector<Scalar> getActivationValues() const;

    void setInput(Scalar input);
    Scalar getInput() const;

    const TermObject& getTerm(const std::string& name) const;

private:
    std::string name_;
    std::vector<TermObject> terms_;
    TermNames tnames_;

    Range range_;

    Scalar xin_;
};

}

#endif // INPUTVAR_HPP
