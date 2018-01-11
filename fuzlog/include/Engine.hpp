#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "fuzlog.h"

namespace flogic {

class Engine
{
public:
    Engine();

    void setInput(Scalar v);
    Scalar getOutput();

    void process();

private:
    Scalar input_;
    Scalar output_;

    friend class EngineFactory;
};

}

#endif // ENGINE_HPP
