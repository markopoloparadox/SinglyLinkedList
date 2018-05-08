#include <iostream>
#include <iomanip>
#include "sll.hpp"
#include "sll2.hpp"

int main()
{
    system("tabs -2");
    Node<int> glava;
    sll2::Push_back(&glava, 1);
    sll2::Push_back(&glava, 2);
    sll::Push_front(&glava, 3);
    sll2::Pop_front(&glava);
    sll::Push_back(&glava, 3);
    sll2::Push_front(&glava, 1);
    sll2::Empty(&glava);
    return 0;
}