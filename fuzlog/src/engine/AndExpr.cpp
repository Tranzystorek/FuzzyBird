#include "AndExpr.hpp"

using namespace flogic;

AndExpr::AndExpr(const std::vector<TermBinding>& binds, TNorm* tnorm)
    : bindings_(binds),
      tnorm_(tnorm)
{

}

Scalar AndExpr::evaluate(const std::vector<InputVar>& vars,
                         const InputNames& inputnames) const
{
    Scalar ret = 1.;

    for(auto& bind : bindings_)
    {
        const InputVar& input = vars[inputnames.at(bind.invar)];
        const TermObject& vterm = input.getTerm(bind.term);
        Scalar xin = input.getInput();

        ret = tnorm_->compute(ret, vterm->membership(xin));
    }

    return ret;
}
