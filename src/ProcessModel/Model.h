#ifndef MODEL_H
#define MODEL_H

#include <map>
#include <vector>

#include "Block.h"
#include "Connector.h"

class Model
{
public:
    Model();

    bool blockIsSupported(const std::string& type);
    bool initialize(const std::vector<Block*>& blocks, const std::vector<Connector*>& connectors);

protected:

    void addBlockProperty(const std::string& type, const Property& property);
    void addConnectorProperty(const Property& property);
    void addNodeProperty(const Property& property);

private:

    std::map<std::string, std::vector<Property>> blockProperties_;
    std::vector<Property> connectorProperties_;
    std::vector<Property> nodeProperties_;
};

#include "PGModel.h"

#endif // MODEL_H
