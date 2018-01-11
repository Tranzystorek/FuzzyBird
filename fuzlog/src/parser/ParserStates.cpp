#include "ParserStates.hpp"

ParserStates::ParserStates()
{
}

void ParserStates::processToken(const std::string& tok)
{
    if(state_ == State::INPUT)
    {
        switch(sub_)
        {
        case Substate::NAME:
            break;

        case Substate::RANGE:
            break;

        case Substate::TERM:
            break;
        }
    }

    else if(state_ == State::OUTPUT)
    {
        switch(sub_)
        {
        case Substate::NAME:
            break;

        case Substate::RANGE:
            break;

        case Substate::TERM:
            break;

        case Substate::AGGREGATION:
            break;

        case Substate::DEFUZZIFIER:
            break;
        }
    }

    else if(state_ == State::RULES)
    {
        switch(sub_)
        {
        case Substate::RULE:
            break;

        case Substate::IMPLICATION:
            break;
        }
    }
}
