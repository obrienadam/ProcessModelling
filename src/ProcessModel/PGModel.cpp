#include <math.h>
#include <QDebug>
\
#include "PGModel.h"

PGModel::PGModel()
{
    addConnectorProperty(Property("Diameter", "D", 1., 0., 100.));
    addConnectorProperty(Property("Length", "L", 1., 0., 100.));

    addConnectorSolution(Property("Flow rate", "Q", 0., 0., 1000.));

    setResistanceFunction(
                [](const std::map<std::string, Property>& properties,
                const std::map<std::string, Property>& solutionVariables)->double
    {
        double diameter = properties.find("Diameter")->second.value;
        double length = properties.find("Length")->second.value;
        double Q = solutionVariables.find("Flow rate")->second.value;

        double area = 3.14*diameter*diameter/4./144.;

        qDebug() << area;

        double velocity = Q/area;

        qDebug() << velocity;

        //double velocityPressure = pow(velocity/4005, 2);

        double dPl = 2.238/diameter*velocity/(1000*1000)*(0.1833 + 1./pow(diameter, 1./3))/area;

        qDebug() << dPl;

        return std::max(length/100*dPl, 1e-8); // relaxed in case the flow rate is currenty 0
    }
    );
}
