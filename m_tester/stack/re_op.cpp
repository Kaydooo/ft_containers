
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
    TEST_NAMESPACE::stack<char> testStack;
    


    for(char c = 'a'; c < 'g' ; ++c)
        testStack.push(c);

    std::cout << std::endl << "Stack 1 a to f" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    print_container_size(testStack);
    std::cout << "top = " << testStack.top() << std::endl;

    TEST_NAMESPACE::stack<char> testStack2(testStack);
    std::cout << std::endl << "Stack 2 copy of Stack 1" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    print_container_size(testStack2);
    std::cout << "top = " << testStack2.top() << std::endl;


    std::cout << "STACK2 == STACK1  " << (testStack2 == testStack) << std ::endl;
    std::cout << "STACK2 != STACK1  " << (testStack2 != testStack) << std ::endl;
    std::cout << "STACK2 <= STACK1  " << (testStack2 <= testStack) << std ::endl;
    std::cout << "STACK2 >= STACK1  " << (testStack2 >= testStack) << std ::endl;
    std::cout << "STACK2 >  STACK1  " << (testStack2 > testStack) << std ::endl;
    std::cout << "STACK2 <  STACK1  " << (testStack2 < testStack) << std ::endl;
    std::cout << std::endl << "Stack2 pop() twice" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    testStack2.pop();
    testStack2.pop();
    std::cout << std ::endl;
    std::cout << "STACK2 == STACK1  " << (testStack2 == testStack) << std ::endl;
    std::cout << "STACK2 != STACK1  " << (testStack2 != testStack) << std ::endl;
    std::cout << "STACK2 <= STACK1  " << (testStack2 <= testStack) << std ::endl;
    std::cout << "STACK2 >= STACK1  " << (testStack2 >= testStack) << std ::endl;
    std::cout << "STACK2 >  STACK1  " << (testStack2 > testStack) << std ::endl;
    std::cout << "STACK2 <  STACK1  " << (testStack2 < testStack) << std ::endl;
        std::cout << std::endl << "Stack 1 pop() three times" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    testStack.pop();
    testStack.pop();
    testStack.pop();
    std::cout << std ::endl;
    std::cout << "STACK2 == STACK1  " << (testStack2 == testStack) << std ::endl;
    std::cout << "STACK2 != STACK1  " << (testStack2 != testStack) << std ::endl;
    std::cout << "STACK2 <= STACK1  " << (testStack2 <= testStack) << std ::endl;
    std::cout << "STACK2 >= STACK1  " << (testStack2 >= testStack) << std ::endl;
    std::cout << "STACK2 >  STACK1  " << (testStack2 > testStack) << std ::endl;
    std::cout << "STACK2 <  STACK1  " << (testStack2 < testStack) << std ::endl;


    return 0;
  
}
