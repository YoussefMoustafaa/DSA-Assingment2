
#include "BinarySearchTree.h"

template <class T>
binarySearchTreeType<T>::binarySearchTreeType(function<int(const T &, const T &)> comp)
{
    root = nullptr;
    compare = comp;
}

template <class T>
bool binarySearchTreeType<T>::isEmpty()
{
    return (root == nullptr);
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
void binarySearchTreeType<T>::descendingorderTraversal()
{
    descendingorder(root);
}

template <class T>
void binarySearchTreeType<T>::inorder(nodeType<T> *p)
{
    if (p != nullptr)
    {
        inorder(p->left);
        cout << p->data << " ";
        inorder(p->right);
    }
}

template <class T>
void binarySearchTreeType<T>::preorder(nodeType<T> *p)
{
    if (p != nullptr)
    {
        cout << p->data << " ";
        preorder(p->left);
        preorder(p->right);
    }
}

template <class T>
void binarySearchTreeType<T>::postorder(nodeType<T> *p)
{
    if (p != nullptr)
    {
        postorder(p->left);
        postorder(p->right);
        cout << p->data << " ";
    }
}

template <class T>
void binarySearchTreeType<T>::descendingorder(nodeType<T> *p)
{
    if (p != nullptr)
    {
        descendingorder(p->right);
        cout << p->data << " ";
        descendingorder(p->left);
    }
}

template <class T>
void binarySearchTreeType<T>::clear(nodeType<T> *&p)
{
    if (p != nullptr)
    {
        clear(p->left);
        clear(p->right);
        delete p;
        p = nullptr;
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

    while (current != nullptr)
    {
        int compResult = compare(item, current->data);
        if (compResult == 0)
            return true;
        else if (compResult < 0)
            current = current->left;
        else
            current = current->right;
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
    if (p == nullptr)
        return false;

    int compResult = compare(p->data, item);
    if (compResult == 0)
        return true;
    else if (compResult < 0)
        return searchRecPriv(p->left, item);
    else
        return searchRecPriv(p->right, item);
}

template <class T>
void binarySearchTreeType<T>::insert(T item)
{
    nodeType<T> *current;
    nodeType<T> *trailCurrent;
    nodeType<T> *newNode;

    newNode = new nodeType<T>;
    newNode->data = item;
    newNode->left = nullptr;
    newNode->right = nullptr;

    if (root == nullptr)
        root = newNode;
    else
    {
        current = root;
        trailCurrent = nullptr;

        while (current != nullptr)
        {
            trailCurrent = current;
            int compResult = compare(item, current->data);
            if (compResult < 0)
                current = current->left;
            else
                current = current->right;
        }

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
    nodeType<T> *current = root;
    nodeType<T> *parent = nullptr;
    bool found = false;

    if (root == nullptr)
    {
        cout << "Cannot delete from the empty tree." << endl;
        return;
    }

    // Find the node to be deleted and its parent
    while (current != nullptr && !found)
    {
        int compResult = compare(current->data, item);
        if (compResult == 0)
            found = true;
        else
        {
            parent = current;
            if (compResult < 0)
                current = current->left;
            else
                current = current->right;
        }
    }

    if (!found)
    {
        cout << "The delete item is not in the tree." << endl;
        return;
    }

    // Case 1: Node to be deleted is a leaf node
    if (current->left == nullptr && current->right == nullptr)
    {
        if (parent == nullptr) // Root node
            root = nullptr;
        else if (parent->left == current)
            parent->left = nullptr;
        else
            parent->right = nullptr;
        delete current;
    }
    // Case 2: Node to be deleted has one child
    else if (current->left == nullptr || current->right == nullptr)
    {
        nodeType<T> *child = (current->left != nullptr) ? current->left : current->right;
        if (parent == nullptr) // Root node
            root = child;
        else if (parent->left == current)
            parent->left = child;
        else
            parent->right = child;
        delete current;
    }
    // Case 3: Node to be deleted has two children
    else
    {
        // Find the successor node
        nodeType<T> *successor = current->right;
        parent = current;

        while (successor->left != nullptr)
        {
            parent = successor;
            successor = successor->left;
        }

        // Copy the data of the successor to the current node
        current->data = successor->data;

        // Delete the successor node (it will have no left child)
        if (parent->left == successor)
            parent->left = successor->right;
        else
            parent->right = successor->right;

        delete successor;
    }
}
