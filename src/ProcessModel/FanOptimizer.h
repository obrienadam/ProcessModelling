#ifndef FAN_OPTIMIZER_H
#define FAN_OPTIMIZER_H

#include "Solver.h"

class FanOptimizer: public Solver
{
public:

    double solve(
            std::vector<Block*>& blocks,
            std::vector<Connector*>& connectors,
            bool useCachedMaps = false,
            int maxIters = 100
            ) override;
};

#endif
