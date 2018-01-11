#ifndef ANDEXPR_HPP
#define ANDEXPR_HPP

#include "fuzlog.h"

#include <vector>

#include "InputVar.hpp"

namespace flogic {

struct TermBinding
{
    TermBinding(int in, int term) : invar(in), term(term) {}

    int invar;
    int term;
};

class AndExpr
{
public:
    AndExpr(const std::vector<TermBinding>& binds);

    Scalar evaluate(const std::vector<InputVar>& vars);

private:
    std::vector<TermBinding> bindings_;
};

}

#endif // ANDEXPR_HPP
