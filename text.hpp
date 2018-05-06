#pragma once
#include "hack.hpp"

namespace text
{
    constexpr auto PUSH_BACK =  "void Push_back(Node<T>* head, T val) {\n"
                                "\twhile(head->next != nullptr) {\n"
                                "\t\thead = head->next\n"
                                "\t}\n"
                                "\tauto node = new Node<T>(val);\n"
                                "\thead->next = node;\n"
                                "}; //Push_back\n";

    inline void Push_back(int pos = 0)
    {
        hack::ClearTextArea();
        system("tabs -2");
        hack::WriteToTextArea(PUSH_BACK);
        if (pos == 0)
        {
            hack::WriteToTextArea("void Push_back(Node<T>* head, T val) {\t<--\n");
            hack::MoveCursor(hack::TextAreaStart, 0);
        }
        else if (pos == 1)
        {
            hack::WriteToTextArea("void Push_back(Node<T>* head, T val) {\n", 0, hack::Color::Green);
            hack::WriteToTextArea("\twhile(head->next != nullptr) {\t<--\n", 1);
            hack::MoveCursor(hack::TextAreaStart + 1, 0);
        }
        else if (pos == 2)
        {
            hack::WriteToTextArea("\twhile(head->next != nullptr) {\n", 1, hack::Color::Green);
            hack::WriteToTextArea("\t\thead = head->next\t<--\n", 2);
            hack::MoveCursor(hack::TextAreaStart + 2, 0);
        }
        else if (pos == 3)
        {
            hack::WriteToTextArea("\twhile(head->next != nullptr) {\t<--\n", 1);
            hack::WriteToTextArea("\t\thead = head->next\n", 2, hack::Color::Green);
            hack::MoveCursor(hack::TextAreaStart + 1, 0);
        }
        else if (pos == 4)
        {
            hack::WriteToTextArea("\twhile(head->next != nullptr) {\n", 1, hack::Color::Red);
            hack::WriteToTextArea("\tauto node = new Node<T>(val);\t<--\n", 4);
            hack::MoveCursor(hack::TextAreaStart + 4, 0);
        }
        else if (pos == 5)
        {
            hack::WriteToTextArea("\tauto node = new Node<T>(val);\n", 4, hack::Color::Green);
            hack::WriteToTextArea("\thead->next = node;\t<--\n", 5);
            hack::MoveCursor(hack::TextAreaStart + 5, 0);
        }
        else if (pos == 6)
        {
            hack::WriteToTextArea("\thead->next = node;\n", 5, hack::Color::Green);
            hack::WriteToTextArea("}; //Push_back\t<--\n", 6);
            hack::MoveCursor(hack::TextAreaStart + 6, 0);
        }
    }

    constexpr auto PUSH_FRONT = "void Push_front(Node<T>* head, T val) {\n"
                                "\tauto node = new Node<T>(val);\n"
                                "\tnode->next = head->next;\n"
                                "\thead->next = node;\n"
                                "}; //Push_front\n";

    inline void Push_front(int pos = 0)
    {
        hack::ClearTextArea();
        system("tabs -2");
        hack::WriteToTextArea(PUSH_FRONT);
        if (pos == 0)
        {
            hack::WriteToTextArea("void Push_front(Node<T>* head, T val) {\t<--\n");
            hack::MoveCursor(hack::TextAreaStart, 0);
        }
        else if (pos == 1)
        {
            hack::WriteToTextArea("void Push_front(Node<T>* head, T val) {\n", 0, hack::Color::Green);
            hack::WriteToTextArea("\tauto node = new Node<T>(val);\t<--\n", 1);
            hack::MoveCursor(hack::TextAreaStart + 1, 0);
        }
        else if (pos == 2)
        {
            hack::WriteToTextArea("\tauto node = new Node<T>(val);\n", 1, hack::Color::Green);
            hack::WriteToTextArea("\tnode->next = head->next;\t<--\n", 2);
            hack::MoveCursor(hack::TextAreaStart + 2, 0);
        }
        else if (pos == 3)
        {
            hack::WriteToTextArea("\tnode->next = head->next;\n", 2,  hack::Color::Green);
            hack::WriteToTextArea("\thead->next = node;\t<--\n", 3);
            hack::MoveCursor(hack::TextAreaStart + 3, 0);
        }
        else if (pos == 4)
        {
            hack::WriteToTextArea("\thead->next = node;\n", 3, hack::Color::Green);
            hack::WriteToTextArea("}; //Push_front\t<--\n", 4);
            hack::MoveCursor(hack::TextAreaStart + 4, 0);
        }
    }

    constexpr auto EMPTY =  "bool Empty(Node<T>* head) {\n"
                            "\treturn head->next == nullptr;\n"
                            "}; //Empty\n";
    
