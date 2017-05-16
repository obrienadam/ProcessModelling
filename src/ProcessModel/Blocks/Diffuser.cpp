#include "Diffuser.h"

Diffuser::Diffuser()
    :
      Block(1, 1, 0, "Diffuser", "Diffuser")
{
    addProperty(Property("Ain", "Inlet area", 1., 0., 100, Unit("m^2", 1.)));
    addProperty(Property("Aout", "Outlet area", 1., 0., 100, Unit("m^2", 1.)));
}
