#include "component.h"

Component::Component(int nInputs, int nOutputs)
    :
      inputs_(nInputs),
      outputs_(nOutputs)
{
    for(Node *&input: inputs_)
    {
        input = new Node(Node::INPUT);
        allNodes_.push_back(input);
    }

    for(Node *&output: outputs_)
    {
        output = new Node(Node::OUTPUT);
        allNodes_.push_back(output);
    }
}

Component::~Component()
{
    for(Node* node: allNodes_)
        delete node;
}

void Component::addNodeProperty()
{
    for(Node *node: allNodes_)
        node->addProperty();
}

void Component::removeNodeProperty(int i)
{
    for(Node *node: allNodes_)
        node->removeProperty(i);
}
