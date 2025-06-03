#ifndef LIST_H
#define LIST_H
#include "iterator.h"
#include <cstddef>
#include <stdexcept>
#include "node.h"

namespace clist {

template<typename T>
class List {
public:
    using value_type = T;
    using size_type = std::size_t;
    using iterator = Iterator<T>;
    using const_iterator = Iterator<const T>;

    List();
    ~List();

    void push_back(const T& value);
    void push_front(const T& value);

    Iterator begin();
    Iterator end();

    size_type size() const;
    bool empty() const;
    void clear();

private:
    Node<T>* head_;
    size_type size_;

    void insert_after(Node<T>* pos, const T& value);
    void delete_node(Node<T>* node);
};

}

#endif
