#pragma once
#include <termios.h>
#include <unistd.h>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

namespace hack
{
    namespace color
    {
        constexpr auto RED_FG = "\e[38;2;255;0;0m";
        constexpr auto GREEN_FG = "\e[38;2;0;255;0m";
        constexpr auto BLUE_FG = "\e[38;2;0;0;255m";
        constexpr auto GRAY_BG = "\e[48;2;83;83;32m";
        constexpr auto RESET = "\e[0m";
    }

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
        case Color::Black:
            system("tput setaf 0");
            break;
        case Color::Red:
            system("tput setaf 1");
            break;
        case Color::Green:
            system("tput setaf 2");
            break;
        case Color::Cyan:
            system("tput setaf 6");
            break;
        }
    }

    constexpr auto DisplayAreaStart = 0;
    constexpr auto TextAreaStart = 16;
    constexpr auto TextAreaSize = 7;
    constexpr auto TerminalEnd = TextAreaStart + TextAreaSize;

    inline void WriteText(std::string text, int r, int c, Color color = Color::Default)
    {
        SetColor(color);
        std::string t = "tput cup " + std::to_string(r) + " " + std::to_string(c);
        system(t.c_str());
        std::cout << text;
        SetColor(Color::Default);
    }

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

        for(int i = 0; i < TextAreaSize; ++i)
        {
            std::cout << std::setfill(' ') << std::setw(80) << " " << "\n";
        }
    }

    inline void WriteToTextArea(std::string text, int c = 0, Color color = Color::Default)
    {
        c += TextAreaStart;
        SetColor(color);
        std::string t = "tput cup " + std::to_string(c) + " " + std::to_string(0);
        system(t.c_str());
        std::cout << text;
        SetColor(Color::Default);
    }

    static auto TEXT_POS = 0;

    // IN: text
    // IN: nio - next instruction position
    inline void WriteToTextArea(std::vector<std::string>& text, const int nip = 0)
    {
        ClearTextArea();
        MoveCursor(TextAreaStart, 0);
        int j = 0;
        if(text.size() <= 7) {
            for(auto& elem : text) {
                std::cout << std::setw(3) << j << " " << elem << "\n";
                j += 1;
            }
            MoveCursor(TextAreaStart + nip, 0);
            return;
        }

        if(nip <= 3) {
            for(int i = 0; i < TextAreaSize; ++i) {
                std::cout << std::setw(3) << i << " " << text[i] << "\n";
            }
            MoveCursor(TextAreaStart + nip, 0);
        }
        else if(text.size() - 1 - nip <= 3) {
            for(int i = text.size() - TextAreaSize; i < text.size(); ++i) {
                std::cout << std::setw(3) << i << " "  << text[i] << "\n";
            }
            MoveCursor(TextAreaStart + (TextAreaSize - (text.size() - 1 - nip) - 1), 0);
        }
        else {
            for(int i = nip - 3; i <= nip + 3; ++i) {
                std::cout << std::setw(3) << i << " " << text[i] << "\n";
            }
            MoveCursor(TextAreaStart + 3, 0);
        }
    }
}