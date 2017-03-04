#include "SimpleLinearModel.h"

SimpleLinearModel::SimpleLinearModel()
{
    addConnectorProperty(Property("R", "R", 1., 0., 1e12, Unit("Pa*s/m^3", 1.)));
    addConnectorProperty(Property("Length", "L", 1., 0., 100., Unit("m", 1.)));
    addConnectorSolution(Property("Flow rate", "Q", 0., 0., 1e12, Unit("m", 1.)));

    setResistanceFunction(
                [](const std::map<std::string, Property>& properties, const std::map<std::string, Property>& solutionVariables)->double
    {
        return properties.find("R")->second.value*properties.find("Length")->second.value;
    }
    );
}
