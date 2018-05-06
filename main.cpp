#include <iostream>
#include <iomanip>
#include "sll.hpp"
#include "sll2.hpp"

int main()
{
    Node<int> glava;
    sll2::Empty(&glava);
    sll2::Push_front(&glava, 2);
    sll2::Push_back(&glava, 3);
    sll2::Push_front(&glava, 1);
    sll2::Empty(&glava);
    return 0;
}