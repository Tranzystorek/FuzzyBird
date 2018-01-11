#ifndef FUZLOG_H
#define FUZLOG_H

#include <vector>
#include <unordered_map>
#include <string>

namespace flogic {

//common library type for scalar values
using Scalar = double;

//type for name maps
using InputNames = std::unordered_map<std::string, int>;

//struct for value range
struct Range
{
    Range(Scalar l, Scalar h) : lower(l), higher(h) {}

    Scalar lower;
    Scalar higher;
};

}

#endif // FUZLOG_H
