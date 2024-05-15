#include <iostream>
#include <cassert>
// #include "itemClass/Item.h"
#include "BinarySearchTree.h"
using namespace std;

// constructor initializing the root with null
template <class T>
BinarySearchTree<T>::BinarySearchTree()
{
    root = NULL;
}

//***********************************************************************************

// traversing through the tree
template <class T>
void BinarySearchTree<T>::inorderTraversal()
{
    inorder(root);
}
template <class T>
void BinarySearchTree<T>::preorderTraversal()
{
    preorder(root);
}

template <class T>
void BinarySearchTree<T>::postorderTraversal()
{
    postorder(root);
}

template <class T>
void BinarySearchTree<T>::inorder(node<T> *p)
{
    if (p != NULL)
    {
        inorder(p->left);
        cout << p->data << " ";
        inorder(p->right);
    }
}

template <class T>
void BinarySearchTree<T>::preorder(node<T> *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        preorder(p->left);
        preorder(p->right);
    }
}

template <class T>
void BinarySearchTree<T>::postorder(node<T> *p)
{
    if (p != NULL)
    {
        postorder(p->left);
        postorder(p->right);
        cout << p->data << " ";
    }
}

//***************************************************************************************

// checking is empty

template <class T>
bool BinarySearchTree<T>::isEmpty()
{
    return (root == NULL);
}
//***************************************************************************************

// inserting into tree

template <class T>
void BinarySearchTree<T>::insert(T data)
{
    node<T> *newNode = new node<T>();
    newNode->data = data;

    if (root == NULL)
    {
        root = newNode;
        return;
    }
    node<T> *current = root;
    node<T> *trailCurrent = root;
    while (current != NULL)
    {
        trailCurrent = current;
        current->data < data ? current = current->right : current = current->left;
    }

    // you can't set the current directly to new node because it will not be connected to its parent node
    // so you need to set the new node to the left or right of the trailCurrent
    data > trailCurrent->data ? trailCurrent->right = newNode : trailCurrent->left = newNode;
}

//*********************************************************************************
// searching
template <class T>
bool BinarySearchTree<T>::search(T item)
{
    node<T> *current = root;

    while (current != NULL)
    {
        if (current->data == item)
            return true;
        else if (current->data > item)
            current = current->left;
        else
            current = current->right;
    }

    return false;
}
//*****************************************************************************

// deletion from tree

// first item is searched to make sure it is in the tree
template <class T>
void BinarySearchTree<T>::remove(T item)
{
    node<T> *current;      // pointer to traverse the tree
    node<T> *trailCurrent; // pointer behind current

    if (root == NULL)
    {
        cout << "Cannot delete from the empty tree." << endl;
        return;
    }

    if (root->data == item)
    {
        deleteFromTree(root);
        return;
    }

    // If code reaches here, the item is not the root
    trailCurrent = root;

    if (root->data > item)
        current = root->left;
    else
        current = root->right;

    // Search for the item to be deleted
    while (current != NULL)
    {
        if (current->data == item)
            break;
        else
        {
            trailCurrent = current;
            if (current->data > item)
                current = current->left;
            else
                current = current->right;
        }
    }

    // Once the while loop is done, current points to either NULL or to the node to be deleted
    if (current == NULL)
        cout << "The delete item is not in the tree." << endl;
    else if (trailCurrent->data > item)
        deleteFromTree(trailCurrent->left);
    else
        deleteFromTree(trailCurrent->right);
}

template <class T>
void BinarySearchTree<T>::deleteFromTree(node<T> *p)
{
    node<T> *current;      // pointer to traverse the tree
    node<T> *trailCurrent; // pointer behind current
    node<T> *temp;         // pointer to delete the node

    if (p->left == NULL && p->right == NULL)
    {
        delete p;
        p = NULL;
    }
    else if (p->left == NULL)
    {
        temp = p;
        p = p->right;
        delete temp;
    }
    else if (p->right == NULL)
    {
        temp = p;
        p = p->left;
        delete temp;
    }
    else
    {
        current = p->left;
        trailCurrent = NULL;

        while (current->right != NULL)
        {
            trailCurrent = current;
            current = current->right;
        }

        p->data = current->data;

        if (trailCurrent == NULL) // Current did not move; current == p->left; adjust p
            p->left = current->left;
        else
            trailCurrent->right = current->left;

        delete current;
    }
}
