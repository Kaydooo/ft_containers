
#include "print.hpp"
#include <cstdlib>

#ifdef STD
#define TEST_NAMESPACE std
#include <vector>
#endif

#ifdef FT
#define TEST_NAMESPACE ft
#include "vector.hpp"
#endif

#ifndef TEST_NAMESPACE
#define TEST_NAMESPACE ft
#include "vector.hpp"
#endif

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;
    TEST_NAMESPACE::vector<char> testVector;
    TEST_NAMESPACE::vector<char>::const_iterator it;
    TEST_NAMESPACE::vector<char>::const_iterator ite;

    for(char c = 'a' ; c <= 'z' ; ++c)
        testVector.push_back(c);

    it = testVector.begin();
    ite = testVector.end();
    print_container_size(testVector);
    print_container_content(it, ite);

    std::cout << "vec[0] = "  << testVector[0] << " | "<< " vec[20] = " << testVector[20] << std::endl ;
    std::cout << "at 5 = "  << testVector.at(5) << " | "<< "at 20 = " << testVector.at(20) << std::endl ;
    try
    {
        std::cout << "at 50 = "  << testVector.at(50) << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << std::endl << "Out of range !!!" << std::endl;
    }

    std::cout << "front = "  << testVector.front() << " | "<< "back = " << testVector.back() << std::endl ;

    char* a = testVector.data();

    a[10] = 'z';
    print_container_size(testVector);
    print_container_content(it, ite);


    return 0;
  
}
