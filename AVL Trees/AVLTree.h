//
// Created by mahmoud on 5/12/2024.
//

#ifndef DSA_ASSINGMENT2_AVLTREE_H
#define DSA_ASSINGMENT2_AVLTREE_H


#include <iostream>
#include <functional>
#include <vector>

using namespace std;

template<class T>
struct Node
{
    T data;
    int height;
    Node *lchild;
    Node *rchild;
};

template<class T>
class AVLTree {
private:

    function<int(const T&, const T&)> compare;
    void traverseAndStore(Node<T> *p, std::vector<T> &nodes);
public:
    Node<T> *root;
    AVLTree(function<int(const T&, const T&)> comp = less<T>());
    Node<T>* getRoot();
    void clear(Node<T> *p);
    int BalanceFactor(Node<T> *p);
    int NodeHeight(Node<T> *p);
    Node<T> *LLRotation(Node<T> *p);
    Node<T> *LRRotation(Node<T> *p);
    Node<T> *RRRotation(Node<T> *p);
    Node<T> *RLRotation(Node<T> *p);
    Node<T> *insert(Node<T> *p, T key);
    Node<T> *InOrderPredecessor(Node<T> *p);
    Node<T> *InOrderSuccessor(Node<T> *p);
    Node<T> *Delete(Node<T> *p, T key);
    void ascdisplay(Node<T> *p);
    void dscdisplay(Node<T> *p);
    std::vector<T> getAllNodes();
    ~AVLTree();

};


#endif //DSA_ASSINGMENT2_AVLTREE_H
