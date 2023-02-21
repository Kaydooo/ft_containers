
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
    const long SIZE = 8;
    TEST_NAMESPACE::map<int, char> testMap;
    TEST_NAMESPACE::map<int, char>::const_iterator it;
    TEST_NAMESPACE::map<int, char>::const_iterator ite;
    TEST_NAMESPACE::map<int, char>::const_iterator resIT;
    TEST_NAMESPACE::pair< TEST_NAMESPACE::map<int, char>::iterator, bool> result;
    
    std::cout << std::endl << "Map1 Default Constructor" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    print_container_size(testMap);
    
    TEST_NAMESPACE::vector<TEST_NAMESPACE::pair<int, char> > testVec;

    for(size_t i = 0 ; i < SIZE; ++i)
        testVec.push_back(TEST_NAMESPACE::make_pair(i, 'a' + i));

    std::cout << std::endl << "Map1 insert elements " << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    result =  testMap.insert(TEST_NAMESPACE::make_pair(90, 'Z'));
    std::cout << "insert (90, 'z') -- > " << result.second << std::endl;
    result =  testMap.insert(TEST_NAMESPACE::make_pair(10, 'j'));
    std::cout << "insert (10, 'j') -- > " << result.second << std::endl;
    result =  testMap.insert(TEST_NAMESPACE::make_pair(90, 'Z'));
    std::cout << "insert (90, 'z') -- > " << result.second << std::endl;
    resIT =  testMap.insert(testMap.begin(), TEST_NAMESPACE::make_pair(90, 'Z'));
    std::cout << "insert (90, 'z') at begin()-- > " << resIT->first << std::endl;
    resIT =  testMap.insert(testMap.begin(), TEST_NAMESPACE::make_pair(29, 'Z'));
    std::cout << "insert (29, 'z') at begin()-- > " << resIT->first << std::endl;
    it = testMap.begin();
    ite = testMap.end();
    print_container_size(testMap);
    print_container_content(it, ite);

    TEST_NAMESPACE::map<int, char> testMap2;
    std::cout << std::endl << "Map2 insert range " << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    testMap2.insert(testVec.begin(), testVec.end());
    it = testMap2.begin();
    ite = testMap2.end();
    print_container_size(testMap2);
    print_container_content(it, ite);

    std::cout << std::endl << "Map2 Map1 swap " << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    testMap2.swap(testMap);
    std::cout << std::endl << "Map2 " << std::endl;
    it = testMap2.begin();
    ite = testMap2.end();
    print_container_size(testMap2);
    print_container_content(it, ite);

    std::cout << std::endl << "Map1 " << std::endl;
    it = testMap.begin();
    ite = testMap.end();
    print_container_size(testMap);
    print_container_content(it, ite);

    std::cout << "MAP1 ERASE 3 -- > " << testMap.erase(3) << std::endl;
    print_container_size(testMap);
    print_container_content(it, ite);
    std::cout << "MAP1 ERASE 3 -- > " << testMap.erase(3) << std::endl;
    print_container_size(testMap);
    print_container_content(it, ite);

    testMap.erase(testMap.begin(), ++(++testMap.begin()));
    std::cout << "MAP1 ERASE begin(), begin() + 2 "<< std::endl;
    it = testMap.begin();
    ite = testMap.end();
    print_container_size(testMap);
    print_container_content(it, ite);

    testMap.erase(++(++testMap.begin()), --testMap.end());
    std::cout << "MAP1 ERASE begin() + 3 , end() - 1 "<< std::endl;
    it = testMap.begin();
    ite = testMap.end();
    print_container_size(testMap);
    print_container_content(it, ite);

    testMap.erase(++testMap.begin());
    std::cout << "MAP1 ERASE begin() + 1 "<< std::endl;
    it = testMap.begin();
    ite = testMap.end();
    print_container_size(testMap);
    print_container_content(it, ite);


    std::cout << std::endl << "Map2 Map1 ft::swap " << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    TEST_NAMESPACE::swap(testMap2, testMap);
    
    std::cout << std::endl << "Map2 " << std::endl;
    it = testMap2.begin();
    ite = testMap2.end();
    print_container_size(testMap2);
    print_container_content(it, ite);

    std::cout << std::endl << "Map1 " << std::endl;
    it = testMap.begin();
    ite = testMap.end();
    print_container_size(testMap);
    print_container_content(it, ite);

    std::cout << "MAP1 clear() "<< std::endl;
    testMap.clear();
    it = testMap.begin();
    ite = testMap.end();
    print_container_size(testMap);
    print_container_content(it, ite);

    return 0;
}
