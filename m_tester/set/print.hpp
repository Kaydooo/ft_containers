#ifndef PRINT_HPP
#define PRINT_HPP

#include <iostream>

template <typename container>
void    print_container_size(container &cont)
{
    std::cout << "Size = " << cont.size() << std::endl;
    std::cout << "empty() = " << cont.empty() << std::endl;
    // std::cout << "max_size = " << cont.max_size() << std::endl;
}

template <typename Iterator>
void    print_container_content(Iterator &first, Iterator &last)
{
    Iterator    it;
    std::cout << "Content : " << std::endl;
    for(it = first ; it != last; ++it)
        std::cout << "Key = " << *it << std::endl;
    std::cout << "---------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
}

#endif