
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
    const long SIZE = 5;
    TEST_NAMESPACE::vector<int> testVector;
    TEST_NAMESPACE::vector<int>::const_iterator it;
    TEST_NAMESPACE::vector<int>::const_iterator ite;

    
    for(int i = 0; i < SIZE; ++i)
        testVector.push_back(i);
    std::cout << "Vector 1" << std::endl;
    it = testVector.begin();
    ite = testVector.end();

    print_container_size(testVector);
    print_container_content(it, ite);

    TEST_NAMESPACE::vector<int> testVector2(testVector);
    std::cout << "Vector 2 - copy_constructor" << std::endl;
    it = testVector2.begin();
    ite = testVector2.end();
    print_container_size(testVector2);
    print_container_content(it, ite);

    TEST_NAMESPACE::vector<int> testVector3(5, 10);
    std::cout << "Vector 3 - fill_constructor n = 5 , val = 10" << std::endl;
    it = testVector3.begin();
    ite = testVector3.end();
    print_container_size(testVector3);
    print_container_content(it, ite);

    TEST_NAMESPACE::vector<int> testVector4(testVector3.begin(), testVector3.end());
    std::cout << "Vector 4 - range_constructor" << std::endl;
    it = testVector4.begin();
    ite = testVector4.end();
    print_container_size(testVector4);
    print_container_content(it, ite);

    testVector4 = testVector;
    std::cout << "Assignment operator -- > Vector 4 = Vector1" << std::endl;
    it = testVector4.begin();
    ite = testVector4.end();
    print_container_size(testVector4);
    print_container_content(it, ite);

    {
        TEST_NAMESPACE::vector<int> tmp = testVector4;
    }
    std::cout << "Deep copy test " << std::endl;
    it = testVector4.begin();
    ite = testVector4.end();
    print_container_size(testVector4);
    print_container_content(it, ite);


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
