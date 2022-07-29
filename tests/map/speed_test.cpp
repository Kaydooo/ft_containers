#include "../../inc/map.hpp"
#include <map>
#include <cstdlib>

#ifdef STD
#define TEST_NAMESPACE std
#endif

#ifdef FT
#define TEST_NAMESPACE ft
#endif

#ifndef TEST_NAMESPACE
#define TEST_NAMESPACE ft
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

    TEST_NAMESPACE::map<int, int> testMap;

    for(int i = 0; i < SIZE; ++i)
    {
        testMap.insert(TEST_NAMESPACE::make_pair(i, i+1));
    }
    testMap.erase(testMap.begin(), testMap.end());
    return 0;
}
