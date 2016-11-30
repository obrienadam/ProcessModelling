#include "Node.h"

Node::Node(Type type)
    :
      type_(type)
{

}

Node::Node(Type type, int nProperties)
    :
      type_(type),
      properties_(nProperties)
{

}

void Node::addProperty()
{
    properties_.push_back(0.);
}

void Node::removeProperty(int i)
{
    properties_.erase(properties_.begin() + i);
}
