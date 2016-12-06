#include "Property.h"

Property::Property(const std::string &name, double value, double min, double max, bool userSpecified)
    :
      name(name),
      value(value),
      min(min),
      max(max),
      userSpecified_(userSpecified)
{

}
