#include "FlowModel.h"
#include "Block.h"

double &FlowModel::NodeState::operator()(std::string varName)
{
    return *vars_.find(varName)->second;
}

double &FlowModel::ConnectorState::operator()(std::string varName)
{
    return *vars_.find(varName)->second;
}

//- Initialization
void FlowModel::initialize(std::vector<std::shared_ptr<Block> > &&blocks) const
{
    for(std::shared_ptr<Block>& block: blocks)
        initialize(block);
}

void FlowModel::initialize(std::vector<std::shared_ptr<Connector> > &&connectors) const
{
    for(std::shared_ptr<Connector>& connector: connectors)
        initialize(connector);
}

//- Options
template<>
int FlowModel::getOpt<int>(const std::string &opt, int def) const
{
    auto it = options_.find(opt);

    if(it != options_.end())
        return std::stoi(it->second);
    else
        return def;
}

template<>
double FlowModel::getOpt<double>(const std::string &opt, double def) const
{
    auto it = options_.find(opt);

    if(it != options_.end())
        return std::stod(it->second);
    else
        return def;
}

template<>
std::string FlowModel::getOpt<std::string>(const std::string &opt, std::string def) const
{
    auto it = options_.find(opt);

    if(it != options_.end())
        return it->second;
    else
        return def;
}

void FlowModel::constructMaps(std::vector<std::shared_ptr<Block> > &blocks)
{
    int id = 0;

    nodeToIndexMap_.clear();
    indexToNodeMap_.clear();

    for(std::shared_ptr<Block>& block: blocks)
        for(auto& node: block->nodes())
        {
            nodeToIndexMap_[node.get()] = id++;
            indexToNodeMap_.push_back(node.get());
        }
}
