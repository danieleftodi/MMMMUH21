#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    int height;
    Node* lchild;
    Node* rchild;
};

class AVL
{
    public:
    Node* root;

    AVL(){root = nullptr;}

    //Helper methods for insert n delete
    int NodeHeight(Node *p);
    int BalanceFactor(Node *p);
    Node* LLRotation(Node *p);
    Node* RRRotation(Node *p);
    Node* LRRotation(Node *p);
    Node* RLRotation(Node *p);
    Node* InPre(Node *p);
    Node* InSucc(Node *p);

    //insert
    Node* rInsert(Node* p,int key);

    //Traversals
    void Inorder(Node *p);
    void Inorder(){Inorder(root);}
    Node* getRoot(){return root;}

    //delete
    Node* Delete(Node* p, int key);

};

int AVL::NodeHeight(Node *p)
{
    int hl;
    int hr;

    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
}

int AVL::BalanceFactor(Node *p)
{
    int hl;
    int hr;

    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    return hl - hr;
}

void AVL::Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout<<p->data<<", "<<flush;
        Inorder(p->rchild);
    }
}

Node* AVL::InPre(Node *p)
{
    while (p && p->rchild != nullptr)
    {
        p = p->rchild;
    }
    return p;
}

Node* AVL::InSucc(Node *p)
{
    while (p && p->lchild != nullptr)
    {
        p = p->lchild;
    }
    return p;
}

Node* AVL::LLRotation(Node *p)
{
    Node* pl = p->lchild;
    Node* plr = pl->rchild;

    pl->rchild=p;
    p->lchild=plr;

    //Update NodeHeight
    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);

    //Update root
    if(root==p)
    {
        root=pl;
    }
    return pl;
}
Node* AVL::RRRotation(Node *p)
{
    Node* pr = p->rchild;
    Node* prl = pr->lchild;

    pr->lchild=p;
    p->rchild=prl;

    //Update NodeHeight
    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);

    //Update root
    if(root==p)
    {
        root=pr;
    }
    return pr;
}
Node* AVL::LRRotation(Node *p)
{
    Node* pl = p->lchild;
    Node* plr = pl->rchild;

    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;

    plr->lchild=pl;
    plr->rchild=p;

    //Update NodeHeight
    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);
    plr->height=NodeHeight(plr);

    //Update root
    if(root==p)
    {
        root=plr;
    }
    return plr;
}
Node* AVL::RLRotation(Node *p)
{
    Node* pr = p->rchild;
    Node* prl = pr->lchild;

    pr->lchild=prl->rchild;
    p->rchild=prl->lchild;

    prl->rchild=pr;
    prl->lchild=p;

    //Update NodeHeight
    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);
    prl->height=NodeHeight(prl);

    //Update root
    if(root==p)
    {
        root=prl;
    }
    return prl;
}
Node* AVL::rInsert(Node *p, int key) {
    Node* t;
    if (p == nullptr){
        t = new Node;
        t->data = key;
        t->lchild = nullptr;
        t->rchild = nullptr;
        t->height = 1;  // Starting height from 1 onwards instead of 0
        return t;
    }
 
    if (key < p->data){
        p->lchild = rInsert(p->lchild, key);
    } else if (key > p->data){
        p->rchild = rInsert(p->rchild, key);
    }
 
    // Update height
    p->height = NodeHeight(p);

    //balance n rotation
    if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
    {
        return LLRotation(p);
    }
    else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
    {
        return LRRotation(p);
    }
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
    {
        return RRRotation(p);
    }
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
    {
        return RLRotation(p);
    }

    return p;
}

Node* AVL::Delete(Node *p, int key) {
    if (p == nullptr){
        return nullptr;
    }
 
    if (p->lchild == nullptr && p->rchild == nullptr){
        if (p == root){
            root = nullptr;
        }
        delete p;
        return nullptr;
    }
 
    if (key < p->data){
        p->lchild = Delete(p->lchild, key);
    } else if (key > p->data){
        p->rchild = Delete(p->rchild, key);
    } else {
        Node* q;
        if (NodeHeight(p->lchild) > NodeHeight(p->rchild)){
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        } else {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
 
    // Update height
    p->height = NodeHeight(p);

    //Balance n Rotation
    if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
    {
        return LLRotation(p);
    }
    else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
    {
        return LRRotation(p);
    }
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
    {
        return RRRotation(p);
    }
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
    {
        return RLRotation(p);
    }
    else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 0)
    {
        return LLRotation(p);
    }
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 0)
    {
        return RRRotation(p);
    }
    
    return p;

}

int main()
{
    AVL tree;

    int A[]={10, 20, 30, 25, 28, 27, 5};
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++)
    {
        tree.root = tree.rInsert(tree.root, A[i]);
    }

    tree.Inorder();
    cout<<endl;

    // Delete
    std::cout << "Let's delete: 28" << std::endl;
    tree.Delete(tree.root, 28);
    tree.Inorder();
    cout<<endl;

    return 0;
}
