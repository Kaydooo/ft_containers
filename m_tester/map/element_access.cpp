
#include "print.hpp"
#include <cstdlib>

#ifdef STD
#define TEST_NAMESPACE std
#include <map>
#include <vector>
#include <utility>
#endif

#ifdef FT
#define TEST_NAMESPACE ft
#include "map.hpp"
#include "vector.hpp"

#endif

#ifndef TEST_NAMESPACE
#define TEST_NAMESPACE ft
#include "map.hpp"
#include "vector.hpp"
#endif

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;
    const long SIZE = 15;
    TEST_NAMESPACE::map<int, char>::const_iterator it;
    TEST_NAMESPACE::map<int, char>::const_iterator ite;
    
    
    TEST_NAMESPACE::vector<TEST_NAMESPACE::pair<int, char> > testVec;
    for(size_t i = 0 ; i < SIZE; ++i)
        testVec.push_back(TEST_NAMESPACE::make_pair(i, 'a' + i));

    TEST_NAMESPACE::map<int, char> testMap(testVec.begin(), testVec.end());

    std::cout << std::endl <<  "Map Fill Constructor" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    it = testMap.begin();
    ite = testMap.end();
    print_container_size(testMap);
    print_container_content(it, ite);

    std::cout << "Element  [3] -- > " << testMap[3] << std::endl;
    std::cout << "Element  [1] -- > " << testMap[1] << std::endl;
    std::cout << "Element  [5] -- > " << testMap[5] << std::endl;
    std::cout << "Element  [30] -- > " << testMap[30] << std::endl;
    testMap[30] = 'Z';
    std::cout << "testMap[30] = 'Z' " << testMap[30] << std::endl;
    std::cout << "Element  [30] -- > " << testMap[30] << std::endl;
    std::cout << "at  [10] -- > " << testMap.at(10)  << std::endl;
    std::cout << "at  [30] -- > " << testMap.at(30)  << std::endl;
    std::cout << "at  [11] -- > " << testMap.at(11)  << std::endl;
    try{
        std::cout << "at  [500] -- > " << testMap.at(500)  << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << std::endl << "Execpetion .. Out of range !" << std::endl;
    }






    return 0;
  
}
