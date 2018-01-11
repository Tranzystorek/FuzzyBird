#ifndef INPUTVAR_HPP
#define INPUTVAR_HPP

#include "fuzlog.h"

#include <vector>
#include <unordered_map>
#include <string>

#include "Term.hpp"

namespace flogic {

struct Range
{
    Scalar lower;
    Scalar higher;
};

class InputVar
{
public:
    using TermNames = std::unordered_map<std::string, int>;
public:
    InputVar(const std::string& name, std::vector<TermObject>&& terms);

    std::vector<Scalar> getActivationValues() const;

    void setInput(Scalar input);
    const TermObject& getTerm(const std::string& name);

private:
    std::string name_;
    std::vector<TermObject> terms_;
    TermNames tnames_;

    Range range_;

    Scalar xin_;
};

}

#endif // INPUTVAR_HPP
