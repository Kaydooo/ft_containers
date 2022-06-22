#include "Vector.hpp"
#include <vector>
#include <iostream>

int main()
{
    ft::vector<int> test(15, 11);
    ft::vector<int>::iterator it;

    // it = test.begin();
    for(it = test.begin() ; it != test.end(); ++it)
        std::cout << *it << std::endl;

}