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
#include  <stdexcept>

namespace ft
{
    template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
    class map
    {
        public:
            typedef Key     key_type;
            typedef T       mapped_type;
            typedef ft::pair<const Key, T>  value_type;
            typedef Compare             key_compare;
            typedef Alloc       allocator_type;
            typedef typename allocator_type::reference       reference;
            typedef typename allocator_type::const_reference    const_reference;
            typedef RedBlackTree_Node<value_type>        node_type;
            typedef node_type*                  node_pointer;
            typedef RedBlackTree<value_type, Compare, node_type> tree_type;
            typedef tree_type*                        tree_pointer;
            //iteraors here
            typedef MapIterator<value_type, Compare, node_type>     iterator;
            typedef MapIterator<const value_type, Compare, node_type>     const_iterator;
            typedef map_reverse_Iterator<iterator>           reverse_iterator;
            typedef map_reverse_Iterator<const_iterator>     const_reverse_iterator;
            typedef typename allocator_type::difference_type    difference_type;
            typedef typename allocator_type::size_type          size_type;
            typedef typename allocator_type::pointer    pointer;
            typedef typename allocator_type::const_pointer    const_pointer;
            
            typedef          std::allocator<tree_type>         tree_allocator;



        /* Value Compare .. This class will create an object that can be used
        to compare 2 values of type ft::pair<const Key, T> , this object will 
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
        explicit map( const Compare& comp = Compare(), const Alloc& alloc = Alloc()): allocc(alloc), comp(comp)
        { 
            // mapTree = treeAllocator.allocate(1);
            // treeAllocator.construct(mapTree, tree_type());
        }

        template <class InputIterator>
        map (InputIterator first, InputIterator last,
        const key_compare& comp = key_compare(),
        const allocator_type& alloc = allocator_type()): allocc(alloc), comp(comp)
        {
            // mapTree = treeAllocator.allocate(1);
            // treeAllocator.construct(mapTree, tree_type());
            (void)comp;
            (void)alloc;
            insert(first, last);
            	
        }

        map (const map& x) : allocc(x.allocc), comp(x.comp)
        {
            // mapTree = treeAllocator.allocate(1);
            // treeAllocator.construct(mapTree, tree_type());
            insert(x.begin(), x.end());
        }

        ~map(void)
        {
            clear();
            // treeAllocator.destroy(mapTree);
            // treeAllocator.deallocate(mapTree, 1);
        }

        map& operator= (const map& x)
        {
            if(this != &x)
            {
                clear();
                // treeAllocator.destroy(mapTree);
                // treeAllocator.deallocate(mapTree, 1);
                // mapTree = treeAllocator.allocate(1);
                // treeAllocator.construct(mapTree, tree_type());
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

        const_iterator    begin() const
        {
            return (mapTree.begin());
        }
        reverse_iterator rbegin() { return reverse_iterator(end()); }
        reverse_iterator rend()   { return reverse_iterator(begin()); }
        const_reverse_iterator rbegin() const{ return const_reverse_iterator(end()); }
        const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }
        iterator    end()
        {
            return (mapTree.end());
        }


        const_iterator    end() const
        {
            return (mapTree.end());
        }

        ft::pair<iterator,bool> insert( const value_type& value )
        {
            return (mapTree.insert(value));
        }

        iterator insert (iterator position, const value_type& val)
        {
            (void) position;
            ft::pair<iterator, bool> result;
            result = mapTree.insert(val);
            return (result.first);
        }
        
        template <class InputIterator>
        void insert (InputIterator first, InputIterator last)
        {
            size_type dist = ft::distance(first, last);
            // std::cout << "distance = " << dist << std::endl;

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
        
        void erase (iterator position)
        {
            erase(position->first);
            // nodeAllocator.destroy(result);
            // nodeAllocator.deallocate(result, 1);
        }
        size_type erase (const key_type& k)
        {
            // std::cout << "HE HE : " << k << std::endl;
            return(mapTree.erase_key(k));
        }
        void erase (iterator first, iterator last)
        {
            size_type dist = ft::distance(first, last);
            key_type    *keys = new key_type[dist];
            for (size_type i = 0; i < dist; ++i, ++first)
                keys[i] = first->first;
                
            for (size_type i = 0; i < dist; ++i)
                erase(keys[i]);

            delete [] keys;
                
        }

        void clear()
        {
            mapTree.clear();
        }

        T& operator[]( const Key& key )
        {
            
            return insert(ft::make_pair(key, T())).first->second;
        }
        T& at( const Key& key )
        {
            iterator it = mapTree.find(key);
            if(it == end())
                throw std::out_of_range("wronge use of at : OUT OF RANGE\n");
            return(it->second);
        }

        const T& at( const Key& key ) const
        {
            const_iterator it = mapTree.find(key);
            if(it == end())
                throw std::out_of_range("wronge use of at : OUT OF RANGE\n");
            return(it->second);
        }

        void swap( map& other )
        {
            mapTree.swap(other.mapTree);
        }
        size_type count( const key_type& k ) const
        {
            return (mapTree.count(k));
        }
        iterator find (const key_type& k)
        {
            return(mapTree.find(k));
        }
        const_iterator find (const key_type& k) const
        {
            return(mapTree.find_const(k));
        } 
        value_compare value_comp() const
        {
            return (value_compare(key_compare()));
        }

        key_compare key_comp() const
        {
            return (key_compare());
        }

        allocator_type get_allocator() const
        {
            return(allocator_type());
        }
        
    iterator		lower_bound(const key_type &key) {
		return (mapTree.lower_bound(key));

	}

	const_iterator	lower_bound(const key_type &key) const 
    {
		return (mapTree.lower_bound_const(key));
	}


	iterator		upper_bound(const key_type &key) {
        return (mapTree.upper_bound(key));
	}

	const_iterator	upper_bound(const key_type &key) const {

		return (mapTree.upper_bound_const(key));
	}

	pair<const_iterator,const_iterator>	equal_range(const key_type &key) const {
		pair<const_iterator, const_iterator> res;

		res.first = lower_bound(key);
		res.second = upper_bound(key);
		return (res);
	}

	pair<iterator,iterator>				equal_range(const key_type &key) {
		pair<iterator, iterator> res;

		res.first = lower_bound(key);
		res.second = upper_bound(key);
		return (res);
	}
        private:
            tree_type     mapTree;
            // tree_allocator   treeAllocator;
            allocator_type  allocc;
            Compare         comp;

    };

    template <class Key, class T, class Compare, class Alloc>
    bool	operator==(const map<Key, T, Compare, Alloc> &lhs,
                        const map<Key, T, Compare, Alloc> &rhs) {
        if (lhs.size() != rhs.size())
            return false;
        return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }

    template <class Key, class T, class Compare, class Alloc>
    bool	operator!=(const map<Key, T, Compare, Alloc> &lhs,
                        const map<Key, T, Compare, Alloc> &rhs) {
        return !(lhs == rhs);
    }

    template <class Key, class T, class Compare, class Alloc>
    bool	operator< (const map<Key, T, Compare, Alloc> &lhs,
                        const map<Key, T, Compare, Alloc> &rhs) {
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

    template <class Key, class T, class Compare, class Alloc>
    bool	operator<=(const map<Key, T, Compare, Alloc> &lhs,
                        const map<Key, T, Compare, Alloc> &rhs) {
        return !(rhs < lhs);
    }

    template <class Key, class T, class Compare, class Alloc>
    bool	operator> (const map<Key, T, Compare, Alloc> &lhs,
                        const map<Key, T, Compare, Alloc> &rhs) {
        return (rhs < lhs);
    }

    template <class Key, class T, class Compare, class Alloc>
    bool	operator>=(const map<Key, T, Compare, Alloc> &lhs,
                        const map<Key, T, Compare, Alloc> &rhs) {
        return !(lhs < rhs);
    }

    template< class Key, class T, class Compare, class Alloc >
    void swap( ft::map<Key,T,Compare,Alloc>& lhs,
            ft::map<Key,T,Compare,Alloc>& rhs )
    {
        lhs.swap(rhs);
    }


}



#endif