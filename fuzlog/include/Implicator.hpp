#ifndef IMPLICATOR_HPP
#define IMPLICATOR_HPP

#include "fuzlog.h"

#include <string>

#include "Term.hpp"
#include "Norm.hpp"

namespace flogic {

class Implicator : public Term
{
public:
    Implicator(TNorm* tnorm, Term* out);

    Scalar membership(Scalar x) const;

    void setActivation(Scalar act);

private:
    TNormObject tnorm_;

    Scalar activation_;
    Term* outterm_;
};

}

#endif // IMPLICATOR_HPP
