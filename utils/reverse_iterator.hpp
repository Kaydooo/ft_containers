/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-guna <mal-guna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 19:06:00 by mal-guna          #+#    #+#             */
/*   Updated: 2022/08/08 19:06:00 by mal-guna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <exception>
#include <stdexcept> 
#include <memory>
#include <cstddef>
#include <algorithm>
#include <iostream>

namespace   ft
{
    /* My reverse_Iterator Class */
    template <class Iterator>
    class   reverse_Iterator
    {
        public:
            typedef  Iterator                               iterator_type;
            typedef  typename   Iterator::value_type        value_type;
            typedef  typename   Iterator::pointer           pointer;
            typedef  typename   Iterator::reference         reference;
            typedef  ptrdiff_t                              difference_type;
            typedef  typename Iterator::iterator_category   iterator_category;

            reverse_Iterator(void): baseIterator(NULL){}

            reverse_Iterator(iterator_type it): baseIterator(it) {}
            
            template <typename U>
            reverse_Iterator(const reverse_Iterator<U>& other): baseIterator(other.base()){}

            reverse_Iterator&   operator=(const reverse_Iterator& rhs)
            {
                this->baseIterator = rhs.baseIterator;
                return (*this);
            }

            iterator_type base()const {
                return (baseIterator);
            }	

            reference operator*() const 
            { 			
			    return (*(baseIterator - 1));
            }
            pointer operator->() { return (&operator*()); }

            // Prefix increment
            reverse_Iterator& operator++() { --baseIterator; return *this; }  

            // Postfix increment
            reverse_Iterator operator++(int) { reverse_Iterator tmp = *this; ++(*this); return tmp; }
            
            // Prefix dec
            reverse_Iterator& operator--() { ++baseIterator; return *this; }  

            // Postfix dec
            reverse_Iterator operator--(int) { reverse_Iterator tmp = *this; --(*this); return tmp; }

            reverse_Iterator    operator+(difference_type n) const { return (baseIterator - n); }

            reverse_Iterator    operator-(difference_type n) const { return (baseIterator + n); }
            
			reverse_Iterator& operator+=(difference_type num) {
				baseIterator = baseIterator - num;
				return (*this);
			}	
			
			reverse_Iterator& operator-=(difference_type num) {
				baseIterator = baseIterator + num;
				return (*this);
			}

            value_type& operator[](difference_type num) {
				return (*(baseIterator - num - 1));
			}

        private:
            iterator_type    baseIterator;
    };

    template<typename T>
    bool  operator==(const ft::reverse_Iterator<T> lhs, const ft::reverse_Iterator<T> rhs){ return (lhs.base() == rhs.base()); }
    template<typename T1, typename T2>
    bool operator==(const ft::reverse_Iterator<T1> lhs, const ft::reverse_Iterator<T2> rhs){ return (lhs.base() == rhs.base()); }

    template<typename T>
    bool  operator!=(const ft::reverse_Iterator<T> lhs, const ft::reverse_Iterator<T> rhs){ return (lhs.base() != rhs.base()); }
    template<typename T1, typename T2>
    bool operator!=(const ft::reverse_Iterator<T1> lhs, const ft::reverse_Iterator<T2> rhs){ return (lhs.base() != rhs.base()); }
    
    template<typename T>
    bool  operator>(const ft::reverse_Iterator<T> lhs, const ft::reverse_Iterator<T> rhs){ return (lhs.base() < rhs.base()); }
    template<typename T1, typename T2>
    bool operator>(const ft::reverse_Iterator<T1> lhs, const ft::reverse_Iterator<T2> rhs){ return (lhs.base() < rhs.base()); }

    template<typename T>
    bool  operator<(const ft::reverse_Iterator<T> lhs, const ft::reverse_Iterator<T> rhs){ return (lhs.base() > rhs.base()); }
    template<typename T1, typename T2>
    bool operator<(const ft::reverse_Iterator<T1> lhs, const ft::reverse_Iterator<T2> rhs){ return (lhs.base() > rhs.base()); }

    template<typename T>
    bool  operator>=(const ft::reverse_Iterator<T> lhs, const ft::reverse_Iterator<T> rhs){ return (lhs.base() <= rhs.base()); }
    template<typename T1, typename T2>
    bool operator>=(const ft::reverse_Iterator<T1> lhs, const ft::reverse_Iterator<T2> rhs){ return (lhs.base() <= rhs.base()); }

    template<typename T>
    bool  operator<=(const ft::reverse_Iterator<T> lhs, const ft::reverse_Iterator<T> rhs){ return (lhs.base() >= rhs.base()); }
    template<typename T1, typename T2>
    bool operator<=(const ft::reverse_Iterator<T1> lhs, const ft::reverse_Iterator<T2> rhs){ return (lhs.base() >= rhs.base()); }

    template<typename T>
    typename ft::reverse_Iterator<T>::difference_type operator-(const ft::reverse_Iterator<T> lhs, const ft::reverse_Iterator<T> rhs)
    { return (rhs.base() - lhs.base()); }

    template<typename T1, typename T2>
    typename ft::reverse_Iterator<T1>::difference_type operator-(const ft::reverse_Iterator<T1> lhs, const ft::reverse_Iterator<T2> rhs)
    { return (rhs.base() - lhs.base()); }

    template<typename T>
    typename ft::reverse_Iterator<T>::difference_type operator+(const ft::reverse_Iterator<T> lhs, const ft::reverse_Iterator<T> rhs)
    { return (lhs.base() + rhs.base()); }

    template<typename T1, typename T2>
    typename ft::reverse_Iterator<T1>::difference_type operator+(const ft::reverse_Iterator<T1> lhs, const ft::reverse_Iterator<T2> rhs)
    { return (lhs.base() + rhs.base()); }

    template<typename T> ft::reverse_Iterator<T> operator+(
        typename ft::reverse_Iterator<T>::difference_type x,
        typename ft::reverse_Iterator<T>& rhs)
    { return (rhs + x); }
}

#endif
