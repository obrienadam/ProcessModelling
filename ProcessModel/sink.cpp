#include "sink.h"

Sink::Sink()
{
    node_ = new Node(Node::SINK);
}

Sink::~Sink()
{
    delete node_;
}
