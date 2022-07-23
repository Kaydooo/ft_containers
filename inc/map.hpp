#ifndef MAP_HPP
#define MAP_HPP

// #include "../utils/RedBlackTree.hpp"
// #include <functional>
#include <utility>
#include <memory>
// #include <cstddef>
// #include "../utils/MapIterator.hpp"
#include "../utils/container_utils.hpp"
#include "../utils/RedBlackTree.hpp"
// #include <bits/stdc++.h>
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
            typedef RedBlackTree<value_type, Compare> tree_type;
            typedef tree_type*                        tree_pointer;
            //iteraors here
            typedef MapIterator<value_type, Compare>     iterator;
            typedef MapIterator<value_type, Compare>     const_iterator;
            typedef typename allocator_type::difference_type    difference_type;
            typedef typename allocator_type::size_type          size_type;
            typedef typename allocator_type::pointer    pointer;
            typedef typename allocator_type::const_pointer    const_pointer;
            // typedef          std::allocator<tree_type>         tree_allocator;



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
                        (void)comp;
            (void)alloc;            
        }

        template <class InputIterator>
        map (InputIterator first, InputIterator last,
        const key_compare& comp = key_compare(),
        const allocator_type& alloc = allocator_type())
        {
            (void)comp;
            (void)alloc;
            insert(first, last);
        }

        map (const map& x) 
        {
            if(x.size())
                insert(x.begin(), x.end());
        }

        ~map(void){}

        map& operator= (const map& x)
        {
            if(this != &x)
            {
                //clear first after clear() is done
                insert(x.begin(), x.end());
            }
            
            return (*this);
        }


        // template< class InputIt >
        // map( InputIt first, InputIt last,
        // const Compare& comp = Compare(),
        // const Allocator& alloc = Allocator() );

        /* Capacity And size */

        size_type	size(void) const { return (mapTree.size()); }
        size_type	max_size(void) const {return (mapTree.max_size());}
        bool		empty(void) const {return (mapTree.empty());}

        iterator    begin()
        {
            return(mapTree.begin());
        }

        iterator    end()
        {
            return (mapTree.end());
        }

        const_iterator    begin() const
        {
            return (mapTree.begin());
        }

        const_iterator    end() const
        {
            return (mapTree.end());
        }

        std::pair<iterator,bool> insert( const value_type& value )
        {
            return (mapTree.insert(value));
        }

        iterator insert (iterator position, const value_type& val)
        {
            (void) position;
            std::pair<iterator, bool> result;
            result = mapTree.insert(val);
            return (result.first);
        }
        
        template <class InputIterator>
        void insert (InputIterator first, InputIterator last)
        {
            size_type dist = ft::distance(first, last);
            for (size_type i = 0; i < dist; ++i)
            {
                mapTree.insert(*first);
                ++first;
            }
        }

        void    testPrint()
        {
            // std::cout << "TEST PRINT\n";
            mapTree.printTree();
            // std::cout << "\nEND TEST PRINT\n";
        }
        
        // void erase (iterator position)
        // {
        //     node_pointer result;
        //     result = rootNode->find(rootNode, position->first);
        //     if(result == NULL)
        //         return;
        //     result = result->erase(result);
        //     --mapSize;
        //     // nodeAllocator.destroy(result);
        //     // nodeAllocator.deallocate(result, 1);
        // }
        // size_type erase (const key_type& k)
        // {
        //     node_pointer result;
        //     result = rootNode->find(rootNode, k);
        //     if(result == NULL)
        //         return 0;
        //     result = result->erase(result);
        //     --mapSize;
        //     nodeAllocator.destroy(result);
        //     nodeAllocator.deallocate(result, 1);
        //     return 1;
        // }
        // void erase (iterator first, iterator last)
        // {
        //     size_type dist = ft::distance(first, last);
        //     for (size_type i = 0; i < dist; ++i)
        //     {
        //         erase(first->first);
        //         ++first;
        //     }
        // }

        size_type count( const key_type& k ) const
        {
            return (mapTree.count(k));
        }
        iterator find (const key_type& k)
        {
            return(mapTree.find(k));
        }
        const_iterator find (const key_type& k) const;   
        value_compare value_comp() const
        {
            return (value_compare(key_compare()));
        }

        allocator_type get_allocator() const
        {
            return(allocator_type());
        }
        private:
            tree_type     mapTree;


    };
}



#endif