#include "PGModel.h"

PGModel::PGModel()
{
    addBlockProperty("Fan", Property("Pressure ratio", 1.3, 1., 2.));
    addBlockProperty("Fan", Property("Efficiencty", 0.9, 0., 1.));
    addBlockProperty("Fan", Property("K", 0.3, 0., 10.));

    addConnectorProperty(Property("Diameter", 1., 0., 100.));
    addConnectorProperty(Property("Length", 1., 0., 100.));
    addConnectorProperty(Property("Flow rate", 0., 0., 1000.));

    addNodeProperty(Property("Pressure", 0., 1e5, 1e6));
    addNodeProperty(Property("Temperature", 0., 273., 1e4));
}
