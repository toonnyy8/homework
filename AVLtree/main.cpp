#include <iostream>
#include <cstdlib>
#include <string>
#include "include/tree.hpp"

int main()
{
    // std::string filename;
    // std::cin >> filename;
    tree::BSTree<int, double> t(1, 2.5);
    t.insert(2, 2);
    t.insert(-12, 3);
    std::cout << t.search(-12);
    t.insert(7, 7);
    t.insert(-2, 0);
    std::cout << "end";
    system("PAUSE");
    return 0;
}
