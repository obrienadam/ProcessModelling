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
    for(const auto& entry: connectorProperties_)
    {
        const Property& p = entry.second;
        connector->addProperty(p);
    }

    for(const auto& entry: connectorSolutions_)
    {
        const Solution& s = entry.second;
        connector->addSolution(s);
    }

    connector->setResistanceFunction(resistanceFunction_);
    return true;
}

void Model::addConnectorProperty(const Property &property)
{
    connectorProperties_[property.symbol] = property;
}

void Model::addConnectorSolution(const Solution &solution)
{
    connectorSolutions_[solution.symbol] = solution;
}

void Model::setResistanceFunction(const std::function<double(const std::map<std::string, Property>&, const std::map<std::string, Solution>&)> &resistanceFunction)
{
    resistanceFunction_ = resistanceFunction;
}
