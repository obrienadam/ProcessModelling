#include <math.h>
#include "PGModel.h"

PGModel::PGModel()
{
    addConnectorProperty(Property("Diameter", "D", 1., 0., 100.));
    addConnectorProperty(Property("Length", "L", 1., 0., 100.));

    addConnectorSolution(Property("Flow rate", "Q", 0., 0., 1000.));

    setResistanceFunction(
                [](const std::map<std::string, Property>& properties, const std::map<std::string, Property>& solutionVariables)->double
    {
        double diameter = properties.find("Diameter")->second.value;
        double length = properties.find("Length")->second.value;
        double Q = solutionVariables.find("Flow rate")->second.value;

        double area = M_PI*diameter*diameter/4;
        double velocity = Q/area;

        //double velocityPressure = pow(velocity/4005, 2);

        double dPl = 2.238/diameter*pow(velocity/1000, 2)*(0.1833 + 1./pow(diameter, 1./3));

        return std::max(length/100*dPl, 1e-8); // relaxed in case the flow rate is currenty 0
    }
    );
}
