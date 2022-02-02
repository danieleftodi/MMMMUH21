//
//  10_Day_ten_AVL_Tree_Rotations.cpp
//  10_Day_ten_AVL_Tree_Rotations
//
//  Created by Daniel Eftodi on 2022-01-20.
//

#include "10_Day_ten_AVL_Tree_Rotations.h"

// 1. AVL Tree Rotations: Introduction
class Node
{
public:
    int data;
    int height;
    
    class Node *lchild;
    class Node *rchild;
};

// AVL Tree
class AVL
{
private:
    
    
public:
    class Node *root;
    
    AVL()
    {
        DBG_LOG("[DBG] class AVL :: ", "AVL()");
        root = nullptr;
    }
    
    // Helper methods for insert and delete
    int NodeHeight(class Node *p);
    int BalanceFactor(class Node *p);
    
    class Node *LLRotation(class Node *p);
    class Node *RRRotation(class Node *p);
    class Node *LRRotation(class Node *p);
    class Node *RLRotation(class Node *p);
    
    class Node *InPre(class Node *p);
    class Node *InSucc(class Node *p);
    
    // Insert
    class Node *rInsert(class Node *p, int key);
    
    // Traversals
    void InOrder(class Node *p);
    void InOrder()
    {
        InOrder(root);
    }
    
    // Get Root
    class Node *getRoot()
    {
        DBG_LOG("[DBG] class AVL :: ", "*getRoot()");
        return root;
    }
    
    // Delete
    class Node *Delete(class Node *p, int key);
};

int AVL::NodeHeight(class Node *p)
{
    int hl;
    int hr;
        
    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;
    
    // return hl + 1 if hl is larger then hr
    // else return hr + 1
    return hl > hr ? hl + 1 : hr + 1;
}

int AVL::BalanceFactor(class Node *p)
{
    int hl;
    int hr;
    
    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;
    
    return hl - hr;
    
}

void AVL::InOrder(class Node *p)
{
    if (p)
    {
        InOrder(p->lchild);
        std::cout << p->data << ", " << std::flush;
        InOrder(p->rchild);
    }
}

Node *AVL::InPre(class Node *p)
{
    while (p && p->rchild != nullptr)
    {
        p = p->rchild;
    }
    
    return p;
}

Node *AVL::InSucc(class Node *p)
{
    while (p && p->lchild != nullptr)
    {
        p = p->lchild;
    }
    
    return p;
}

Node *AVL::LLRotation(class Node *p)
{
    class Node *pl  =  p->lchild;
    class Node *plr = pl->rchild; // Think: p->lchild->rchild;
    
    pl->rchild = p;
    p->lchild = plr;
    
    // Update NodeHeight
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    
    // Update root
    if (root == p)
    {
        root = pl;
    }
    
    return pl;
}

Node *AVL::RRRotation(class Node *p)
{
    class Node *pr  =  p->rchild;
    class Node *prl = pr->lchild; // Think: p->rchild->lchild;
    
    pr->lchild = p;
    p->rchild = prl;
    
    // Update NodeHeight
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    
    // Update root
    if (root == p)
    {
        root = pr;
    }
    
    return pr;
}

Node *AVL::LRRotation(class Node *p)
{
    class Node *pl  =  p->lchild;
    class Node *plr = pl->rchild; // Think: p->lchild->rchild;
    
    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
    
    plr->lchild = pl;
    plr->rchild = p;
    
    // Update NodeHeight
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    plr->height = NodeHeight(plr);
    
    // Update root
    if (root == p)
    {
        root = plr;
    }
    
    return plr;
}

Node *AVL::RLRotation(class Node *p)
{
    class Node *pr  =  p->rchild;
    class Node *prl = pr->lchild; // Think: p->rchild->lchild;
    
    pr->lchild = prl->rchild;
    p->rchild  = prl->lchild;
    
    prl->rchild = pr;
    prl->lchild = p;
    
    // Update NodeHeight
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    prl->height = NodeHeight(prl);
    
    // Update root
    if (root == p)
    {
        root = prl;
    }
    
    return prl;
}

Node *AVL::rInsert(class Node *p, int key)
{
    DBG_LOG("[DBG] AVL::rInsert :: ", "BEGIN");
    class Node *t = nullptr;
    
    if (p == nullptr) {
        t = new class Node;
        t->data = key;
        t->lchild = nullptr;
        t->rchild = nullptr;
        t->height = 1; // Starting height from 1 onwards instead of 0
        return t;
    }
    
    if (key < p->data)
    {
        p->lchild = rInsert(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = rInsert(p->rchild, key);
    }
    
    // Update height
    p->height = NodeHeight(p);
    
    // Balance and rotation
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
    {
        return LLRotation(p);
    }
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
    {
        return LRRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->lchild) == -1)
    {
        return RRRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->lchild) == 1)
    {
        return RLRotation(p);
    }
    
    DBG_LOG("[DBG] *AVL::rInsert :: ", "END");
    return p;
}

