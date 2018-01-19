#ifndef ENGINEFACTORY_HPP
#define ENGINEFACTORY_HPP

#include "fuzlog.h"

#include "Engine.hpp"
#include "Term.hpp"
#include "Norm.hpp"

#include "EngineProperties.hpp"

namespace flogic {

class TermFactory
{
public:
    TermFactory();

    static Term* createTerm(const TermProperties& props);
};

class TNormFactory
{
public:
    TNormFactory();

    static TNorm* createTNorm(const TNormProperties& props);
};

class SNormFactory
{
public:
    SNormFactory();

    static SNorm* createSNorm(const SNormProperties& props);
};

class DefuzzifierFactory
{
public:
    DefuzzifierFactory();

    static Defuzzifier* createDefuzzifier(const DefuzzifierProperties& props);
};

class EngineFactory
{
public:
    EngineFactory();

    static Engine* createEngine(const EngineProperties& props);
};

}

#endif // ENGINEFACTORY_HPP
