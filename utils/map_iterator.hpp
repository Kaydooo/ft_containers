/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-guna <mal-guna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 19:05:24 by mal-guna          #+#    #+#             */
/*   Updated: 2022/08/08 19:05:25 by mal-guna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
#define  MAP_ITERATOR_HPP


namespace ft
{

    template<class T, class Compare, class node_type>
    class map_iterator
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
        map_iterator(void) : dataNode(NULL), endNode(NULL)  {}

        /*  Node  Constructor */
		map_iterator(const node_pointer &node, const node_pointer &end):dataNode(node), endNode(end) {}

        /*  Copy  Constructor */
        map_iterator(const map_iterator& other):dataNode(other.dataNode), endNode(other.endNode){}

        
        /* Conversion Operators */
        // * converts normal iterator to constant_iterator
        operator map_iterator<const T, Compare, node_type> (void) const { return map_iterator<const T, Compare, node_type> (dataNode, endNode); }

        // * converts const_iterator to iterator but because map doesn't allow const_it to iterator conversion this was commented.
        // template<typename U>
        // operator map_iterator<U, Compare, node_type> (void) { return map_iterator<U, Compare, node_type> (dataNode, endNode); }

        /*  Copy Assignment Operator */
        map_iterator&   operator=(const map_iterator& rhs)
        {
            if(this != &rhs)
            {
                this->dataNode = rhs.dataNode;
                this->endNode = rhs.endNode;
            }
            return (*this);
        }

        bool  operator==(const map_iterator& other) const { return(this->dataNode == other.dataNode); }

        bool  operator!=(const map_iterator& other) const { return(this->dataNode != other.dataNode); }

        reference_type  operator*() const { return( dataNode->data );}

        pointer_type operator->()const { return &operator*(); }

        map_iterator&       operator++()
        {
            if(dataNode->child[1] == NULL)
            {
                node_pointer temp = dataNode;
                if(temp == endNode)
                    return (*this);
                if (dataNode->parent)
                {
                    dataNode = dataNode->parent;
                    while(dataNode->parent && c(dataNode->data.first, temp->data.first)) 
                        dataNode = dataNode->parent;                            
                    if(c(dataNode->data.first, temp->data.first))
                    {
                        endNode->parent = dataNode;
                        dataNode = endNode;
                    }
                }
                else{
                    dataNode = endNode;
                }
            }
            else if (dataNode->child[1] != NULL)
            {
                dataNode = dataNode->child[1];
                get_far_left();
            }
            return (*this);
        }

        map_iterator&       operator--()
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
                    while(dataNode->parent && c(temp->data.first, dataNode->data.first))
                        dataNode = dataNode->parent;
                    if(c(temp->data.first, dataNode->data.first))
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

        map_iterator operator++(int)
        {
            map_iterator tmp(dataNode, endNode);
            ++(*this);
            return (tmp);
        }  
        map_iterator operator--(int)
        {
            map_iterator tmp(dataNode, endNode);
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
    };

}

#endif 