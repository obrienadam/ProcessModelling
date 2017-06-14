#ifndef PG_FLOW_MODEL_H
#define PG_FLOW_MODEL_H

#include "IncompressibleFlowModel.h"

class PROCESSMODELSHARED_EXPORT PGFlowModel : public IncompressibleFlowModel
{
    class ConnectorState: public IncompressibleFlowModel::ConnectorState
    {
    public:

        ConnectorState();

        ConnectorState(const ConnectorState& other);

        virtual std::map<std::string, double> solution() const;

        virtual std::map<std::string, double> properties() const;

        virtual void setProperties(const std::map<std::string, double>& properties);

        double resistance() const;

    protected:

        void initVariableMap();

        double &Ke_, &D_, &L_, &dpSpec_, &QSpec_;
    };

    virtual std::string type() const
    { return "PGFlowModel"; }

    void initialize(std::shared_ptr<Connector>& connector) const;
};

#endif // PGMODEL_H
