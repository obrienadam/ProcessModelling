#ifndef SOLVER_H
#define SOLVER_H

#include <vector>
#include <map>

#include "processmodel_global.h"
#include "Block.h"
#include "Connector.h"
#include "Matrix.h"

class PROCESSMODELSHARED_EXPORT Solver
{
public:
    Solver();

    bool solve(
            std::vector<Block*>& blocks,
            std::vector<Connector*>& connectors,
            bool useCachedMaps = false,
            int maxIters = 1
            );

    const std::vector<Node*>& nodes() const { return indexToNodeMap_; }
    int nodeId(const Node* node) const { return nodeToIndexMap_.find(node)->second; }

    Matrix matrix, b;

private:

    void constructMaps(std::vector<Block*>& blocks, std::vector<Connector *> &connectors);
    void constructMatrix();

    void mapSolutionToModel(const Matrix& x);
    void updateFlowRates(std::vector<Connector*>& connectors);

    std::map<const Node*, int> nodeToIndexMap_;
    std::vector<Node*> indexToNodeMap_;

    //- Property names
    std::vector<std::string> nodePropertyNames_;
    std::vector<std::string> connectorPropertyNames_;
};

#endif // SOLVER_H
