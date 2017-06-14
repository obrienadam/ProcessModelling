#ifndef OPTIMIZER_H
#define OPTIMIZER_H

#include "Block.h"

class Optimizer
{
public:

    typedef std::map<std::string, std::shared_ptr<Block>> VariableBlocks;
    typedef std::vector<std::shared_ptr<Block>> ObjectiveBlocks;

    virtual bool converged() const = 0;

    virtual void setup(const VariableBlocks& variables, const ObjectiveBlocks& objectives) = 0;

    virtual void setObjectiveValues(const std::vector<double>& values) = 0;

private:

};

#endif
