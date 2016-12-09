#include "Nozzle.h"

Nozzle::Nozzle()
    :
      Block(1, 1, 0, "Nozzle", "Nozzle")
{
    addProperty("Inlet area", "Ain", 1., 0., 100);
    addProperty("Outlet Area", "Aout", 1., 0., 100);
}
