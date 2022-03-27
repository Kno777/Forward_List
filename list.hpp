#include <iostream>
#include "list.h"

template <typename T>
Forward_List<T>::Forward_List()
{
    head = nullptr;
    m_size = 0;
}

template <typename T>
Forward_List<T>::~Forward_List()
{
    clear();
}

template <typename T>
Forward_List<T>::Forward_List(const Forward_List<T> &oth)
{
    clear();

    Node<T> * tmp = oth.head->m_next;
    head = new Node<T>(oth.head->m_value);
    Node<T> * tmp2 = head->m_next;
    while (tmp != nullptr)
    {
        tmp2 = new Node<T>(tmp->m_value);
        tmp = tmp->m_next;
        tmp2 = tmp2->m_next;
    }
}

template <typename T>
Forward_List<T>::Forward_List(const std::initializer_list<T>& oth)
{
    head = new Node<T>(*oth.begin());
    Node<T> *tmp = head;
    const T* it = oth.begin() + 1;
    for (; it != oth.end(); ++it)
    {
        tmp->m_next = new Node<T>(*it);
        tmp = tmp->m_next;
    }
}

template <typename T>
Forward_List<T>::Forward_List(Forward_List<T> && oth)
{
    if(!oth.empty())
    {
        head = oth.head;
        oth.head = nullptr;
    }
}

template <typename T>
Forward_List<T>& Forward_List<T>::operator=(const Forward_List<T>& oth)
{
    if(this == &oth)
    {
        return *this;
    }
    clear();

    Node<T>* tmp = oth.head->m_next;
    head = new Node<T>(oth.head->m_value);
    Node<T> * tmp2 = head->m_next;
    while (tmp != nullptr)
    {
        tmp2 = new Node<T>(tmp->m_value);
        tmp = tmp->m_next;
        tmp2 = tmp2->m_next;
    }
    return *this;
}

// template <typename T>
// Forward_List<T>::Node<T>::Node(T value, Node<T> *next) : m_value{0}, m_next{nullptr}
// {
//     m_value = value;
//     m_next = next;
// }

template <typename T>
void Forward_List<T>::push_front(const T& value)
{
    if(this->empty())
    {
        head = new Node<T>(value);
    }
    else
    {
        head = new Node<T>(value,head);
    }
}

template <typename T>
bool Forward_List<T>::empty() const
{
    return this->begin() == this->end();
}

template <typename T>
unsigned Forward_List<T>::size()
{
    return m_size;
}

template <typename T>
T &Forward_List<T>::front()
{
    return this->head->m_value;
}

template <typename T>
const T &Forward_List<T>::front() const
{
    return this->head->m_value;
}

template <typename T>
void Forward_List<T>::clear()
{
    while (head != nullptr)
    {
        Node<T>* tmp = head->m_next;
        delete head;
        head = tmp;
    }
}

template <typename T>
void Forward_List<T>::pop_front()
{
    if(head->m_next != nullptr)
    {
        Node<T> * tmp = head->m_next;
        delete head;
        head = tmp;
    }
}

template <typename T>
bool Forward_List<T>::iterator::operator==(Forward_List<T>::iterator oth)
{
    return this->m_ptr == oth.m_ptr;
}

template <typename T>
bool Forward_List<T>::iterator::operator!=(Forward_List<T>::iterator oth)
{
    return this->m_ptr != oth.m_ptr;
}

template <typename T>
T& Forward_List<T>::iterator::operator*()
{
    return m_ptr->m_value;
}

template <typename T>
const T& Forward_List<T>::iterator::operator*() const
{
    return m_ptr->m_value;
}

template <typename T>
T* Forward_List<T>::iterator::operator->()
{
    return this->m_ptr;
}

template <typename T>
const T* Forward_List<T>::iterator::operator->() const
{
    return this->m_ptr;
}

template <typename T>
typename Forward_List<T>::iterator& Forward_List<T>::iterator::operator++()
{
    m_ptr = m_ptr->m_next;
    return *this;
}

template <typename T>
typename Forward_List<T>::iterator Forward_List<T>::iterator::operator++(int)
{
    Forward_List<T>::iterator tmp(*this);
    ++*this;
    return tmp;
}

template <typename T>
typename Forward_List<T>::iterator Forward_List<T>::begin() const
{
    Forward_List<T>::iterator it(head);
    return it;
}

template <typename T>
typename Forward_List<T>::iterator Forward_List<T>::end() const
{
    Node<T>* tmp = head;
    while (tmp)
    {
        tmp = tmp->m_next;
    }
    Forward_List<T>::iterator it(tmp);
    return it;
}