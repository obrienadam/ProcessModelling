#ifndef COMPONENT_H
#define COMPONENT_H

#include <vector>
#include <unordered_map>

#include "node.h"

class Component
{
public:
    Component(int nInputs, int nOutputs);
    ~Component();

    void addNodeProperty();
    void removeNodeProperty(int i);

protected:

    std::vector<Node*> inputs_;
    std::vector<Node*> outputs_;
    std::vector<Node*> allNodes_;
    std::unordered_map<std::string, double> properties;
};

#endif // COMPONENT_H
