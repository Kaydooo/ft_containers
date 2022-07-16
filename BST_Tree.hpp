
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