#ifndef PROCESSMODEL_H
#define PROCESSMODEL_H

#include <vector>
#include <string>

#include "component.h"

class ProcessModel
{
public:
    ProcessModel();

    bool addNodeProperty(const std::string& property);
    const std::vector<std::string>& properties() const { return nodeProperties_; }

    void addComponent(Component *component);
    Component& component(int i);

private:

    std::vector<std::string> nodeProperties_;
    std::vector<Component*> components_;
};

#endif // PROCESSMODEL_H
