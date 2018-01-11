#include "Tokenizer.hpp"

#include <algorithm>
#include <cctype>

std::string toLCase(const std::string& s)
{
    std::string conv = s;

    for(char& c : conv)
        c = tolower(c);

    return conv;
}

Tokenizer::Tokenizer(const char* dropped,
                     const char* kept)
    : dropped_(dropped),
      kept_(kept),
      valid_(false)
{
}

Tokenizer::Tokenizer(const std::string& s,
                     const char* dropped,
                     const char* kept,
                     bool lcase)
    : dropped_(dropped),
      kept_(kept),
      forceLowercase_(lcase),
      valid_(true)
{
    if(forceLowercase_)
        text_ = toLCase(s);
    else
        text_ = s;

    parse();
}

void Tokenizer::assign(const std::string& s)
{
    if(forceLowercase_)
        text_ = toLCase(s);
    else
        text_ = s;

    valid_ = true;

    tokens_.clear();
    parse();
}

void Tokenizer::setKept(const char* k)
{
    kept_ = k;
}

void Tokenizer::setDropped(const char* d)
{
    dropped_ = d;
}

void Tokenizer::parse()
{
    std::string token;

    for(char& c : text_)
    {
        if(dropped_.find(c) != std::string::npos)
        {
            if(!token.empty())
            {
                tokens_.push_back(token);
                token.clear();
            }
        }

        else if(kept_.find(c) != std::string::npos)
        {
            if(!token.empty())
            {
                tokens_.push_back(token);
                token.clear();
            }

            tokens_.push_back(std::string(&c));
        }

        else
            token += c;
    }

    if(!token.empty())
        tokens_.push_back(token);
}
