#ifndef PARSERSTATES_HPP
#define PARSERSTATES_HPP

#include <string>

struct FuncArgs
{
    enum Type
    {
        NONE,
        TRIANGLE,
        RECTANGLE,
        TRAPEZOID,
        BINARY
    };

    FuncArgs()
        : type(NONE),
          argpos(0)
    {}

    Type type;
    int argpos;
};

class ParserStates
{
public:
    enum State
    {
        INPUT,
        OUTPUT,
        RULES,

        BEGIN,
        END,
        ERROR
    };

    enum Substate
    {
        UNSPECIFIED,

        RANGE,
        RANGE_DELIM,
        RANGE_LOWER_BOUND,
        RANGE_HIGHER_BOUND,

        NAME,
        NAME_DELIM,
        NAME_STRING,

        TERM,
        TERM_DELIM,
        TERM_NAME,
        TERM_FUNC,

        RULE,
        RULE_DELIM,
        RULE_IF,
        RULE_INPUT_NAME,
        RULE_INPUT_IS,
        RULE_INPUT_TERM,
        RULE_THEN,
        RULE_OUTPUT_NAME,
        RULE_OUTPUT_IS,
        RULE_OUTPUT_TERM,

        AGGREGATION,
        AGGR_DELIM,
        AGGR_SNORM,

        IMPLICATION,
        IMPL_DELIM,
        IMPL_TNORM,

        DEFUZZIFIER,
        DEFUZ_DELIM,
        DEFUZ_TYPE,
    };

public:
    ParserStates();

    void processToken(const std::string& tok);
    void finish();
    void reset();

    State getState() const {return state_;}
    Substate getSubstate() const {return sub_;}

private:
    State state_;
    Substate sub_;
    FuncArgs fargs_;
};

#endif // PARSERSTATES_HPP
