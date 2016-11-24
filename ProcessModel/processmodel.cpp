#include <algorithm>

#include "processmodel.h"

ProcessModel::ProcessModel()
{

}

bool ProcessModel::addNodeProperty(const std::string &property)
{
    if(std::find(nodeProperties_.begin(), nodeProperties_.end(), property) != nodeProperties_.end())
        return false;

    nodeProperties_.push_back(property);

    for(Component *component: components_)
        component->addNodeProperty();

    return true;
}

void ProcessModel::addComponent(Component *component)
{
    components_.push_back(component);
}

Component &ProcessModel::component(int i)
{
    return *components_[i];
}
