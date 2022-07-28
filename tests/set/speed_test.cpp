#include "../../inc/set.hpp"
#include <set>
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
        TEST_NAMESPACE::set<int> testSet;

        for(int i = 0; i < SIZE; ++i)
        {
            testSet.insert(i);
        }
        testSet.erase(testSet.begin(), testSet.end());
        return 0;
    }
    std::cout << "Pleaes Include Namespace as the argument .." << std::endl;
  
}
