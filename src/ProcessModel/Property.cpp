#include "Property.h"

Property::Property(const std::string &name, const std::string &symbol, double value, double min, double max, const Unit &unit, bool userSpecified)
    :
      name(name),
      symbol(symbol),
      value(value),
      min(min),
      max(max),
      unit_(unit),
      userSpecified_(userSpecified)
{
    min = -1e9;
    max = 1e9;
}
