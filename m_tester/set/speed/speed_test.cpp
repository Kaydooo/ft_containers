#include <cstdlib>

#ifdef STD
#define TEST_NAMESPACE std
#include <set>
#endif

#ifdef FT
#define TEST_NAMESPACE ft
#include "set.hpp"
#endif

#ifndef TEST_NAMESPACE
#define TEST_NAMESPACE ft
#include "set.hpp"
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

    TEST_NAMESPACE::set<int> testSet;

    for(int i = 0; i < SIZE; ++i)
    {
        testSet.insert(i);
    }
    testSet.erase(testSet.begin(), testSet.end());
    return 0;
  
}
