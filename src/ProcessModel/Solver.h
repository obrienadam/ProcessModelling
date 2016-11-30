#ifndef SOLVER_H
#define SOLVER_H

#include <map>

#include "processmodel_global.h"
#include "ProcessModel.h"

class PROCESSMODELSHARED_EXPORT Solver
{
public:
    Solver();
    bool solve(ProcessModel& pm);

    void  constructMaps(ProcessModel &pm);

private:
    std::map<Node*, int> nodeToIndexMap_;
    std::vector<Node*> indexToNodeMap_;
};

#endif // SOLVER_H
