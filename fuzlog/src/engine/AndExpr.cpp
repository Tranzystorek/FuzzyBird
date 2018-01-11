#include "AndExpr.hpp"

using namespace flogic;

AndExpr::AndExpr(const std::vector<TermBinding>& binds)
    : bindings_(binds)
{

}

Scalar AndExpr::evaluate(const std::vector<InputVar>& vars,
                         const InputNames& inputnames)
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
