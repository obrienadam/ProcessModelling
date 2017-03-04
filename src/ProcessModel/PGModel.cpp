#include <math.h>
#include <QDebug>
\
#include "PGModel.h"

PGModel::PGModel()
{
    addConnectorProperty(Property("Entrance loss coefficient", "K", 0., 0., 100., Unit("N/A")));
    addConnectorProperty(Property("Diameter", "D", 1., 0.01, 100., Unit("in", 0.0254)));
    addConnectorProperty(Property("Length", "L", 1., 0.01, 1e12, Unit("ft", 0.3048)));
    addConnectorSolution(Property("Flow rate", "Q", 0., 0., 1e12, Unit("CFM", 1./2118.88)));

    setResistanceFunction(
                [](const std::map<std::string, Property>& properties,
                const std::map<std::string, Property>& solutionVariables)->double
    {
        double diameter = properties.find("Diameter")->second.value;
        double length = properties.find("Length")->second.value;
        double Q = fabs(solutionVariables.find("Flow rate")->second.value);
        double area = 3.14*diameter*diameter/4./144.;
        double velocity = Q/area;

        //double velocityPressure = pow(velocity/4005, 2);

        double dPl = 2.238/diameter*velocity/(1000*1000)*(0.1833 + 1./pow(diameter, 1./3))/area;

        double rEnt = properties.find("Entrance loss coefficient")->second.value*velocity/(4005*4005*area);

        if(dPl == 0)
            return 1.;
        else
            return std::max(length/100*dPl + rEnt, 0.);
    }
    );
}
