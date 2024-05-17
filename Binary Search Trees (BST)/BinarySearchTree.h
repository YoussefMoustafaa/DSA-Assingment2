#include <iostream>
#include <functional>
#include <cassert>

using namespace std;

template <class T>
struct nodeType
{
    T data;
    nodeType *left;
    nodeType *right;
};

template <class T>
class binarySearchTreeType

{
private:
    nodeType<T> *root;
    function<int(const T &, const T &)> compare;
    void clear(nodeType<T> *&p);
    void inorder(nodeType<T> *p);
    void preorder(nodeType<T> *p);
    void postorder(nodeType<T> *p);
    void deleteFromTree(nodeType<T> *&p);
    bool searchRecPriv(nodeType<T> *, T);

public:
    bool isEmpty();
    bool search(T);
    bool searchRec(T);
    void insert(T);
    void remove(T);
    void inorderTraversal();
    void preorderTraversal();
    void postorderTraversal();
    void clearTree();
    binarySearchTreeType(function<int(const T &, const T &)> comp = less<T>());
    ~binarySearchTreeType();
};
