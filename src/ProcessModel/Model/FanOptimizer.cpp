#include "FanOptimizer.h"

double FanOptimizer::solve(std::vector<Block *> &blocks, std::vector<Connector *> &connectors, bool useCachedMaps, int maxIters)
{
    std::vector<Block*> resistValves;
    Block* fan = nullptr;

    for(Block* block: blocks)
    {
        if(block->type() == "Fan")
            fan = block;
        else if(block->type() == "Restrictor Valve")
            resistValves.push_back(block);
    }

    if(!fan)
        return false;

    if(!resistValves.size() > 0)
        return false;

    if(!useCachedMaps)
        constructMaps(blocks, connectors);

    double dp = 0.;

    for(int i = 0; i < 10000; ++i)
    {
        fan->setProperty("dP", dp);
        //- Solve flow

        double error = Solver::solve(blocks, connectors, true, 20*maxIters);

        //- Adjust power
        bool converged = true;
        for(Block* block: resistValves)
        {
            double Qobj = block->getProperty("Qobj");
            double Q = block->getSolution("Q");

            if(fabs(Q - Qobj) > 1e-4)
            {
                if(Q - Qobj < 0.)
                {
                dp += 0.001;
                converged = false;
                break;
                }
            }
            else
            {

            }
        }

        if(converged)
            break;
    }

    updateBlockSolutions(blocks);
}
