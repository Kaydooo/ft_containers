
#include <iostream>
#include <vector>

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
                if(curr->parent)
                {
                        if(curr->parent->leftChild == curr)
                            curr->parent->leftChild = NULL;
                        else if(curr->parent->rightChild == curr)
                            curr->parent->rightChild = NULL;
                }
                curr = NULL;
            }
            else if(curr->rightChild == NULL)
            {
                temp =  curr;
                if(curr->parent)
                {
                    if(curr->parent->leftChild == curr)
                        curr->parent->leftChild = curr->leftChild;
                    else if(curr->parent->rightChild == curr)
                        curr->parent->rightChild = curr->leftChild;
                    curr->leftChild->parent = curr->parent;
                }
                curr->leftChild->root = curr->leftChild;
                curr->leftChild->endNode = curr->endNode;
                curr->leftChild->parent = NULL;
                curr = NULL;
            }
            else if(curr->leftChild == NULL)
            {
                temp =  curr;
                if(curr->parent)
                {
                    if(curr->parent->leftChild == curr)
                        curr->parent->leftChild = curr->rightChild;
                    else if(curr->parent->rightChild == curr)
                        curr->parent->rightChild = curr->rightChild;
                    curr->rightChild->parent = curr->parent;
                }
                curr->rightChild->root = curr->rightChild;
                curr->rightChild->endNode = curr->endNode;
                curr->rightChild->parent = NULL;
                curr = NULL;
            }
            else
            {
                temp = curr;
                bstNode * replacement = get_far_left(curr->rightChild);
                replacement = erase(replacement);
                replacement->rightChild = curr->rightChild;
                replacement->leftChild = curr->leftChild;
                replacement->parent = curr->parent;
                if(curr->parent)
                {
                    if(curr->parent->leftChild == curr)
                        curr->parent->leftChild = replacement;
                    else if(curr->parent->rightChild == curr)
                        curr->parent->rightChild = replacement;
                }
                if(curr->rightChild)
                    curr->rightChild->parent = replacement;
                if(curr->leftChild)
                    curr->leftChild->parent = replacement;
                replacement->root = replacement;
                replacement->endNode = curr->endNode;
                // replacement->endNode->root = replacement;
                curr = replacement;
            }
            return (temp);
        }

        bstNode *get_far_left(bstNode* &node)
        {
            bstNode *temp = node;
            while(temp->leftChild)
                temp = temp->leftChild;
            return (temp);
        }

        bstNode *get_root(bstNode* &node)
        {
            bstNode *temp = node;
            while(temp->parent)
                temp = temp->parent;
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

        bstNode* buildTreeUtil(std::vector<bstNode*> &nodes, int start, 
                        int end) 
        { 
            // base case 
            if (start > end) 
                return NULL; 
        
            /* Get the middle element and make it root */
            int mid = (start + end)/2; 
            bstNode* root = nodes[mid]; 
        
            /* Using index in Inorder traversal, construct 
            left and right subtress */
            root->leftChild  = buildTreeUtil(nodes, start, mid-1); 
            root->rightChild = buildTreeUtil(nodes, mid+1, end); 
        
            return root; 
        } 

        void storeBSTNodes(bstNode* root, std::vector<bstNode*> &nodes) 
        { 
        // Base case 
        if (root==NULL) 
            return; 

        // Store nodes in Inorder (which is sorted 
        // order for BST) 
        storeBSTNodes(root->leftChild, nodes); 
        nodes.push_back(root); 
        storeBSTNodes(root->rightChild, nodes); 
        } 

        bstNode* buildTree(bstNode* root) 
        { 
            // Store nodes of given BST in sorted order 
            std::vector<bstNode*> nodes; 
            storeBSTNodes(root, nodes); 
        
            // Constucts BST from nodes[] 
            int n = nodes.size(); 
            return buildTreeUtil(nodes, 0, n-1); 
        } 

        void preOrder(bstNode* node) 
        { 
            if (node == NULL) 
                return; 
            std::cout<<node->key<<" "; 
            preOrder(node->leftChild); 
            preOrder(node->rightChild); 
        } 

        
    };

    
}