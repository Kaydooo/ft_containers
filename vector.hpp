/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-guna <mal-guna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 01:56:16 by mal-guna          #+#    #+#             */
/*   Updated: 2022/06/22 02:53:12 by mal-guna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <vector>
#include <memory>
#include <cstddef>


namespace ft
{
    /* Iterator Categaorie Tags */
    struct input_iterator_tag{};
    struct output_iterator_tag{};
    struct forward_iterator_tag: public input_iterator_tag{};
    struct bidirectional_iterator_tag: public forward_iterator_tag{};
    struct random_access_iterator_tag: public bidirectional_iterator_tag{};




    /* My Iterator Class */
    template<class T>
    class   Iterator
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

            Iterator(): itPtr(NULL){}
            Iterator(pointer_type ptr): itPtr(ptr){}
            Iterator(const Iterator& other): itPtr(other.itPtr){}
            Iterator&   operator=(const Iterator& rhs)
            {
                this->itPtr = rhs.itPtr;
                return (*this);
            }

            reference_type operator*() const { return *itPtr; }
            pointer_type operator->() { return itPtr; }

            // Prefix increment
            Iterator& operator++() { itPtr++; return *this; }  

            // Postfix increment
            Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }

            friend bool operator== (const Iterator& a, const Iterator& b) { return a.itPtr == b.itPtr; };
            friend bool operator!= (const Iterator& a, const Iterator& b) { return a.itPtr != b.itPtr; };
            friend Iterator& operator+ (const Iterator& a, const Iterator& b) { return a.itPtr + b.itPtr; };
            friend Iterator& operator- (const Iterator& a, const Iterator& b) { return a.itPtr - b.itPtr; };

        private:
            pointer_type    itPtr;
    };


    /* My Vector Class */
    template < class T, class Alloc = std::allocator<T> >
    class vector
    {
        public:
        //Typedefs for shorter and more readable code.
            typedef Alloc                               allocator_type;
            typedef T                                   value_type;
            typedef typename allocator_type::reference           reference;
            typedef typename allocator_type::const_reference     const_reference;
            typedef typename allocator_type::pointer             pointer;
            typedef typename allocator_type::const_pointer       const_pointer;
            typedef Iterator<value_type>                iterator;
            typedef Iterator<const value_type>          const_iterator;
            //reverse_it
            //const_reverse_it
            typedef typename allocator_type::difference_type     difference_type;
            typedef typename allocator_type::size_type           size_type;


            /* Default Constrctor */
            explicit vector (const allocator_type& alloc = allocator_type()): vectorAllocator(alloc), vectorData(NULL), vectorSize(0), vectorCapacity(0){}
            
            /* Fill Constrctor */
            explicit vector (size_type n, const value_type& val = value_type(),
                            const allocator_type& alloc = allocator_type()): vectorAllocator(alloc), vectorData(NULL), vectorSize(n), vectorCapacity(n)
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
            // template <class InputIterator>
            vector (iterator first, iterator last,
            const allocator_type& alloc = allocator_type()): vectorAllocator(alloc)
            {
                difference_type diff = last - first; // use distance instead when implemented in iterator 
                vectorData = vectorAllocator.allocate(diff);
                pointer	temp = vectorData;
                for (size_type i = 0; i < (size_type)diff; i++)
                {
                    vectorAllocator.construct(temp, *first);	
                    temp++;
                    first++;
                }
                
            }

            /* Copy Constrctor */
            vector (const vector& x): vectorAllocator(x.vectorAllocator), vectorCapacity(x.vectorCapacity), vectorSize(x.vectorSize)
            {
                vectorData = vectorAllocator.allocate(vectorCapacity);
                pointer	temp = vectorData;
                for (size_type i = 0; i < vectorSize; i++)
                {
                    vectorAllocator.construct(temp, x.vectorData[i]);	
                    temp++;
                }
            }
            
            /*  */
            iterator begin() { return iterator(vectorData); }
            iterator end()   { return iterator(vectorData + vectorSize); }
        private:
            allocator_type  vectorAllocator;
            pointer         vectorData;
            size_type       vectorSize;
            size_type       vectorCapacity;



    };


}