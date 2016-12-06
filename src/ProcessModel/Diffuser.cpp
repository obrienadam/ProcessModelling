#include "Diffuser.h"

Diffuser::Diffuser()
    :
      Block(1, 1, 0, "Diffuser", "Diffuser")
{
    addProperty("Inlet area", 1., 0., 100);
    addProperty("Outlet Area", 1., 0., 100);
}
