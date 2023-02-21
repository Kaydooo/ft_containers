
#include "print.hpp"
#include <cstdlib>

#ifdef STD
#define TEST_NAMESPACE std
#include <map>
#endif

#ifdef FT
#define TEST_NAMESPACE ft
#include "map.hpp"
#endif

#ifndef TEST_NAMESPACE
#define TEST_NAMESPACE ft
#include "map.hpp"
#endif

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;
    TEST_NAMESPACE::map<char, char> testMap;
    TEST_NAMESPACE::map<char, char>::const_iterator it;
    TEST_NAMESPACE::map<char, char>::const_iterator ite;

    


    for(char c = 'a'; c < 'g' ; ++c)
        testMap.insert(TEST_NAMESPACE::make_pair(c, c + 2));

    std::cout << std::endl << "Map 1 a to f" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    it = testMap.begin();
    ite = testMap.end();
    print_container_size(testMap);
    print_container_content(it, ite);

    std::cout << std::endl << "Map 2 Copy Constructor Map1" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    TEST_NAMESPACE::map<char, char> testMap2(testMap);

    std::cout << "MAP2 == MAP1  " << (testMap2 == testMap) << std ::endl;
    std::cout << "MAP2 != MAP1  " << (testMap2 != testMap) << std ::endl;
    std::cout << "MAP2 <= MAP1  " << (testMap2 <= testMap) << std ::endl;
    std::cout << "MAP2 >= MAP1  " << (testMap2 >= testMap) << std ::endl;
    std::cout << "MAP2 >  MAP1  " << (testMap2 > testMap) << std ::endl;
    std::cout << "MAP2 <  MAP1  " << (testMap2 < testMap) << std ::endl;
    std::cout << std::endl << "Map2 remove end() - 1 " << std::endl;
    std::cout << "------------------------------------------" << std::endl;

    testMap2.erase(--testMap2.end());
    std::cout << std ::endl;

    std::cout << "MAP2 == MAP1  " << (testMap2 == testMap) << std ::endl;
    std::cout << "MAP2 != MAP1  " << (testMap2 != testMap) << std ::endl;
    std::cout << "MAP2 <= MAP1  " << (testMap2 <= testMap) << std ::endl;
    std::cout << "MAP2 >= MAP1  " << (testMap2 >= testMap) << std ::endl;
    std::cout << "MAP2 >  MAP1  " << (testMap2 > testMap) << std ::endl;
    std::cout << "MAP2 <  MAP1  " << (testMap2 < testMap) << std ::endl;
    std::cout << std::endl << "Map 1 erase begin()" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    testMap.erase(testMap.begin());
    std::cout << std ::endl;

    std::cout << "MAP2 == MAP1  " << (testMap2 == testMap) << std ::endl;
    std::cout << "MAP2 != MAP1  " << (testMap2 != testMap) << std ::endl;
    std::cout << "MAP2 <= MAP1  " << (testMap2 <= testMap) << std ::endl;
    std::cout << "MAP2 >= MAP1  " << (testMap2 >= testMap) << std ::endl;
    std::cout << "MAP2 >  MAP1  " << (testMap2 > testMap) << std ::endl;
    std::cout << "MAP2 <  MAP1  " << (testMap2 < testMap) << std ::endl;

    std::cout << std::endl << "Map 2 erase begin(), begin()  + 1 , Map 1 erase end() - 1" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    testMap2.erase(testMap2.begin(), ++testMap2.begin());
    testMap.erase(--testMap.end());
    std::cout << std ::endl;
    std::cout << "MAP2 == MAP1  " << (testMap2 == testMap) << std ::endl;
    std::cout << "MAP2 != MAP1  " << (testMap2 != testMap) << std ::endl;
    std::cout << "MAP2 <= MAP1  " << (testMap2 <= testMap) << std ::endl;
    std::cout << "MAP2 >= MAP1  " << (testMap2 >= testMap) << std ::endl;
    std::cout << "MAP2 >  MAP1  " << (testMap2 > testMap) << std ::endl;
    std::cout << "MAP2 <  MAP1  " << (testMap2 < testMap) << std ::endl;


    return 0;
  
}
