#include "IncompressibleFlowModel.h"
#include "Node.h"
#include "Connector.h"
#include "Block.h"
#include "Matrix.h"

IncompressibleFlowModel::NodeState::NodeState()
    :
      p_(*vars_.insert(std::make_pair("p", std::make_shared<double>(0.))).first->second)
{
    //- aliases
    vars_["P"] = vars_["p"];
    vars_["Pressure"] = vars_["p"];
}

std::map<std::string, double> IncompressibleFlowModel::NodeState::solution() const
{
    return {{"Pressure", p_}};
}

IncompressibleFlowModel::ConnectorState::ConnectorState()
    :
      r_(*vars_.insert(std::make_pair("R", std::make_shared<double>(0.))).first->second),
      Q_(*vars_.insert(std::make_pair("Q", std::make_shared<double>(0.))).first->second)
{
    //- aliases
    vars_["Resistance"] = vars_["R"];
    vars_["Flow rate"] = vars_["Q"];
}

std::map<std::string, double> IncompressibleFlowModel::ConnectorState::solution() const
{
    return {{"Flow rate", Q_}};
}

std::map<std::string, double> IncompressibleFlowModel::ConnectorState::properties() const
{
    return {{"Resistance", r_}};
}

void IncompressibleFlowModel::ConnectorState::setProperties(const std::map<std::string, double> &properties)
{
    r_ = properties.find("Resistance")->second;
}

double IncompressibleFlowModel::ConnectorState::resistance() const
{
    return r_;
}

void IncompressibleFlowModel::initialize(std::shared_ptr<Block>& block) const
{
    for(std::shared_ptr<Node>& node: block->nodes())
        node->setState(std::shared_ptr<NodeState>(new NodeState()));
}

void IncompressibleFlowModel::initialize(std::shared_ptr<Connector> &connector) const
{
    connector->setState(std::shared_ptr<ConnectorState>(new ConnectorState()));
}

void IncompressibleFlowModel::solve(std::vector<std::shared_ptr<Block> > &blocks, std::vector<std::shared_ptr<Connector> > &connectors)
{
    constructMaps(blocks);

    Matrix mat(nNodes(), nNodes());
    Matrix x(nNodes(), 1), x0(nNodes(), 1);
    Matrix b(nNodes(), 1);

    for(std::shared_ptr<Connector>& connector: connectors)
        connector->state()("Q") = 0.;

    for(int iter = 0, end = getOpt<int>("maxIters", 100); iter < end; ++iter)
    {
        mat.fill(0.);
        b.fill(0.);

        //- Construct equations for block outputs/sinks
        for(std::shared_ptr<Block>& block: blocks)
        {
            block->setNodeEquations();

            for(const std::shared_ptr<Node>& node: block->nodes())
            {
                int row = nodeToIndexMap_[node.get()];

                for(const auto& entry: node->equation().coeffs())
                {
                    int col = nodeToIndexMap_[entry.first.get()];
                    mat(row, col) += entry.second;
                }

                b(row, 0) = node->equation().source();
            }
        }

        //- Solve
        x0 = x;
        x = arma::solve(mat, b);

        mapSolutionToNodes(x, blocks);
        updateConnectors(connectors);
    }
}

void IncompressibleFlowModel::mapSolutionToNodes(const Matrix &x, std::vector<std::shared_ptr<Block> > &blocks)
{
    for(std::shared_ptr<Block>& block: blocks)
        for(std::shared_ptr<Node>& node: block->nodes())
        {
            int id = nodeToIndexMap_.find(node.get())->second;
            node->state()("p") = x(id, 0);
        }
}

void IncompressibleFlowModel::updateConnectors(std::vector<std::shared_ptr<Connector> > &connectors)
{
    for(std::shared_ptr<Connector>& connector: connectors)
    {
        double p1 =  connector->sourceNode()->state()("p");
        double p2 = connector->destNode()->state()("p");
        double r = connector->resistance();

        connector->state()("Q") = (p1 - p2)/r;
    }
}
