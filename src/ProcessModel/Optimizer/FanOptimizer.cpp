#include "FanOptimizer.h"

//double FanOptimizer::solve(std::vector<Block *> &blocks, std::vector<Connector *> &connectors, bool useCachedMaps, int maxIters)
//{
//    std::vector<Block*> resistValves;
//    Block* fan = nullptr;

//    for(Block* block: blocks)
//    {
//        if(block->type() == "Fan")
//            fan = block;
//        else if(block->type() == "Restrictor Valve")
//            resistValves.push_back(block);
//    }

//    if(!fan)
//        return false;

//    if(!resistValves.size() > 0)
//        return false;

//    if(!useCachedMaps)
//        constructMaps(blocks, connectors);

//    double dp = 0.;

//    for(int i = 0; i < 10000; ++i)
//    {
//        fan->setProperties({{"Pressure increase", dp}});
//        //- Solve flow

//        double error = Solver::solve(blocks, connectors, true, 20*maxIters);

//        //- Adjust power
//        bool converged = true;
//        for(Block* block: resistValves)
//        {
//            double Qobj = block->properties().find("Max flow rate")->second;
//            double Q = block->solution().find("Flow rate")->second;

//            if(fabs(Q - Qobj) > 1e-4)
//            {
//                if(Q - Qobj < 0.)
//                {
//                dp += 0.001;
//                converged = false;
//                break;
//                }
//            }
//            else
//            {

//            }
//        }

//        if(converged)
//            break;
//    }

//    updateBlockSolutions(blocks);
//}

bool FanOptimizer::converged() const
{

}

void FanOptimizer::setup(const VariableBlocks &variables, const ObjectiveBlocks &objectives)
{
    fan_ = std::dynamic_pointer_cast<Fan>(variables.find("Target Fan")->second);

    for(auto& valve: objectives)
        valves_.push_back(std::dynamic_pointer_cast<RestrictorValve>(valve));
}

void FanOptimizer::setObjectiveValues(const std::vector<double> &values)
{
    if(valves_.size() == values.size())
        for(int i = 0, end = values.size(); i < end; ++i)
            valves_[i]->setQmax(values[i]);
}

void FanOptimizer::setFanPower()
{
    std::shared_ptr<RestrictorValve> minQ = nullptr;

    for(std::shared_ptr<RestrictorValve>& valve: valves_)
    {
        double Q = valve->Q();
        double Qmax = valve->Qmax();

        if(Q < Qmax && (Q - Qmax) < (minQ->Q() - minQ->Qmax()))
        {
            minQ = valve;
        }
    }

    if(!minQ)
        return;

    double inc = (minQ->Qmax() - minQ->Q())/minQ->Q();
    fan_->setPressureIncrease(inc*fan_->pressureIncrease());
}
