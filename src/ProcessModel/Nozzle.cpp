#include "Nozzle.h"

Nozzle::Nozzle()
    :
      Block(1, 1, 0, "Nozzle", "Nozzle")
{
    addProperty(Property("Inlet area", "Ain", 1., 0., 100, Unit("m^2", 1.)));
    addProperty(Property("Outlet Area", "Aout", 1., 0., 100, Unit("m^2", 1.)));
}
