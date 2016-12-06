#ifndef PROPERTY_H
#define PROPERTY_H

#include <string>

class Property
{
public:
    Property(const std::string& name,
             double value = 0.,
             double min = 0.,
             double max = 100.,
             bool userSpecified = true);

    bool isUserSpecified() const { return userSpecified_; }

    //- So the type can be specified in a map/set
    bool operator<(const Property& rhs) const { return name < rhs.name; }
    bool operator==(const Property& rhs) const { return name == rhs.name; }

    std::string name;
    double value, min, max;

private:
    bool userSpecified_;

};

#endif // PROPERTY_H
