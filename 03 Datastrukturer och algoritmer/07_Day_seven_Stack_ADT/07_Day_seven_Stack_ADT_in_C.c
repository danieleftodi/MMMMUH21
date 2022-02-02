//
//  07_Day_seven_Stack_ADT_in_C.c
//  07_Day_seven_Stack_ADT_in_C
//
//  Created by Daniel Eftodi on 2022-01-12.
//

#include "07_Day_seven_Stack_ADT_in_C.h"

// 1. Stack ADT: Introduction
struct Stack
{
    int size;
    int top;
    int *S;
};

void create(struct Stack *st)
{
   printf("Enter Size: ");
   scanf("%d", &st->size);

   st->top = -1;
   st->S   = (int *) malloc(st->size * sizeof(int));
}

void push(struct Stack *st, int x)
{
    if (st->top == st->size-1)
    {
        printf("Stack Overflow: %d\n", x);
    }
    else
    {
        st->top++;
        st->S[st->top] = x;
        printf("pushed: %d\n", x);
    }
}

int pop(struct Stack *st)
{
    int x = -1;

    if (st->top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        x = st->S[st->top--];
    }

    return x;
}

void Display(struct Stack st)
{
    int i = 0;
    
    for(i = st.top; i >= 0; i--)
    {
        printf("%d\n", st.S[i]);
    }
    
    printf("\n");
}

int peek(struct Stack st, int index)
{
    int x = 0;
    
    if (st.top == -1)
    {
        printf("Invalid Index");
        return -1;
    }
    else
    {
        x = st.S[st.top--];
    }
    
    return x;
}

int isEmpty(struct Stack st)
{
    if (st.top == -1)
    {
        return 1;
    }
    
    return 0;
}

int isFull(struct Stack st)
{
    return st.top == st.size -1;
}

int stackTop(struct Stack st)
{
    if (!isEmpty(st))
    {
        return st.S[st.top];
    }
    
    return -1;
}

int one_main()
{
    struct Stack st;

    // Uppgift 0. Skapa en Create funktion
    printf("[Create]\n");
    create(&st);
    printf("\n");
    
    // Uppgift 1. Skapa en Push funktion
    printf("[Push]\n");
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 50);
    printf("\n");

    // Uppgift 2. Skapa en Display funktion
    printf("[Display]\n");
    Display(st);
    
    // Uppgift 3. Skapa Pop funktion
    printf("[Pop]\n");
    printf("Poped: %d\n", pop(&st));
    printf("\n");

    // Display
    printf("[Display]\n");
    Display(st);

    // Uppgift 4. Skapa en peek funktion
    printf("[Peek]\n");
    printf("Peek: %d \n\n", peek(st, 2) );
    
    return 0;
}


// 2. Stack ADT:
struct two_Node
{
    int data;
    struct two_Node *next;
} *two_top = NULL;

void two_push(int x)
{
    struct two_Node *t;
    t = (struct two_Node*) malloc(sizeof(struct two_Node));
    
    if (t == NULL)
    {
        printf("Stack is full\n");
    }
    else
    {
        t->data = x;
        t->next = two_top;
        two_top = t;
    }
}

int two_pop()
{
    struct two_Node *t;
    int x = -1;
    
    if (two_top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        // store old top in t
        t = two_top;
        
        // new top is next
        two_top = two_top->next;
        
        x = t->data;
        
        free(t);
    }
    return x;
}

