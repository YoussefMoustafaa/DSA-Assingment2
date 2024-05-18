#include <bits/stdc++.h>

using namespace std;

struct Node
{
     Node *lchild;
    int data;
    int height;
     Node *rchild;
} *root = nullptr;

int BalanceFactor( Node *p)
{
    int hl, hr;

    hl = (p && p->lchild) ? p->lchild->height:0;
    hr = (p && p->rchild) ? p->rchild->height:0;

    return hl-hr;
}


int NodeHeight(Node *p)
{
    int hl, hr;
    hl = (p && p->lchild) ? p->lchild->height:0;
    hr = (p && p->rchild) ? p->rchild->height:0;

    return hl > hr ? hl+1 : hr+1;
}


 Node *LLRotation( Node *p)
{
     Node *pl = p->lchild;
     Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if (root == p)
        root = pl;

    return pl;
}

 Node *LRRotation( Node *p)
{
     Node *pl = p->lchild;
     Node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    if (root = p)
        root = plr;

    return plr;
}


 Node* RRRotation( Node *p)
{
     Node *pr = p->rchild;
     Node *prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    if (root == p)
        root = pr;

    return pr;
}


 Node *RLRotation( Node *p)
{
     Node *pr = p->rchild;
     Node *prl = pr->lchild;

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


 Node *RInsert( Node *p, int key)
{
     Node *t = NULL;

    if (p == NULL) {
        t = new Node();
        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = NULL;
        return t;
    }

    if (key < p->data)
        p->lchild = RInsert(p->lchild, key);
    else
        p->rchild = RInsert(p->rchild, key);

    p->height = NodeHeight(p);

    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
        return LLRotation(p);
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
        return LRRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->lchild) == -1)
        return RRRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->lchild) == 1)
        return RLRotation(p);

    return p;
}



int main() {

    root = RInsert(root, 10);
    RInsert(root, 20);
    RInsert(root, 30);

    return 0;
}