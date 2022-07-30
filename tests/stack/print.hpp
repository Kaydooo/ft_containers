#ifndef PRINT_HPP
#define PRINT_HPP

#include <iostream>

template <typename container>
void    print_container_size(container &cont)
{
    std::cout << "Size = " << cont.size() << std::endl;
    std::cout << "empty() = " << cont.empty() << std::endl;

}

#endif