    inline void Empty(int pos = 0)
    {
        hack::ClearTextArea();
        system("tabs -2");
        hack::WriteToTextArea(EMPTY);
        if (pos == 0)
        {
            hack::WriteToTextArea("bool Empty(Node<T>* head) {\t<--\n");
            hack::MoveCursor(hack::TextAreaStart, 0);
        }
        else if (pos == 1)
        {
            hack::WriteToTextArea("bool Empty(Node<T>* head) {\n", 0, hack::Color::Green);
            hack::WriteToTextArea("\treturn head->next == nullptr;\t<--\n", 1);
            hack::MoveCursor(hack::TextAreaStart + 1, 0);
        }
        else if (pos == 2)
        {
            hack::WriteToTextArea("\treturn head->next == nullptr;\n", 1, hack::Color::Green);
            hack::WriteToTextArea("}; //Empty\t<--\n", 2);
            hack::MoveCursor(hack::TextAreaStart + 2, 0);
        }
        else if (pos == 3)
        {
            hack::WriteToTextArea("\treturn head->next == nullptr;\n", 1, hack::Color::Red);
            hack::WriteToTextArea("}; //Empty\t<--\n", 2);
            hack::MoveCursor(hack::TextAreaStart + 2, 0);
        }
    }

    constexpr auto POP_FRONT1 =     "bool Pop_front(Node<T>* head) {\n"
                                    "\tif(Empty(head)) return false;\n"
                                    "\n"
                                    "\tauto node = head->next;\n"
                                    "\thead->next = node->next;\n"
                                    "\tdelete (node);\n"
                                    "\treturn true;\n";

    constexpr auto POP_FRONT2 =     "\tif(Empty(head)) return false;\n"
                                    "\n"
                                    "\tauto node = head->next;\n"
                                    "\thead->next = node->next;\n"
                                    "\tdelete (node);\n"
                                    "\treturn true;\n"
                                    "}; //Pop_Front\n";


    inline void Pop_front(int pos = 0)
    {
        hack::ClearTextArea();
        system("tabs -2");
        hack::WriteToTextArea(POP_FRONT1);
        if (pos == 0)
        {
            hack::WriteToTextArea("bool Pop_front(Node<T>* head) {\t<--\n");
            hack::MoveCursor(hack::TextAreaStart, 0);
        }
        else if (pos == 1)
        {
            hack::WriteToTextArea("bool Pop_front(Node<T>* head) {\n", 0, hack::Color::Green);
            hack::WriteToTextArea("\tif(Empty(head)) return false;\t<--\n", 1);
            hack::MoveCursor(hack::TextAreaStart + 1, 0);
        }
        else if (pos == 2)
        {
            hack::ClearTextArea();
            hack::WriteToTextArea(POP_FRONT2);
            hack::WriteToTextArea("\tif(Empty(head)) return false;\n", 0, hack::Color::Red);
            hack::WriteToTextArea("}; //Pop_Front\t<--\n", 6);
            hack::MoveCursor(hack::TextAreaStart + 6, 0);
        }
        else if (pos == 3)
        {
            hack::WriteToTextArea("\tif(Empty(head)) return false;\n", 1, hack::Color::Green);
            hack::WriteToTextArea("\tauto node = head->next;\t<--\n", 3);
            hack::MoveCursor(hack::TextAreaStart + 3, 0);
        }
        else if (pos == 4)
        {
            hack::WriteToTextArea("\tauto node = head->next;\n", 3, hack::Color::Green);
            hack::WriteToTextArea("\thead->next = node->next;\t<--\n", 4);
            hack::MoveCursor(hack::TextAreaStart + 4, 0);
        }
        else if (pos == 5)
        {
            hack::ClearTextArea();
            hack::WriteToTextArea(POP_FRONT2);
            hack::WriteToTextArea("\thead->next = node->next;\n", 3, hack::Color::Green);
            hack::WriteToTextArea("\tdelete (node);\t<--\n", 4);
            hack::MoveCursor(hack::TextAreaStart + 4, 0);
        }
        else if (pos == 6)
        {
            hack::ClearTextArea();
            hack::WriteToTextArea(POP_FRONT2);
            hack::WriteToTextArea("\tdelete (node);\n", 4, hack::Color::Red);
            hack::WriteToTextArea("\treturn true;\t<--\n", 5);
            hack::MoveCursor(hack::TextAreaStart + 5, 0);
        }
        else if (pos == 7)
        {
            hack::ClearTextArea();
            hack::WriteToTextArea(POP_FRONT2);
            hack::WriteToTextArea("\treturn true;\n", 5, hack::Color::Green);
            hack::WriteToTextArea("}; //Pop_Front\t<--\n", 6);
            hack::MoveCursor(hack::TextAreaStart + 6, 0);
        }
    }
}