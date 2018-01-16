#ifndef OUTPUTVAR_HPP
#define OUTPUTVAR_HPP

#include "fuzlog.h"

#include <vector>
#include <string>

#include "Term.hpp"

namespace flogic {

class OutputVar
{
public:
    OutputVar();
    OutputVar(const std::string& name, const Range& r, std::vector<TermObject>&& terms);

    const Range& getRange() const;

    void setOutput(Scalar xout);
    Scalar getOutput() const;

    const TermObject& getTerm(const std::string& name) const;

private:
    std::string name_;
    std::vector<TermObject> terms_;
    TermNames tnames_;

    Range range_;

    Scalar xout_;
};

}

#endif // OUTPUTVAR_HPP
