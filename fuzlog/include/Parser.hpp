#ifndef PARSER_HPP
#define PARSER_HPP

#include <unordered_map>
#include <fstream>

#include "Tokenizer.hpp"
#include "ParserStates.hpp"
#include "EngineProperties.hpp"

class Parser
{
public:
    using Identifiers = std::unordered_map<std::string, int>;

public:
    Parser(const char* filename);

    void parse();

private:
    ParserStates pstates_;
    std::ifstream file_;

    Identifiers inTerms_;
    Identifiers outTerms_;

    EngineProperties properties_;
};

#endif // PARSER_HPP
