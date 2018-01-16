#ifndef ENGINEPROPERTIES_HPP
#define ENGINEPROPERTIES_HPP

#include "fuzlog.h"

#include <string>
#include <vector>

namespace flogic {

struct TermProperties
{
    TermProperties();

    enum Type {BINARY, RAMP, RECTANGLE, TRAPEZOID, TRIANGLE};

    std::string name;
    Type type;

    std::vector<Scalar> params;
};

struct TNormProperties
{
    TNormProperties();

    enum Function {ALGEBRAIC_PRODUCT, MINIMUM};

    Function function;
};

struct SNormProperties
{
    SNormProperties();

    enum Function {BOUNDED_SUM, MAXIMUM};

    Function function;
};

struct DefuzzifierProperties
{
    DefuzzifierProperties();

    enum Type {BISECTOR, CENTROID};

    Type type;
    int resolution;
};

struct VariableProperties
{
    VariableProperties();

    std::string name;
    Range range;
    std::vector<TermProperties> terms;
};

struct RuleProperties
{
    RuleProperties();

    struct ConditionBlock
    {
        std::string vname;
        std::string tname;
    };

    std::vector<ConditionBlock> conditions;
    ConditionBlock conclusion;
};

struct EngineProperties
{
    EngineProperties();

    std::vector<VariableProperties> invars;
    VariableProperties outvar;

    std::vector<RuleProperties> rules;

    TNormProperties implication;
    SNormProperties aggregation;

    DefuzzifierProperties defuzzifier;
};

}

#endif // ENGINEPROPERTIES_HPP
