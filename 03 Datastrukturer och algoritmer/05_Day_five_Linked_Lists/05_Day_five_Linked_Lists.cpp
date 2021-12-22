//
//  05_Day_five_Sparse_Matrix_Polymonial_Functions.cpp
//  05_Day_five_Sparse_Matrix_Polymonial_Functions
//
//  Created by Daniel Eftodi on 2021-12-22.
//

#include "05_Day_five_Linked_Lists.h"

// 1. Linked Lists: Introduction
struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[],int n)
{
    int i;
    struct Node *t, *last;
    
    first = (struct Node *) malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    
    for (i=1; i<n; i++)
    {
        t = (struct Node*) malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    while(p != NULL)
    {
        printf("p: %d \n", p->data);
        p = p->next;
    }
}

void RDisplay(struct Node *p)
{
    if(p != NULL)
    {
        RDisplay(p->next);
        printf("%d ",p->data);
    }
}

int Count(struct Node *p)
{
    int i = 0;
    
    while(p != NULL)
    {
        DBG_LOG("[DBG] Count: ", std::to_string(++i));
        p = p->next;
    }
    
    return i;
}

int RCount(struct Node *p)
{
    static int i = 0;
    
    if (p != NULL)
    {
        DBG_LOG("[DBG] RCount: ", std::to_string(++i));
        return RCount(p->next) + 1;
    }
    else
    {
        return 0;
    }
    
    return 0;
}

int Sum(struct Node *p)
{
    int sum = 0;
    
    while(p != NULL)
    {
        sum = (sum + p->data);
        DBG_LOG("[DBG] Sum: ", std::to_string(sum), "  p: ", std::to_string(p->data));
        p = p->next;
    }
    
    return sum;
}

int RSum(struct Node *p)
{
    static int sum = 0;
    
    if (p != NULL)
    {
        sum = (sum + p->data);
        DBG_LOG("[DBG] Sum: ", std::to_string(sum), "  p: ", std::to_string(p->data));
        
        return (RSum(p->next) + p->data);
        
    }
    else
    {
        sum = 0;
        return 0;
    }
    
    return 0;
}

int Max (struct Node *p)
{
    // init, set max to lowest INT32 value
    int max = INT32_MIN;
    
    //while-loop-check != NULL
    while (p != NULL)
    {
        if (max < p->data)
        {
            max = p->data;
            DBG_LOG("[DBG] Max: ", std::to_string(max));
        }
        else
        {
            DBG_LOG("[DBG] p-data is LESS: ", std::to_string(p->data));
        }
        
        //point to next struct in list
        p = p->next;
    }
    
    DBG_LOG("[DBG] Max is: ", std::to_string(max));
    
    return max;
}

int RMax (struct Node *p)
{
    // init, set max to lowest INT32 value
    static int max = INT32_MIN;
    
    // temp int
    static int temp = 0;
                   
    if (p != NULL)
    {
        if (max < p->data)
        {
            max = p->data;
            DBG_LOG("[DBG] RMax: ", std::to_string(max));
        }
        else
        {
            DBG_LOG("[DBG] p-data: ", std::to_string(p->data),
                    " is LESS then max: ", std::to_string(max));
        }
        
        //point to next struct in list
        return RMax(p->next);
        
    }
    else
    {
        //we need to reset max = 0 ...
        //so we can run the function several times, after each other.
        temp = max;
        max = INT32_MIN;
        
        return temp;
    }
    
    //if we fail, for some reason. Lets make it obvious.
    return -1337;
}

int one_main()
{
//    struct Node *temp;
    //         0 1 2  3  4 5  6 7  8  9   [COMPUTER]
    //         1 2 3  4  5 6  7 8  9  10  [HUMAN]
    int A[] = {3,5,7,10,25,8,32,2};

    // Uppgift 0. Skapa en Create funktion som skapar samtliga noder
    printf("[Create]\n");
    create(A,8);
    printf("\n");
    
    // Uppgift 1. Skapa en Display funktion som visar samtliga noder
    printf("[Display]\n");
    Display(first);
    printf("\n");
    
    // Uppgift 2. Skapa Count och en Sum funktion som redovisar antalet noder och deras summa
    printf("[Count]\n");
    printf("Count: %d \n\n", Count(first) );

    printf("[Sum]\n");
    printf("Sum: %d \n\n", Sum(first) );
    
    // Recursive functions:
    printf("[RCount]\n");
    printf("RCount: %d \n\n", RCount(first) );
    
    printf("[RSum]\n");
    printf("RSum: %d \n\n", RSum(first) );
    
    // Uppgift 3. Skapa en Max funktion som visar den största noden
    printf("[Max]\n");
    printf("Max: %d \n\n", Max(first) );
    
    printf("[RMax]\n");
    printf("RMax: %d \n\n", RMax(first) );
    
    // Uppgift 4. Skapa en Search funktion där du kan söka efter ett specifik data bland noderna
    
    // Uppgift 5. Skapa en Insert funktion där du placerar en nod emellan två andra
    
    // Uppgift 6. Skapa en Delete funktion som kan eliminera en nod
    
    // Uppgift 7. Skapa en isSorted funktion för att se om noderna är sorterade
    
    // Uppgift 8. Skapa en Merge funktion för att föra ihop två linked lists
    
    // Uppgift 9. Skapa en PruneDoubles funktion för att ta bort dubbletter
    
    // Uppgift 10. Skapa en Reverse funktion för att reversa nodernas ordning
    
    return 0;
}


// 2. Linked Lists:
int two_main()
{
    
    return 0;
}


// 3. Linked Lists:
int three_main()
{
    
    return 0;
}

/* INIT - BEGIN */
int main(int argc, char ** argv){
    
    int key_pressed = '\0';
    
    // 1. Linked Lists: Introduction
    printf("[01] Sparse Matrix & Polymonial Functions: Introduction Linked Lists\n");
    one_main();
    printf("[01] Press any key: "); key_pressed = c_getche(); printf(" [%d] \n\n", key_pressed);
    
    // 2. Linked Lists:
//    printf("[02] Linked Lists: \n");
//    two_main();
//    printf("[02] Press any key: "); key_pressed = c_getche(); printf(" [%d] \n\n", key_pressed);
    
    // 3. Linked Lists:
//    printf("[03] Linked Lists: \n");
//    three_main();
//    printf("[03] Press any key: "); key_pressed = c_getch(); printf(" [%d] \n\n", key_pressed);

    
    //Endnig with an extra new line
    std::cout << "\n";
    
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
