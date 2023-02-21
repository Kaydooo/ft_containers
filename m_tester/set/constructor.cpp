
#include "print.hpp"
#include <cstdlib>

#ifdef STD
#define TEST_NAMESPACE std
#include <set>
#include <vector>
#include <utility>
#endif

#ifdef FT
#define TEST_NAMESPACE ft
#include "set.hpp"
#include "vector.hpp"

#endif

#ifndef TEST_NAMESPACE
#define TEST_NAMESPACE ft
#include "set.hpp"
#include "vector.hpp"
#endif

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;
    const long SIZE = 8;
    TEST_NAMESPACE::set<int> testMap;
    TEST_NAMESPACE::set<int>::const_iterator it;
    TEST_NAMESPACE::set<int>::const_iterator ite;
    

    std::cout << std::endl << "Map1 Default Constructor" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    print_container_size(testMap);
    
    TEST_NAMESPACE::vector<int > testVec;

    for(size_t i = 0 ; i < SIZE; ++i)
        testVec.push_back(i*2);

    TEST_NAMESPACE::set<int> testMap2(testVec.begin(), testVec.end());

    std::cout << std::endl <<  "Map2 Fill Constructor" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    it = testMap2.begin();
    ite = testMap2.end();
    print_container_size(testMap2);
    print_container_content(it, ite);

    std::cout << std::endl <<  "Map3 Copy Constructor" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    TEST_NAMESPACE::set<int> testMap3(testMap2);
    it = testMap3.begin();
    ite = testMap3.end();
    print_container_size(testMap3);
    print_container_content(it, ite);
    {
    std::cout << std::endl <<  "Deep Copy test" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    TEST_NAMESPACE::set<int> testMapX(testMap2);
    it = testMapX.begin();
    ite = testMapX.end();
    print_container_size(testMapX);
    print_container_content(it, ite);
    }
    std::cout << std::endl <<  "Map1 Assignment operator r" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    testMap = testMap2;
    it = testMap.begin();
    ite = testMap.end();
    print_container_size(testMap);
    print_container_content(it, ite);

    return 0;
  
}
