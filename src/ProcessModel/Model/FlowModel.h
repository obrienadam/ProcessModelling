#ifndef FLOW_MODEL_H
#define FLOW_MODEL_H

#include <string>
#include <map>
#include <vector>
#include <memory>
#include <unordered_map>

#include "processmodel_global.h"
#include "Matrix.h"

class Node;
class Connector;
class Block;

class FlowModel
{
public:

    //- NodeState class
    class NodeState
    {
    public:

        virtual std::map<std::string, double> solution() const = 0;

        double& operator()(std::string varName);

    protected:
        std::unordered_map<std::string, std::shared_ptr<double>> vars_;
    };

    //- ConnectorState class
    class ConnectorState
    {
    public:

        virtual std::map<std::string, double> solution() const = 0;

        virtual std::map<std::string, double> properties() const = 0;

        virtual void setProperties(const std::map<std::string, double>& properties) = 0;

        double& operator()(std::string varName);

        virtual double resistance() const = 0;

    protected:
        std::unordered_map<std::string, std::shared_ptr<double>> vars_;
    };

    virtual std::string type() const = 0;

    //- nodes
    size_t nNodes() const
    { return indexToNodeMap_.size(); }

    //- Options
    template<class T>
    T getOpt(const std::string& opt, T def = T()) const;

    //- Initialization

    void initialize(std::vector<std::shared_ptr<Block> > &&blocks) const;

    void initialize(std::vector<std::shared_ptr<Connector> > &&connectors) const;

    virtual void initialize(std::shared_ptr<Block>& block) const = 0;

    virtual void initialize(std::shared_ptr<Connector>& connector) const = 0;

    //- Solve
    virtual void solve(std::vector<std::shared_ptr<Block>>& blocks, std::vector<std::shared_ptr<Connector>>& connectors) = 0;

    //- Misc
    int id(const std::shared_ptr<Node>& node) const
    { return nodeToIndexMap_.find(node.get())->second; }

protected:

    virtual void mapSolutionToNodes(const Matrix& x, std::vector<std::shared_ptr<Block>>& blocks) = 0;

    virtual void updateConnectors(std::vector<std::shared_ptr<Connector>>& connectors) = 0;

    void constructMaps(std::vector<std::shared_ptr<Block>>& blocks);

    //- Index maps
    std::unordered_map<const Node*, int> nodeToIndexMap_;

    std::vector<Node*> indexToNodeMap_;

    //- Options
    std::unordered_map<std::string, std::string> options_;
};

#endif
