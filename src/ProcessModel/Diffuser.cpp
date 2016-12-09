#include "Diffuser.h"

Diffuser::Diffuser()
    :
      Block(1, 1, 0, "Diffuser", "Diffuser")
{
    addProperty("Inlet area", "Ain", 1., 0., 100);
    addProperty("Outlet Area", "Aout", 1., 0., 100);
}
