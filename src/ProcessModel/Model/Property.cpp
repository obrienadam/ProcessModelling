#include "Property.h"

Property::Property(const std::string &symbol,
                   const std::string &description,
                   double value,
                   double min,
                   double max,
                   const Unit &unit)
    :
      symbol(symbol),
      description(description),
      value(value),
      min(min),
      max(max),
      unit_(unit)
{

}
