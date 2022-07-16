#ifndef MAP_HPP
#define MAP_HPP

#include <functional>
#include <utility>
// #include <exception>
// #include <stdexcept>
#include <memory>
#include <cstddef>
#include "MapIterator.hpp"
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
            typedef MapIterator<const value_type, Compare>     const_iterator;
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
            rootNode = NULL;
            mapSize = 0;
        }

        template <class InputIterator>
        map (InputIterator first, InputIterator last,
        const key_compare& comp = key_compare(),
        const allocator_type& alloc = allocator_type());

        map (const map& x) : compare(x.compare), mapAllocator(x.mapAllocator)
        , nodeAllocator(x.nodeAllocator), rootNode(x.rootNode), mapSize(x.mapSize){} // fix it later


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
            temp = rootNode->leftChild;
            if(temp->leftChild)
            {
                while(temp->leftChild)
                    temp = temp->leftChild;
                temp->rightChild->parent = temp;
                return (iterator(temp->leftChild));
            }
            temp->parent = rootNode;
            return (iterator(temp));
        }

        iterator    end()
        {
            return (iterator(rootNode->endNode));
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
            ++mapSize;
            return (result);
        }
        void    testPrint()
        {
            std::cout << "TEST PRINT\n";
            rootNode->printTree(rootNode);
            std::cout << "END TEST PRINT\n";
        }

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