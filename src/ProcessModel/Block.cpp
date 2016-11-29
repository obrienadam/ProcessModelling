#include "Block.h"

Block::Block(const std::string &type, const std::string &name)
    :
      type(type),
      name(name)
{

}

Block::Block(int nInputs, int nOutputs, int nSinks, const std::string &type, const std::string &name)
    :
      Block(type, name)
{
    for(int i = 0; i < nInputs; ++i)
    {
        Node* node = new Node(Node::INPUT);
        inputs_.push_back(node);
        nodes_.push_back(node);
    }

    for(int i = 0; i < nOutputs; ++i)
    {
        Node* node = new Node(Node::OUTPUT);
        outputs_.push_back(node);
        nodes_.push_back(node);
    }

    for(int i = 0; i < nSinks; ++i)
    {
        Node* node = new Node(Node::SINK);
        sinks_.push_back(node);
        nodes_.push_back(node);
    }
}

Block::~Block()
{
    for(Node* node: nodes_)
        delete node;
}
