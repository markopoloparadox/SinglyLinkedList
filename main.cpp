#include <iostream>
#include <iomanip>
#include "list.hpp"
#include "list2.hpp"

int main()
{
    Node<int> glava;
    list2::IsEmpty(&glava);
    list2::InsertBeg(&glava, 20);
    list::InsertEnd(&glava, 1);
    list::InsertEnd(&glava, 2);
    list::InsertEnd(&glava, 3);
    list::InsertEnd(&glava, 4);
    list::InsertEnd(&glava, 5);
    list::InsertEnd(&glava, 6);
    list::InsertEnd(&glava, 7);
    list::InsertEnd(&glava, 8);
    //list2::InsertEnd(&glava, 9);
    //list::InsertBeg(&glava, 3);
    //list::InsertBeg(&glava, 4);
    list::RemoveBeg(&glava);
    list::RemoveBeg(&glava);
    list2::IsEmpty(&glava);
    //
    //for(int i = 1; i < 10; ++i)
    //{
    //    list::InsertEnd(&glava, i);
    //}
    //list::Print(&glava);
    //auto size = list::Size(&glava);
    return 0;
}