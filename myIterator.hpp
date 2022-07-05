#ifndef MYITERATOR_HPP
#define MYITERATOR_HPP

#include <exception>
#include <stdexcept> 
#include <memory>
#include <cstddef>
#include <algorithm>
#include <iostream>


namespace   ft
{
    /* Iterator Categaorie Tags */
    struct input_iterator_tag{};
    struct output_iterator_tag{};
    struct forward_iterator_tag: public input_iterator_tag{};
    struct bidirectional_iterator_tag: public forward_iterator_tag{};
    struct random_access_iterator_tag: public bidirectional_iterator_tag{};




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

            // using value_type = vector::value_type;
            // using pointer_type = vector::pointer;
            // using reference_type = vector::reference;
            // using difference_type = vector::difference_type;
            // using iterator_category = random_access_iterator_tag;

            Iterator(void): itPtr(NULL){}
            Iterator(pointer_type ptr): itPtr(ptr){}
            template <typename U>
            Iterator(const Iterator<U>& other): itPtr(other.getPtr()){}

            Iterator&   operator=(const Iterator& rhs)
            {
                this->itPtr = rhs.itPtr;
                return (*this);
            }

            pointer_type getPtr() const
            { return (this->itPtr); }

            reference_type operator*() const { return *itPtr; }
            pointer_type operator->() { return itPtr; }

            // Prefix increment
            Iterator& operator++() { itPtr++; return *this; }  

            // Postfix increment
            Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
            
            // Prefix dec
            Iterator& operator--() { itPtr--; return *this; }  

            // Postfix dec
            Iterator operator--(int) { Iterator tmp = *this; --(*this); return tmp;}

            Iterator    operator+(difference_type n) const { return (itPtr + n); }
			// Iterator& operator+(difference_type num) {
			// 	Iterator temp;
            //     temp.itPtr = itPtr + num;
			// 	return (temp);
			// }	
            Iterator    operator-(difference_type n) const { return (itPtr - n); }
			// Iterator& operator-(difference_type num) {
			// 	Iterator temp;
            //     temp.itPtr = itPtr - num;
			// 	return (temp);
			// }
            
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

    /*  
        Operators Overload == , != , > , < , >= , <= , - , +  
        We used template so these overloads can work with iterators and const_interators
    */
    template<typename T>
    bool  operator==(const ft::Iterator<T> lhs, const ft::Iterator<T> rhs){ return (lhs.getPtr() == rhs.getPtr()); }
    template<typename T1, typename T2>
    bool operator==(const ft::Iterator<T1> lhs, const ft::Iterator<T2> rhs){ return (lhs.getPtr() == rhs.getPtr()); }

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
    {
        return (lhs.getPtr() - rhs.getPtr());
    }
    template<typename T1, typename T2>
    typename ft::Iterator<T1>::difference_type operator-(const ft::Iterator<T1> lhs, const ft::Iterator<T2> rhs)
    {
        return (lhs.getPtr() - rhs.getPtr());
    }
    template<typename T>
    typename ft::Iterator<T>::difference_type operator+(const ft::Iterator<T> lhs, const ft::Iterator<T> rhs)
    {
        return (lhs.getPtr() + rhs.getPtr());
    }
    template<typename T1, typename T2>
    typename ft::Iterator<T1>::difference_type operator+(const ft::Iterator<T1> lhs, const ft::Iterator<T2> rhs)
    {
        return (lhs.getPtr() + rhs.getPtr());
    }

    template<typename T> ft::Iterator<T> operator+(
        typename ft::Iterator<T>::difference_type x,
        typename ft::Iterator<T>& rhs)
        {
            return (&(*rhs) + x);
        }
    template<class InputIterator>
    size_t distance(InputIterator first, InputIterator last)
    {
        size_t i = 0;
        while (first != last)
        {
            i++;
            first++;
        }	
        return (i);
    }
}


#endif