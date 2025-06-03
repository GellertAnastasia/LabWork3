#ifndef ITERATOR_H
#define ITERATOR_H
#include "node.h"

namespace clist
{

template<typename T, bool IsConst>
class Iterator
{
public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type        = T;
    using difference_type   = std::ptrdiff_t;
    using pointer           = T*;
    using reference         = T&;

    using node_type = Node<T>;

    Iterator() : ptr_(nullptr) {}
    explicit Iterator(node_type* ptr) : ptr_(ptr) {}
    
    template <bool B, typename = std::enable_if_t<IsConst && !B>>
    Iterator(const Iterator<std::remove_const_t<T>, B>& other) : ptr_(other.node()) {}
    
    Iterator(const Iterator& other) = default;
    Iterator& operator=(const Iterator& other) = default;

    reference operator*() const
    {
        return ptr_->data;
    }
    pointer operator->() const
    {
        return &(ptr_->data);
    }

    Iterator& operator++()
    {
        if (ptr_) ptr_ = ptr_->next;
        return *this;
    }

    Iterator operator++(int)
    {
        Iterator temp = *this;
        ++(*this);
        return temp;
    }

    Iterator& operator--()
    {
        ptr_ = ptr_->prev;
        return *this;
    }

    Iterator operator--(int)
    {
        Iterator temp = *this;
        --(*this);
        return temp;
    }

    bool operator==(const Iterator& other) const
    {
        return ptr_ == other.ptr_;
    }

    bool operator!=(const Iterator& other) const
    {
        return ptr_ != other.ptr_;
    }

    node_type* node() const
    {
        return ptr_;
    }

private:
    node_type* ptr_;
    template<typename, bool> friend class Iterator_impl;
};

template<typename T>
using iterator = Iterator<T, false>;

template<typename T>
using const_iterator = Iterator<T, true>;

}

#endif
