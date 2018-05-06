#pragma once

template <class T>
struct Node 
{
    Node() = default;
    ~Node() = default;
    Node(T val) : val(val) {}

    Node* next = nullptr;
    T val;
};