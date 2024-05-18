//
// Created by mahmoud on 5/12/2024.
//

#include "AVLTree.h"
#include <iostream>
#include <functional>

using namespace std;

template<class T>
AVLTree<T>::AVLTree(function<int(const T&, const T&)> comp)
{
    root = nullptr;
    compare = comp;
}

template<class T>
void AVLTree<T>::clear(Node<T> *p)
{
    if (p)
    {
        clear(p->lchild);
        clear(p->rchild);
        delete p;
        p = nullptr;
    }
}

template<class T>
Node<T>* AVLTree<T>::getRoot()
{
    return root;
}

template<class T>
int AVLTree<T>::BalanceFactor(Node<T> *p)
{
    int hl = (p && p->lchild) ? p->lchild->height : 0;
    int hr = (p && p->rchild) ? p->rchild->height : 0;
    return hl - hr;
}

template<class T>
int AVLTree<T>::NodeHeight(Node<T> *p)
{
    int hl = (p && p->lchild) ? p->lchild->height : 0;
    int hr = (p && p->rchild) ? p->rchild->height : 0;
    return hl > hr ? hl + 1 : hr + 1;
}


template<class T>
Node<T>* AVLTree<T>::LLRotation(Node<T> *p)
{
    Node<T> *pl = p->lchild;
    Node<T> *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if (root == p)
        root = pl;

    return pl;
}


template<class T>
Node<T>* AVLTree<T>::LRRotation(Node<T> *p)
{
    Node<T> *pl = p->lchild;
    Node<T> *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;
    
    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    if (root == p)
        root = plr;

    return plr;
}


template<class T>
Node<T>* AVLTree<T>::RRRotation(Node<T> *p)
{
    Node<T> *pr = p->rchild;
    Node<T> *prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    if (root == p)
        root = pr;

    return pr;
}


template<class T>
Node<T>* AVLTree<T>::RLRotation(Node<T> *p)
{
    Node<T> *pr = p->rchild;
    Node<T> *prl = pr->lchild;

    p->rchild = prl->lchild;
    pr->lchild = prl->rchild;

    prl->lchild = p;
    prl->rchild = pr;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    prl->height = NodeHeight(prl);

    if (root == p)
        root = prl;

    return prl;
}


template<class T>
Node<T>* AVLTree<T>::insert(Node<T> *p, T key)
{
    Node<T> *t = NULL;
    if (p == NULL) {
        t = new Node<T>();
        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (compare(key, p->data))
        p->lchild = insert(p->lchild, key);
    else if (compare(p->data, key))
        p->rchild = insert(p->rchild, key);

    p->height = NodeHeight(p);

    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
        return LLRotation(p);
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
        return LRRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
        return RRRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
        return RLRotation(p);

    return p;
}


template<class T>
Node<T>* AVLTree<T>::InOrderPredecessor(Node<T>* p) {
    while (p && p->rchild != nullptr) {
        p = p->rchild;
    }
    return p;
}


template<class T>
Node<T>* AVLTree<T>::InOrderSuccessor(Node<T>* p) {
    while (p && p->lchild != nullptr) {
        p = p->lchild;
    }
    return p;
}

template<class T>
Node<T>* AVLTree<T>::Delete(Node<T> *p, T key)
{
    if (p == nullptr)
        return nullptr;

    if (compare(key, p->data))
        p->lchild = Delete(p->lchild, key);
    else if (compare(p->data, key))
        p->rchild = Delete(p->rchild, key);
    else {
        if (p->lchild == nullptr || p->rchild == nullptr) {
            Node<T>* temp = p->lchild ? p->lchild : p->rchild;
            if (temp == nullptr) {
                temp = p;
                p = nullptr;
            } else {
                *p = *temp;
            }
            delete temp;
        } else {
            Node<T>* temp = InOrderSuccessor(p->rchild);
            p->data = temp->data;
            p->rchild = Delete(p->rchild, temp->data);
        }
    }

    if (p == nullptr)
        return p;

    p->height = NodeHeight(p);

    // int balance = BalanceFactor(p);

    // if (balance > 1 && BalanceFactor(p->lchild) >= 0)
    //     return LLRotation(p);
    // if (balance > 1 && BalanceFactor(p->lchild) < 0) {
    //     p->lchild = LRRotation(p->lchild);
    //     return LLRotation(p);
    // }
    // if (balance < -1 && BalanceFactor(p->rchild) <= 0)
    //     return RRRotation(p);
    // if (balance < -1 && BalanceFactor(p->rchild) > 0) {
    //     p->rchild = RLRotation(p->rchild);
    //     return RRRotation(p);
    // }

    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
        return LLRotation(p);
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
        return LRRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
        return RRRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
        return RLRotation(p);

    return p;
}


template<class T>
void AVLTree<T>::ascdisplay(Node<T> *p)
{
    if (p) {
        ascdisplay(p->lchild);
        cout << p->data << " ";
        ascdisplay(p->rchild);
    }
}template<class T>
void AVLTree<T>::dscdisplay(Node<T> *p)
{
    if (p) {
        dscdisplay(p->rchild);
        cout << p->data << " ";
        dscdisplay(p->lchild);
    }
}




template<class T>
AVLTree<T>::~AVLTree()
{
    clear(root);
}
template<class T>
vector<T> AVLTree<T>::getAllNodes() {
    vector<T> nodes;
    traverseAndStore(root, nodes);
    return nodes;
}

template<class T>
void AVLTree<T>::traverseAndStore(Node<T> *p, vector<T> &nodes) {
    if (p) {
        traverseAndStore(p->lchild, nodes);
        nodes.push_back(p->data);
        traverseAndStore(p->rchild, nodes);
    }
}
