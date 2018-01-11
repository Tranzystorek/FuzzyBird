#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "fuzlog.h"

#include <vector>
#include <unordered_map>
#include <string>

#include "InputVar.hpp"
#include "OutputVar.hpp"
#include "AndExpr.hpp"

namespace flogic {

class Engine
{
public:
    Engine();

    void setInput(Scalar v);
    Scalar getOutput();

    void process();

private:
    //Scalar input_;
    //Scalar output_;

    std::vector<InputVar> inputs_;
    InputNames inputnames_;

    std::vector<AndExpr> ands_;

    OutputVar output_;

private:
    friend class EngineFactory;
};

}

#endif // ENGINE_HPP
