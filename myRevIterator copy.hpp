#ifndef MYREVITERATOR_HPP
#define MYREVITERATOR_HPP

#include <exception>
#include <stdexcept> 
#include <memory>
#include <cstddef>
#include <algorithm>
#include <iostream>
#include "myIterator.hpp"


namespace   ft
{
    /* reverse_Iterator Categaorie Tags */




    /* My reverse_Iterator Class */
    template <class T>
    class   reverse_Iterator
    {
        public:
            typedef  T valuetype;
            typedef  T* pointer_type;
            typedef  T& reference_type;
            typedef  ptrdiff_t difference_type;
            typedef  random_access_iterator_tag iterator_category;

            // using value_type = vector::value_type;
            // using pointer_type = vector::pointer;
            // using reference_type = vector::reference;
            // using difference_type = vector::difference_type;
            // using iterator_category = random_access_iterator_tag;

            reverse_Iterator(void): itPtr(NULL){}
            reverse_Iterator(pointer_type ptr): itPtr(ptr){}
            reverse_Iterator(Iterator<T> it): itPtr(it.getPtr()) {}
            template <typename U>
            reverse_Iterator(const reverse_Iterator<U>& other): itPtr(other.getPtr()){}

            reverse_Iterator&   operator=(const reverse_Iterator& rhs)
            {
                this->itPtr = rhs.itPtr;
                return (*this);
            }

            Iterator<T> base()const {
                return (itPtr);
            }	
            pointer_type getPtr() const
            { return (this->itPtr); }

            reference_type operator*() const 
            { 			
			    return (*(itPtr - 1));
            }
            pointer_type operator->() { return (itPtr - 1); }

            // Prefix increment
            reverse_Iterator& operator++() { --itPtr; return *this; }  

            // Postfix increment
            reverse_Iterator operator++(int) { reverse_Iterator tmp = *this; ++(*this); return tmp; }
            
            // Prefix dec
            reverse_Iterator& operator--() { ++itPtr; return *this; }  

            // Postfix dec
            reverse_Iterator operator--(int) { reverse_Iterator tmp = *this; --(*this); return tmp; }

            reverse_Iterator    operator+(difference_type n) const { return (itPtr - n); }
			// reverse_Iterator& operator+(difference_type num) {
			// 	reverse_Iterator temp;
            //     temp.itPtr = itPtr + num;
			// 	return (temp);
			// }	
            reverse_Iterator    operator-(difference_type n) const { return (itPtr + n); }
			// reverse_Iterator& operator-(difference_type num) {
			// 	reverse_Iterator temp;
            //     temp.itPtr = itPtr - num;
			// 	return (temp);
			// }
            
			reverse_Iterator& operator+=(difference_type num) {
				itPtr = itPtr - num;
				return (*this);
			}	
			
			reverse_Iterator& operator-=(difference_type num) {
				itPtr = itPtr + num;
				return (*this);
			}

            valuetype& operator[](difference_type num) {
				return (*(itPtr - num - 1));
			}

        private:
            pointer_type    itPtr;
    };

    /*  
        Operators Overload == , != , > , < , >= , <= , - , +  
        We used template so these overloads can work with iterators and const_interators
    */
    template<typename T>
    bool  operator==(const ft::reverse_Iterator<T> lhs, const ft::reverse_Iterator<T> rhs){ return (lhs.getPtr() == rhs.getPtr()); }
    template<typename T1, typename T2>
    bool operator==(const ft::reverse_Iterator<T1> lhs, const ft::reverse_Iterator<T2> rhs){ return (lhs.getPtr() == rhs.getPtr()); }

    template<typename T>
    bool  operator!=(const ft::reverse_Iterator<T> lhs, const ft::reverse_Iterator<T> rhs){ return (lhs.getPtr() != rhs.getPtr()); }
    template<typename T1, typename T2>
    bool operator!=(const ft::reverse_Iterator<T1> lhs, const ft::reverse_Iterator<T2> rhs){ return (lhs.getPtr() != rhs.getPtr()); }
    
    template<typename T>
    bool  operator>(const ft::reverse_Iterator<T> lhs, const ft::reverse_Iterator<T> rhs){ return (lhs.getPtr() < rhs.getPtr()); }
    template<typename T1, typename T2>
    bool operator>(const ft::reverse_Iterator<T1> lhs, const ft::reverse_Iterator<T2> rhs){ return (lhs.getPtr() < rhs.getPtr()); }

    template<typename T>
    bool  operator<(const ft::reverse_Iterator<T> lhs, const ft::reverse_Iterator<T> rhs){ return (lhs.getPtr() > rhs.getPtr()); }
    template<typename T1, typename T2>
    bool operator<(const ft::reverse_Iterator<T1> lhs, const ft::reverse_Iterator<T2> rhs){ return (lhs.getPtr() > rhs.getPtr()); }

    template<typename T>
    bool  operator>=(const ft::reverse_Iterator<T> lhs, const ft::reverse_Iterator<T> rhs){ return (lhs.getPtr() <= rhs.getPtr()); }
    template<typename T1, typename T2>
    bool operator>=(const ft::reverse_Iterator<T1> lhs, const ft::reverse_Iterator<T2> rhs){ return (lhs.getPtr() <= rhs.getPtr()); }

    template<typename T>
    bool  operator<=(const ft::reverse_Iterator<T> lhs, const ft::reverse_Iterator<T> rhs){ return (lhs.getPtr() >= rhs.getPtr()); }
    template<typename T1, typename T2>
    bool operator<=(const ft::reverse_Iterator<T1> lhs, const ft::reverse_Iterator<T2> rhs){ return (lhs.getPtr() >= rhs.getPtr()); }

    template<typename T>
    typename ft::reverse_Iterator<T>::difference_type operator-(const ft::reverse_Iterator<T> lhs, const ft::reverse_Iterator<T> rhs)
    {
        return (rhs.getPtr() - lhs.getPtr());
    }
    template<typename T1, typename T2>
    typename ft::reverse_Iterator<T1>::difference_type operator-(const ft::reverse_Iterator<T1> lhs, const ft::reverse_Iterator<T2> rhs)
    {
        return (rhs.getPtr() - lhs.getPtr());
    }
    template<typename T>
    typename ft::reverse_Iterator<T>::difference_type operator+(const ft::reverse_Iterator<T> lhs, const ft::reverse_Iterator<T> rhs)
    {
        return (lhs.getPtr() + rhs.getPtr());
    }
    template<typename T1, typename T2>
    typename ft::reverse_Iterator<T1>::difference_type operator+(const ft::reverse_Iterator<T1> lhs, const ft::reverse_Iterator<T2> rhs)
    {
        return (lhs.getPtr() + rhs.getPtr());
    }

    template<typename T> ft::reverse_Iterator<T> operator+(
        typename ft::reverse_Iterator<T>::difference_type x,
        typename ft::reverse_Iterator<T>& rhs)
        {
            return (rhs + x);
        }
    

}


#endif