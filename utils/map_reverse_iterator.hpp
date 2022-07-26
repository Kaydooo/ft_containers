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
    class   map_reverse_Iterator
    {
        public:
            typedef  Iterator                               iterator_type;
            typedef  typename   Iterator::value_type         value_type;
            typedef  typename   Iterator::pointer_type      pointer_type;
            typedef  typename   Iterator::reference_type    reference_type;
            typedef  ptrdiff_t                              difference_type;
            typedef  typename Iterator::iterator_category             iterator_category;

            map_reverse_Iterator(void): baseIterator(){}
            map_reverse_Iterator(iterator_type it): baseIterator(it) {}
            template <typename U>
            map_reverse_Iterator(const map_reverse_Iterator<U>& other): baseIterator(other.base()){}

            map_reverse_Iterator&   operator=(const map_reverse_Iterator& rhs)
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
            map_reverse_Iterator& operator++() { --baseIterator; return *this; }  

            // Postfix increment
            map_reverse_Iterator operator++(int) { map_reverse_Iterator tmp = *this; ++(*this); return tmp; }
            
            // Prefix dec
            map_reverse_Iterator& operator--() { ++baseIterator; return *this; }  

            // Postfix dec
            map_reverse_Iterator operator--(int) { map_reverse_Iterator tmp = *this; --(*this); return tmp; }


        private:
            iterator_type    baseIterator;
    };

    /*  
        Operators Overload == , != , > , < , >= , <= , - , +  
        We used template so these overloads can work with iterators and const_interators
    */
    template<typename T>
    bool  operator==(const ft::map_reverse_Iterator<T> lhs, const ft::map_reverse_Iterator<T> rhs){ return (lhs.base() == rhs.base()); }
    template<typename T1, typename T2>
    bool operator==(const ft::map_reverse_Iterator<T1> lhs, const ft::map_reverse_Iterator<T2> rhs){ return (lhs.base() == rhs.base()); }

    template<typename T>
    bool  operator!=(const ft::map_reverse_Iterator<T> lhs, const ft::map_reverse_Iterator<T> rhs){ return (lhs.base() != rhs.base()); }
    template<typename T1, typename T2>
    bool operator!=(const ft::map_reverse_Iterator<T1> lhs, const ft::map_reverse_Iterator<T2> rhs){ return (lhs.base() != rhs.base()); }
    
    template<typename T>
    bool  operator>(const ft::map_reverse_Iterator<T> lhs, const ft::map_reverse_Iterator<T> rhs){ return (lhs.base() < rhs.base()); }
    template<typename T1, typename T2>
    bool operator>(const ft::map_reverse_Iterator<T1> lhs, const ft::map_reverse_Iterator<T2> rhs){ return (lhs.base() < rhs.base()); }

    template<typename T>
    bool  operator<(const ft::map_reverse_Iterator<T> lhs, const ft::map_reverse_Iterator<T> rhs){ return (lhs.base() > rhs.base()); }
    template<typename T1, typename T2>
    bool operator<(const ft::map_reverse_Iterator<T1> lhs, const ft::map_reverse_Iterator<T2> rhs){ return (lhs.base() > rhs.base()); }

    template<typename T>
    bool  operator>=(const ft::map_reverse_Iterator<T> lhs, const ft::map_reverse_Iterator<T> rhs){ return (lhs.base() <= rhs.base()); }
    template<typename T1, typename T2>
    bool operator>=(const ft::map_reverse_Iterator<T1> lhs, const ft::map_reverse_Iterator<T2> rhs){ return (lhs.base() <= rhs.base()); }

    template<typename T>
    bool  operator<=(const ft::map_reverse_Iterator<T> lhs, const ft::map_reverse_Iterator<T> rhs){ return (lhs.base() >= rhs.base()); }
    template<typename T1, typename T2>
    bool operator<=(const ft::map_reverse_Iterator<T1> lhs, const ft::map_reverse_Iterator<T2> rhs){ return (lhs.base() >= rhs.base()); }

    template<typename T>
    typename ft::map_reverse_Iterator<T>::difference_type operator-(const ft::map_reverse_Iterator<T> lhs, const ft::map_reverse_Iterator<T> rhs)
    {
        return (rhs.base() - lhs.base());
    }
    template<typename T1, typename T2>
    typename ft::map_reverse_Iterator<T1>::difference_type operator-(const ft::map_reverse_Iterator<T1> lhs, const ft::map_reverse_Iterator<T2> rhs)
    {
        return (rhs.base() - lhs.base());
    }
    template<typename T>
    typename ft::map_reverse_Iterator<T>::difference_type operator+(const ft::map_reverse_Iterator<T> lhs, const ft::map_reverse_Iterator<T> rhs)
    {
        return (lhs.base() + rhs.base());
    }
    template<typename T1, typename T2>
    typename ft::map_reverse_Iterator<T1>::difference_type operator+(const ft::map_reverse_Iterator<T1> lhs, const ft::map_reverse_Iterator<T2> rhs)
    {
        return (lhs.base() + rhs.base());
    }

    template<typename T> ft::map_reverse_Iterator<T> operator+(
        typename ft::map_reverse_Iterator<T>::difference_type x,
        typename ft::map_reverse_Iterator<T>& rhs)
    {
        return (rhs + x);
    }
}

#endif