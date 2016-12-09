#include "MassFlowReservoir.h"

MassFlowReservoir::MassFlowReservoir()
    :
      Block(0, 0, 1, "Mass Flow Reservoir", "Q")
{
    addProperty("Flow rate", "Q", 0, -1000, 1000);
}
