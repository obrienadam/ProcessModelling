#include "SimpleLinearModel.h"

SimpleLinearModel::SimpleLinearModel()
{
    addConnectorProperty(Property("R", "R", 1., 0., 100.));
    addConnectorProperty(Property("Length", "L", 1., 0., 100.));

    addConnectorSolution(Property("Flow rate", "Q", 0., 0., 1000.));

    setResistanceFunction(
                [](const std::map<std::string, Property>& properties, const std::map<std::string, Property>& solutionVariables)->double
    {
        return properties.find("R")->second.value*properties.find("Length")->second.value;
    }
    );
}
