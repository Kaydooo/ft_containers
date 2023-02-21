
#include <iostream>
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

    long SIZE;
    if(argc > 1)
        SIZE = atol(argv[1]);
    else
        SIZE = 10000000;

    TEST_NAMESPACE::vector<int> testVector;

    for(int i = 0; i < SIZE; ++i)
        testVector.push_back(i);
    testVector.erase(testVector.begin(), testVector.end());
    return 0;
  
}
