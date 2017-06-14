#ifndef INCOMPRESSIBLE_FLOW_MODEL_H
#define INCOMPRESSIBLE_FLOW_MODEL_H

#include "FlowModel.h"

class IncompressibleFlowModel: public FlowModel
{
public:

    //- NodeState
    class NodeState: public FlowModel::NodeState
    {
    public:

        NodeState();

        std::map<std::string, double> solution() const;

    protected:

        double &p_;
    };

    //- ConnectorState
    class ConnectorState: public FlowModel::ConnectorState
    {
    public:

        ConnectorState();

        virtual std::map<std::string, double> solution() const;

        virtual std::map<std::string, double> properties() const;

        virtual void setProperties(const std::map<std::string, double>& properties);

        virtual double resistance() const;

    protected:
        double &r_;
        double &Q_;
    };

    virtual std::string type() const
    { return "IncompressibleFlowModel"; }

    void initialize(std::shared_ptr<Block>& block) const;

    void initialize(std::shared_ptr<Connector>& connector) const;

    void solve(std::vector<std::shared_ptr<Block> > &blocks, std::vector<std::shared_ptr<Connector> > &connectors);

protected:

    virtual void mapSolutionToNodes(const Matrix& x, std::vector<std::shared_ptr<Block>>& blocks);

    virtual void updateConnectors(std::vector<std::shared_ptr<Connector> > &connectors);

};

#endif
