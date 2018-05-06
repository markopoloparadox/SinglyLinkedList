#pragma once
#include "node.hpp"
#include "sll.hpp"

// Singly Linked List Container
template <class T>
class SLLContainer
{
public:
    SLLContainer() = default;
    ~SLLContainer();

    int Size();
    Node* T Front();
    Node* T Back();
    void Push_back(T val);
    void Push_front(T val);
    void Pop_back();
    void Pop_front();

private:
    Node<T> head;
};

template <class T>
void SLLContainer<T>::Push_back(T val)
{
    list::InsertEnd(&head, val);
}

template <class T>
void SLLContainer<T>::Push_front(T val)
{
    list::InsertBeg(&head, val);
}

template <class T>
void SLLContainer<T>::Pop_back()
{
    list::RemoveEnd(&head);
}

template <class T>
int SLLContainer<T>::Size()
{
    return list::Size(&head);
}

template <class T>
void SLLContainer<T>::Pop_front()
{
    list::RemoveBeg(&head);
}

template <class T>
SLLContainer<T>::~SLLContainer()
{
    list::DeleteList(&head);
}

template <class T>
Node<T>* SLLContainer<T>::Front()
{
    return list::Front(&head);
}

template <class T>
Node<T>* SLLContainer<T>::Back()
{
    return list::Back(&head);
}