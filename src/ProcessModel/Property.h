#ifndef PROPERTY_H
#define PROPERTY_H

#include <string>
#include "Unit.h"

class Property
{
public:
    Property(const std::string& symbol = "Undefined",
             const std::string& description = "",
             double value = 0.,
             double min = 0.,
             double max = 100.,
             const Unit& unit = Unit("Metric", 1.));

    bool isUserSpecified() const { return userSpecified_; }
    const Unit& unit() const { return unit_; }

    std::string symbol, description;
    double value, min, max;

private:
    bool userSpecified_;
    Unit unit_;

};

#endif // PROPERTY_H
