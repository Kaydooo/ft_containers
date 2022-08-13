/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-guna <mal-guna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 19:05:22 by mal-guna          #+#    #+#             */
/*   Updated: 2022/08/08 19:05:22 by mal-guna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYITERATOR_HPP
#define MYITERATOR_HPP

#include <exception>
#include <stdexcept> 
#include <memory>
#include <cstddef>
#include <algorithm>
#include <iostream>
#include "container_utils.hpp"

namespace   ft
{

    /* My Iterator Class */
    template <class T>
    class   Iterator
    {
        public:
            typedef  T valuetype;
            typedef  T* pointer_type;
            typedef  T& reference_type;
            typedef  std::ptrdiff_t difference_type;
            typedef  random_access_iterator_tag iterator_category;

            Iterator(void): itPtr(NULL){}
            Iterator(pointer_type ptr): itPtr(ptr){}
            template <typename U>
            Iterator(const Iterator<U>& other): itPtr(other.getPtr()){}
            Iterator&   operator=(const Iterator& rhs)
            {
                this->itPtr = rhs.itPtr;
                return (*this);
            }

            
            pointer_type getPtr() const { return (this->itPtr); }

            reference_type operator*() const { return *itPtr; }

            pointer_type operator->() { return itPtr; }

            Iterator& operator++() { itPtr++; return *this; }  

            Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
            
            Iterator& operator--() { itPtr--; return *this; }  
            
            Iterator operator--(int) { Iterator tmp = *this; --(*this); return tmp; }

            Iterator    operator+(difference_type n) const { return (itPtr + n); }

            Iterator    operator-(difference_type n) const { return (itPtr - n); }
            
			Iterator& operator+=(difference_type num) {
				itPtr = itPtr + num;
				return (*this);
			}	
			
			Iterator& operator-=(difference_type num) {
				itPtr = itPtr - num;
				return (*this);
			}

            valuetype& operator[](difference_type num) {
				return (*(itPtr + num));
			}

        private:
            pointer_type    itPtr;
    };

    template<typename T>
    typename ft::Iterator<T>::difference_type  operator==(const ft::Iterator<T> lhs, const ft::Iterator<T> rhs){ return (lhs.getPtr() == rhs.getPtr()); }
    template<typename T1, typename T2>
    typename ft::Iterator<T1>::difference_type operator==(const ft::Iterator<T1> lhs, const ft::Iterator<T2> rhs){ return (lhs.getPtr() == rhs.getPtr()); }

    template<typename T>
    bool  operator!=(const ft::Iterator<T> lhs, const ft::Iterator<T> rhs){ return (lhs.getPtr() != rhs.getPtr()); }
    template<typename T1, typename T2>
    bool operator!=(const ft::Iterator<T1> lhs, const ft::Iterator<T2> rhs){ return (lhs.getPtr() != rhs.getPtr()); }
    
    template<typename T>
    bool  operator>(const ft::Iterator<T> lhs, const ft::Iterator<T> rhs){ return (lhs.getPtr() > rhs.getPtr()); }
    template<typename T1, typename T2>
    bool operator>(const ft::Iterator<T1> lhs, const ft::Iterator<T2> rhs){ return (lhs.getPtr() > rhs.getPtr()); }

    template<typename T>
    bool  operator<(const ft::Iterator<T> lhs, const ft::Iterator<T> rhs){ return (lhs.getPtr() < rhs.getPtr()); }
    template<typename T1, typename T2>
    bool operator<(const ft::Iterator<T1> lhs, const ft::Iterator<T2> rhs){ return (lhs.getPtr() < rhs.getPtr()); }

    template<typename T>
    bool  operator>=(const ft::Iterator<T> lhs, const ft::Iterator<T> rhs){ return (lhs.getPtr() >= rhs.getPtr()); }
    template<typename T1, typename T2>
    bool operator>=(const ft::Iterator<T1> lhs, const ft::Iterator<T2> rhs){ return (lhs.getPtr() >= rhs.getPtr()); }

    template<typename T>
    bool  operator<=(const ft::Iterator<T> lhs, const ft::Iterator<T> rhs){ return (lhs.getPtr() <= rhs.getPtr()); }
    template<typename T1, typename T2>
    bool operator<=(const ft::Iterator<T1> lhs, const ft::Iterator<T2> rhs){ return (lhs.getPtr() <= rhs.getPtr()); }

    template<typename T>
    typename ft::Iterator<T>::difference_type operator-(const ft::Iterator<T> lhs, const ft::Iterator<T> rhs)
    { return (lhs.getPtr() - rhs.getPtr()); }

    template<typename T1, typename T2>
    typename ft::Iterator<T1>::difference_type operator-(const ft::Iterator<T1> lhs, const ft::Iterator<T2> rhs)
    { return (lhs.getPtr() - rhs.getPtr()); }

    template<typename T>
    typename ft::Iterator<T>::difference_type operator+(const ft::Iterator<T> lhs, const ft::Iterator<T> rhs)
    { return (lhs.getPtr() + rhs.getPtr()); }

    template<typename T1, typename T2>
    typename ft::Iterator<T1>::difference_type operator+(const ft::Iterator<T1> lhs, const ft::Iterator<T2> rhs)
    { return (lhs.getPtr() + rhs.getPtr()); }

    template<typename T> ft::Iterator<T> operator+(typename ft::Iterator<T>::difference_type x, typename ft::Iterator<T>& rhs)
    { return (&(*rhs) + x); }
}


#endif
