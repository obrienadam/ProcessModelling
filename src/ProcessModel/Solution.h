#ifndef SOLUTION_H
#define SOLUTION_H

#include <string>

class Solution
{
public:

    Solution() {}
    Solution(const std::string& symbol,
             const std::string& description,
             const std::string& unit = "N/A",
             double value = 0.) :
        symbol(symbol),
        description(description),
        unit(unit),
        value(value)
    {

    }

    std::string symbol, description, unit;
    double value = 0.;
};

#endif
