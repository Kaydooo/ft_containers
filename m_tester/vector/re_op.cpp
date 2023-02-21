
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
    const long SIZE = 5;
    TEST_NAMESPACE::vector<int> testVector;
    TEST_NAMESPACE::vector<int>::const_iterator it;
    TEST_NAMESPACE::vector<int>::const_iterator ite;

    for(int i = 0; i < SIZE; ++i)
        testVector.push_back(i);
    std::cout << "Vector 1" << std::endl;
    it = testVector.begin();
    ite = testVector.end();
    print_container_size(testVector);
    print_container_content(it, ite);

    TEST_NAMESPACE::vector<int> testVector2(testVector);
    std::cout << "Vector 2" << std::endl;
    it = testVector2.begin();
    ite = testVector2.end();
    print_container_size(testVector2);
    print_container_content(it, ite);

    TEST_NAMESPACE::vector<int> testVector3(5, 10);
    std::cout << "Vector 3    n = 5 , val = 10" << std::endl;
    it = testVector3.begin();
    ite = testVector3.end();
    print_container_size(testVector3);
    print_container_content(it, ite);

    std::cout << "VECT2 == VECT1  " << (testVector2 == testVector) << std ::endl;
    std::cout << "VECT2 != VECT1  " << (testVector2 != testVector) << std ::endl;
    std::cout << "VECT2 <= VECT1  " << (testVector2 <= testVector) << std ::endl;
    std::cout << "VECT2 >= VECT1  " << (testVector2 >= testVector) << std ::endl;
    std::cout << "VECT2 >  VECT1  " << (testVector2 > testVector) << std ::endl;
    std::cout << "VECT2 <  VECT1  " << (testVector2 < testVector) << std ::endl;
    std::cout << std ::endl;
    std::cout << "VECT3 == VECT1  " << (testVector3 == testVector) << std ::endl;
    std::cout << "VECT3 != VECT1  " << (testVector3 != testVector) << std ::endl;
    std::cout << "VECT3 <= VECT1  " << (testVector3 <= testVector) << std ::endl;
    std::cout << "VECT3 >= VECT1  " << (testVector3 >= testVector) << std ::endl;
    std::cout << "VECT3 >  VECT1  " << (testVector3 > testVector) << std ::endl;
    std::cout << "VECT3 <  VECT1  " << (testVector3 < testVector) << std ::endl;

    return 0;
  
}
