#pragma once
#include "node.hpp"
#include <iomanip>
#include <iostream>
#include <vector>
#include "hack.hpp"
#include "InsertText.hpp"

namespace list2
{
    constexpr int NodeWidht = 16;
    constexpr int WindowSize = 80;
    constexpr int NodeToNodeDistance = 3;

    template<class T>
    void ShowNode(Node<T>* node, int r, int c, hack::Color color = hack::Color::Default)
    {
        hack::SetColor(color);
        hack::MoveCursor(r, c);
        std::cout << std::setfill('-') << std::setw(16) << "-" << "\n";
        hack::MoveCursor(r + 1, c);
        std::cout << "|" << std::setfill(' ')  << std::setw(14) << std::left << node << "|" << "\n";
        hack::MoveCursor(r + 2, c);
        std::cout << "|"  << std::setfill('-') << std::setw(14) << "-" << "|" << "\n";
        hack::MoveCursor(r + 3, c);
        std::cout << "|" << std::setfill(' ') << std::setw(14) << std::left << std::to_string(node->val) << "|" << "\n";
        hack::MoveCursor(r + 4, c);
        std::cout << "|"  << std::setfill('-') << std::setw(14) << "-" << "|" << "\n";
        hack::MoveCursor(r + 5, c);
        std::cout << "|" << std::setfill(' ')  << std::setw(14) << std::left << node->next << "|" << "\n";
        hack::MoveCursor(r + 6, c);
        std::cout << std::setfill('-') << std::setw(16) << "-" << "\n";
        hack::SetColor(hack::Color::Default);
    };

    inline void ShowPipe(int r, int c, hack::Color color = hack::Color::Default)
    {
        hack::SetColor(color);
        hack::MoveCursor(r, c);
        std::cout << "-" << "\n";
        c += 1;
        hack::MoveCursor(r, c);
        std::cout << "|" << "\n";
        hack::MoveCursor(r - 1, c);
        std::cout << "|" << "\n";
        hack::MoveCursor(r - 2, c);
        std::cout << "|" << "\n";
        hack::MoveCursor(r - 3, c);
        std::cout << "|" << "\n";
        hack::MoveCursor(r - 4, c);
        std::cout << "-" << "\n";
        hack::MoveCursor(r - 4, c + 1);
        std::cout << ">" << "\n";
        hack::SetColor(hack::Color::Default);
    };

    inline void ShowArrow(int r, int c, hack::Color color = hack::Color::Default)
    {
        SetColor(color);
        c += NodeWidht/2;
        r -= 1;
        hack::MoveCursor(r, c);
        std::cout << "\\/" << "\n";
        hack::MoveCursor(r - 1, c);
        std::cout << "||" << "\n";
        hack::MoveCursor(r - 2, c);
        std::cout << "||" << "\n";
        hack::MoveCursor(r - 3, c);
        std::cout << "||" << "\n";
        hack::SetColor(hack::Color::Default);
    };

    inline void DrawPipe(int r, int cStart, int cEnd, hack::Color color = hack::Color::Default)
    {
        SetColor(color);
        cStart += NodeWidht - 2;
        r += 7;
        hack::MoveCursor(r, cStart);
        std::cout << "|" << "\n";
        hack::MoveCursor(r+1, cStart);
        std::cout << "|" << "\n";
        for(; cStart <= cEnd; ++cStart) {
            hack::MoveCursor(r+2, cStart);
            std::cout << "-" << "\n";
        }
        hack::MoveCursor(r+1, cStart);
        std::cout << "|" << "\n";
        hack::MoveCursor(r, cStart);
        std::cout << "/\\" << "\n";
        hack::SetColor(hack::Color::Default);
    };


