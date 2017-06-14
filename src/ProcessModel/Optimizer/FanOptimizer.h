#ifndef FAN_OPTIMIZER_H
#define FAN_OPTIMIZER_H

#include "Optimizer.h"
#include "Fan.h"
#include "RestrictorValve.h"

class FanOptimizer: public Optimizer
{
public:

    bool converged() const;

    void setup(const VariableBlocks& variables, const ObjectiveBlocks& objectives);

    void setObjectiveValues(const std::vector<double>& values);

protected:

    void setFanPower();

    std::shared_ptr<Fan> fan_;
    std::vector<std::shared_ptr<RestrictorValve>> valves_;
};

#endif
