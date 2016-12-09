#include "PressureReservoir.h"

PressureReservoir::PressureReservoir()
    :
      Block(0, 0, 1, "Pressure Reservoir", "Patm")
{
    addProperty("Pressure", "P", 101325., 0, 2*101325);
}
