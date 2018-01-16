#ifndef ANDEXPR_HPP
#define ANDEXPR_HPP

#include "fuzlog.h"

#include <vector>
#include <string>

#include "InputVar.hpp"
#include "Term.hpp"
#include "Norm.hpp"

namespace flogic {

struct TermBinding
{
    TermBinding() {}
    TermBinding(const std::string& in, const std::string& term) : invar(in), term(term) {}

    std::string invar;
    std::string term;
};

class AndExpr
{
public:
    AndExpr(const std::vector<TermBinding>& binds, TNorm* tnorm);

    Scalar evaluate(const std::vector<InputVar>& vars,
                    const InputNames& inputnames) const;

private:
    std::vector<TermBinding> bindings_;

    TNormObject tnorm_;
};

}

#endif // ANDEXPR_HPP
