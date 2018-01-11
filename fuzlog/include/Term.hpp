#ifndef TERM_HPP
#define TERM_HPP

#include "fuzlog.h"

#include <memory>
#include <string>

namespace flogic {

class Term;
using TermObject = std::unique_ptr<Term>;

class Term
{
public:
    Term(const std::string& name) : name_(name) {}
    virtual ~Term() {}

    virtual Scalar membership(Scalar x) = 0;

    const std::string& getName() const {return name_;}

private:
    std::string name_;
};

}

#endif // TERM_HPP
