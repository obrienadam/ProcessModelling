#include "Nozzle.h"

Nozzle::Nozzle()
    :
      Block(1, 1, 0, "Nozzle", "Nozzle")
{
    addProperty(Property("Ain", "Inlet area", 1., 0., 100, Unit("m^2", 1.)));
    addProperty(Property("Aout", "Outlet area", 1., 0., 100, Unit("m^2", 1.)));
}
