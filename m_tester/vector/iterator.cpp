
#include "print.hpp"
#include <cstdlib>
#ifdef STD
#define TEST_NAMESPACE std
#include <vector>
#endif

#ifdef FT
#define TEST_NAMESPACE ft
#include "vector.hpp"
#endif

#ifndef TEST_NAMESPACE
#define TEST_NAMESPACE ft
#include "vector.hpp"
#endif

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;
    const long SIZE = 20;
    TEST_NAMESPACE::vector<int> testVector;
    TEST_NAMESPACE::vector<int>::iterator it;
    TEST_NAMESPACE::vector<int>::iterator ite;
    TEST_NAMESPACE::vector<int>::reverse_iterator rit;
    TEST_NAMESPACE::vector<int>::reverse_iterator rite;

    for(int i = 0; i < SIZE; ++i)
        testVector.push_back(i);

    std::cout << "Vector 1" << std::endl;
    it = testVector.begin();
    ite = testVector.end();
    print_container_size(testVector);
    print_container_content(it, ite);

    std::cout << "Vector 1 - reverse" << std::endl;
    rit = testVector.rbegin();
    rite = testVector.rend();
    print_container_size(testVector);
    print_container_content(rit, rite);


    std::cout << "Vector 1 -- const_iterator" << std::endl;
    it = testVector.begin();
    ite = testVector.end();
    print_container_size(testVector);
    print_container_content(it, ite);

    
    std::cout << "Vector 1 -- reverse const_iterator" << std::endl;
    rit = testVector.rbegin();
    rite = testVector.rend();
    print_container_size(testVector);
    print_container_content(rit, rite);





    //insert
    // testVector2.insert(testVector2.begin(), testVector.begin(), testVector.end());
    // std::cout << "Vector 2 after inserting vec1.begin() to vec1.end()" << std::endl;
    // print_container_size(testVector2);
    // print_container_content(testVector2.begin(), testVector2.end());

    // testVector2.insert(testVector2.begin() + 3, testVector.begin(), testVector.begin() + 5);
    // std::cout << "Vector 2 after inserting vec1.begin() to vec1.begin() + 5 into vec2.begin() + 3" << std::endl;
    // print_container_size(testVector2);
    // print_container_content(testVector2.begin(), testVector2.end());

    // testVector.erase(testVector.begin(), testVector.end());
    // std::cout << "Vector 1 after erasing from vec1.begin() to vec1.end()" << std::endl;
    // print_container_size(testVector);


    return 0;
  
}
