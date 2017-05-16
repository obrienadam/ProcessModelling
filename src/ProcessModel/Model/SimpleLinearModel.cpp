#include "SimpleLinearModel.h"

SimpleLinearModel::SimpleLinearModel()
{
    addConnectorProperty(Property("R", "Resistance", 1., 0., 1e12, Unit("Pa*s/m^3", 1.)));
    addConnectorProperty(Property("L", "Length", 1., 0., 100., Unit("m", 1.)));
    addConnectorSolution(Solution("Q", "Flow rate", "m^3/s"));

    setResistanceFunction(
                [](const std::map<std::string, Property>& properties, const std::map<std::string, Solution>& solutionVariables)->double
    {
        return properties.find("R")->second.value*properties.find("L")->second.value;
    }
    );
}
