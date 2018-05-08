#pragma once
#include "hack.hpp"

namespace text
{
    inline void Push_back(int pos = 0)
    {
        std::vector<std::string> text = 
        {
            "void Push_back(Node<T>* head, T val) {",
            "\twhile(head->next != nullptr) {",
            "\t\thead = head->next",
            "\t}",
            "\tauto node = new Node<T>(val);",
            "\thead->next = node;",
            "}; //Push_back",
        };
        int nip = 0;
        if (pos == 0)
        {
            text[0] = hack::color::GRAY_BG + text[0] + hack::color::RESET;
            nip = 0;
        }
        else if (pos == 1)
        {

            text[1] = hack::color::GRAY_BG + text[1] + hack::color::RESET;
            nip = 1;
        }
        else if (pos == 2)
        {
            text[1] = hack::color::GREEN_FG + text[1]+ hack::color::RESET;
            text[2] = hack::color::GRAY_BG + text[2] + hack::color::RESET;
            nip = 2;
        }
        else if (pos == 3)
        {
            text[2] = hack::color::GREEN_FG + text[2]+ hack::color::RESET;
            text[1] = hack::color::GRAY_BG + text[1] + hack::color::RESET;
            nip = 1;
        }
        else if (pos == 4)
        {
            text[1] = hack::color::GREEN_FG + text[1]+ hack::color::RESET;
            text[4] = hack::color::GRAY_BG + text[4] + hack::color::RESET;
            nip = 4;
        }
        else if (pos == 5)
        {
            text[4] = hack::color::GREEN_FG + text[4]+ hack::color::RESET;
            text[5] = hack::color::GRAY_BG + text[5] + hack::color::RESET;
            nip = 5;
        }
        else if (pos == 6)
        {

            text[5] = hack::color::GREEN_FG + text[5]+ hack::color::RESET;
            text[6] = hack::color::GRAY_BG + text[6] + hack::color::RESET;
            nip = 6;
        }

        hack::WriteToTextArea(text, nip);
    }

    inline void Push_front(int pos = 0)
    {
        std::vector<std::string> text = 
        {
            "void Push_front(Node<T>* head, T val) {",
            "\tauto node = new Node<T>(val);",
            "\tnode->next = head->next;",
            "\thead->next = node;",
            "}; //Push_front\n"
        };
        int nip = 0;
        if (pos == 0)
        {
            text[0] = hack::color::GRAY_BG + text[0] + hack::color::RESET;
            nip = 0;
        }
        else if (pos == 1)
        {
            text[1] = hack::color::GRAY_BG + text[1] + hack::color::RESET;
            nip = 1;
        }
        else if (pos == 2)
        {
            text[1] = hack::color::GREEN_FG + text[1]+ hack::color::RESET;
            text[2] = hack::color::GRAY_BG + text[2] + hack::color::RESET;
            nip = 2;
        }
        else if (pos == 3)
        {
            text[3] = hack::color::GRAY_BG + text[3] + hack::color::RESET;
            nip = 3;
        }
        else if (pos == 4)
        {
            text[3] = hack::color::GREEN_FG + text[3]+ hack::color::RESET;
            text[4] = hack::color::GRAY_BG + text[4] + hack::color::RESET;
            nip = 4;
        }

        hack::WriteToTextArea(text, nip);
    }
    
    inline void Empty(int pos = 0)
    {
        std::vector<std::string> text = 
        {
            "bool Empty(Node<T>* head) {",
            "\treturn head->next == nullptr;",
            "}; //Empty"
        };
        int nip = 0;
        if (pos == 0)
        {
            text[0] = hack::color::GRAY_BG + text[0] + hack::color::RESET;
            nip = 0;
        }
        else if (pos == 1)
        {
            text[1] = hack::color::GRAY_BG + text[1] + hack::color::RESET;
            nip = 1;
        }
        else if (pos == 2)
        {
            text[1] = hack::color::GREEN_FG + text[1] + hack::color::RESET;
            text[2] = hack::color::GRAY_BG + text[2] + hack::color::RESET;
            nip = 2;
        }
        else if (pos == 3)
        {
            text[1] = hack::color::RED_FG + text[1] + hack::color::RESET;
            text[2] = hack::color::GRAY_BG + text[2] + hack::color::RESET;
            nip = 2;
        }

        hack::WriteToTextArea(text, nip);
    }


    inline void Pop_front(int pos = 0)
    {
        std::vector<std::string> text = 
        {
            "bool Pop_front(Node<T>* head) {",
            "\tif(Empty(head)) return false;",
            "",
            "\tauto node = head->next;",
            "\thead->next = node->next;",
            "\tdelete (node);",
            "\treturn true;",
            "}; //Pop_Front"
        };
        int nip = 0;
        if (pos == 0)
        {
            text[0] = hack::color::GRAY_BG + text[0] + hack::color::RESET;
            nip = 0;
        }
        else if (pos == 1)
        {
            text[1] = hack::color::GRAY_BG + text[1] + hack::color::RESET;
            nip = 1;
        }
        else if (pos == 2)
        {
            text[1] = hack::color::RED_FG + text[1] + hack::color::RESET;
            text[7] = hack::color::GRAY_BG + text[7] + hack::color::RESET;
            nip = 7;
        }
        else if (pos == 3)
        {
            text[1] = hack::color::GREEN_FG + text[1] + hack::color::RESET;
            text[3] = hack::color::GRAY_BG + text[3] + hack::color::RESET;
            nip = 3;
        }
        else if (pos == 4)
        {
            text[3] = hack::color::GREEN_FG + text[3] + hack::color::RESET;
            text[4] = hack::color::GRAY_BG + text[4] + hack::color::RESET;
            nip = 4;
        }
        else if (pos == 5)
        {
            text[4] = hack::color::GREEN_FG + text[4] + hack::color::RESET;
            text[5] = hack::color::GRAY_BG + text[5] + hack::color::RESET;
            nip = 5;
        }
        else if (pos == 6)
        {
            text[5] = hack::color::RED_FG + text[5] + hack::color::RESET;
            text[6] = hack::color::GRAY_BG + text[6] + hack::color::RESET;
            nip = 6;
        }
        else if (pos == 7)
        {
            text[6] = hack::color::GREEN_FG + text[6] + hack::color::RESET;
            text[7] = hack::color::GRAY_BG + text[7] + hack::color::RESET;
            nip = 7;
        }

        hack::WriteToTextArea(text, nip);
    }
}