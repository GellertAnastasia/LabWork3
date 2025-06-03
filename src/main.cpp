#include <iostream>
#include "list.h"


int main() {
    clist::List<int> clist;
    clist.push_back(1);
    clist.push_back(2);
    clist.push_back(3);

    for (auto it = clist.begin(); it != clist.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';

    const clist::List<int>& const_list = clist;
    for (auto it = const_list.cbegin(); it != const_list.cend(); ++it) {
        std::cout << *it << ' ';
    }
}
