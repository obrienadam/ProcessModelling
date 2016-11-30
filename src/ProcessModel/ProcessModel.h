#ifndef PROCESSMODEL_H
#define PROCESSMODEL_H

#include <vector>
#include <string>

#include "processmodel_global.h"
#include "Block.h"

class PROCESSMODELSHARED_EXPORT ProcessModel
{
public:
    ProcessModel();
    ~ProcessModel();

    bool addNodeProperty(const std::string& property);
    const std::vector<std::string>& properties() const { return nodeProperties_; }

    void addBlock(Block* block);
    void deleteBlock(Block* block);

    std::vector<Block*> blocks() { return blocks_; }

private:

    std::vector<std::string> nodeProperties_;
    std::vector<Block*> blocks_;
};

#endif // PROCESSMODEL_H
