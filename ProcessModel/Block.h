#ifndef BLOCK_H
#define BLOCK_H

#include <string>

#include <node.h>

class Block
{
public:
    Block(const std::string& type, const std::string& name = "New block");
    Block(int nInputs,
          int nOutputs,
          int nSinks,
          const std::string& type, const std::string& name = "New Block");
    ~Block();

    const std::string type;
    std::string name;

private:
    std::vector<Node*> inputs_;
    std::vector<Node*> outputs_;
    std::vector<Node*> sinks_;
    std::vector<Node*> nodes_;
};

#endif // BLOCK_H
