#include "BST_Tree.hpp"


namespace ft
{
    struct input_iterator_tag{};
    struct output_iterator_tag{};
    struct forward_iterator_tag: public input_iterator_tag{};
    struct bidirectional_iterator_tag: public forward_iterator_tag{};
    struct random_access_iterator_tag: public bidirectional_iterator_tag{};

    template<class T, class Compare>
    class MapIterator
    {
        public:

        typedef T   value_type;
        typedef T*  pointer_type;
        typedef T&  reference_type;
        typedef bstNode<T, Compare> node_type;
        typedef bstNode<T, Compare>* node_pointer;
        typedef  std::ptrdiff_t difference_type;
        typedef  bidirectional_iterator_tag iterator_category;

        node_pointer    dataNode;
        Compare c;

        MapIterator(): dataNode(NULL){}
        MapIterator(const node_pointer& node): dataNode(node){}


        // template <typename U, class Comp = Compare>
        MapIterator(const MapIterator& other): dataNode(other.dataNode){}

        MapIterator&   operator=(const MapIterator& rhs)
        {
            if(this != &rhs)
                this->dataNode = rhs.dataNode;
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
        pointer_type operator->() { return &operator*(); }

        MapIterator&       operator++()
        {
            if(dataNode->rightChild == NULL)
            {
                node_pointer temp = dataNode;
                if (dataNode->parent)
                {
                    dataNode = dataNode->parent;
                    while(dataNode->parent && c(dataNode->data.first, temp->data.first)) // use compare here later
                    {
                        dataNode = dataNode->parent;                            
                    }
                    if(dataNode->data.first < temp->data.first)
                    {
                        dataNode = dataNode->endNode;
                    }
                }
                else{
                    dataNode = dataNode->endNode;
                }
            }
            else if (dataNode->rightChild != NULL)
            {
                dataNode = dataNode->rightChild;
                get_far_left();
            }
            return (*this);
        }

        MapIterator&       operator--()
        {    
            if(dataNode->leftChild == NULL)
            {
                node_pointer temp = dataNode;
                if (dataNode->parent)
                {
                    dataNode = dataNode->parent;
                    while(dataNode->parent && c(temp->data.first, dataNode->data.first)) // use compare here later
                    {
                        dataNode = dataNode->parent;                            
                    }
                    if(dataNode->data.first > temp->data.first)
                    {
                        get_far_left();
                    }
                }
                else
                {
                    if(dataNode->endNode == dataNode)
                    {
                        dataNode = dataNode->root;
                        get_far_right();
                    }
                    else
                        get_far_left();
                }
            }
            else if (dataNode->leftChild != NULL)
            {
                dataNode = dataNode->leftChild;
                get_far_right();
            }
            return (*this);
        }
        // MapIterator       operator++(int)
        // {
        //     MapIterator temp(dataNode);
        //     ++(*this);
        //     return (temp);

        // }
        MapIterator operator++(int)
        {
            MapIterator tmp(dataNode);
            ++(*this);
            return (tmp);
        }  
        MapIterator operator--(int)
        {
            MapIterator tmp(dataNode);
            --(*this);
            return (tmp);
        }          
        private:
            void    get_far_left()
            {
                while(dataNode->leftChild)
                    dataNode = dataNode->leftChild;
            }
            void    get_far_right()
            {
                while(dataNode->rightChild)
                    dataNode = dataNode->rightChild;
            }
        //     bstNode *dataNode;

    };



}