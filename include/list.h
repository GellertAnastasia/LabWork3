#ifndef LIST_H
#define LIST_H
#include "iterator.h"
#include <cstddef>
#include <stdexcept>
#include "node.h"

namespace clist
{
template<typename T>
class List
{
public:
    using value_type = T;
    using size_type = std::size_t;
    using iterator = Iterator<T, false>;
    using const_iterator = Iterator<T, true>;

    List() : head_(nullptr), size_(0) {}
    ~List()
    {
        clear();
    }

    List(const List&) = delete;
    List& operator=(const List&) = delete;

    void push_back(const T& value)
    {
        Node<T>* node = new Node<T>(value);
        if (!head_)
        {
            head_ = node;
            head_->next = head_;
            head_->prev = head_;
        }
        else
        {
            Node<T>* tail = head_->prev;
            tail->next = node;
            node->prev = tail;
            node->next = head_;
            head_->prev = node;
        }
        ++size_;
    }

    void push_front(const T& value)
    {
        push_back(value);
        head_ = head_->prev;
    }

    void pop_back()
    {
        if (!head_) throw std::underflow_error("List is empty");

        if (size_ == 1)
        {
            delete head_;
            head_ = nullptr;
        }
        else
        {
            Node<T>* tail = head_->prev;
            Node<T>* before_tail = tail->prev;
            before_tail->next = head_;
            head_->prev = before_tail;
            delete tail;
        }
        --size_;
    }

    void pop_front()
    {
        if (!head_) throw std::underflow_error("List is empty");

        if (size_ == 1)
        {
            delete head_;
            head_ = nullptr;
        }
        else
        {
            Node<T>* old_head = head_;
            Node<T>* new_head = head_->next;
            Node<T>* tail = head_->prev;

            tail->next = new_head;
            new_head->prev = tail;

            delete old_head;
            head_ = new_head;
        }
        --size_;
    }

    iterator begin()
    {
        return iterator(head_, head_, false);
    }

    iterator end()
    {
        return iterator(head_, head_, true);
    }

    const_iterator begin() const
    {
        return const_iterator(head_, head_, false);
    }

    const_iterator end() const
    {
        return const_iterator(head_, head_, true);
    }

    const_iterator cbegin() const
    {
        return const_iterator(head_, head_, false);
    }
    const_iterator cend() const
    {
        return const_iterator(head_, head_, true);
    }

    size_type size() const
    {
        return size_;
    }
    bool empty() const
    {
        return size_ == 0;
    }

    void clear()
    {
        while (!empty())
        {
            pop_back();
        }
    }

private:
    Node<T>* head_;
    size_type size_;
};

}

#endif
