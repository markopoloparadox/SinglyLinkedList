#pragma once

#include "node.hpp"

namespace list
{
    template<class T>
    bool IsEmpty(Node<T>* glava)
    {
        return glava->next == nullptr;
    };

    template<class T>
    Node<T>* FindNodeWithVal(Node<T>* glava, T val)
    {
        glava = glava->next;
        while(glava !=  nullptr) 
        {
            if(glava->val == val){
                return glava;
            }
            glava = glava->next;
        }
        return nullptr;
    };


    template<class T>
    bool RemoveNode(Node<T>* glava, Node<T>* node)
    {
        if(IsEmpty(glava)) return false;
        while(glava->next !=  nullptr) 
        {
            if(glava->next == node){
                glava->next = node->next;
                delete node;
                return true;
            }
            glava = glava->next;
        }
        return false;
    };


    template<class T>
    void InsertEnd(Node<T>* cvor, T val)
    {
        while(cvor->next != nullptr) {
            cvor = cvor->next;
        }
        auto noviCvor = new Node<T>(val);
        cvor->next = noviCvor;
    };

    template<class T>
    void RemoveEnd(Node<T>* glava)
    {
        if(IsEmpty(glava)) return;

        while(glava->next->next != nullptr) {
            glava = glava->next;
        }
        delete (glava->next);
        glava->next = nullptr;
    };

    template<class T>
    void InsertBeg(Node<T>* glava, T val)
    {
        auto noviCvor = new Node<T>(val);
        noviCvor->next = glava->next;
        glava->next = noviCvor;
    };


    template<class T>
    bool RemoveBeg(Node<T>* glava)
    {
        if(IsEmpty(glava)) return false;
        auto cvor = glava->next;
        glava->next = cvor->next;
        delete (cvor);
        return true;
    };

    template<class T>
    void DeleteList(Node<T>* glava)
    {
        while(RemoveBeg(glava));
    };

    template<class T>
    int Size(Node<T>* glava)
    {
        int i = 0;
        while(glava->next != nullptr) {
            glava = glava->next;
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