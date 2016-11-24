#ifndef NODE_H
#define NODE_H

#include <vector>

class Node
{
public:
    enum Type{INPUT, OUTPUT, SINK};

    Node(Type type);
    Node(Type type, int nProperties);

    bool isInput() const { return type_ == INPUT; }
    bool isOutput() const { return type_ == OUTPUT; }
    bool isSink() const { return type_ == SINK; }

    void addProperty();
    void removeProperty(int i);

private:

    std::vector<double> properties_;
    const Type type_;
};
#endif // NODE_H
