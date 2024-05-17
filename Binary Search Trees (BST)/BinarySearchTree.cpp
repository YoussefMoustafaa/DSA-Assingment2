
#include "BinarySearchTree.h"

template <class T>
binarySearchTreeType<T>::binarySearchTreeType(function<int(const T &, const T &)> comp)
{
    root = NULL;
    compare = comp;
}

template <class T>
bool binarySearchTreeType<T>::isEmpty()
{
    return (root == NULL);
}

template <class T>
void binarySearchTreeType<T>::inorderTraversal()
{
    inorder(root);
}

template <class T>
void binarySearchTreeType<T>::preorderTraversal()
{
    preorder(root);
}

template <class T>
void binarySearchTreeType<T>::postorderTraversal()
{
    postorder(root);
}

template <class T>
void binarySearchTreeType<T>::inorder(nodeType<T> *p)
{
    if (p != NULL)
    {
        inorder(p->left);
        cout << p->data << " ";
        inorder(p->right);
    }
}

template <class T>
void binarySearchTreeType<T>::preorder(nodeType<T> *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        preorder(p->left);
        preorder(p->right);
    }
}

template <class T>
void binarySearchTreeType<T>::postorder(nodeType<T> *p)
{
    if (p != NULL)
    {
        postorder(p->left);
        postorder(p->right);
        cout << p->data << " ";
    }
}

template <class T>
void binarySearchTreeType<T>::clear(nodeType<T> *&p)
{
    if (p != NULL)
    {
        clear(p->left);
        clear(p->right);
        delete p;
        p = NULL;
    }
}

template <class T>
void binarySearchTreeType<T>::clearTree()
{
    clear(root);
}

template <class T>
binarySearchTreeType<T>::~binarySearchTreeType()
{
    clear(root);
}

template <class T>
bool binarySearchTreeType<T>::search(T item)
{
    nodeType<T> *current = root;

    while (current != NULL)
    {
        int compResult = compare(item, current->data);
        if (compResult < 0)
            current = current->left;
        else if (compResult > 0)
            current = current->right;
        else
            return true;
    }

    return false;
}

template <class T>
bool binarySearchTreeType<T>::searchRec(T item)
{
    return searchRecPriv(root, item);
}

template <class T>
bool binarySearchTreeType<T>::searchRecPriv(nodeType<T> *p, T item)
{
    if (p == NULL)
        return false;
    int compResult = compare(p->data, item);
    if (compResult == 0)
        return true;
    else if (compResult > 0)
        return searchRecPriv(p->left, item);
    else
        return searchRecPriv(p->right, item);
}

template <class T>
void binarySearchTreeType<T>::insert(T item)
{
    nodeType<T> *current;      // pointer to traverse the tree
    nodeType<T> *trailCurrent; // pointer behind current
    nodeType<T> *newNode;      // pointer to create the node

    newNode = new nodeType<T>;
    assert(newNode != NULL);
    newNode->data = item;
    newNode->left = NULL;
    newNode->right = NULL;

    if (root == NULL)
        root = newNode;
    else
    {
        current = root;
        trailCurrent = NULL;

        while (current != NULL)
        {
            trailCurrent = current;

            int compResult = compare(item, current->data);
            if (compResult < 0)
                current = current->left;
            else if (compResult > 0)
                current = current->right;
            else
            {
                cout << "The insert item is already in the list -- ";
                cout << "duplicates are not allowed." << endl;
                delete newNode;
                return;
            }
        } // end while

        int compResult = compare(item, trailCurrent->data);
        if (compResult < 0)
            trailCurrent->left = newNode;
        else
            trailCurrent->right = newNode;
    }
}

template <class T>
void binarySearchTreeType<T>::remove(T item)
{
    nodeType<T> *current;      // pointer to traverse the tree
    nodeType<T> *trailCurrent; // pointer behind current
    bool found = false;

    if (root == NULL)
    {
        cout << "Cannot delete from the empty tree." << endl;
        return;
    }

    current = root;
    trailCurrent = root;

    while (current != NULL && !found)
    {
        int compResult = compare(current->data, item);
        if (compResult == 0)
            found = true;
        else
        {
            trailCurrent = current;

            if (compResult < 0)
                current = current->left;
            else
                current = current->right;
        }
    } // end while

    if (current == NULL)
        cout << "The delete item is not in the tree." << endl;
    else if (found)
    {
        if (current == root)
            deleteFromTree(root);
        else
        {
            int compResult = compare(trailCurrent->data, item);
            if (compResult > 0)
                deleteFromTree(trailCurrent->left);
            else
                deleteFromTree(trailCurrent->right);
        }
    }
    else
        cout << "The delete item is not in the tree." << endl;
}

template <class T>
void binarySearchTreeType<T>::deleteFromTree(nodeType<T> *&p)
{
    nodeType<T> *current;      // pointer to traverse
                               // the tree
    nodeType<T> *trailCurrent; // pointer behind current
    nodeType<T> *temp;         // pointer to delete the node

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
        } // end while

        p->data = current->data;

        if (trailCurrent == NULL) // current did not move;
                                  // current == p->left; adjust p
            p->left = current->left;
        else
            trailCurrent->right = current->left;

        delete current;
    }
}
