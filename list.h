#ifndef __LIST__H__
#define __LIST__H__

#include <initializer_list>

template <typename T>
class Forward_List
{
public:
    Forward_List(); // ok
    ~Forward_List(); // ok
    Forward_List(const Forward_List<T> &); // ok 
    Forward_List(const std::initializer_list<T> &); // ok
    Forward_List(Forward_List<T>&&); // ok
    Forward_List &operator=(const Forward_List<T> &); // ok
public:
    bool empty() const; // ok
    unsigned size(); // ok
    T& front(); // ok
    const T& front() const; // ok
    void clear(); // ok
    void sort();  // ?
    void push_front(const T&); // ok
    void pop_front(); // ok
private:
    unsigned m_size;
private:
    template <typename U>
    struct Node
    {
        T m_value;
        Node<T> * m_next;
        Node(T val = T(), Node<T> *next = nullptr) : m_value{val}, m_next { next } {}
    };
    Node<T>* head;
public:
    class iterator
    {
    public:
        iterator() = default;
        ~iterator() = default;
        iterator(const iterator &) = default;
        iterator &operator=(const iterator &) = default;
        iterator(iterator &&) = default;
        iterator(Node<T> *ptr) : m_ptr{ptr} {}

    public:
        bool operator==(iterator);   // ok
        bool operator!=(iterator);   // ok
        iterator &operator++();      // ok
        iterator operator++(int);    // ok
        T &operator*();              // ok
        const T &operator*() const;  // ok
        T *operator->();             // ok
        const T *operator->() const; // ok
    private:
        Node<T> *m_ptr;
    };
    iterator begin() const;
    iterator end() const;
};

#include "list.hpp"

#endif // __LIST__H__