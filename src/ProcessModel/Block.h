#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <memory>

#include <Node.h>

class Block
{
public:

    Block(int nInputs,
          int nOutputs,
          int nSinks,
          const std::string& type, const std::string& name = "Block");

    ~Block();

    //- Node info
    size_t nInputs() const { return inputs_.size(); }
    size_t nOutputs() const { return outputs_.size(); }
    size_t nSinks() const { return sinks_.size(); }
    size_t nNodes() const { return nodes_.size(); }

    std::vector<std::shared_ptr<Node>>& inputs() { return inputs_; }
    std::vector<std::shared_ptr<Node>>& outputs() { return outputs_; }
    std::vector<std::shared_ptr<Node>>& sinks() { return sinks_; }

    //- Iterator
    std::vector<std::shared_ptr<Node>>::iterator begin() { return nodes_.begin(); }
    std::vector<std::shared_ptr<Node>>::iterator end() { return nodes_.end(); }

    //- General info
    const std::string& getName() const { return name; }
    const std::string& getType() const { return type; }

    const std::string type;
    std::string name;

private:
    std::vector<std::shared_ptr<Node>> inputs_;
    std::vector<std::shared_ptr<Node>> outputs_;
    std::vector<std::shared_ptr<Node>> sinks_;
    std::vector<std::shared_ptr<Node>> nodes_;

    //- Properties
    std::vector<double> properties_;
};

#endif // BLOCK_H
