#ifndef MAPITERATOR_HPP
#define  MAPITERATOR_HPP
#include "RedBlackTree.hpp"


namespace ft
{

    template<class T, class Compare, class node_type>
    class MapIterator
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
        MapIterator(void);

        /*  Node  Constructor */
		MapIterator(node_type *node, node_type *end);

        /*  Copy  Constructor */
        template <typename U>
        MapIterator(const MapIterator<U, Compare, node_type>& other):dataNode(other.dataNode), endNode(other.endNode){}

        /*  Copy Assignment Operator */
        MapIterator&   operator=(const MapIterator& rhs)
        {
            if(this != &rhs)
            {
                this->dataNode = rhs.dataNode;
                this->endNode = rhs.endNode;
            }
            return (*this);
        }

        bool  operator==(const MapIterator& other) const 
        { 
            return(this->dataNode == other.dataNode);
        }

        bool  operator!=(const MapIterator& other) const 
        { 
            return(this->dataNode != other.dataNode);
        }

        reference_type  operator*() const { return( dataNode->data );}
        pointer_type operator->()const { return &operator*(); }

        MapIterator&       operator++()
        {
            if(dataNode->child[1] == NULL)
            {
                node_pointer temp = dataNode;
                if(temp == endNode)
                    return (*this);
                if (dataNode->parent)
                {
                    dataNode = dataNode->parent;
                    while(dataNode->parent && c(dataNode->data.first, temp->data.first)) // use compare here later
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

        MapIterator&       operator--()
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
                    while(dataNode->parent && c(temp->data.first, dataNode->data.first)) // use compare here later
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

        MapIterator operator++(int)
        {
            MapIterator tmp(dataNode, endNode);
            ++(*this);
            return (tmp);
        }  
        MapIterator operator--(int)
        {
            MapIterator tmp(dataNode, endNode);
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




        template <typename T, class Comp, typename node_type>
        MapIterator<T, Comp, node_type>::MapIterator(void) : dataNode(NULL), endNode(NULL)  { return ; }

        template <typename T, class Comp, typename node_type>
        MapIterator<T, Comp, node_type>::MapIterator(node_type *node, node_type *end):dataNode(node), endNode(end) {return ;}



}

#endif 