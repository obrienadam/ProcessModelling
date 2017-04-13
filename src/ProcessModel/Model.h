#ifndef MODEL_H
#define MODEL_H

#include <map>
#include <vector>

#include "Block.h"
#include "Connector.h"

class PROCESSMODELSHARED_EXPORT Model
{
public:
    Model();

    bool blockIsSupported(const std::string& type);

    bool initialize(const std::vector<Connector*>& connectors);
    bool initialize(Connector* connector);

    virtual const std::string type() const = 0;

protected:

    void addConnectorProperty(const Property& property);
    void addConnectorSolution(const Solution &solution);
    void setResistanceFunction(const std::function<double(const std::map<std::string, Property>&, const std::map<std::string, Solution>&)> &resistanceFunction);

private:

    std::map<std::string, Property> connectorProperties_;
    std::map<std::string, Solution> nodeSolutions_;
    std::map<std::string, Solution> connectorSolutions_;

    std::function<double(const std::map<std::string, Property>&, const std::map<std::string, Solution>&)> resistanceFunction_;
};

#include "SimpleLinearModel.h"
#include "PGModel.h"

#endif // MODEL_H
