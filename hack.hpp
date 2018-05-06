#pragma once
#include <termios.h>
#include <unistd.h>
#include <iomanip>
#include <iostream>
#include <string>

namespace hack
{
    enum class Color
    {
        Default = 0,
        Green,
        Black,
        Cyan,
        Red
    };

    inline char getch()
    {
        char buf = 0;
        struct termios old = {0};
        fflush(stdout);

        if(tcgetattr(0, &old) < 0)
            perror("tcgetattr");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[CTIME] = 0;
        if(tcsetattr(0, TCSANOW, &old) < 0)
            perror("tcsetattr ICANON");
        if(read(0, &buf, 1) < 0)
            perror("read");
        old.c_lflag &= ICANON;
        old.c_lflag &= ECHO;

        if(tcsetattr(0, TCSADRAIN, &old) < 0)
            perror("tcsetattr ~ICANON");
        printf("%c\n", buf);

        return buf;
    }

    inline void MoveCursor(int r, int c)
    {
        std::string t = "tput cup " + std::to_string(r) + " " + std::to_string(c);
        system(t.c_str());
    }

    inline void ClearText(int r, int c)
    {
        std::string t = "tput cup " + std::to_string(r) + " " + std::to_string(c);
        system(t.c_str());
        std::cout << std::setfill(' ') << std::setw(80 - r) << " " << "\n";
    }

    inline void SetColor(Color color)
    {
        std::string coloS = "";
        switch(color)
        {
        case Color::Default:
            system("tput sgr0");
            break;
        case Color::Green:
            system("tput setaf 2");
            break;
        case Color::Black:
            system("tput setaf 0");
            break;
        case Color::Cyan:
            system("tput setaf 6");
            break;
        case Color::Red:
            system("tput setaf 1");
            break;
        }
    }

    inline void WriteText(std::string text, int r, int c, Color color = Color::Default)
    {
        SetColor(color);
        std::string t = "tput cup " + std::to_string(r) + " " + std::to_string(c);
        system(t.c_str());
        std::cout << text;
        SetColor(Color::Default);
    }

    constexpr auto DisplayAreaStart = 0;
    constexpr auto TextAreaStart = 16;

    inline void ClearDisplayArea()
    {
        std::string t = "tput cup " + std::to_string(0) + " " + std::to_string(0);
        system(t.c_str());

        for(int i = 0; i < TextAreaStart; ++i)
        {
            std::cout << std::setfill(' ') << std::setw(80) << " " << "\n";
        }
    }

    inline void ClearTextArea()
    {
        std::string t = "tput cup " + std::to_string(TextAreaStart) + " " + std::to_string(0);
        system(t.c_str());

        for(int i = 0; i < 7; ++i)
        {
            std::cout << std::setfill(' ') << std::setw(80) << " " << "\n";
        }
    }

    inline void WriteToTextArea(std::string text, Color color = Color::Default)
    {
        SetColor(color);
        std::string t = "tput cup " + std::to_string(TextAreaStart) + " " + std::to_string(0);
        system(t.c_str());
        std::cout << text;
        SetColor(Color::Default);
    }
}