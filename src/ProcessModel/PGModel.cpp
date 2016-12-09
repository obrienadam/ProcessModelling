#include "PGModel.h"

PGModel::PGModel()
{
    addBlockProperty("Fan", Property("Pressure ratio", "PI", 1.3, 1., 2.));
    addBlockProperty("Fan", Property("Efficiencty", "eta", 0.9, 0., 1.));
    addBlockProperty("Fan", Property("Loss coefficient", "K", 0.3, 0., 10.));

    addBlockProperty("Pressure Reservoir", Property("Pressure", "P", 101325, 0, 10*101325));
    addBlockProperty("Mass Flow Reservoir", Property("Flow rate", "Q", 0, -1000, 1000));

    addConnectorProperty(Property("Diameter", "D", 1., 0., 100.));
    addConnectorProperty(Property("Length", "L", 1., 0., 100.));
    addConnectorProperty(Property("Flow rate", "Q", 0., 0., 1000.));

    addNodeProperty(Property("Pressure", "P", 0., 1e5, 1e6));
    addNodeProperty(Property("Temperature", "T", 0., 273., 1e4));
}