void two_Display()
{
    struct two_Node *p;
    p = two_top;
    
    while(p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
    
    printf("\n");
}

int two_main()
{
    two_push(10);
    two_push(20);
    two_push(30);
    two_push(40);
    
    two_Display();
    
    printf("%d\n", two_pop() );
    
    return 0;
}


// 3. Stack ADT:
struct three_Node
{
    char data; // vi uppdaterar till char då de e vad vi har i vårt uttryck
    struct three_Node *next;
} *three_top = NULL;

void three_push(int x)
{
    struct three_Node *t;
    t = (struct three_Node*) malloc(sizeof(struct three_Node));
    
    if (t == NULL)
    {
        printf("Stack is full\n");
    }
    else
    {
        t->data = x;
        t->next = three_top;
        three_top = t;
    }
}

char three_pop()
{
    struct three_Node *t;
    char x = -1; // vi uppdaterar till char då de e vad vi har i vårt uttryck
    
    if (three_top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        // store old top in t
        t = three_top;
        
        // new top is next
        three_top = three_top->next;
        
        x = t->data;
        
        free(t);
    }
    return x;
}

void three_Display()
{
    struct three_Node *p;
    p = three_top;
    
    while(p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
    
    printf("\n");
}

int three_isBalanced(char *exp)
{
    int i;
    
    for(i = 0; exp[i] != '\0'; i++ )
    {
        if (exp[i] == '(')
        {
            three_push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            if(three_top == NULL)
            {
                return 0;
            }
            
            three_pop();
        }
    }
    
    if (three_top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
    return 0;
}

int three_pre(char x)
{
    if( x == '+' || x == '-')
    {
        return 1;
    }
    else if ( x == '*' || x == '/')
    {
        return 2;
    }
    
    return 0;
}

int three_isOperand(char x)
{
    if ( x == '+' || x == '-' || x == '*' || x == '/')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

char * three_InToPost(char *infix)
{
    int i = 0, j = 0;
    char *postfix;
    unsigned long len = strlen(infix);
    postfix = (char *) malloc ((len/2) * sizeof(char));
    
    while (infix[i] != '\0')
    {
        if (three_isOperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (three_pre(infix[i]) > three_pre(three_top->data))
            {
                 three_push(infix[i++]);
            }
            else
            {

            }
        }
    }
    
    return 0;
}

int three_Eval(char *postfix)
{
    int i=0;
    int x1, x2, r=0;
    
    for(i = 0; postfix[i] != '\0'; i++)
    {
        if(three_isOperand(postfix[i]))
        {
            three_push(postfix[i] - '0');
        }
        else
        {
            x2 = three_pop();
            x1 = three_pop();
            
            switch (postfix[i]) {
                case '+':
                    r = x1 + x2;
                    break;
                case '-':
                    r = x1 - x2;
                    break;
                case '*':
                    r = x1 * x2;
                    break;
                case '/':
                    r = x1 / x2;
                    break;
                default:
                    break;
            }
            
            three_push(r);
        }
    }
    
    return three_top->data;
}

int three_main()
{
    char *exp = "((a+b) * (c+d))";
    
    printf("isBalanced: %d\n", three_isBalanced(exp));
    
    char *infix = "a+b*C-d/e";
    three_push('#');
    
    
    char *postfix="234*+82/-";
    
    printf("Result is %d\n", three_Eval(postfix));

    
    return 0;
}

/* INIT - BEGIN */
int main(int argc, char ** argv){
    
    int key_pressed = '\0';
    
    // 1. Stack ADT: Introduction
    printf("[01] Struct\n");
    one_main();
    printf("[01] Press any key: ");
    key_pressed = c_getch();
    key_pressed = c_getch();
    printf(" [%d] \n\n", key_pressed);
    
    // 2. Stack ADT:
    printf("[02] Node\n");
    two_main();
    printf("[02] Press any key: ");
    key_pressed = c_getch();
    printf(" [%d] \n\n", key_pressed);
    
    // 3. Stack ADT:
    printf("[03] Three \n");
    three_main();
    printf("\n");
    printf("[03] Press any key: ");
    key_pressed = c_getch();
    printf(" [%d] \n\n", key_pressed);

    
    //Endnig with an extra new line
    printf("\n");
    
    return 0;
}
/* INIT - END */


/* IMPLEMENTATION OF ALL FUNCTIONS - BEGIN */

// void DBG_LOG(std::string sText,
//              std::string sVarA,
//              std::string sVarB,
//              std::string sVarC,
//              std::string sVarD,
//              std::string sVarE,
//              std::string sVarF,
//              std::string sVarG,
//              std::string sVarH,
//              std::string sVarI,
//              std::string sVarJ,
//              std::string sVarK,
//              std::string sVarL,
//              std::string sVarM)
// {
// #if DEBUG_LOGGING
//     printf("%s%s%s%s%s%s%s%s%s%s%s%s%s%s\n",
//            sText.c_str(),
//            sVarA.c_str(),
//            sVarB.c_str(),
//            sVarC.c_str(),
//            sVarD.c_str(),
//            sVarE.c_str(),
//            sVarF.c_str(),
//            sVarG.c_str(),
//            sVarH.c_str(),
//            sVarI.c_str(),
//            sVarJ.c_str(),
//            sVarK.c_str(),
//            sVarL.c_str(),
//            sVarM.c_str());
// #endif
// }

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
