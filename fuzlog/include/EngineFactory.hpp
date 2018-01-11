#ifndef ENGINEFACTORY_HPP
#define ENGINEFACTORY_HPP

#include "fuzlog.h"

#include "Engine.hpp"

namespace flogic {

class EngineFactory
{
public:
    EngineFactory();

    Engine createEngine();
};

}

#endif // ENGINEFACTORY_HPP
