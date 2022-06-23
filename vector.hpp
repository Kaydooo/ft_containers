/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-guna <mal-guna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 01:56:16 by mal-guna          #+#    #+#             */
/*   Updated: 2022/06/23 02:45:41 by mal-guna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <vector>
#include <exception>
#include <stdexcept> 
#include <memory>
#include <cstddef>
#include <algorithm>

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
            
            // Prefix dec
            Iterator& operator--() { itPtr--; return *this; }  

            // Postfix dec
            Iterator operator--(int) { Iterator tmp = *this; --(*this); return tmp; }


			Iterator& operator+(difference_type num) {
				Iterator temp;
                temp.itPtr = itPtr + num;
				return (temp);
			}	
			
			Iterator& operator-(difference_type num) {
				Iterator temp;
                temp.itPtr = itPtr - num;
				return (temp);
			}
            
			Iterator& operator+=(difference_type num) {
				itPtr = itPtr + num;
				return (*this);
			}	
			
			Iterator& operator-=(difference_type num) {
				itPtr = itPtr - num;
				return (*this);
			}

            Iterator& operator[](difference_type num) {
				
				return (*(itPtr + num));
			}

            friend bool operator== (const Iterator& a, const Iterator& b) { return a.itPtr == b.itPtr; }
            friend bool operator!= (const Iterator& a, const Iterator& b) { return a.itPtr != b.itPtr; }
            friend bool operator< (const Iterator& a, const Iterator& b) { return a.itPtr < b.itPtr; }
            friend bool operator> (const Iterator& a, const Iterator& b) { return a.itPtr > b.itPtr; }
            friend bool operator<= (const Iterator& a, const Iterator& b) { return a.itPtr <= b.itPtr; }
            friend bool operator>= (const Iterator& a, const Iterator& b) { return a.itPtr >= b.itPtr; }

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
            template <class InputIterator>
            vector(const_iterator first, const_iterator last, const allocator_type& alloc = allocator_type()): vectorAllocator(alloc)
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
            };
            /*  */

        /* Iterators */
        
            iterator begin() { return iterator(vectorData); }
            iterator end()   { return iterator(vectorData + vectorSize); }
            const_iterator begin() const{ return const_iterator(vectorData); }
            const_iterator end() const { return const_iterator(vectorData + vectorSize); }
        //////////////////// rbegin + rend To Be Done !//////////////////
        

        /* member functions (Capacity) */

        size_type   size() const { return (vectorSize);}
        size_type   max_size() const { return (vectorAllocator.max_size());}
        size_type   capacity() const { return (vectorCapacity);}
        bool        empty() const { return (vectorSize == 0);}
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
                    for(size_type i = vectorSize - 1; i >= n ; i--)
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

        void push_back (const value_type& val)
        {
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
        template <class InputIterator>
        void assign (const_iterator first, const_iterator last)
        {
            difference_type diff = last - first;    
            
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
        
        
        private:
            allocator_type  vectorAllocator;
            pointer         vectorData;
            size_type       vectorSize;
            size_type       vectorCapacity;

    };

    template <class T, class Alloc>
    void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
    {
        x.swap(y);
    }

}