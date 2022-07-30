#ifndef SET_ITERATOR_HPP
#define  SET_ITERATOR_HPP
#include "RedBlackTree.hpp"

namespace ft
{
    template<class T, class Compare, class node_type>
    class set_iterator
    {
        public:

        typedef T                           value_type;
        typedef T*                          pointer_type;
        typedef T&                          reference_type;
        typedef node_type*                  node_pointer;
        typedef std::ptrdiff_t              difference_type;
        typedef bidirectional_iterator_tag  iterator_category;


        /* Iterator class vars */
        node_pointer    dataNode;
        node_pointer    endNode;
        Compare c;

        /* Default Constructor */
        set_iterator(void) : dataNode(NULL), endNode(NULL)  {}
        /*  Node  Constructor */
		set_iterator(node_type *dn, node_type *end):dataNode(dn), endNode(end) {}

        /*  Copy  Constructor */
        // * template was used to allow conversion from iterator to const_iterator and vice versa.. unlike map , set allows conversion from const_it to it.
        // * conversion operator was used in map to allow one way conversion only --> it to const_it .
        template <typename U>
        set_iterator(const set_iterator<U, Compare, node_type>& other):dataNode(other.dataNode), endNode(other.endNode){}

        set_iterator&   operator=(const set_iterator& rhs)
        {
            if(this != &rhs)
            {
                this->dataNode = rhs.dataNode;
                this->endNode = rhs.endNode;
            }
            return (*this);
        }

        bool  operator==(const set_iterator& other) const { return(this->dataNode == other.dataNode); }

        bool  operator!=(const set_iterator& other) const { return(this->dataNode != other.dataNode); }

        reference_type  operator*() const { return( dataNode->data ); }

        pointer_type operator->()const { return &operator*(); }

        set_iterator&       operator++()
        {
            if(dataNode->child[1] == NULL)
            {
                node_pointer temp = dataNode;
                if(temp == endNode)
                    return (*this);
                if (dataNode->parent)
                {
                    dataNode = dataNode->parent;
                    while(dataNode->parent && c(dataNode->data, temp->data))
                        dataNode = dataNode->parent;                            
                    if(c(dataNode->data, temp->data))
                    {
                        endNode->parent = dataNode;
                        dataNode = endNode;
                    }
                }
                else
                    dataNode = endNode;
            }
            else if (dataNode->child[1] != NULL)
            {
                dataNode = dataNode->child[1];
                get_far_left();
            }
            return (*this);
        }

        set_iterator&       operator--()
        {    
            if(dataNode == endNode)
            {
                dataNode = endNode->parent;
                get_far_right();
            }
            else if(dataNode->child[0] == NULL)
            {
                node_pointer temp = dataNode;
                if (dataNode->parent)
                {
                    dataNode = dataNode->parent;
                    while(dataNode->parent && c(temp->data, dataNode->data))
                        dataNode = dataNode->parent;
                    if(c(temp->data, dataNode->data))
                        get_far_left();
                }
                else
                {
                    if(dataNode == endNode)
                    {
                        dataNode = endNode->parent;
                        get_far_right();
                    }
                    else
                        get_far_left();
                }
            }
            else if (dataNode->child[0] != NULL)
            {
                dataNode = dataNode->child[0];
                get_far_right();
            }
            return (*this);
        }

        set_iterator operator++(int)
        {
            set_iterator tmp(dataNode, endNode);
            ++(*this);
            return (tmp);
        }  
        set_iterator operator--(int)
        {
            set_iterator tmp(dataNode, endNode);
            --(*this);
            return (tmp);
        }          
        private:
            void    get_far_left()
            {
                while(dataNode->child[0])
                    dataNode = dataNode->child[0];
            }
            void    get_far_right()
            {
                while(dataNode->child[1])
                    dataNode = dataNode->child[1];
            }
    }; // end of set_iterator

} // end of namespace ft

#endif 