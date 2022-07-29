#include "../../inc/vector.hpp"
#include <vector>
#include <cstdlib>

template <typename container>
void    print_container_size(container cont)
{
    std::cout << "Size = " << cont.size() << std::endl;
    std::cout << "Capacity = " << cont.capacity() << std::endl;
    std::cout << "max_size = " << cont.max_size() << std::endl;
}

template <typename Iterator>
void    print_container_content(Iterator first, Iterator last)
{
    Iterator    it;
    std::cout << "Content : " << std::endl;
    for(it = first ; it != last; ++it)
        std::cout << " * " << *it << std::endl;
}

int main(int argc, char **argv)
{
    if(argc != 1)
    {      
        const long SIZE = 10;

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
        std::cout << " Vector 1" << std::endl;
        print_container_size(testVector);
        print_container_content(testVector.begin(), testVector.end());

        TEST_NAMESPACE::vector<int> testVector2(testVector);
        std::cout << " Vector 2 , copy of Vector 1" << std::endl;

        print_container_size(testVector2);
        print_container_content(testVector2.begin(), testVector2.end());

        testVector2.insert(testVector2.begin(), testVector.begin(), testVector.end());
        std::cout << " Vector 2 after inserting vec1.begin() to vec1.end()" << std::endl;
        print_container_size(testVector2);
        print_container_content(testVector2.begin(), testVector2.end());

        testVector2.insert(testVector2.begin() + 3, testVector.begin(), testVector.begin() + 5);
        std::cout << " Vector 2 after inserting vec1.begin() to vec1.begin() + 5 into vec2.begin() + 3" << std::endl;
        print_container_size(testVector2);
        print_container_content(testVector2.begin(), testVector2.end());

        testVector.erase(testVector.begin(), testVector.end());
        std::cout << " Vector 1 after erasing from vec1.begin() to vec1.end()" << std::endl;
        print_container_size(testVector);


        return 0;
    }
    std::cout << "Pleaes Include Namespace as the argument .." << std::endl;
  
}
