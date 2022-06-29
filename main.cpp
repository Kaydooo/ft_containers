#include "vector.hpp"
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

    /* Push + Pop */
    std::cout << "push_back" << std::endl;
    test.push_back(15);
    // test.push_back(19);
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
    
    /* Insert */
     std::cout << "Insert" << std::endl;
    // test.insert(test.end(), 5, 99);
    // test.insert(test.end(), 100, 99);
    std::vector<int> a;
    a.push_back(1);
    a.push_back(332);
    a.push_back(443);
    a.push_back(554);
    // a.push_back(534);
    test.insert(test.begin(), 5, 444);
    test.insert(test.begin(), a.begin(), a.end());


    std::vector<int> insertArray;
    // insertArray.push_back(11);
    // insertArray.push_back(22);
    // insertArray.push_back(33);
    // insertArray.push_back(44);
    // insertArray.push_back(55);
    // test.insert(test.begin(), insertArray.begin()+2, insertArray.end());
    // test.insert(test.begin(), 233);
    // test.insert(test.begin() + 10, 17);
    // test.insert(test.end(), 17);


    for(it = test.begin() ; it < test.end(); ++it)
        std::cout << *it << std::endl;
    std::cout << "size = " << test.size() << std::endl;
    std::cout << "max_size = " << test.max_size() << std::endl;
    std::cout << "Capacity = " << test.capacity() << std::endl;
    /* Clear */

    // std::vector<int> test3;
    // test3.push_back(10);
    // test3.push_back(12);
    // test3.push_back(13);
    // test3.push_back(14);
    // test3.push_back(15);
    // std::vector<int>::iterator it1 = test3.begin();
    // std::vector<int>::iterator it2 = test3.end();
    // ft::vector<int> test4(it1, it2);
    // ft::vector<int>::iterator it3;
    // std::cout << "Range Constructed  " << std::endl;

    // for(it3 = test4.begin() ; it3 < test4.end(); ++it3)
    //     std::cout << *it3 << std::endl;
    // std::cout << "size = " << test4.size() << std::endl;
    // std::cout << "max_size = " << test4.max_size() << std::endl;
    // std::cout << "Capacity = " << test4.capacity() << std::endl;

    // test4.clear();
    // std::cout << "Cleared " << std::endl;

    // for(it3 = test4.begin() ; it3 < test4.end(); ++it3)
    //     std::cout << *it3 << std::endl;
    // std::cout << "size = " << test4.size() << std::endl;
    // std::cout << "max_size = " << test4.max_size() << std::endl;
    // std::cout << "Capacity = " << test4.capacity() << std::endl;

}