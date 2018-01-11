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
    using TermNames = std::unordered_map<std::string, int>;
public:
    InputVar(const std::string& name, std::vector<TermObject>&& terms);

    std::vector<Scalar> getActivationValues() const;

    void setInput(Scalar input);
    Scalar getInput() const;

    const TermObject& getTerm(const std::string& name) const;

private:
    std::string name_;
    std::vector<TermObject> terms_;
    TermNames tnames_;

    Scalar xin_;

    Range range_;
};

}

#endif // INPUTVAR_HPP
