
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

    TEST_NAMESPACE::vector<int> testVector2;
    std::cout << "Vector 2 --> assign (15, 99)" << std::endl;
    testVector2.assign(15, 99);
    it = testVector2.begin();
    ite = testVector2.end();
    print_container_size(testVector2);
    print_container_content(it, ite);


    for(int i = 0; i < 18; ++i)
        testVector.insert(testVector.begin(), 5);
        
   std::cout << "Vector 1 before assiging to vec2" << std::endl;
    it = testVector.begin();
    ite = testVector.end();
    print_container_size(testVector);
    print_container_content(it, ite);

    std::cout << "Vector 2 --> assign (vect.begin(), vect.end())" << std::endl;
    testVector2.assign(testVector.begin(), testVector.end());
    it = testVector2.begin();
    ite = testVector2.end();
    print_container_size(testVector2);
    print_container_content(it, ite);

    testVector2.pop_back();
    testVector2.pop_back();
    std::cout << "Vector 2 --> pop_back pop_back" << std::endl;
    it = testVector2.begin();
    ite = testVector2.end();
    print_container_size(testVector2);
    print_container_content(it, ite);

    it = testVector2.insert(testVector2.begin(), 20);
    ite = testVector2.insert(testVector2.end(), 33);
    std::cout << "Vector 2 --> insert 20 at begin() insert 33 at end()" << std::endl;
    std::cout << "return of first insert = " << *it << std::endl;
    std::cout << "return of second insert = " << *ite << std::endl;
    it = testVector2.begin();
    ite = testVector2.end();
    print_container_size(testVector2);
    print_container_content(it, ite);

    testVector2.insert(testVector2.end(),14, 5);
    std::cout << "Vector 2 --> insert fill at end()" << std::endl;
    std::cout << "return of first insert = " << *it << std::endl;
    std::cout << "return of second insert = " << *ite << std::endl;
    it = testVector2.begin();
    ite = testVector2.end();
    print_container_size(testVector2);
    print_container_content(it, ite);

    testVector2.insert(testVector2.end()- 15 ,testVector.begin(), testVector.end());
    std::cout << "Vector 2 --> insert range at end() - 15" << std::endl;
    std::cout << "return of first insert = " << *it << std::endl;
    std::cout << "return of second insert = " << *ite << std::endl;
    it = testVector2.begin();
    ite = testVector2.end();
    print_container_size(testVector2);
    print_container_content(it, ite);
    testVector2.insert(testVector2.end()- 15 ,testVector2.begin(), testVector2.end());
    std::cout << "Vector 2 --> insert range at end() - 15" << std::endl;
    std::cout << "return of first insert = " << *it << std::endl;
    std::cout << "return of second insert = " << *ite << std::endl;
    it = testVector2.begin();
    ite = testVector2.end();
    print_container_size(testVector2);
    print_container_content(it, ite);


    testVector2.swap(testVector);
    std::cout << "Vector 2 -- > swap with Vector 1" << std::endl;
    it = testVector2.begin();
    ite = testVector2.end();
    print_container_size(testVector2);
    print_container_content(it, ite);
    std::cout << "Vector 1" << std::endl;
    it = testVector.begin();
    ite = testVector.end();
    print_container_size(testVector);
    print_container_content(it, ite);
    TEST_NAMESPACE::swap(testVector2, testVector);
    std::cout << "Swap again using ft::swap()" << std::endl;

    std::cout << "Vector 2" << std::endl;
    it = testVector2.begin();
    ite = testVector2.end();
    print_container_size(testVector2);
    print_container_content(it, ite);
    std::cout << "Vector 1" << std::endl;
    it = testVector.begin();
    ite = testVector.end();
    print_container_size(testVector);
    print_container_content(it, ite);

    testVector2.clear();
    testVector.clear();

    std::cout << "Clear Vector 1 + 2" << std::endl;
    std::cout << "Vector 2" << std::endl;
    it = testVector2.begin();
    ite = testVector2.end();
    print_container_size(testVector2);
    print_container_content(it, ite);
    std::cout << "Vector 1" << std::endl;
    it = testVector.begin();
    ite = testVector.end();
    print_container_size(testVector);
    print_container_content(it, ite);

    TEST_NAMESPACE::vector<int> testVector3;
    testVector3.insert(testVector3.end(), 1);
    testVector3.insert(testVector3.end(), 2);
    it = testVector3.begin();
    ite = testVector3.end();
    print_container_size(testVector3);
    print_container_content(it, ite);

    return 0;
}
