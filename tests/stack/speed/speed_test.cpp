#include "../../../inc/vector.hpp"
#include <vector>
#include <utility>
#include <cstdlib>


int main(int argc, char **argv)
{
    if(argc != 1)
    {      
        const long SIZE = 1000000;

        if(argv[1] == std::string("ft"))
        {
            #define TEST_NAMESPACE ft
            std::cout << "FT TEST for " << SIZE << " NUMBERS" << std ::endl;
        }
        else if (argv[1] == std::string("std"))
        {
            #ifndef TEST_NAMESPACE
             #define TEST_NAMESPACE std
             #endif
            std::cout << "STD TEST" << SIZE << " NUMBERS" << std ::endl;
        }
        TEST_NAMESPACE::vector<int> testMap;

        for(int i = 0; i < SIZE; ++i)
        {
            testMap.push_back(i);
        }
        std::cout << "Insertion Completed ! " << std::endl;
        std::cout << "Size before Deletion = " << testMap.size() << std::endl;
        testMap.erase(testMap.begin(), testMap.end());
        std::cout << "Size after Deletion = " << testMap.size() << std::endl;
        return 0;
    }
    std::cout << "Pleaes Include Namespace as the argument .." << std::endl;
  
}
