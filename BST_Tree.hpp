
#include <iostream>
#include <vector>
#include <stack>

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


        void    addRecursive(bstNode *current, bstNode *&newNode, bool &res, bstNode* &nodeRes) {
        (void) res;
        (void) nodeRes;
        bstNode *temp;
        if(c(current->data.first, newNode->data.first))
        {
            if(current->rightChild == NULL)
            {
                current->rightChild = newNode;
                return;
            }
            temp = current->rightChild;
        }
        else if(c(newNode->data.first, current->data.first))
        {
            if(current->leftChild == NULL)
            {
                current->leftChild = newNode;
                return;
            }
            temp = current->leftChild;
        }
        else{
            std::cout << "OBJECT DOUBLICATE FOUND !!" << std::endl;
            return;
        }
        while(temp)
        {
            if(c(temp->data.first, newNode->data.first))
            {
                if(temp->rightChild == NULL)
                {
                    temp->rightChild = newNode;
                    return;
                }
                temp = temp->rightChild;
            }
            else if(c(newNode->data.first, temp->data.first))
            {
                if(temp->leftChild == NULL)
                {
                    temp->leftChild = newNode;
                    return;
                }
                temp = temp->leftChild;
            }
            else{
                std::cout << "OBJECT DOUBLICATE FOUND !!" << std::endl;
                return;
            }
        }

        }
        
         void    addRecursive2(bstNode *&current, bstNode *&newNode, bool &res, bstNode* &nodeRes) {
        // if (current == NULL) {
        //     newNode->parent = current;
        //     nodeRes = newNode;
        //     return (newNode);
        // }
        // if (c(newNode->data.first,  current->data.first)) {
        //     current->leftChild = addRecursive(current->leftChild, newNode, res, nodeRes);
        //     current->leftChild->parent = current;
        // } else if (c(current->data.first,  newNode->data.first)) {
        //     current->rightChild = addRecursive(current->rightChild, newNode, res, nodeRes);
        //     current->rightChild->parent = current;
        // } else {
        //     std::cout << "Value Already Exists !! " << std::endl;
        //     res = false;
        //     nodeRes = current;
        //     return current;
        // }
        // return current;
        (void) res;
        (void) nodeRes;
        bstNode *temp;
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;
        if(!current)
        {
            current = newNode;
            current->parent = NULL;
            return;
        }
        if(c(current->data.first, newNode->data.first))
        {
            if(current->rightChild == NULL)
            {
                current->rightChild = newNode;
                return;
            }
            temp = current->rightChild;
        }
        else if(c(newNode->data.first, current->data.first))
        {
            if(current->leftChild == NULL)
            {
                current->leftChild = newNode;
                return;
            }
            temp = current->leftChild;
        }
        else{
            std::cout << "OBJECT DOUBLICATE FOUND !!" << std::endl;
            return;
        }
        while(temp)
        {
            if(c(temp->data.first, newNode->data.first))
            {
                if(temp->rightChild == NULL)
                {
                    temp->rightChild = newNode;
                    return;
                }
                temp = temp->rightChild;
            }
            else if(c(newNode->data.first, temp->data.first))
            {
                if(temp->leftChild == NULL)
                {
                    temp->leftChild = newNode;
                    return;
                }
                temp = temp->leftChild;
            }
            else{
                std::cout << "OBJECT DOUBLICATE FOUND !!" << std::endl;
                return;
            }
        }

        }
        // template<class U>
        // bstNode*    find(bstNode* &curr, U &toFind)
        // {
        //     if(curr == NULL)
        //     {
        //         std::cout << "NOT FOUND !! \n";
        //         return(curr);
        //     }
        //     if(c(curr->data.first, toFind))
        //         return(find(curr->rightChild, toFind));
        //     if(c(toFind, curr->data.first))
        //         return(find(curr->leftChild, toFind));

        //     return(curr);
        // }

        // bstNode*    erase(bstNode* &curr)
        // {
        //     bstNode*    temp;
        //     if(curr->rightChild == NULL && curr->leftChild == NULL)
        //     {
        //         temp =  curr;
        //         if(curr->parent)
        //         {
        //                 if(curr->parent->leftChild == curr)
        //                     curr->parent->leftChild = NULL;
        //                 else if(curr->parent->rightChild == curr)
        //                     curr->parent->rightChild = NULL;
        //         }
        //         curr = NULL;
        //     }
        //     else if(curr->rightChild == NULL)
        //     {
        //         temp =  curr;
        //         if(curr->parent)
        //         {
        //             if(curr->parent->leftChild == curr)
        //                 curr->parent->leftChild = curr->leftChild;
        //             else if(curr->parent->rightChild == curr)
        //                 curr->parent->rightChild = curr->leftChild;
        //             curr->leftChild->parent = curr->parent;
        //         }
        //         curr->leftChild->root = curr->leftChild;
        //         curr->leftChild->endNode = curr->endNode;
        //         curr->leftChild->parent = NULL;
        //         curr = NULL;
        //     }
        //     else if(curr->leftChild == NULL)
        //     {
        //         temp =  curr;
        //         if(curr->parent)
        //         {
        //             if(curr->parent->leftChild == curr)
        //                 curr->parent->leftChild = curr->rightChild;
        //             else if(curr->parent->rightChild == curr)
        //                 curr->parent->rightChild = curr->rightChild;
        //             curr->rightChild->parent = curr->parent;
        //         }
        //         curr->rightChild->root = curr->rightChild;
        //         curr->rightChild->endNode = curr->endNode;
        //         curr->rightChild->parent = NULL;
        //         curr = NULL;
        //     }
        //     else
        //     {
        //         temp = curr;
        //         bstNode * replacement = get_far_left(curr->rightChild);
        //         replacement = erase(replacement);
        //         replacement->rightChild = curr->rightChild;
        //         replacement->leftChild = curr->leftChild;
        //         replacement->parent = curr->parent;
        //         if(curr->parent)
        //         {
        //             if(curr->parent->leftChild == curr)
        //                 curr->parent->leftChild = replacement;
        //             else if(curr->parent->rightChild == curr)
        //                 curr->parent->rightChild = replacement;
        //         }
        //         if(curr->rightChild)
        //             curr->rightChild->parent = replacement;
        //         if(curr->leftChild)
        //             curr->leftChild->parent = replacement;
        //         replacement->root = replacement;
        //         replacement->endNode = curr->endNode;
        //         // replacement->endNode->root = replacement;
        //         curr = replacement;
        //     }
        //     return (temp);
        // }

        // bstNode *get_far_left(bstNode* &node)
        // {
        //     bstNode *temp = node;
        //     while(temp->leftChild)
        //         temp = temp->leftChild;
        //     return (temp);
        // }

        // bstNode *get_root(bstNode* &node)
        // {
        //     bstNode *temp = node;
        //     while(temp->parent)
        //         temp = temp->parent;
        //     return (temp);
        // }
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

        // void printTree(bstNode    *root)
        // {
        //     std::vector<bstNode* > s;
        //     std::vector<bstNode*> s2;
        //     bstNode *curr = root;
        
        //     while (curr != NULL || s.empty() == false)
        //     {
        //         /* Reach the left most Node of the
        //         curr Node */
        //         while (curr !=  NULL)
        //         {
        //             /* place pointer to a tree node on
        //             the stack before traversing
        //             the node's left subtree */
        //             s2.push_back(curr);
        //             curr = curr->leftChild;
        //         }
        
        //         /* Current must be NULL at this point */
        //         curr = s2.back();
        //         s2.pop_back();
        
        //         std::cout << curr->data.first << " ";
        //         s.push_back(curr);
        
        //         /* we have visited the node and its
        //         left subtree.  Now, it's right
        //         subtree's turn */
        //         curr = curr->rightChild;
        
        //     } /* end of while */
        //     std::vector<bstNode*> it;
        //     for (size_t i = 0; i < s.size(); ++i)
        //     {
        //         std::cout << s[i]->data.first << " ";
        //     }
        // }
        // bstNode* buildTreeUtil(std::vector<bstNode*> &nodes, int start, 
        //                 int end) 
        // { 
        //     // base case 
        //     if (start > end) 
        //         return NULL; 
        
        //     /* Get the middle element and make it root */
        //     int mid = (start + end)/2; 
        //     bstNode* root = nodes[mid]; 
        
        //     /* Using index in Inorder traversal, construct 
        //     left and right subtress */
        //     root->leftChild  = buildTreeUtil(nodes, start, mid-1); 
        //     root->rightChild = buildTreeUtil(nodes, mid+1, end); 
        
        //     return root; 
        // } 
        // bstNode* buildTreeUtil(std::vector<bstNode*> &nodes, int start, 
        //                 int end) 
        // { 
        //     // base case 

        
        //     /* Get the middle element and make it root */
        //     int mid = (start + end)/2; 
        //     bstNode* root = nodes[mid]; 
        
        //     /* Using index in Inorder traversal, construct 
        //     left and right subtress */
        //     while()
        //     root->leftChild  = buildTreeUtil(nodes, start, mid-1); 
        //     root->rightChild = buildTreeUtil(nodes, mid+1, end); 
        
        //     return root; 
        // } 

        // bstNode* buildTreeUtil(std::vector<bstNode*> &nodes, size_t size)
        // { 
        //     bstNode* current = nodes[0];
        //     current->leftChild = NULL;
        //     current->rightChild = NULL;
        //     current->parent = NULL;
        //     bstNode* newNode;
        //     bstNode* temp;
        //     for(size_t i = 1; i < size ; ++i )
        //     {
        //         newNode = nodes[i];
        //         newNode->leftChild = NULL;
        //         newNode->rightChild = NULL;
        //         newNode->parent =NULL;
        //         if(c(current->data.first, newNode->data.first))
        //         {
        //         if(current->rightChild == NULL)
        //         {
        //             current->rightChild = newNode;
        //             continue;
        //         }
        //         temp = current->rightChild;
        //         }
        //         else if(c(newNode->data.first, current->data.first))
        //         {
        //         if(current->leftChild == NULL)
        //         {
        //             current->leftChild = newNode;
        //             continue;
        //         }
        //         temp = current->leftChild;
        //         }
        //         else{
        //         std::cout << "OBJECT DOUBLICATE FOUND !!" << std::endl;
        //             continue;
        //         }
        //         while(temp)
        //         {
        //         if(c(temp->data.first, newNode->data.first))
        //         {
        //             if(temp->rightChild == NULL)
        //             {
        //                 temp->rightChild = newNode;
        //                 break;
        //             }
        //             temp = temp->rightChild;
        //         }
        //         else if(c(newNode->data.first, temp->data.first))
        //         {
        //             if(temp->leftChild == NULL)
        //             {
        //                 temp->leftChild = newNode;
        //                 break;
        //             }
        //             temp = temp->leftChild;
        //         }
        //         else{
        //             std::cout << "OBJECT DOUBLICATE FOUND !!" << std::endl;
        //             break;
        //         }
        //         }
        //     }
            
        //    return current;
        // } 

        class IndxRng_t  // tool to simplify iteration
        {
        public:
        IndxRng_t() = delete; // no default
        IndxRng_t(int li, int ri)
            : lIndx (li)
            , rIndx (ri)
            {}
        ~IndxRng_t() = default;

        // get'er and set'er free.  also glutton free.  gmo free.
        bool            done() { return (lIndx > rIndx); } // range used up
        int              mid() { return ((lIndx + rIndx) / 2); } // compute
        IndxRng_t   left(int m) { return {lIndx, m-1}; }  // ctor
        IndxRng_t  right(int m) { return {m+1, rIndx}; }  // ctor
        private:
        int lIndx;
        int rIndx;
        };

        bstNode* array2balancedI(std::vector<bstNode*> &nodes, int lIndex, int rIndex)
        {
            std::vector<IndxRng_t>  todo;
            bstNode* result;
            result = NULL;
            bool rtf;
            bstNode* tmp;
            todo.push_back({lIndex, rIndex}); // load the first range

            // iterative loop (No recursion)
            do
            {
            if (0 == todo.size()) break; // exit constraint
            // no more ranges to extract mid from

            // fetch something to do
            IndxRng_t  todoRng = todo.back();
            todo.pop_back(); // and remove from the todo list

            if(todoRng.done()) continue; // lIndex > rIndex 

            int mid = todoRng.mid();
            result->addRecursive2(result, nodes[mid], rtf, tmp);  // do this
            // tree.insert(array[mid]);             // instead of this

            todo.push_back(todoRng.right(mid) ); // iterate on right
            todo.push_back(todoRng.left(mid)  ); // iterate on left

            }while(1);
            return result;
        }

 void storeBSTNodes(bstNode* root, std::vector<bstNode*> &nodes)
{
    // create an empty stack
    std::stack<bstNode*> stack;
 
    // start from the root node (set current node to the root node)
    bstNode* curr = root;
 
    // if the current node is null and the stack is also empty, we are done
    while (!stack.empty() || curr != NULL)
    {
        // if the current node exists, push it into the stack (defer it)
        // and move to its left child
        if (curr != NULL)
        {
            stack.push(curr);
            curr = curr->leftChild;
        }
        else {
            // otherwise, if the current node is null, pop an element from the stack,
            // print it, and finally set the current node to its right child
            curr = stack.top();
            stack.pop();
            nodes.push_back(curr);
 
            curr = curr->rightChild;
        }
    }
}
        // void storeBSTNodes(bstNode* root, std::vector<bstNode*> &nodes) 
        // { 
        // // Base case 
        // if (root==NULL) 
        //     return; 

        // // Store nodes in Inorder (which is sorted 
        // // order for BST) 
        // storeBSTNodes(root->leftChild, nodes); 
        // nodes.push_back(root); 
        // storeBSTNodes(root->rightChild, nodes); 
        // } 

        bstNode* buildTree(bstNode* root) 
        { 
            // Store nodes of given BST in sorted order 
            std::vector<bstNode*> nodes; 
            storeBSTNodes(root, nodes); 
            // Constucts BST from nodes[] 
            int n = nodes.size(); 
            return array2balancedI(nodes, 0, n - 1); 
        } 

        // void preOrder(bstNode* node) 
        // { 
        //     if (node == NULL) 
        //         return; 
        //     std::cout<<node->key<<" "; 
        //     preOrder(node->leftChild); 
        //     preOrder(node->rightChild); 
        // } 

        
    };

    
}