
#include <iostream>

namespace ft
{
    template <class T, class Compare>
    class bstNode
    {
        public:
        typedef T value_type;
        bstNode* parent;
        bstNode* leftChild;
        bstNode* rightChild;
        bstNode* endNode;
        bstNode* root;
        value_type  data;
        Compare c;

        bstNode():parent(NULL), leftChild(NULL), rightChild(NULL), endNode(NULL), root(NULL){}
        bstNode(T value): parent(NULL), leftChild(NULL), rightChild(NULL), endNode(NULL), root(NULL), data(value){}


        bstNode *addRecursive(bstNode *current, bstNode *newNode, bool &res, bstNode* &nodeRes) {
        if (current == NULL) {
            newNode->parent = current;
            nodeRes = newNode;
            return (newNode);
        }
        if (c(newNode->data.first,  current->data.first)) {
            current->leftChild = addRecursive(current->leftChild, newNode, res, nodeRes);
            current->leftChild->parent = current;
        } else if (c(current->data.first,  newNode->data.first)) {
            current->rightChild = addRecursive(current->rightChild, newNode, res, nodeRes);
            current->rightChild->parent = current;
        } else {
            std::cout << "Value Already Exists !! " << std::endl;
            res = false;
            nodeRes = current;
            return current;
        }
        return current;
        }
        
        template<class U>
        bstNode*    find(bstNode* &curr, U &toFind)
        {
            if(curr == NULL)
            {
                std::cout << "NOT FOUND !! \n";
                return(curr);
            }
            if(c(curr->data.first, toFind))
                return(find(curr->rightChild, toFind));
            if(c(toFind, curr->data.first))
                return(find(curr->leftChild, toFind));

            return(curr);
        }

        bstNode*    erase(bstNode* &curr)
        {
            bstNode*    temp;
            if(curr->rightChild == NULL && curr->leftChild == NULL)
            {
                temp =  curr;
                if(curr->parent->leftChild == curr)
                    curr->parent->leftChild = NULL;
                else if(curr->parent->rightChild == curr)
                    curr->parent->rightChild = NULL;
                curr = NULL;
            }
            else if(curr->rightChild == NULL)
            {
                temp =  curr;
                if(curr->parent->leftChild == curr)
                    curr->parent->leftChild = curr->leftChild;
                else if(curr->parent->rightChild == curr)
                    curr->parent->rightChild = curr->leftChild;
                curr = NULL;
            }
            else if(curr->leftChild == NULL)
            {
                temp =  curr;
                if(curr->parent->leftChild == curr)
                    curr->parent->leftChild = curr->rightChild;
                else if(curr->parent->rightChild == curr)
                    curr->parent->rightChild = curr->rightChild;
                curr = NULL;
            }
            return (temp);
        }

        // template<class U>
        // bool    isEqual(value_type &a, U &b)
        // {
        //     if(c(a.first, b))
        //         return false;
        //     else if(c(b.first, a))
        //         return true;

        //     return true;                
        // }
        void printTree(bstNode *node)
        {
            if (node != NULL)
            {
                printTree(node->leftChild);
                std::cout << node->data.first << " | ";
                printTree(node->rightChild);
            }
        }

        
    };

    
}