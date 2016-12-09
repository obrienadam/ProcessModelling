#include "Property.h"

Property::Property(const std::string &name, const std::string &symbol, double value, double min, double max, bool userSpecified)
    :
      name(name),
      symbol(symbol),
      value(value),
      min(min),
      max(max),
      userSpecified_(userSpecified)
{

}
