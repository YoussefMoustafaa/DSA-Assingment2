#include <iostream>
#include <cassert>

template <class T>
struct node
{
    T data;
    node<T> *left;
    node<T> *right;
    node()
    {
        left = NULL;
        right = NULL;
    }
};

template <class T>
class BinarySearchTree
{
private:
    node<T> *root;
    void inorder(node<T> *);
    void preorder(node<T> *);
    void postorder(node<T> *);
    void deleteFromTree(node<T> *);

public:
    BinarySearchTree();
    void inorderTraversal();
    void preorderTraversal();
    void postorderTraversal();
    bool isEmpty();
    void insert(T data);
    bool search(T item);
    void remove(T data);
};

//*******************************************
// class BinarySearchTreeForItem : BinarySearchTree<Item>
// {
// };
