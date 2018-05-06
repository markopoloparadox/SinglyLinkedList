#pragma once
#include <iomanip>
#include <iostream>
#include <vector>

#include "node.hpp"
#include "hack.hpp"
#include "text.hpp"
#include "display.hpp"

// Singly Linked List 2
namespace sll2
{
    template<class T>
    bool Empty(Node<T>* head)
    {
        hack::ClearDisplayArea();
        hack::ClearTextArea();

        int r = 0;
        int c = 0;
        display::ShowNodeAndN(head, head, r, c);
        text::Empty(0);
        hack::getch();

        //ShowArrow(r, c + NodeWidht + NodeToNodeDistance);
        text::Empty(1);
        hack::getch();

        if(head->next == nullptr)
        {
            display::ShowPipe(r+5, c + display::NodeWidht, hack::Color::Green);
            text::Empty(2);
            hack::getch();
        }
        else {
            display::ShowPipe(r+5, c + display::NodeWidht, hack::Color::Red);
            text::Empty(3);
            hack::getch();
        }
        return head->next == nullptr;
    };

    template<class T>
    void Push_front(Node<T>* head, T val)
    {
        hack::ClearDisplayArea();
        hack::ClearTextArea();

        int r = 0;
        int c = 0;

        display::ShowNodeAndN(head, head, r, 0);
        text::Push_front(0);
        hack::getch();
        hack::ClearDisplayArea();

        display::ShowNode(head, r, c, hack::Color::Cyan);
        if(head->next) {
            display::ShowNodeAndN(head, head->next, r, c + (display::FullNodeWidth * 2), -1, 0);
            display::DrawPipe(r, c, c + (display::FullNodeWidth * 2));
        }
        text::Push_front(1);
        hack::getch();

        auto node = new Node<T>(val);
        display::ShowNode(node, r, display::GetNextNodePos(c), hack::Color::Green);
        text::Push_front(2);
        hack::getch();

        node->next = head->next;
        display::ShowNode(node, r, display::GetNextNodePos(c));
        if(head->next) {
            display::ShowPipe(r+5, c + (display::NodeToNodeDistance * 1) + (display::NodeWidht * 2), hack::Color::Green);
            display::DrawPipe(r, c, c + (display::FullNodeWidth * 2), hack::Color::Green);
        }
        text::Push_front(3);
        hack::getch();

        head->next = node;
        hack::ClearDisplayArea();
        display::ShowNodeAndN(head, head, r, 0);
        display::ShowPipe(r+5, c + display::NodeWidht, hack::Color::Green);
        text::Push_front(4);
        hack::getch();
    };

    template<class T>
    bool Pop_front(Node<T>* head)
    {
        hack::ClearDisplayArea();
        hack::ClearTextArea();

        int r = 0;
        int c = 0;

        display::ShowNodeAndN(head, head, r, 0);
        text::Pop_front(0);
        hack::getch();


        text::Pop_front(1);
        hack::getch();
        hack::ClearDisplayArea();

        auto status = sll2::Empty(head);

        if(status == true) {
            display::ShowPipe(r+5, c + display::NodeWidht, hack::Color::Red);
            text::Pop_front(2);
            hack::getch();
            return false;
        }

        display::ShowPipe(r+5, c + display::NodeWidht, hack::Color::Green);
        text::Pop_front(3);
        hack::getch();
        hack::ClearDisplayArea();

        auto node = head->next;
        text::Pop_front(4);
        display::ShowNodeAndN(head, head, r, 0);
        display::ShowNode(head->next, r, c + display::FullNodeWidth, hack::Color::Green);
        hack::getch();
        hack::ClearDisplayArea();


        head->next = node->next;
        display::ShowNode(head, r, c, hack::Color::Cyan);
        display::ShowNode(node, r, c + display::FullNodeWidth);
        if(head->next != nullptr) {
            display::ShowNodeAndN(head, head->next, r , c + display::FullNodeWidth + display::FullNodeWidth, -1, 0);
            display::ShowPipe(r+5, c + display::NodeWidht + display::FullNodeWidth, hack::Color::Green);
            display::DrawPipe(r, c, c + (display::FullNodeWidth * 2), hack::Color::Green);
        }
        else {
            display::ShowPipe(r+5, c + display::NodeWidht, hack::Color::Red);
        }
        text::Pop_front(5);
        hack::getch();
        hack::ClearDisplayArea();

        display::ShowNode(head, r, c, hack::Color::Cyan);
        display::ShowNode(node, r, c + display::FullNodeWidth, hack::Color::Red);
        if(head->next != nullptr) {
            display::ShowNodeAndN(head, head->next, r , c + display::FullNodeWidth + display::FullNodeWidth, -1, 0);
            display::DrawPipe(r, c, c + (display::FullNodeWidth * 2));
        }

        delete (node);
        text::Pop_front(6);
        hack::getch();
        hack::ClearDisplayArea();

        display::ShowNodeAndN(head, head, r, 0);
        text::Pop_front(7);  
        hack::getch(); 
        return true;
    };

    template<class T>
    void Push_back(Node<T>* head, T val)
    {
        hack::ClearDisplayArea();
        hack::ClearTextArea();

        int r = 0;
        int c = 0;
        display::ShowNodeAndN(head, head, r, c);
        text::Push_back(0);
        hack::getch();
        hack::ClearDisplayArea();


        bool isNotDone = head->next;
        auto currentNode = head;
        display::ShowNodeAndN(head, currentNode, r, c);
        //ShowArrow(r, c + NodeWidht + NodeToNodeDistance);
        text::Push_back(1);
        hack::getch();


        while(currentNode->next)
        {
            display::ShowPipe(r+5, c + display::NodeWidht, hack::Color::Green);
            text::Push_back(2);
            hack::getch();
            hack::ClearDisplayArea();

            if((c + display::NodeWidht + display::NodeToNodeDistance) < (display::WindowSize - display::NodeWidht - display::FullNodeWidth)) {
                c = display::GetNextNodePos(c);
            }
            else {
                c = display::FullNodeWidth;
            }

            currentNode = currentNode->next;
            display::ShowNodeAndN(head, currentNode, r, c);
            display::ShowNode(currentNode, r, c, hack::Color::Green);
            text::Push_back(3);
            hack::getch();
            display::ShowNode(currentNode, r, c);
        }
        hack::ClearDisplayArea();

        display::ShowNodeAndN(head, currentNode, r, c);
        display::ShowPipe(r+5, c + display::NodeWidht, hack::Color::Red);
        text::Push_back(4);
        hack::getch();
        hack::ClearDisplayArea();


        // Create a new node
        auto newNode = new Node<T>(val);
        display::ShowNodeAndN(head, currentNode, r, c);
        display::ShowNode(newNode, r, display::GetNextNodePos(c), hack::Color::Green);
        text::Push_back(5);
        hack::getch();

        currentNode->next = newNode;
        // Link the new node to the last element 
        display::ShowPipe(r + 5, c + display::NodeWidht, hack::Color::Green);
        display::ShowNode(newNode, r, display::GetNextNodePos(c));
        text::Push_back(6);
        hack::getch();
    };
}