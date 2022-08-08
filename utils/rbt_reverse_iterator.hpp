/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt_reverse_iterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-guna <mal-guna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 19:05:52 by mal-guna          #+#    #+#             */
/*   Updated: 2022/08/08 19:05:52 by mal-guna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_REVERSE_ITERATOR_HPP
#define MAP_REVERSE_ITERATOR_HPP

#include <exception>
#include <stdexcept> 
#include <memory>
#include <cstddef>
#include <algorithm>
#include <iostream>
// #include "myIterator.hpp"


namespace   ft
{
    /* My reverse_Iterator Class */
    template <class Iterator>
    class   rbt_reverse_iterator
    {
        public:
            typedef  Iterator                               iterator_type;
            typedef  typename   Iterator::value_type        value_type;
            typedef  typename   Iterator::pointer_type      pointer_type;
            typedef  typename   Iterator::reference_type    reference_type;
            typedef  ptrdiff_t                              difference_type;
            typedef  typename Iterator::iterator_category   iterator_category;

            rbt_reverse_iterator(void): baseIterator(){}

            rbt_reverse_iterator(iterator_type it): baseIterator(it) {}

            template <typename U>
            rbt_reverse_iterator(const rbt_reverse_iterator<U>& other): baseIterator(other.base()){}

            rbt_reverse_iterator&   operator=(const rbt_reverse_iterator& rhs)
            {
                this->baseIterator = rhs.baseIterator;
                return (*this);
            }

            iterator_type base()const { return (baseIterator); }	

            reference_type operator*() const 
            { 			
                iterator_type temp = baseIterator;
			    return (*(--temp));
            }

            pointer_type operator->() const { return (&operator*()); }

            rbt_reverse_iterator& operator++() { --baseIterator; return *this; }  

            rbt_reverse_iterator operator++(int) { rbt_reverse_iterator tmp = *this; ++(*this); return tmp; }
            
            rbt_reverse_iterator& operator--() { ++baseIterator; return *this; }  

            rbt_reverse_iterator operator--(int) { rbt_reverse_iterator tmp = *this; --(*this); return tmp; }

        private:
            iterator_type    baseIterator;
    };

    /*  
        Operators Overload == , != 
        We used template so these overloads can work with iterators and const_interators
    */
    template<typename T>
    bool  operator==(const ft::rbt_reverse_iterator<T> lhs, const ft::rbt_reverse_iterator<T> rhs){ return (lhs.base() == rhs.base()); }
    template<typename T1, typename T2>
    bool operator==(const ft::rbt_reverse_iterator<T1> lhs, const ft::rbt_reverse_iterator<T2> rhs){ return (lhs.base() == rhs.base()); }

    template<typename T>
    bool  operator!=(const ft::rbt_reverse_iterator<T> lhs, const ft::rbt_reverse_iterator<T> rhs){ return (lhs.base() != rhs.base()); }
    template<typename T1, typename T2>
    bool operator!=(const ft::rbt_reverse_iterator<T1> lhs, const ft::rbt_reverse_iterator<T2> rhs){ return (lhs.base() != rhs.base()); }
    
} // end of namespace ft

#endif