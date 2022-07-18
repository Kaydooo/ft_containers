#ifndef MAP_HPP
#define MAP_HPP

#include <functional>
#include <utility>
// #include <exception>
// #include <stdexcept>
#include <memory>
#include <cstddef>
#include "MapIterator.hpp"
#include "container_utils.hpp"
// #include <algorithm>
// #include <iostream>

namespace ft
{
    template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
    class map
    {
        public:
            typedef Key     key_type;
            typedef T       mapped_type;
            typedef std::pair<const Key, T>  value_type;
            typedef Compare             key_compare;
            typedef Alloc       allocator_type;
            typedef typename allocator_type::reference       reference;
            typedef typename allocator_type::const_reference    const_reference;
            typedef bstNode<value_type, Compare>     node_type;
            typedef bstNode<value_type, Compare>*    node_pointer;
            
            //iteraors here
            typedef MapIterator<value_type, Compare>     iterator;
            typedef MapIterator<value_type, Compare>     const_iterator;
            typedef typename allocator_type::difference_type    difference_type;
            typedef typename allocator_type::size_type          size_type;
            typedef typename allocator_type::pointer    pointer;
            typedef typename allocator_type::const_pointer    const_pointer;
            typedef std::allocator<node_type>   node_allocator;


        /* Value Compare .. This class will create an object that can be used
        to compare 2 values of type std::pair<const Key, T> , this object will 
        only use the Compare (Which is less<Key>) to compare the keys of the passed pairs */

        class value_compare
        : public std::binary_function<value_type, value_type, bool>
        {
            friend class map<Key, T, Compare, Alloc>;
            protected:
            key_compare comp;

            value_compare(key_compare c)
            : comp(c) { }

            public:
            bool operator()(const value_type& x, const value_type& y) const
            { return comp(x.first, y.first); }
        };


        /* Constructors  */
        explicit map( const Compare& comp = Compare(), const Alloc& alloc = Alloc())
        {            
            compare = comp;
            mapAllocator = alloc;
            nodeAllocator = node_allocator();
            rootNode = NULL;
            mapSize = 0;
        }

        template <class InputIterator>
        map (InputIterator first, InputIterator last,
        const key_compare& comp = key_compare(),
        const allocator_type& alloc = allocator_type())
        {
            compare = comp;
            mapAllocator = alloc;
            nodeAllocator = node_allocator();
            rootNode = NULL;
            mapSize = 0;
            insert(first, last);
        }

        map (const map& x) : compare(x.compare), mapAllocator(x.mapAllocator)
        , nodeAllocator(x.nodeAllocator), rootNode(NULL), mapSize(0)
        {
            if(x.size())
                insert(x.begin(), x.end());
        }
        
        // map& operator= (const map& x)
        // {
        //     if(this != &x)
        //     {
                
        //     }
            
        //     return (*this);
        // }


        // template< class InputIt >
        // map( InputIt first, InputIt last,
        // const Compare& comp = Compare(),
        // const Allocator& alloc = Allocator() );

        /* Capacity And size */

        size_type	size(void) const { return (mapSize); }
        size_type	max_size(void) const {return (node_allocator().max_size());}
        bool		empty(void) const {return (mapSize == 0? true : false);}

        iterator    begin()
        {
            node_pointer    temp;
            temp = rootNode;
            if(temp->leftChild)
            {
                while(temp->leftChild)
                    temp = temp->leftChild;
            }
            return (iterator(temp));
        }

        iterator    end()
        {
            return (iterator(rootNode->endNode));
        }

        const_iterator    begin() const
        {
            node_pointer    temp;
            temp = rootNode;
            if(temp->leftChild)
            {
                while(temp->leftChild)
                    temp = temp->leftChild;
            }
            return (const_iterator(temp));
        }

        const_iterator    end() const
        {
            return (const_iterator(rootNode->endNode));
        }

        std::pair<iterator,bool>    insert( const value_type& value )
        {
            std::pair<iterator, bool> result;
            node_pointer nodeRes;
            node_pointer    newNode =  nodeAllocator.allocate(1);
            nodeAllocator.construct(newNode, value);
            result.second = true;
            if(mapSize == 0)
            {
                node_pointer    endN =  nodeAllocator.allocate(1);
                rootNode = newNode;
                endN->endNode = endN;
                endN->root = rootNode;
                rootNode->root = rootNode;
                rootNode->endNode = endN;
                result.first = iterator(rootNode);
            }
            else
            {
                rootNode->addRecursive(rootNode, newNode, result.second, nodeRes);
                result.first = iterator(nodeRes);
            }
            // if(mapSize % 100000 == 0)
            rootNode = rootNode->buildTree(rootNode);
            ++mapSize;
            return (result);
        }




        iterator insert (iterator position, const value_type& val)
        {
            (void) position;
            std::pair<iterator, bool> result;
            result = this->insert(val);
            return (result.first);
        }
        
        template <class InputIterator>
        void insert (InputIterator first, InputIterator last)
        {
            size_type dist = ft::distance(first, last);
            for (size_type i = 0; i < dist; ++i)
            {
                insert(*first);
                ++first;
            }
        }

        void    testPrint()
        {
            std::cout << "TEST PRINT\n";
            rootNode->printTree(rootNode);
            std::cout << "\nEND TEST PRINT\n";
        }
        
        void erase (iterator position)
        {
            node_pointer result;
            result = rootNode->find(rootNode, position->first);
            if(result == NULL)
                return;
            result = result->erase(result);
            --mapSize;
            // nodeAllocator.destroy(result);
            // nodeAllocator.deallocate(result, 1);
        }
        size_type erase (const key_type& k)
        {
            node_pointer result;
            result = rootNode->find(rootNode, k);
            if(result == NULL)
                return 0;
            result = result->erase(result);
            --mapSize;
            nodeAllocator.destroy(result);
            nodeAllocator.deallocate(result, 1);
            return 1;
        }
        void erase (iterator first, iterator last)
        {
            size_type dist = ft::distance(first, last);
            for (size_type i = 0; i < dist; ++i)
            {
                erase(first->first);
                ++first;
            }
        }

        iterator find (const key_type& k)
        {
            node_pointer result;
            result = rootNode->find(rootNode, k);
            if (result == NULL)
                return(end());
            return(iterator(result));
        }
        const_iterator find (const key_type& k) const;   
        value_compare value_comp() const
        {
            return (value_compare(key_compare()));
        }
        protected:
            key_compare compare;
        private:
            Alloc       mapAllocator;
            node_allocator       nodeAllocator;
            node_pointer     rootNode;
            size_type   mapSize;


    };
}



#endif