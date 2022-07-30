#ifndef SET_HPP
#define SET_HPP

#include <memory>
#include "../utils/RedBlackTree_set.hpp"
#include  <stdexcept>

namespace ft
{
    template <class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
    class set
    {
        public:
            typedef const T                                             key_type;
            typedef const T                                             value_type;
            typedef Compare                                             key_compare;
            typedef Compare                                             value_compare;
            typedef Alloc                                               allocator_type;
            typedef typename allocator_type::reference                  reference;
            typedef typename allocator_type::const_reference            const_reference;
            typedef RedBlackTree_Node<value_type>                       node_type;
            typedef node_type*                                          node_pointer;
            typedef RedBlackTree_set<value_type, Compare, node_type>    tree_type;
            typedef tree_type*                                          tree_pointer;
            typedef set_iterator<value_type, Compare, node_type>        iterator;
            typedef set_iterator<const value_type, Compare, node_type>  const_iterator;
            typedef rbt_reverse_iterator<iterator>                      reverse_iterator;
            typedef rbt_reverse_iterator<const_iterator>                const_reverse_iterator;
            typedef typename allocator_type::difference_type            difference_type;
            typedef size_t                                              size_type;
            typedef typename allocator_type::pointer                    pointer;
            typedef typename allocator_type::const_pointer              const_pointer;
            typedef std::allocator<tree_type>                           tree_allocator;


            // ----------------------------- Member Functions  ------------------------------ //

            /* Constructors  */

            /* Default Constrctor */
            // * Constructs an empty container, with no elements.
            explicit set( const Compare& comp = Compare(), const Alloc& alloc = Alloc())
            : allocc(alloc), comp(comp){}

            /* Range Constrctor */
            // * Constructs a container with as many elements as the range [first,last), 
            // with each element constructed from its corresponding element in that range.
            template <class InputIterator>
            set (InputIterator first, InputIterator last,
            const key_compare& comp = key_compare(),
            const allocator_type& alloc = allocator_type()): allocc(alloc), comp(comp)
            { insert(first, last); }

            /* Copy Constrctor */
            // * Constructs a container with a copy of each of the elements in x.
            set (const set& x) : allocc(x.allocc), comp(x.comp)
            { insert(x.begin(), x.end()); }

            /*  Destructor */
            ~set(void){ clear(); }

            /*  Assignment operator */
            set& operator= (const set& x)
            {
                if(this != &x)
                {
                    clear();
                    insert(x.begin(), x.end());
                }
                return (*this);
            }

            /* Iterators */
            
            // * begin() returns iterator that points to the first element in the container. which equals to the smallest 
            //   element in the tree, this element can be found by geting the farthest left element in the tree.
            iterator                begin() { return(mapTree.begin()); }
            const_iterator          begin() const { return (mapTree.begin()); }

            // * end() returns itreator that points to the element that follows the last element in the tree. 
            //   which equals to an imaginery node that is present in RedBlackTree object mapTree.
            iterator                end() { return (mapTree.end()); }
            const_iterator          end() const { return (mapTree.end()); }

            reverse_iterator        rbegin() { return reverse_iterator(end()); }
            const_reverse_iterator  rbegin() const{ return const_reverse_iterator(end()); }

            reverse_iterator        rend()   { return reverse_iterator(begin()); }
            const_reverse_iterator  rend() const { return const_reverse_iterator(begin()); }

            /* Capacity And size */
            size_type	size(void) const { return (mapTree.size()); }
            size_type	max_size(void) const {return (mapTree.max_size());}
            bool		empty(void) const {return (mapTree.empty());}
            
            ft::pair<iterator,bool> insert( const value_type& value )
            { return (mapTree.insert(value)); }


            /* Modifiers */
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
            
            void erase (iterator position) { erase(*position); }

            size_type erase (const key_type& k) { return(mapTree.erase_key(k)); }

            void erase (iterator first, iterator last)
            {
                size_type dist = ft::distance(first, last);
                key_type_n    *keys = new key_type_n[dist];
                for (size_type i = 0; i < dist; ++i, ++first)
                    keys[i] = *first;
                    
                for (size_type i = 0; i < dist; ++i)
                    erase(keys[i]);
                delete [] keys;
            }

            void clear() { mapTree.clear(); }

            void swap( set& other ) { mapTree.swap(other.mapTree); }

            size_type count( const key_type& k ) const { return (mapTree.count(k)); }

            iterator find (const key_type& k) { return(mapTree.find(k)); }

            const_iterator find (const key_type& k) const { return(mapTree.find_const(k)); } 

            value_compare value_comp() const { return (key_compare()); }

            key_compare key_comp() const { return (key_compare()); }

            allocator_type get_allocator() const { return(allocator_type()); }
                
            iterator		lower_bound(const key_type &key) { return (mapTree.lower_bound(key)); }

            const_iterator	lower_bound(const key_type &key) const { return (mapTree.lower_bound_const(key)); }

            iterator		upper_bound(const key_type &key) { return (mapTree.upper_bound(key)); }

            const_iterator	upper_bound(const key_type &key) const { return (mapTree.upper_bound_const(key)); }

            pair<const_iterator,const_iterator>	equal_range(const key_type &key) const
            {
                pair<const_iterator, const_iterator> res;

                res.first = lower_bound(key);
                res.second = upper_bound(key);
                return (res);
            }

            pair<iterator,iterator>				equal_range(const key_type &key)
            {
                pair<iterator, iterator> res;

                res.first = lower_bound(key);
                res.second = upper_bound(key);
                return (res);
            }

        private:
            typedef T           key_type_n;
            tree_type     mapTree;
            allocator_type  allocc;
            Compare         comp;

            void    printTree() { mapTree.printTree(); }

    };

    template <class T, class Compare, class Alloc>
    bool	operator==(const set<T, Compare, Alloc> &lhs,
                        const set<T, Compare, Alloc> &rhs) 
    {
        if (lhs.size() != rhs.size())
            return false;
        return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }

    template <class T, class Compare, class Alloc>
    bool	operator!=(const set<T, Compare, Alloc> &lhs,
                        const set<T, Compare, Alloc> &rhs) 
    { return !(lhs == rhs); }

    template <class T, class Compare, class Alloc>
    bool	operator< (const set<T, Compare, Alloc> &lhs,
                        const set<T, Compare, Alloc> &rhs) 
    { return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()); }

    template < class T, class Compare, class Alloc>
    bool	operator<=(const set< T, Compare, Alloc> &lhs,
                        const set< T, Compare, Alloc> &rhs) 
    { return !(rhs < lhs); }

    template < class T, class Compare, class Alloc>
    bool	operator> (const set< T, Compare, Alloc> &lhs,
                        const set< T, Compare, Alloc> &rhs) 
    { return (rhs < lhs); }

    template < class T, class Compare, class Alloc>
    bool	operator>=(const set< T, Compare, Alloc> &lhs,
                        const set< T, Compare, Alloc> &rhs) 
    { return !(lhs < rhs); }

    template<  class T, class Compare, class Alloc >
    void swap( ft::set<T,Compare,Alloc>& lhs,
            ft::set<T,Compare,Alloc>& rhs )
    { lhs.swap(rhs); }

}// end of namespace ft

#endif