#include <iostream>
#include "list.h"


int main() 
{
    clist::List<int> list;
    list.push_back(10);
    list.push_front(5);
    list.push_back(15);

    for (auto it = list.begin(); list.size() && it != list.end(); ++it) 
    {
        std::cout << *it << " ";
        if (++it == list.begin()) break;
    }
    return 0;
}
