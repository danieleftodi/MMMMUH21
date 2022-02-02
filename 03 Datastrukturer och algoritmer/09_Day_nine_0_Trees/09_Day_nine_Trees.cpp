//
//  09_Day_nine_Trees.cpp
//  09_Day_nine_Trees
//
//  Created by Daniel Eftodi on 2022-01-19.
//

#include "09_Day_nine_Trees.h"

// 1. Trees: Introduction
class Node
{
public:
    int data;
    
    class Node *lchild;
    class Node *rchild;
    
    Node() {};
    Node(int data);
};

Node::Node(int data) {
    lchild = nullptr;
    this->data = data;
    rchild = nullptr;
}

class Queue
{
private:
    int front;
    int rear;
    int size;
    class Node **Q;
    
public:
    Queue()
    {
        front = rear = -1;
        size = 10;
        Q = new class Node *[size];
    }
    
    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new class Node *[size];
    }
    
    void enqueue(class Node *x);
    class Node *dequeue();
    
    int isEmpty()
    {
        return front == rear;
    }
    
};

void Queue::enqueue(class Node *x)
{
    if (rear == (size - 1))
    {
        printf("Queue is full\n");
    }
    else
    {
        rear++;
        Q[rear] = x;
    }
}

Node *Queue::dequeue()
{
    class Node *x = NULL;
    if (front == rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        x = Q[front + 1];
        front++;
    }
    
    return x;
}

class Tree
{
private:
    class Node *root;
    
public:
    Tree()
    {
        root = NULL;
    }
    
    // Create our tree
    void CreateTree();
    
    // Pre-order
    void Preorder()
    {
        Preorder(root);
    }
    void Preorder(class Node *p);
    
    // In-order
    void Inorder()
    {
        Inorder(root);
    }
    void Inorder(class Node *p);
    
    void Postorder()
    {
        Postorder(root);
    }
    void Postorder(class Node *p);
    
    void Levelorder()
    {
        Levelorder(root);
    }
    void Levelorder(class Node *p);
    
    int Height()
    {
        return Height(root);
    }
    int Height(class Node *root);
    
};

void Tree::CreateTree()
{
    DBG_LOG("[DBG] Tree::CreateTree :: ", "BEGIN");
    
    class Node *p = nullptr, *t = nullptr;
    int x;
    std::string z;
    Queue q(100);
    
    printf("Enter root value: ");
    scanf("%d", &x);
    
    root = new class Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);
    
    while (!q.isEmpty())
    {
        p = q.dequeue();
        printf("Enter left child of %d: ", p->data);
        scanf("%d", &x);
        
        if (x != -1)
        {
            t = new class Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        
        printf("Enter right child of %d: ", p->data);
        scanf("%d", &x);
        
        if (x != -1)
        {
            t = new class Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        printf("\n");
    }
    
    DBG_LOG("[DBG] Tree::CreateTree :: ", "END");
}

void Tree::Preorder(class Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(class Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        
        Inorder(p->rchild);
//        printf("%d", p->data);
    }
}

void Tree::Postorder(class Node *p)
{
    if (p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d\n", p->data);
    }
}

int Tree::Height(class Node *root)
{
    int x = 0, y = 0;
    if (root == 0)
    {
        return 0;
    }
    
    x = Height(root->lchild);
    y = Height(root->rchild);
    if (x > y)
    {
        return x + 1;
    }
    else
    {
        return y = 1;
    }
}

void Tree::Levelorder(class Node *p)
{
    Queue q(100);
    printf("%d", root->data);
    q.enqueue(root);
    
    while (!q.isEmpty())
    {
        root = q.dequeue();
        if (root->lchild)
        {
            printf("%d ", root->lchild->data);
            q.enqueue(root->lchild);
        }
        if (root->rchild)
        {
            printf("%d ", root->rchild->data);
            q.enqueue(root->rchild);
        }
    }
}

int one_main()
{
    DBG_LOG("[DBG] one_main :: ", "BEGIN");
    
    // Create our Tree
    class Tree t;
    t.CreateTree();
    
    //
    std::cout << "Preorder: ";
    t.Preorder();
    std::cout << std::endl;
    
    //
    std::cout << "Inorder: ";
    t.Inorder();
    std::cout << std::endl;
    
    DBG_LOG("[DBG] one_main :: ", "BEGIN");
    return 0;
}


// 2. Trees:
int two_main()
{
    
    return 0;
}


// 3. Trees:
int three_main()
{
    return 0;
}

/* INIT - BEGIN */
int main(int argc, char ** argv){
    
    int key_pressed = '\0';
    
    // 1. Trees: Introduction
    printf("[01] Trees: Introduction\n");
    one_main();
    printf("[01] Press any key: ");
    key_pressed = c_getch();
    key_pressed = c_getch();
    printf(" [%d] \n\n", key_pressed);
    
    // 2. Trees:
 
    // 3. Trees:
    

    
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
