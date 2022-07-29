#include "../../inc/vector.hpp"
#include <vector>
#include <cstdlib>


int main(int argc, char **argv)
{
    if(argc != 1)
    {     
        long SIZE;
        if(argc > 2)
            SIZE = atol(argv[2]);
        else
            SIZE = 10000000;
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
        TEST_NAMESPACE::vector<int> testVector;

        for(int i = 0; i < SIZE; ++i)
            testVector.push_back(i);
        testVector.erase(testVector.begin(), testVector.end());
        return 0;
    }
    std::cout << "Pleaes Include Namespace as the argument .." << std::endl;
  
}
