#include "AndExpr.hpp"

using namespace flogic;

AndExpr::AndExpr(const std::vector<TermBinding>& binds)
    : bindings_(binds)
{

}

Scalar AndExpr::evaluate(const std::vector<InputVar>& vars)
{
    Scalar ret = 1.;

    //TODO evaluate
    //multiply all values using a given TNorm (default: Min)

    return ret;
}
