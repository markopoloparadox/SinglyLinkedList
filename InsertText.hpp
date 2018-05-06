#pragma once
#include "hack.hpp"

namespace text
{
    constexpr auto INSERT_END = "void InsertEnd(Node<T>* cvor, T val) {\n"
                                "\twhile(cvor->next != nullptr) {\n"
                                "\t\tcvor = cvor->next\n"
                                "\t}\n"
                                "\tauto noviCvor = new Node<T>(val);\n"
                                "\tcvor->next = noviCvor;\n"
                                "}; //InsertEnd\n";

    inline void InsertEnd(int pos = 0)
    {
        hack::ClearTextArea();
        system("tabs -2");
        hack::WriteToTextArea(INSERT_END);
        if (pos == 0)
        {
            hack::WriteText("void InsertEnd(Node<T>* cvor, T val) {\t<--\n", hack::TextAreaStart, 0);
        }
        else if (pos == 1)
        {
            hack::WriteText("void InsertEnd(Node<T>* cvor, T val) {\n", hack::TextAreaStart, 0, hack::Color::Green);
            hack::WriteText("\twhile(cvor->next != nullptr) {\t<--\n", hack::TextAreaStart + 1, 0);
        }
        else if (pos == 2)
        {
            hack::WriteText("\twhile(cvor->next != nullptr) {\n", hack::TextAreaStart + 1, 0, hack::Color::Green);
            hack::WriteText("\t\tcvor = cvor->next\t<--\n", hack::TextAreaStart + 2, 0);
        }
        else if (pos == 3)
        {
            hack::WriteText("\twhile(cvor->next != nullptr) {\t<--\n", hack::TextAreaStart + 1, 0);
            hack::WriteText("\t\tcvor = cvor->next\n", hack::TextAreaStart + 2, 0, hack::Color::Green);
        }
        else if (pos == 4)
        {
            hack::WriteText("\twhile(cvor->next != nullptr) {\n", hack::TextAreaStart + 1, 0, hack::Color::Red);
            hack::WriteText("\tauto noviCvor = new Node<T>(val);\t<--\n", hack::TextAreaStart + 4, 0);
        }
        else if (pos == 5)
        {
            hack::WriteText("\tauto noviCvor = new Node<T>(val);\n", hack::TextAreaStart + 4, 0, hack::Color::Green);
            hack::WriteText("\tcvor->next = noviCvor;\t<--\n", hack::TextAreaStart + 5, 0);
        }
        else if (pos == 6)
        {
            hack::WriteText("\tcvor->next = noviCvor;\n", hack::TextAreaStart + 5, 0, hack::Color::Green);
            hack::WriteText("}; //InsertEnd\t<--\n", hack::TextAreaStart + 6, 0);
        }
    }

    constexpr auto INSERT_BEG = "void InsertBeg(Node<T>* glava, T val) {\n"
                                "\tauto noviCvor = new Node<T>(val);\n"
                                "\tnoviCvor->next = glava->next;\n"
                                "\tglava->next = noviCvor;\n"
                                "}; //InsertBeg\n";

    inline void InsertBeg(int pos = 0)
    {
        hack::ClearTextArea();
        system("tabs -2");
        hack::WriteToTextArea(INSERT_BEG);
        if (pos == 0)
        {
            hack::WriteText("void InsertBeg(Node<T>* glava, T val) {\t<--\n", hack::TextAreaStart, 0);
        }
        else if (pos == 1)
        {
            hack::WriteText("void InsertBeg(Node<T>* glava, T val) {\n", hack::TextAreaStart, 0, hack::Color::Green);
            hack::WriteText("\tauto noviCvor = new Node<T>(val);\t<--\n", hack::TextAreaStart + 1, 0);
        }
        else if (pos == 2)
        {
            hack::WriteText("\tauto noviCvor = new Node<T>(val);\n", hack::TextAreaStart + 1, 0, hack::Color::Green);
            hack::WriteText("\tnoviCvor->next = glava->next;\t<--\n", hack::TextAreaStart + 2, 0);
        }
        else if (pos == 3)
        {
            hack::WriteText("\tnoviCvor->next = glava->next;\n", hack::TextAreaStart + 2, 0, hack::Color::Green);
            hack::WriteText("\tglava->next = noviCvor;\t<--\n", hack::TextAreaStart + 3, 0);
        }
        else if (pos == 4)
        {
            hack::WriteText("\tglava->next = noviCvor;\n", hack::TextAreaStart + 3, 0, hack::Color::Green);
            hack::WriteText("}; //InsertBeg\t<--\n", hack::TextAreaStart + 4, 0);
        }
    }

    constexpr auto IS_EMPTY = "bool IsEmpty(Node<T>* glava) {\n"
                                "\treturn glava->next == nullptr;\n"
                                "}; //IsEmpty\n";
    
    inline void IsEmpty(int pos = 0)
    {
        hack::ClearTextArea();
        system("tabs -2");
        hack::WriteToTextArea(IS_EMPTY);
        if (pos == 0)
        {
            hack::WriteText("bool IsEmpty(Node<T>* glava) {\t<--\n", hack::TextAreaStart, 0);
        }
        else if (pos == 1)
        {
            hack::WriteText("bool IsEmpty(Node<T>* glava) {\n", hack::TextAreaStart, 0, hack::Color::Green);
            hack::WriteText("\treturn glava->next == nullptr;\t<--\n", hack::TextAreaStart + 1, 0);
        }
        else if (pos == 2)
        {
            hack::WriteText("\treturn glava->next == nullptr;\n", hack::TextAreaStart + 1, 0, hack::Color::Green);
            hack::WriteText("}; //IsEmpty\t<--\n", hack::TextAreaStart + 2, 0);
        }
        else if (pos == 3)
        {
            hack::WriteText("\treturn glava->next == nullptr;\n", hack::TextAreaStart + 1, 0, hack::Color::Red);
            hack::WriteText("}; //IsEmpty\t<--\n", hack::TextAreaStart + 2, 0);
        }
    }
}