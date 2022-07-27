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
            typedef  typename   Iterator::value_type         value_type;
            typedef  typename   Iterator::pointer_type      pointer_type;
            typedef  typename   Iterator::reference_type    reference_type;
            typedef  ptrdiff_t                              difference_type;
            typedef  typename Iterator::iterator_category             iterator_category;

            rbt_reverse_iterator(void): baseIterator(){}
            rbt_reverse_iterator(iterator_type it): baseIterator(it) {}
            template <typename U>
            rbt_reverse_iterator(const rbt_reverse_iterator<U>& other): baseIterator(other.base()){}

            rbt_reverse_iterator&   operator=(const rbt_reverse_iterator& rhs)
            {
                this->baseIterator = rhs.baseIterator;
                return (*this);
            }

            iterator_type base()const {
                return (baseIterator);
            }	

            reference_type operator*() const 
            { 			
                iterator_type temp = baseIterator;
			    return (*(--temp));
            }
            pointer_type operator->() const { return (&operator*()); }

            // Prefix increment
            rbt_reverse_iterator& operator++() { --baseIterator; return *this; }  

            // Postfix increment
            rbt_reverse_iterator operator++(int) { rbt_reverse_iterator tmp = *this; ++(*this); return tmp; }
            
            // Prefix dec
            rbt_reverse_iterator& operator--() { ++baseIterator; return *this; }  

            // Postfix dec
            rbt_reverse_iterator operator--(int) { rbt_reverse_iterator tmp = *this; --(*this); return tmp; }


        private:
            iterator_type    baseIterator;
    };

    /*  
        Operators Overload == , != , > , < , >= , <= , - , +  
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
    
    template<typename T>
    bool  operator>(const ft::rbt_reverse_iterator<T> lhs, const ft::rbt_reverse_iterator<T> rhs){ return (lhs.base() < rhs.base()); }
    template<typename T1, typename T2>
    bool operator>(const ft::rbt_reverse_iterator<T1> lhs, const ft::rbt_reverse_iterator<T2> rhs){ return (lhs.base() < rhs.base()); }

    template<typename T>
    bool  operator<(const ft::rbt_reverse_iterator<T> lhs, const ft::rbt_reverse_iterator<T> rhs){ return (lhs.base() > rhs.base()); }
    template<typename T1, typename T2>
    bool operator<(const ft::rbt_reverse_iterator<T1> lhs, const ft::rbt_reverse_iterator<T2> rhs){ return (lhs.base() > rhs.base()); }

    template<typename T>
    bool  operator>=(const ft::rbt_reverse_iterator<T> lhs, const ft::rbt_reverse_iterator<T> rhs){ return (lhs.base() <= rhs.base()); }
    template<typename T1, typename T2>
    bool operator>=(const ft::rbt_reverse_iterator<T1> lhs, const ft::rbt_reverse_iterator<T2> rhs){ return (lhs.base() <= rhs.base()); }

    template<typename T>
    bool  operator<=(const ft::rbt_reverse_iterator<T> lhs, const ft::rbt_reverse_iterator<T> rhs){ return (lhs.base() >= rhs.base()); }
    template<typename T1, typename T2>
    bool operator<=(const ft::rbt_reverse_iterator<T1> lhs, const ft::rbt_reverse_iterator<T2> rhs){ return (lhs.base() >= rhs.base()); }

    template<typename T>
    typename ft::rbt_reverse_iterator<T>::difference_type operator-(const ft::rbt_reverse_iterator<T> lhs, const ft::rbt_reverse_iterator<T> rhs)
    {
        return (rhs.base() - lhs.base());
    }
    template<typename T1, typename T2>
    typename ft::rbt_reverse_iterator<T1>::difference_type operator-(const ft::rbt_reverse_iterator<T1> lhs, const ft::rbt_reverse_iterator<T2> rhs)
    {
        return (rhs.base() - lhs.base());
    }
    template<typename T>
    typename ft::rbt_reverse_iterator<T>::difference_type operator+(const ft::rbt_reverse_iterator<T> lhs, const ft::rbt_reverse_iterator<T> rhs)
    {
        return (lhs.base() + rhs.base());
    }
    template<typename T1, typename T2>
    typename ft::rbt_reverse_iterator<T1>::difference_type operator+(const ft::rbt_reverse_iterator<T1> lhs, const ft::rbt_reverse_iterator<T2> rhs)
    {
        return (lhs.base() + rhs.base());
    }

    template<typename T> ft::rbt_reverse_iterator<T> operator+(
        typename ft::rbt_reverse_iterator<T>::difference_type x,
        typename ft::rbt_reverse_iterator<T>& rhs)
    {
        return (rhs + x);
    }
}

#endif