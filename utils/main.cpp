#include "RedBlackTree.hpp"


int main()
{
    typedef std::pair<int, int>     value_type;
    int SIZE = 200000;
    ft::RedBlackTree<value_type, std::less<int>> test;
    ft::RedBlackTree_Node<value_type> *parent;
    parent = new ft::RedBlackTree_Node<value_type>();
    ft::RedBlackTree_Node<value_type> *n1;
    n1 = new ft::RedBlackTree_Node<value_type>();
    n1->child[0] = NULL;
    n1->child[1] = NULL;
    n1->parent = NULL;
    n1->data = std::make_pair(0, 10);
    n1 = new ft::RedBlackTree_Node<value_type>();
    test.root = n1;
    for(int i = 1; i < SIZE; ++i)
    {
        n1 = new ft::RedBlackTree_Node<value_type>();
        n1->data = std::make_pair(i, 20);
        test.insertNode(test.root, n1);
    }
    // test.printTree(test.root);
    return 0;
}