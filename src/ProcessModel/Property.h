#ifndef PROPERTY_H
#define PROPERTY_H

#include <string>
#include "Unit.h"

class Property
{
public:
    Property(const std::string& name = "Undefined",
             const std::string& symbol = "",
             double value = 0.,
             double min = 0.,
             double max = 100.,
             const Unit& unit = Unit("Metric", 1.),
             bool userSpecified = true);

    bool isUserSpecified() const { return userSpecified_; }

    //- So the type can be specified in a map/set
    bool operator<(const Property& rhs) const { return name < rhs.name; }
    bool operator<(const std::string& propertyName) const { return name < propertyName; }
    bool operator<(const char propertyName[]) const { return name < propertyName; }

    std::string name, symbol;
    double value, min, max;

private:
    bool userSpecified_;
    //Unit unit_;

};

#endif // PROPERTY_H