Node *AVL::Delete(class Node *p, int key)
{
    if (p == nullptr)
    {
        return nullptr;
    }
    
    if (p->lchild == nullptr && p->rchild == nullptr)
    {
        if (p == root)
        {
            root = nullptr;
        }
        
        // Delete the Node where key is found
        std::cout << "Deleted: " << p->data << std::endl;
        delete p;
        
        return nullptr;
    }
 
    if (key < p->data)
    {
        p->lchild = Delete(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = Delete(p->rchild, key);
    }
    else
    {
        class Node *q;
        
        if (NodeHeight(p->lchild) > NodeHeight(p->rchild))
        {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    
    // Update height
    p->height = NodeHeight(p);
    
    // Balance and rotation
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
    {
        return LLRotation(p);
    }
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
    {
        return LRRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
    {
        return RRRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
    {
        return RLRotation(p);
    }
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 0)
    {
        return LLRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 0)
    {
        return RRRotation(p);
    }
    
    return p;
}

int one_main()
{
    DBG_LOG("[DBG] one_main :: ", "BEGIN");
    
    class AVL tree;
    
    int A[] = {10, 20, 30, 25, 28, 27, 5};
    
    // Recursive insert
    for (int i = 0; i < sizeof(A)/sizeof(A[0]); i++)
    {
        tree.root = tree.rInsert(tree.root, A[i]);
    }

    // Inorder Traversal
    tree.InOrder(tree.getRoot());
    std::cout << std::endl;
            
    // Delete
    std::cout << "Let's delete: 28" << std::endl;
    tree.Delete(tree.root, 28);
    tree.InOrder(tree.getRoot());
    std::cout << "\n" << std::endl;
    
    DBG_LOG("[DBG] one_main :: ", "END");
    return 0;
}


// 2. AVL Tree Rotations:
int two_main()
{
    
    return 0;
}


// 3. AVL Tree Rotations:

int three_main()
{
 
    return 0;
}

/* INIT - BEGIN */
int main(int argc, char ** argv){
    
    int key_pressed = '\0';
    
    // 1. AVL Tree Rotations: Introduction
    printf("[01] AVL Tree Rotations: Introduction\n");
    one_main();
    printf("[01] Press any key: ");
    key_pressed = c_getch();
    key_pressed = c_getch();
    printf(" [%d] \n\n", key_pressed);
    
    // 2. AVL Tree Rotations:

    
    // 3. AVL Tree Rotations:


    
    //Endnig with an extra new line
    printf("\n");
    
    return 0;
}
/* INIT - END */


/* IMPLEMENTATION OF ALL FUNCTIONS - BEGIN */

void DBG_LOG(std::string sText,
          std::string sVarA,
          std::string sVarB,
          std::string sVarC,
          std::string sVarD,
          std::string sVarE,
          std::string sVarF,
          std::string sVarG,
          std::string sVarH,
          std::string sVarI,
          std::string sVarJ,
          std::string sVarK,
          std::string sVarL,
          std::string sVarM)
{
#if DEBUG_LOGGING
 printf("%s%s%s%s%s%s%s%s%s%s%s%s%s%s\n",
        sText.c_str(),
        sVarA.c_str(),
        sVarB.c_str(),
        sVarC.c_str(),
        sVarD.c_str(),
        sVarE.c_str(),
        sVarF.c_str(),
        sVarG.c_str(),
        sVarH.c_str(),
        sVarI.c_str(),
        sVarJ.c_str(),
        sVarK.c_str(),
        sVarL.c_str(),
        sVarM.c_str());
#endif
}

/* Read 1 character without echo */
int c_getch(void)
{
    struct termios old, char_new;
    int ch;
    
    tcgetattr(0, &old);
    
    char_new = old;
    char_new.c_lflag &= ~ICANON;
    char_new.c_lflag &= ~ECHO;
    
    tcsetattr(0, TCSANOW, &char_new);
    
    ch = getchar();
    
    tcsetattr(0, TCSANOW, &old);
    
    return ch;
}

/* Read 1 character with echo */
int c_getche(void)
{
    struct termios old, char_new;
    int ch;
    
    tcgetattr(0, &old);
    
    char_new = old;
    char_new.c_lflag &= ~ICANON;
//    char_new.c_lflag &= ~ECHO;

    tcsetattr(0, TCSADRAIN, &char_new);
    
    ch = getchar();
    
    tcsetattr(0, TCSADRAIN, &old);
    return ch;
}

/* IMPLEMENTATION OF ALL FUNCTIONS - END */
