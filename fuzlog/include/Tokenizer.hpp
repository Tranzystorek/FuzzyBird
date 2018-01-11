#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <vector>
#include <string>

class Tokenizer
{
public:
    using Tokens = std::vector<std::string>;

public:
    Tokenizer(const char* d = "", const char* k = "");

    Tokenizer(const std::string& t,
              const char* d,
              const char* k = "",
              bool lc = false);

    void assign(const std::string&);

    void setKept(const char* k);
    void setDropped(const char* d);

    bool isValid() const {return valid_;}

    const Tokens& tokens() {return tokens_;}

private:

    void parse();

private:

    std::string text_;
    Tokens tokens_;

    std::string dropped_;
    std::string kept_;

    bool forceLowercase_;
    bool valid_;
};

#endif //TOKENIZER_HPP
