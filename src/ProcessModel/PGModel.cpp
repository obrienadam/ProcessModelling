#include <math.h>
#include <QDebug>
\
#include "PGModel.h"

PGModel::PGModel()
{
    addConnectorProperty(Property("Ke", "Entrance loss coefficient", 0., 0., 100., Unit("N/A")));
    addConnectorProperty(Property("D", "Diameter", 1., 0.01, 100., Unit("in", 0.0254)));
    addConnectorProperty(Property("L", "Length", 1., 0.01, 1e12, Unit("ft", 0.3048)));
    addConnectorSolution(Solution("Q", "Flow rate", "CFM"));

    setResistanceFunction(
                [](const std::map<std::string, Property>& properties,
                const std::map<std::string, Solution>& solutionVariables)->double
    {
        double diameter = properties.find("D")->second.value;
        double length = properties.find("L")->second.value;
        double Q = fabs(solutionVariables.find("Q")->second.value);
        double area = M_PI*diameter*diameter/4./144.;
        double velocity = Q/area;

        //double velocityPressure = pow(velocity/4005, 2);

        double dPl = 2.238/diameter*velocity/(1000*1000)*(0.1833 + 1./pow(diameter, 1./3))/area;

        double rEnt = properties.find("Ke")->second.value*velocity/(4005*4005*area);

        if(dPl == 0)
            return 1.;
        else
            return std::max(length/100*dPl + rEnt, 0.);
    }
    );
}
