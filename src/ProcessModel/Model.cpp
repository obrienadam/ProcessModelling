#include "Model.h"

Model::Model()
{

}

bool Model::initialize(const std::vector<Connector *> &connectors)
{
    for(Connector* connector: connectors)
        initialize(connector);

    return true;
}

bool Model::initialize(Connector *connector)
{
    connector->setProperties(connectorProperties_);
    connector->setSolutionVariables(connectorSolutionVariables_);
    connector->setResistanceFunction(resistanceFunction_);
    return true;
}

void Model::addConnectorProperty(const Property &property)
{
    connectorProperties_[property.name] = property;
}

void Model::addConnectorSolution(const Property &solution)
{
    connectorSolutionVariables_[solution.name] = solution;
}

void Model::setResistanceFunction(const std::function<double(const std::map<std::string, Property> &, const std::map<std::string, Property> &)> &resistanceFunction)
{
    resistanceFunction_ = resistanceFunction;
}
