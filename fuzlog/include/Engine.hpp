#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "fuzlog.h"

#include <vector>
#include <unordered_map>
#include <string>

#include "InputVar.hpp"
#include "OutputVar.hpp"
#include "AndExpr.hpp"
#include "RuleBlock.hpp"
#include "Defuzzifier.hpp"

namespace flogic {

class Engine
{
private:
    Engine();

public:
    void setInput(const std::string& vname, Scalar v);
    Scalar getOutput();

    void process();

private:
    void activate();
    void calculate();

private:
    std::vector<InputVar> inputs_;
    InputNames inputnames_;

    std::vector<AndExpr> ands_;
    RuleBlock ruleblock_;

    DefuzzifierObject defuzz_;

    OutputVar output_;

private:
    friend class EngineFactory;
};

}

#endif // ENGINE_HPP
