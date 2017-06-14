#include <math.h>
\
#include "PGFlowModel.h"
#include "Connector.h"

PGFlowModel::ConnectorState::ConnectorState()
    :
      IncompressibleFlowModel::ConnectorState::ConnectorState(),
      Ke_(*vars_.insert(std::make_pair("Ke", std::make_shared<double>(0.))).first->second),
      D_(*vars_.insert(std::make_pair("D", std::make_shared<double>(10.))).first->second),
      L_(*vars_.insert(std::make_pair("L", std::make_shared<double>(50.))).first->second),
      dpSpec_(*vars_.insert(std::make_pair("dPSpec", std::make_shared<double>(0.))).first->second),
      QSpec_(*vars_.insert(std::make_pair("QSpec", std::make_shared<double>(0.))).first->second)
{
    //- Aliases
    vars_["Diameter"] = vars_["D"];
    vars_["Length"] = vars_["L"];
    vars_["Residual pressure drop"] = vars_["dPSpec"];
    vars_["Residual reference flow rate"] = vars_["QSpec"];
}

void PGFlowModel::initialize(std::shared_ptr<Connector>& connector) const
{
    connector->setState(std::shared_ptr<ConnectorState>(new ConnectorState()));
}

std::map<std::string, double> PGFlowModel::ConnectorState::solution() const
{
    double area = M_PI*D_*D_/4./144.;
    double velocity = Q_/area;

    return {
        {"Flow rate", Q_},
        {"Velocity pressure", pow(velocity/4005, 2)},
        {"Resistance", r_}
    };
}

std::map<std::string, double> PGFlowModel::ConnectorState::properties() const
{
    return {
        {"Ke", Ke_},
        {"Diameter", D_},
        {"Length", L_},
        {"Residual pressure drop", dpSpec_},
        {"Residual reference flow rate", QSpec_}
    };
}

void PGFlowModel::ConnectorState::setProperties(const std::map<std::string, double> &properties)
{
    Ke_ = properties.find("Ke")->second;
    D_ = properties.find("Diameter")->second;
    L_ = properties.find("Length")->second;
    dpSpec_ = properties.find("Residual pressure drop")->second;
    QSpec_ = properties.find("Residual reference flow rate")->second;
}

double PGFlowModel::ConnectorState::resistance() const
{
    double area = M_PI*D_*D_/4./144.;
    double velocity = Q_/area;

    //double velocityPressure = pow(velocity/4005, 2);

    double dPl = 2.238/D_*velocity/(1000*1000)*(0.1833 + 1./pow(D_, 1./3))/area;
    double rEnt = Ke_*velocity/(4005*4005*area);

    double dpr = dpSpec_*pow(Q_/QSpec_, 2);
    double rSpec = Q_ > 0 && !std::isnan(dpr) ? dpr/Q_: 0;

    r_ = L_/100*dPl + rEnt + rSpec;
    r_ = r_ != 0 ? r_ : 1;

    return r_;
}
