#include "print.hpp"
#include <cstdlib>

#ifdef STD
#define TEST_NAMESPACE std
#include <stack>
#endif

#ifdef FT
#define TEST_NAMESPACE ft
#include "stack.hpp"
#endif

#ifndef TEST_NAMESPACE
#define TEST_NAMESPACE ft
#include "stack.hpp"
#endif

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;
    const long SIZE = 5;
    TEST_NAMESPACE::stack<int> testStack;

    for(int i = 0; i < SIZE; ++i)
        testStack.push(i);
    std::cout << std::endl << "Stack 1 push 0 to 4" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    print_container_size(testStack);
    std::cout << "top = " << testStack.top() << std::endl;

    std::cout << std::endl << "Stack 1 pop 2 times" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    testStack.pop();
    testStack.pop();
    std::cout << "top = " << testStack.top() << std::endl;
    print_container_size(testStack);

    std::cout << std::endl << "Stack 1 pop 4 times" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    testStack.pop();
    testStack.pop();
    std::cout << "top = " << testStack.top() << std::endl;
    print_container_size(testStack);

    return 0;
}
