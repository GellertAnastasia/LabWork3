/* Anastasia Gellert st130144@student.spbu.ru
	labwork 3
*/

#ifndef NODE_H
#define NODE_H

namespace clist
{
template<typename T>
class Node
{
public:
    T data;
    Node* next;
    Node* prev;

    explicit Node(const T& value)
        : data(value), next(this), prev(this) {}

    Node(const T& value, Node* n, Node* p)
        : data(value), next(n), prev(p) {}
};

}

#endif
