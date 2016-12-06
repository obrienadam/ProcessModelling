#include "Fan.h"

Fan::Fan()
    :
      Block(1, 1, 0, "Fan", "Fan")
{
    addProperty("Max power output (kW)", 300, 0, 1000);
    addProperty("Pressure ratio", 1., 0., 10.);
    addProperty("Efficiency", 0.9, 0., 1.);
}