    inline void DrawEmptyBox(int r, int c, hack::Color color = hack::Color::Default)
    {
        hack::SetColor(color);
        hack::MoveCursor(r, c);
        std::cout << std::setfill('-') << std::setw(16) << "-" << "\n";
        hack::MoveCursor(r + 1, c);
        std::cout << "|" << std::setfill(' ')  << std::setw(14) << " " << "|" << "\n";
        hack::MoveCursor(r + 2, c);
        std::cout << "|"  << std::setfill(' ') << std::setw(14) << " " << "|" << "\n";
        hack::MoveCursor(r + 3, c);
        std::cout << "|" << std::setfill(' ') << std::setw(14) << " " << "|" << "\n";
        hack::MoveCursor(r + 4, c);
        std::cout << "|"  << std::setfill(' ') << std::setw(14) << " " << "|" << "\n";
        hack::MoveCursor(r + 5, c);
        std::cout << "|" << std::setfill(' ')  << std::setw(14) << " " << "|" << "\n";
        hack::MoveCursor(r + 6, c);
        std::cout << std::setfill('-') << std::setw(16) << "-" << "\n";
        hack::SetColor(hack::Color::Default);
    }


    template<class T>
    void ShowNodeAndN(Node<T>* glava, Node<T>* node, int r, int c, int front = -1, int back = -1)
    {
        std::vector<Node<T>*> vec;
        int i = 0;
        int index = 0;
        for(auto beg = glava; beg != nullptr; beg = beg->next)
        {
            vec.push_back(beg);
            if(node == beg) {
                index = i;
            }
            i += 1;
        }

        int howManyOnLeft = 0;
        int onLeft = c;
        while(onLeft >= (NodeWidht + NodeToNodeDistance))
        {
            howManyOnLeft += 1;
            onLeft -= NodeWidht + NodeToNodeDistance;
        }

        if(howManyOnLeft > index) {
            howManyOnLeft = index;
        }

        if(back != -1 && howManyOnLeft > back)
        {
            howManyOnLeft = 0;
        }

        int howManyOnRight = 0;
        int onRight = c + NodeWidht;

        while((onRight + NodeWidht + NodeToNodeDistance) <= WindowSize)
        {
            onRight += NodeWidht + NodeToNodeDistance;
            howManyOnRight += 1;
        }

        if((vec.size() - 1 - index) < howManyOnRight)
        {
            howManyOnRight = (vec.size() - 1 - index);
        }

        if(front != -1 && howManyOnRight > front)
        {
            howManyOnRight = 0;
        }

        hack::Color color = hack::Color::Default;
        if(vec[index] == glava)
        {
            color = hack::Color::Cyan;
        }
        ShowNode(vec[index], r, c, color);
        color = hack::Color::Default;

        {
            int row = r;
            int col = c + NodeWidht;
            int i = index + 1;
            while(howManyOnRight > 0) {
                ShowPipe(row + 5, col);
                col += 3;

                if(vec[i] == glava)
                {
                    color = hack::Color::Cyan;
                }
                ShowNode(vec[i], row, col);
                color = hack::Color::Default;
                col += NodeWidht;
                i += 1;
                howManyOnRight -= 1;
            }
        }

        {
            int row = r;
            int col = c;
            int i = index - 1;
            while(howManyOnLeft > 0) {
                ShowPipe(row + 5, col - 3);
                col -= 3 + NodeWidht;
                if(vec[i] == glava)
                {
                    color = hack::Color::Cyan;
                }
                ShowNode(vec[i], row, col, color);
                color = hack::Color::Default;
                i -= 1;
                howManyOnLeft -= 1;
            }
        }
    };

    template<class T>
    bool IsEmpty(Node<T>* glava)
    {
        hack::ClearDisplayArea();
        hack::ClearTextArea();

        int r = 0;
        int c = 0;
        ShowNodeAndN(glava, glava, r, c);
        text::IsEmpty(0);
        hack::getch();

        //ShowArrow(r, c + NodeWidht + NodeToNodeDistance);
        text::IsEmpty(1);
        hack::getch();

        if(glava->next == nullptr)
        {
            ShowPipe(r+5, c + NodeWidht, hack::Color::Green);
            text::IsEmpty(2);
            hack::getch();
        }
        else {
            ShowPipe(r+5, c + NodeWidht, hack::Color::Red);
            text::IsEmpty(3);
            hack::getch();
        }
        return glava->next == nullptr;
    };

