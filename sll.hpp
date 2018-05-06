#pragma once

#include "node.hpp"

// Singly Linked List
namespace sll
{
    template<class T>
    bool Empty(Node<T>* head)
    {
        return head->next == nullptr;
    };

    template<class T>
    Node<T>* Find(Node<T>* node, T val)
    {
        node = node->next;
        while(node != nullptr) 
        {
            if(node->val == val) {
                return node;
            }
            node = node->next;
        }
        return nullptr;
    };


    template<class T>
    bool Erase(Node<T>* head, Node<T>* node)
    {
        if(Empty(head)) return false;
        
        while(head->next !=  nullptr) 
        {
            if(head->next == node) {
                head->next = node->next;
                delete node;
                return true;
            }
            head = head->next;
        }
        return false;
    };


    template<class T>
    void Push_back(Node<T>* head, T val)
    {
        while(head->next != nullptr) {
            head = head->next;
        }
        auto node = new Node<T>(val);
        head->next = node;
    };

    template<class T>
    void Pop_back(Node<T>* head)
    {
        if(IsEmpty(head)) return;

        while(head->next->next != nullptr) {
            head = head->next;
        }
        delete (head->next);
        head->next = nullptr;
    };

    template<class T>
    void Push_front(Node<T>* head, T val)
    {
        auto node = new Node<T>(val);
        node->next = head->next;
        head->next = node;
    };


    template<class T>
    bool Pop_front(Node<T>* head)
    {
        if(Empty(head)) return false;

        auto node = head->next;
        head->next = node->next;
        delete (node);
        return true;
    };

    template<class T>
    T* Front(Node<T>* head)
    {
        return head->next;
    };

    template<class T>
    T* Back(Node<T>* head)
    {
        while(head->next) {
            head = head->next;
        }
        return head;
    };

    template<class T>
    void DeleteList(Node<T>* head)
    {
        while(RemoveBeg(head));
    };

    template<class T>
    int Size(Node<T>* head)
    {
        int i = 0;
        while(head->next != nullptr) {
            head = head->next;
            i += 1;
        }
        return i;
    };

    template<class T>
    int Print(Node<T>* glava)
    {
        glava = glava->next;
        while(glava != nullptr) {
            std::cout << std::setfill('-') << std::setw(21) << "-" << "\n";
            std::cout << "|" << std::setfill(' ')  << "ME: " << std::setw(15) << std::left << glava << "|" << "\n";
            std::cout << "|"  << std::setfill('-') << std::setw(19) << "-" << "|" << "\n";
            std::cout << "|" << std::setfill(' ') << std::setw(19) << std::left << "VAL: " + std::to_string(glava->val) << "|" << "\n";
            std::cout << "|"  << std::setfill('-') << std::setw(19) << "-" << "|" << "\n";
            std::cout << "|" << std::setfill(' ')  << "ADR: " << std::setw(14) << std::left << glava->next << "|" << "\n";
            std::cout << std::setfill('-') << std::setw(21) << "-" << "\n";
            std::cout << "          ||" << "\n";
            std::cout << "          ||" << "\n";
            std::cout << "          \\/" << "\n";
            glava = glava->next;
        }
    };
}