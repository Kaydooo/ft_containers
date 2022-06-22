#include "Vector.hpp"
#include <vector>
#include <iostream>

int main()
{
    ft::vector<int> test(13, 11);
    ft::vector<int>::iterator it;
    ft::vector<int> test1;

    // std::vector<int> test(13, 11);
    // std::vector<int>::iterator it;
    // std::vector<int> test1;
    test1.pop_back();
    std::cout << "1size = " << test1.size() << std::endl;
    std::cout << "1max_size = " << test1.max_size() << std::endl;
    std::cout << "1Capacity = " << test1.capacity() << std::endl;

    // it = test.begin();
    for(it = test.begin() ; it < test.end(); ++it)
        std::cout << *it << std::endl;

    std::cout << "size = " << test.size() << std::endl;
    std::cout << "max_size = " << test.max_size() << std::endl;
    std::cout << "Capacity = " << test.capacity() << std::endl;
    test.reserve(21);
    std::cout << "Reserved 10000" << std::endl;
    std::cout << "size = " << test.size() << std::endl;
    std::cout << "max_size = " << test.max_size() << std::endl;
    std::cout << "Capacity = " << test.capacity() << std::endl;
    test.resize(25, 8);
    std::cout << "resized to  10" << std::endl;
    for(it = test.begin() ; it < test.end(); ++it)
        std::cout << *it << std::endl;
    std::cout << "size = " << test.size() << std::endl;
    std::cout << "max_size = " << test.max_size() << std::endl;
    std::cout << "Capacity = " << test.capacity() << std::endl;
    // try{
    //     std::cout << "access element at 25 :" << test.at(25) << std::endl;
    // }
    // catch(std::exception &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
    std::cout << "push_back" << std::endl;
    test.push_back(15);
    test.push_back(19);
    for(it = test.begin() ; it < test.end(); ++it)
        std::cout << *it << std::endl;
    std::cout << "size = " << test.size() << std::endl;
    std::cout << "max_size = " << test.max_size() << std::endl;
    std::cout << "Capacity = " << test.capacity() << std::endl;
    test.pop_back();
       for(it = test.begin() ; it < test.end(); ++it)
        std::cout << *it << std::endl;
    std::cout << "size = " << test.size() << std::endl;
    std::cout << "max_size = " << test.max_size() << std::endl;
    std::cout << "Capacity = " << test.capacity() << std::endl;
    test.pop_back();
       for(it = test.begin() ; it < test.end(); ++it)
        std::cout << *it << std::endl;
    std::cout << "size = " << test.size() << std::endl;
    std::cout << "max_size = " << test.max_size() << std::endl;
    std::cout << "Capacity = " << test.capacity() << std::endl;
    test.pop_back();
       for(it = test.begin() ; it < test.end(); ++it)
        std::cout << *it << std::endl;
    std::cout << "size = " << test.size() << std::endl;
    std::cout << "max_size = " << test.max_size() << std::endl;
    std::cout << "Capacity = " << test.capacity() << std::endl;



}