#include "Implicator.hpp"

using namespace flogic;

Implicator::Implicator(TNorm* tnorm, Term* out)
    : Term("implicate"),
      tnorm_(tnorm),
      outterm_(out)
{

}

Scalar Implicator::membership(Scalar x) const
{
    return tnorm_->compute(activation_, outterm_->membership(x));
}

void Implicator::setActivation(Scalar act)
{
    activation_ = act;
}
