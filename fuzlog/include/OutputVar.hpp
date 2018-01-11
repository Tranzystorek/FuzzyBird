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

private:
    std::string name_;
    std::vector<TermObject> terms_;
};

}

#endif // OUTPUTVAR_HPP
