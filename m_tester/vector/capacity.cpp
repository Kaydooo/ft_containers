
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
    TEST_NAMESPACE::vector<char> testVector;
    TEST_NAMESPACE::vector<char>::const_iterator it;
    TEST_NAMESPACE::vector<char>::const_iterator ite;

    for(char c = 'a' ; c <= 'g' ; ++c)
        testVector.push_back(c);
    it = testVector.begin();
    ite = testVector.end();

    print_container_size(testVector);
    print_container_content(it, ite);

    TEST_NAMESPACE::vector<char> testVector2;
    it = testVector2.begin();
    ite = testVector2.end();
    testVector2.insert(testVector2.begin(), testVector.begin(), testVector.end());
    print_container_size(testVector2);
    print_container_content(it, ite);

    testVector2.reserve(20);

    testVector2.insert(testVector2.begin(), testVector.begin(), testVector.end());
    it = testVector2.begin();
    ite = testVector2.end();
    print_container_size(testVector2);
    print_container_content(it, ite);

    testVector2.resize(2);
    testVector2.reserve(20);
    it = testVector2.begin();
    ite = testVector2.end();
    print_container_size(testVector2);
    print_container_content(it, ite);

    testVector2.resize(0);
    testVector2.resize(500);

    it = testVector2.begin();
    ite = testVector2.end();
    print_container_size(testVector2);

    return 0;
  
}
