#include "../../inc/map.hpp"
#include <map>
#include <cstdlib>


int main(int argc, char **argv)
{
    if(argc != 1)
    {      
        const long SIZE = 10000000;

        if(argv[1] == std::string("ft"))
        {
            #define TEST_NAMESPACE ft
        }
        else if (argv[1] == std::string("std"))
        {
            #ifndef TEST_NAMESPACE
             #define TEST_NAMESPACE std
            #endif
        }
        TEST_NAMESPACE::map<int, int> testMap;

        for(int i = 0; i < SIZE; ++i)
        {
            testMap.insert(ft::make_pair(i, i+1));
        }
        testMap.erase(testMap.begin(), testMap.end());
        return 0;
    }
    std::cout << "Pleaes Include Namespace as the argument .." << std::endl;
  
}
