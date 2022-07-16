/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-guna <mal-guna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 01:56:16 by mal-guna          #+#    #+#             */
/*   Updated: 2022/07/07 02:45:23 by mal-guna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
// #include <vector>
#include "myIterator.hpp"
#include "reverse_iterator.hpp"

#include <exception>
#include <stdexcept> 
#include <memory>
#include <cstddef>
#include <algorithm>
#include <iostream>

// #include <type_traits>


namespace ft
{
    struct false_type { static const bool value = false;};
    struct true_type { static const bool value = true;};

    template<bool B, class T = void>
    struct enable_if {};

    template<class T>
    struct enable_if<true, T> { typedef T type; };
    
    template <class T>   struct is_integral                     : public ft::false_type {};
    template <>          struct is_integral<bool>               : public ft::true_type {};
    template <>          struct is_integral<char>               : public ft::true_type {};
    template <>          struct is_integral<signed char>        : public ft::true_type {};
    template <>          struct is_integral<unsigned char>      : public ft::true_type {};
    template <>          struct is_integral<wchar_t>            : public ft::true_type {};
    template <>          struct is_integral<short>              : public ft::true_type {};
    template <>          struct is_integral<unsigned short>     : public ft::true_type {};
    template <>          struct is_integral<int>                : public ft::true_type {};
    template <>          struct is_integral<unsigned int>       : public ft::true_type {};
    template <>          struct is_integral<long>               : public ft::true_type {};
    template <>          struct is_integral<unsigned long>      : public ft::true_type {};
    template <>          struct is_integral<long long>          : public ft::true_type {};
    template <>          struct is_integral<unsigned long long> : public ft::true_type {};


    /* My Vector Class */
    template < class T, class Alloc = std::allocator<T> >
    class vector
    {
        public:
        //Typedefs for shorter and more readable code.
            typedef Alloc                               allocator_type;
            typedef T                                   value_type;
            typedef const value_type                    const_value_type;
            typedef typename allocator_type::reference           reference;
            typedef typename allocator_type::const_reference     const_reference;
            typedef typename allocator_type::pointer             pointer;
            typedef typename allocator_type::const_pointer       const_pointer;
            typedef ft::Iterator<value_type>                iterator;
            typedef ft::Iterator<const value_type>          const_iterator;
            typedef ft::reverse_Iterator<iterator>                reverse_iterator;
            typedef ft::reverse_Iterator<const_iterator>          const_reverse_iterator ;
            //reverse_it
            //const_reverse_it
            typedef typename allocator_type::difference_type     difference_type;
            typedef typename allocator_type::size_type           size_type;


            /* Default Constrctor */
            explicit vector (const allocator_type& alloc = allocator_type()): vectorAllocator(alloc), vectorData(NULL), vectorCapacity(0), vectorSize(0){}
            
            /* Fill Constrctor */
            explicit vector (size_type n, const value_type& val = value_type(),
                            const allocator_type& alloc = allocator_type()): vectorAllocator(alloc), vectorData(NULL), vectorCapacity(n), vectorSize(n)
            {
                this->vectorData = vectorAllocator.allocate(n);
                // todo: Try std::uninitialized_fill_n to construct the array
                pointer	temp = vectorData;
                for (size_type i = 0; i < n; i++)
                {
                    vectorAllocator.construct(temp, val);	
                    temp++;
                }
            }

            /* Range Constrctor */
            template <class InputIterator>
            vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL): vectorAllocator(alloc), vectorData(NULL), vectorCapacity(0), vectorSize(0)
            {
                // assign(first, last);
                difference_type diff = ft::distance(first, last); // use distance instead when implemented in iterator
                vectorData = vectorAllocator.allocate(diff);
                vectorSize = diff;
                vectorCapacity = diff;
                pointer	temp = vectorData;
                for (size_type i = 0; i < (size_type)diff; i++)
                {
                    vectorAllocator.construct(temp, *first);	
                    temp++;
                    first++;
                }

            }

            /* Copy Constrctor */
            vector (const vector& x): vectorAllocator(x.vectorAllocator), vectorData(NULL), vectorCapacity(0), vectorSize(0)
            {

                assign(x.begin(), x.end());
                // vectorAllocator = allocator_type();
                // vectorData = vectorAllocator.allocate(vectorCapacity);
                // pointer	temp = vectorData;
                // for (size_type i = 0; i < vectorSize; i++)
                // {
                //     vectorAllocator.construct(temp, x.vectorData[i]);	
                //     temp++;
                // }
                
            }
            
            /*  Destructor */
            ~vector()
            {
                //check if its empty here
                for(size_t i = 0; i < vectorSize; i++)
                    vectorAllocator.destroy(&vectorData[i]);
                vectorAllocator.deallocate(vectorData, vectorCapacity);
            }
            /* Assignment operator overload */

            vector& operator= (const vector& x)
            {
                // To be done..
                clear();
                assign(x.begin(), x.end());
                return (*this);
                
            };
            /*  */

        /* Iterators */
        
            iterator begin() { return iterator(vectorData); }
            iterator end()   { return iterator(vectorData + vectorSize); }
            const_iterator begin() const{ return const_iterator(vectorData); }
            const_iterator end() const { return const_iterator(vectorData + vectorSize); }
            
            reverse_iterator rbegin() { return reverse_iterator(end()); }
            reverse_iterator rend()   { return reverse_iterator(begin()); }
            const_reverse_iterator rbegin() const{ return const_reverse_iterator(end()); }
            const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }
        //////////////////// rbegin + rend To Be Done !//////////////////

        /* member functions (Capacity) */

        size_type   size() const { return (vectorSize); } 
        size_type   max_size() const { return (vectorAllocator.max_size()); }
        size_type   capacity() const { return (vectorCapacity); }
        bool        empty() const { return (vectorSize == 0); }
        
        void        reserve (size_type n)
        {
            if(n > max_size())
                return ;
            if(vectorCapacity < n)
            {
                pointer temp;
                temp = vectorAllocator.allocate(n);
                for(size_type i = 0; i < vectorSize; i++)
                    vectorAllocator.construct(&(temp[i]), vectorData[i]);
                
                for(size_type i = 0; i < vectorSize; i++)
                {
                    vectorAllocator.destroy(&(vectorData[i]));
                }
                vectorAllocator.deallocate(vectorData, vectorCapacity);
                vectorData = temp;
                vectorCapacity = n;
            }
            
        }

        void resize (size_type n, value_type val = value_type())
        {
            if(n != vectorSize)
            {
                if(n > vectorCapacity)
                {
                    if(n > vectorSize*2)
                        this->reserve(n);
                    else
                        this->reserve(vectorSize * 2);
                }
                if(n < vectorSize)
                {
                    for(size_type i = vectorSize - 1; i >= n  && i < vectorSize ; i--)
                        vectorAllocator.destroy(&vectorData[i]);
                }
                else
                {
                    for(size_type i = vectorSize; i < n; i++)
                    {
                        vectorAllocator.construct(&vectorData[i], val);
                    }
                }
                vectorSize = n;
            }
        }

        /* Element access */
        reference operator[] (size_type n){ return (vectorData[n]);}
        const_reference operator[] (size_type n) const{ return vectorData[n];}
        reference at (size_type n){
        
            if(n >= vectorSize)
                throw std::out_of_range("Out Of Range");
            return (vectorData[n]);    
        }
        const_reference at (size_type n) const
        { 
            if(n >= vectorSize)
                throw std::out_of_range("Out Of Range");
            return (vectorData[n]);   
        }
        reference front(){ return (vectorData[0]);}
        const_reference front() const{ return (vectorData[0]);}
        reference back(){ return (vectorData[vectorSize - 1]);}
        const_reference back() const{ return (vectorData[vectorSize - 1]);}
        
        /* Modifiers: */
        void clear()
        {
            this->resize(0);
        }
        
        // void    destroy(void)
        // {
        //     for(size_t i = 0; i < vectorSize; i++)
        //         vectorAllocator.destroy(&vectorData[i]);
        //     vectorAllocator.deallocate(vectorData, vectorCapacity);
        // }
            
        iterator insert( iterator pos, const T& value )
        {
            pointer temp;
            size_type insertPos = &(*pos) - vectorData;
            if(vectorSize == vectorCapacity)
            {
                temp = vectorAllocator.allocate(vectorSize * 2);
                for(size_type i = 0; i < insertPos; ++i)
                    vectorAllocator.construct(&temp[i], vectorData[i]);
                vectorAllocator.construct(&temp[insertPos], value);
                for(size_type i = vectorSize - 1; i >= insertPos && i <= capacity(); --i)
                    vectorAllocator.construct(&temp[i + 1], vectorData[i]);
                for(size_t i = 0; i < vectorSize; i++)
                    vectorAllocator.destroy(&vectorData[i]);
                vectorAllocator.deallocate(vectorData, vectorCapacity);
                vectorCapacity = vectorSize * 2;
                vectorSize++;
                vectorData = temp;
            }
            else
            {
                for(size_type i = vectorSize; i >= (size_type) insertPos && i <= capacity(); --i)
                    vectorData[i] = vectorData[i - 1];
                vectorData[insertPos] = value;
                vectorSize++;
            }
            return (vectorData + insertPos);
        }
        
        void insert( iterator pos, size_type count, const T& value )
        {

            pointer temp;
            size_type insertPos = &(*pos) - vectorData;
            if(vectorSize + count > vectorCapacity)
            {
                temp = vectorAllocator.allocate(vectorSize + std::max(size(), count));
                for(size_type i = 0; i < insertPos; ++i)
                    vectorAllocator.construct(&temp[i], vectorData[i]);
                for(size_type i = insertPos; i < insertPos + count; ++i)
                    vectorAllocator.construct(&temp[i], value);
                for(size_type i = vectorSize - 1; i >= insertPos && i <= capacity(); --i)
                    vectorAllocator.construct(&temp[i + count], vectorData[i]);
                for(size_t i = 0; i < vectorSize; i++)
                    vectorAllocator.destroy(&vectorData[i]);
                vectorAllocator.deallocate(vectorData, vectorCapacity);
                vectorCapacity = vectorSize + std::max(size(), count);
                vectorSize += count;
                vectorData = temp;
            }
            else
            {
                for(size_type i = vectorSize - 1; i >= (size_type) insertPos && i <= capacity(); --i)
                    vectorData[i + count] = vectorData[i];
                for(size_type i = insertPos; i < insertPos + count; ++i)
                    vectorData[i] = value;
                vectorSize += count;
            }
        }

        template< class InputIt >
        void insert( iterator pos, InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = NULL)
        {
            difference_type count =ft::distance(first, last);
            pointer temp;
            size_type insertPos = &(*pos) - vectorData;
            if(vectorSize + count > vectorCapacity)
            {
                temp = vectorAllocator.allocate(vectorSize + std::max(size(), (size_type) count));
                for(size_type i = 0; i < insertPos; ++i)
                    vectorAllocator.construct(&temp[i], vectorData[i]); 
                for(size_type i = insertPos; i < insertPos + count; ++i)
                {   
                    vectorAllocator.construct(&temp[i], *first);
                    ++first;   
                }
                for(size_type i = vectorSize - 1; i >= insertPos && i <= capacity(); --i)
                    vectorAllocator.construct(&temp[i + count], vectorData[i]);
                for(size_t i = 0; i < vectorSize; i++)
                    vectorAllocator.destroy(&vectorData[i]);
                vectorAllocator.deallocate(vectorData, vectorCapacity);
                vectorCapacity = vectorSize + std::max(size(), (size_type) count);
                vectorSize += count;
                vectorData = temp;
            }
            else
            {
                for(size_type i = vectorSize - 1; i >= (size_type) insertPos && i <= capacity(); --i)
                    vectorData[i + count] = vectorData[i];
                for(size_type i = insertPos; i < insertPos + count; ++i)
                {
                    vectorData[i] = *first;
                    ++first;
                }
                vectorSize += count;
            }
        }
        
        void push_back (const value_type& val)
        {
            if(vectorCapacity == 0)
                reserve(1);
            if(vectorSize == vectorCapacity)
                this->reserve((vectorSize) * 2);
            vectorAllocator.construct(&vectorData[vectorSize], val);
            vectorSize++;
        }

        void pop_back()
        {
            if(vectorSize != 0)
            {
                vectorAllocator.destroy(&vectorData[vectorSize - 1]);
                vectorSize--;
            }
        }
        void assign( size_type count, const T& value )
        {
            resize(0);
            insert(begin(), count, value);
        }

        template< class InputIt >
        void assign( InputIt first, InputIt last )
        {
            resize(0);
            insert(begin(), first, last);
        }
        
        // void assign (size_type n, const value_type& val)
        // {
            
        // }

        void swap (vector& x)
        {
            size_type sTemp = vectorSize;
            size_type cTemp = vectorCapacity;
            allocator_type aTemp = vectorAllocator;
            pointer         dTemp = vectorData;

            vectorSize = x.vectorSize;
            vectorCapacity = x.vectorCapacity;
            vectorAllocator = x.vectorAllocator;
            vectorData = x.vectorData;
            
            x.vectorSize = sTemp;
            x.vectorCapacity = cTemp;
            x.vectorAllocator = aTemp;
            x.vectorData = dTemp;
        }
        allocator_type get_allocator() const
        {
            return (vectorAllocator);
        }
        
        T* data()
        {
            return vectorData;
        }
        const T* data() const
        {
            return vectorData;
        }
        
        iterator erase( iterator pos )
        {
            pointer p_pos = &(*pos);
            difference_type diff = &(*pos) - vectorData;
            if (pos + 1 != end())
            {
                for(size_type i = diff; i < vectorSize - 1; ++i)
                    vectorData[i] = vectorData[i + 1];
            }
            vectorSize--;
            vectorAllocator.destroy(&vectorData[size()]);
            return(iterator(p_pos));
        }
        
        iterator erase( iterator first, iterator last )
        {
            size_t eraseLen = ft::distance(first, last);
            size_t firstErasePos = ft::distance(begin(), first);

            if(last != end())
            {
                for(size_type i = firstErasePos + eraseLen; i < vectorSize; ++i)
                {
                    vectorData[i - eraseLen] = vectorData[i];
                }
            }
            for(size_type i = firstErasePos + eraseLen; i < vectorSize; ++i)
                vectorAllocator.destroy(&vectorData[i]);
            vectorSize -= eraseLen;
            return (first);
        }
        private:
            allocator_type  vectorAllocator;
            pointer         vectorData;
            size_type       vectorCapacity;
            size_type       vectorSize;


    };

    template <class T, class Alloc>
    void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
    {
        x.swap(y);
    }
    /* Vector operators overloads */
    template< class T, class Alloc>
    bool operator==( const ft::vector<T,Alloc>& lhs,
                 const ft::vector<T,Alloc>& rhs )
    {
            if(lhs.size() != rhs.size())
                return (false);
            for(size_t i = 0; i < lhs.size(); ++i)
            {
                if(lhs.at(i) != rhs.at(i))
                    return (false);
            }
            return (true);
    }

    template< class T, class Alloc >
    bool operator!=( const ft::vector<T,Alloc>& lhs,
                 const ft::vector<T,Alloc>& rhs )
    {
            return !(lhs == rhs);
    }
    
    template< class T, class Alloc >
    bool operator<( const ft::vector<T,Alloc>& lhs,
                 const ft::vector<T,Alloc>& rhs )
    {
        return(lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }
    
    template< class T, class Alloc >
    bool operator<=( const ft::vector<T,Alloc>& lhs,
                 const ft::vector<T,Alloc>& rhs )
    {
            
        if(rhs == lhs)
            return (true);
        return(lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }
    
    template< class T, class Alloc >
    bool operator>( const ft::vector<T,Alloc>& lhs,
                 const ft::vector<T,Alloc>& rhs )
    {
        if(lhs == rhs)
            return (false);
        return(!(lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())));
            
    }
    template< class T, class Alloc >
    bool operator>=( const ft::vector<T,Alloc>& lhs,
                 const ft::vector<T,Alloc>& rhs )
    {
        if(rhs == lhs)
            return (true);
        return(!lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }

    template<class InputIt1, class InputIt2>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
                                InputIt2 first2, InputIt2 last2)
    {
        for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
            if (*first1 < *first2) return true;
            if (*first2 < *first1) return false;
        }
        return (first1 == last1) && (first2 != last2);
    }
}

#endif