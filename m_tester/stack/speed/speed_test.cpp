
#include <iostream>
#include <cstdlib>

#ifdef STD
#define TEST_NAMESPACE std
#include <stack>
#endif

#ifdef FT
#define TEST_NAMESPACE ft
#include "stack.hpp"
#endif

#ifndef TEST_NAMESPACE
#define TEST_NAMESPACE ft
#include "stack.hpp"
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

    TEST_NAMESPACE::stack<int> testVector;

    for(int i = 0; i < SIZE; ++i)
        testVector.push(i);
    for(int i = 0; i < SIZE; ++i)
        testVector.pop();
    return 0;
  
}