    template<class T>
    void InsertBeg(Node<T>* glava, T val)
    {
        hack::ClearDisplayArea();
        hack::ClearTextArea();

        int r = 0;
        int c = 0;

        ShowNodeAndN(glava, glava, r, 0);
        text::InsertBeg(0);
        hack::getch();
        hack::ClearDisplayArea();

        ShowNode(glava, r, c, hack::Color::Cyan);
        if(glava->next) {
            ShowNodeAndN(glava, glava->next, r, c + (NodeToNodeDistance * 2) + (NodeWidht * 2), -1, 0);
            DrawPipe(r, c, c + (NodeToNodeDistance * 2) + (NodeWidht * 2));
        }
        text::InsertBeg(1);
        hack::getch();

        auto node = new Node<T>(val);
        ShowNode(node, r, c + (NodeToNodeDistance + NodeWidht), hack::Color::Green);
        text::InsertBeg(2);
        hack::getch();

        node->next = glava->next;
        ShowNode(node, r, c + (NodeToNodeDistance + NodeWidht));
        if(glava->next) {
            ShowPipe(r+5, c + (NodeToNodeDistance * 1) + (NodeWidht * 2), hack::Color::Green);
            DrawPipe(r, c, c + (NodeToNodeDistance * 2) + (NodeWidht * 2), hack::Color::Green);
        }
        text::InsertBeg(3);
        hack::getch();

        glava->next = node;
        hack::ClearDisplayArea();
        ShowNodeAndN(glava, glava, r, 0);
        ShowPipe(r+5, c + NodeWidht, hack::Color::Green);
        text::InsertBeg(4);
        hack::getch();
    };

    template<class T>
    void InsertEnd(Node<T>* glava, T val)
    {
        hack::ClearDisplayArea();
        hack::ClearTextArea();

        int r = 0;
        int c = 0;
        ShowNodeAndN(glava, glava, r, c);
        text::InsertEnd(0);
        hack::getch();
        hack::ClearDisplayArea();


        bool isNotDone = glava->next;
        auto currentNode = glava;
        ShowNodeAndN(glava, currentNode, r, c);
        //ShowArrow(r, c + NodeWidht + NodeToNodeDistance);
        text::InsertEnd(1);
        hack::getch();


        while(currentNode->next)
        {
            ShowPipe(r+5, c + NodeWidht, hack::Color::Green);
            text::InsertEnd(2);
            hack::getch();
            hack::ClearDisplayArea();

            if((c + NodeWidht + NodeToNodeDistance) < (WindowSize - NodeWidht - NodeWidht- NodeToNodeDistance)) {
                c += NodeWidht + NodeToNodeDistance;
            }
            else {
                c = NodeWidht + NodeToNodeDistance;
            }

            currentNode = currentNode->next;
            ShowNodeAndN(glava, currentNode, r, c);
            ShowNode(currentNode, r, c, hack::Color::Green);
            text::InsertEnd(3);
            hack::getch();
            ShowNode(currentNode, r, c);
        }
        hack::ClearDisplayArea();

        ShowNodeAndN(glava, currentNode, r, c);
        //DrawEmptyBox(r, c + NodeToNodeDistance + NodeWidht, hack::Color::Black);
        //ShowPipe(r + 5, c + NodeWidht, hack::Color::Black);
        //ShowArrow(r, c + NodeWidht + NodeToNodeDistance, hack::Color::Red);
        ShowPipe(r+5, c + NodeWidht, hack::Color::Red);
        text::InsertEnd(4);
        hack::getch();
        hack::ClearDisplayArea();


        // Create a new node
        auto newNode = new Node<T>(val);
        ShowNodeAndN(glava, currentNode, r, c);
        ShowNode(newNode, r, c + NodeToNodeDistance + NodeWidht, hack::Color::Green);
        text::InsertEnd(5);
        hack::getch();

        currentNode->next = newNode;
        // Link the new node to the last element 
        ShowPipe(r + 5, c + NodeWidht, hack::Color::Green);
        ShowNode(newNode, r, c + NodeToNodeDistance + NodeWidht);
        text::InsertEnd(6);
        hack::getch();
    };
}