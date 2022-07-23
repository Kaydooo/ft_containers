#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP
#include "container_utils.hpp"
#include <assert.h>
#include <iostream>
#include "MapIterator.hpp"
#define RED_COLOR "\033[0;31m"
#define CYAN_COLOR "\033[0;36m"
#define RESET "\033[0m"

#define LEFT  0
#define RIGHT 1
#define left  child[LEFT]
#define right child[RIGHT]
#define childDir(N) ( N == (N->parent)->right ? RIGHT : LEFT )


namespace ft
{
  template<class T, class Compare>
  class RedBlackTree {
    public:
    typedef MapIterator<T, Compare>     iterator;
    typedef MapIterator<T, Compare>     const_iterator;
    typedef RedBlackTree_Node<T>        node_type;
    typedef node_type*                  node_pointer;
    typedef std::allocator<node_type>   node_allocator;
    typedef typename std::allocator<T>::size_type  size_type;
    
    node_allocator nodeAllocator;
    node_pointer  root; 
    node_pointer  endNode;
    size_t  treeSize;
    Compare c;
    
      RedBlackTree(): root(NULL),treeSize(0)
      {
        nodeAllocator = node_allocator();
        endNode = nodeAllocator.allocate(1);
        std::cout << endNode << " < -- \n";
      }

      ~RedBlackTree(){} // Free Tree + endNode here later
      
      void printTree()
      {
        printTree(root);
      }
      void printTree(node_pointer node)
      {
          if (node != NULL)
          {
              printTree(node->left);
              if(node->color == RED)
                std::cout << RED_COLOR << node->data.first << RESET << " | ";
              else
                std::cout << node->data.first << " | ";
              
              printTree(node->right);
          }
      }

      iterator    begin()
      {
          node_pointer    temp;
          temp = root;
          if(temp->child[0])
          {
              while(temp->child[0])
                  temp = temp->child[0];
          }
          return (iterator(temp, endNode));
      }

      iterator    end()
      {
          endNode->parent = root;
          return (iterator(endNode, endNode));
      }

      const_iterator    begin() const
      {
          node_pointer    temp;
          temp = root;
          if(temp->child[0])
          {
              while(temp->child[0])
                  temp = temp->child[0];
          }
          return (const_iterator(temp, endNode));
      }

      const_iterator    end() const
      {
          endNode->parent = root;
          return (const_iterator(endNode, endNode));
      }


        size_type	size(void) const { return (treeSize); }
        size_type	max_size(void) const {return (node_allocator().max_size());}
        bool		empty(void) const {return (treeSize == 0? true : false);}

      std::pair<iterator,bool>    insert(const T& value )
      {
        std::pair<iterator, bool> result;
        node_pointer              nodeRes;
        node_pointer              newNode = nodeAllocator.allocate(1);

        nodeAllocator.construct(newNode, value);
        newNode->parent = NULL;
        newNode->child[0] = NULL;
        newNode->child[1] = NULL;
        result.second = true;
        if(treeSize == 0)
        {
          root = newNode;
          result.first = iterator(newNode, this->endNode);
        }
        else
        {
          nodeRes = insertNode(root, newNode);
          if(nodeRes != newNode)
          {
            result.second = false;
            // nodeAllocator.deallocate(newNode);
            // nodeAllocator.destory(newNode, 1);
          }
          result.first = iterator(nodeRes, this->endNode);
        }
        if (result.second)
          treeSize++;
        return (result);

      }
      node_pointer    insertNode(node_pointer &current, node_pointer &newNode) {

          node_pointer temp;
          if(c(current->data.first, newNode->data.first))
          {
              if(current->right == NULL)
              {
                  insertBalanced(this, newNode, current, RIGHT);
                  return newNode;
              }
              temp = current->right;
          }
          else if(c(current->data.first, newNode->data.first))
          {
              if(current->left == NULL)
              {
                  insertBalanced(this, newNode, current, LEFT);
                  return newNode;
              }
              temp = current->left;
          }
          else{
              std::cout << "OBJECT DOUBLICATE FOUND !!" << std::endl;
              return current;
          }
          while(temp)
          {
              if(c(temp->data.first , newNode->data.first))
              {
                  if(temp->right == NULL)
                  {
                      insertBalanced(this, newNode, temp, RIGHT);
                      return newNode;
                  }
                  temp = temp->right;
              }
              else if(c(temp->data.first , newNode->data.first))
              {
                  if(temp->left == NULL)
                  {
                      insertBalanced(this, newNode, temp, LEFT);
                      return newNode;
                  }
                  temp = temp->left;
              }
              else{
                  std::cout << "OBJECT DOUBLICATE FOUND !!" << std::endl;
                  return temp;
              }
          }
          return current;
      }

      node_pointer RotateDirRoot(RedBlackTree* Tree, node_pointer P, int dir)
      {  
        node_pointer G = P->parent;
        node_pointer S = P->child[1-dir];
        node_pointer C;
        assert(S != NULL);
        C = S->child[dir];
        P->child[1-dir] = C; if (C != NULL) C->parent = P;
        S->child[  dir] = P; P->parent = S;
        S->parent = G;
        if (G != NULL)
          G->child[ P == G->right ? RIGHT : LEFT ] = S;
        else
          Tree->root = S;
        return S; 
      }

      void insertBalanced(RedBlackTree* Tree, node_pointer N, node_pointer P, int dir)
      {
        node_pointer G;
        node_pointer U;

        N->color = RED;
        N->left  = NULL;
        N->right = NULL;
        N->parent = P;
        if (P == NULL)
          Tree->root = N;    
        P->child[dir] = N; 

        do 
        {
          if (P->color == BLACK)
            return;
      
          if ((G = P->parent) == NULL)  
          {
            P->color = BLACK;
            return;
          } 
          
          dir = childDir(P); 
          U = G->child[1-dir]; 
          if (U == NULL || U->color == BLACK) 
          {
            if (N == P->child[1-dir])
            { 
              RotateDirRoot(Tree, P, dir); 
              N = P; 
              P = G->child[dir];
            }
            RotateDirRoot(Tree,G,1-dir); 
            P->color = BLACK;
            G->color = RED;
            return; 
          } 
          P->color = BLACK;
          U->color = BLACK;
          G->color = RED;
          if(G->parent == NULL)
            G->color = BLACK;
          N = G; 
        } while ((P = N->parent) != NULL);

        return;
        

      } // end of insertBalanced


      template<class U>
      size_type    count(U &toFind) const
      {
        if (find(root, toFind))
            return(1);
        return(0);
      }

      template<class U>
      iterator    find(U &toFind)
      {
        node_pointer result;
        result = find(root, toFind);
        if (result == NULL)
            return(end());
        return(iterator(result, endNode));
      }

      template<class U>
      node_pointer    find(node_pointer &curr, U &toFind)
      {
        if(curr == NULL)
        {
            std::cout << "NOT FOUND !! \n";
            return(curr);
        }
        if(c(curr->data.first, toFind))
            return(find(curr->child[1], toFind));
        if(c(toFind, curr->data.first))
            return(find(curr->child[0], toFind));

        return(curr);
      }

      template<class U>
      node_pointer    find(node_pointer curr, U &toFind) const
      {
        if(curr == NULL)
        {
            std::cout << "NOT FOUND !! \n";
            return(curr);
        }
        if(c(curr->data.first, toFind))
            return(find(curr->child[1], toFind));
        if(c(toFind, curr->data.first))
            return(find(curr->child[0], toFind));

        return(curr);
      }
      
  };

  
} // namespace ft
#endif
