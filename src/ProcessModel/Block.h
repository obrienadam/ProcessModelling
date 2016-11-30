#ifndef BLOCK_H
#define BLOCK_H

#include <string>

#include <Node.h>

class Block
{
public:
    Block(const std::string& type, const std::string& name = "New block");
    Block(int nInputs,
          int nOutputs,
          int nSinks,
          const std::string& type, const std::string& name = "New Block");
    ~Block();

    size_t nInputs() const { return inputs_.size(); }
    size_t nOutputs() const { return outputs_.size(); }
    size_t nSinks() const { return sinks_.size(); }
    size_t nNodes() const { return nodes_.size(); }

    std::vector<Node*>::iterator begin() { return nodes_.begin(); }
    std::vector<Node*>::iterator end() { return nodes_.end(); }

    const std::string type;
    std::string name;

private:
    std::vector<Node*> inputs_;
    std::vector<Node*> outputs_;
    std::vector<Node*> sinks_;
    std::vector<Node*> nodes_;
};

#endif // BLOCK_H
