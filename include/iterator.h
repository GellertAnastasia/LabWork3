/* Anastasia Gellert st130144@student.spbu.ru
	labwork 3
*/

#ifndef ITERATOR_H
#define ITERATOR_H

#include <iterator>
#include <concepts>
#include <type_traits>
#include "node.h"

namespace clist
{

template<typename T, bool IsConst>
class Iterator
{
public:
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using reference = std::conditional_t<IsConst, const T&, T&>;
    using pointer = std::conditional_t<IsConst, const T*, T*>;
    using iterator_category = std::bidirectional_iterator_tag;

    using node_type = Node<std::remove_const_t<T>>;

    Iterator() : ptr_(nullptr), head_(nullptr), is_end_(true) {}

    Iterator(node_type* ptr, node_type* head, bool is_end = false)
        : ptr_(ptr), head_(head), is_end_(is_end) {}

    template<bool B, typename = std::enable_if_t<IsConst && !B>>
    Iterator(const Iterator<T, B>& other)
        : ptr_(other.ptr_), head_(other.head_), is_end_(other.is_end_) {}

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
        if (!ptr_ || is_end_) return *this;

        ptr_ = ptr_->next;
        if (ptr_ == head_) is_end_ = true;

        return *this;
    }

    Iterator operator++(int)
    {
        Iterator tmp = *this;
        ++(*this);
        return tmp;
    }

    Iterator& operator--()
    {
        if (is_end_)
        {
            ptr_ = head_->prev;
            is_end_ = false;
        }
        else
        {
            ptr_ = ptr_->prev;
        }
        return *this;
    }

    Iterator operator--(int)
    {
        Iterator tmp = *this;
        --(*this);
        return tmp;
    }

    bool operator==(const Iterator& other) const
    {
        return ptr_ == other.ptr_ && is_end_ == other.is_end_;
    }

    bool operator!=(const Iterator& other) const
    {
        return !(*this == other);
    }

private:
    node_type* ptr_;
    node_type* head_;
    bool is_end_;

    template<typename, bool> friend class Iterator;
};

template<typename T>
using iterator = Iterator<T, false>;

template<typename T>
using const_iterator = Iterator<T, true>;

}

static_assert(std::bidirectional_iterator<clist::iterator<int>>);
static_assert(std::bidirectional_iterator<clist::const_iterator<int>>);

#endif
