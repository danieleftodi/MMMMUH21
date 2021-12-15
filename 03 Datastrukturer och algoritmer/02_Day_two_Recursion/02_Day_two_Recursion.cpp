//
//  16_ATM_in_Cpp.cpp
//  16_ATM_in_Cpp
//
//  Created by Daniel Eftodi on 2021-11-13.
//

#include "02_Day_two_Recursion.h"

// 1. Recursions 101: Introduction
void one_fun(int n)
{
    if ( n > 0)
    {
        printf("n: %d\n", n);
        one_fun(n-1);
    }
}

int one_main()
{
    int x = 3;
    one_fun(x);
    
    return 0;
}

// 2. Recursions 101: Head Recursion
void two_fun(int n)
{
    if ( n > 0)
    {
        two_fun(n-1);       // Recursive Head
        printf("n: %d\n", n);
    }
}

int two_main()
{
    int x = 3;
    two_fun(x);
    
    return 0;
}

// 3. Recursions 101: Tail Recursion
void three_fun(int n)
{
    if ( n > 0)
    {
        printf("n: %d\n", n);
        three_fun(n-1);     // Tail Recursive
    }
}

int three_main()
{
    int x = 3;
    one_fun(x);
    
    return 0;
}

// 4. Recursions 101:
int four_fun(int n)
{
    static int x = 0;
    
    if ( n > 0)
    {
        x++;
        printf("n: %d  x: %d\n", n, x);
        return four_fun(n-1)+x;
    }
    
    return 0;
}

int four_main()
{
    int r;
    r = four_fun(5);
    printf("r: %d\n", r );
    
    return 0;
}

// 5. Recursions 101:
int five_fun(int n)
{
    if ( n > 0)
    {
        printf("n: %d\n", n);
        return five_fun(n-1)+n;
    }
    
    return 0;
}

int five_main()
{
    int a = 5;
    printf("r: %d\n", five_fun(a) );
    
    return 0;
}

// 6. Recursions 101:
int six_fun(int n)
{
    if ( n > 0)
    {
        printf("n: %d\n", n);
        return five_fun(n-1)+n;
    }
    
    return 0;
}

int six_main()
{
    int a = 5;
    printf("r: %d\n", five_fun(a) );
    
    return 0;
}

/* INIT - BEGIN */
int main(int argc, char ** argv){
    
    int key_pressed = '\0';
    
    // 1. Recursions 101: Introduction
    printf("[01] Recursions 101: Introduction\n");
    one_main();
    printf("[01] Press any key: "); key_pressed = c_getche(); printf(" [%d] \n\n", key_pressed);
    
    // 2. Recursions 101: Head Recursion
    printf("[02] Recursions 101: Head Recursion\n");
    two_main();
    printf("[02] Press any key: "); key_pressed = c_getche(); printf(" [%d] \n\n", key_pressed);
    
    // 3. Recursions 101: Tail Recursion
    printf("[03] Recursions 101: Tail Recursion\n");
    three_main();
    printf("[03] Press any key: "); key_pressed = c_getch(); printf(" [%d] \n\n", key_pressed);
    
    // 4. Recursions 101:
    printf("[04] Recursions 101: \n");
    four_main();
    printf("[04] Press any key: "); key_pressed = c_getch(); printf(" [%d] \n\n", key_pressed);
    
    // 5. Recursions 101:
    printf("[05] Recursions 101: \n");
    five_main();
    printf("[05] Press any key: "); key_pressed = c_getch(); printf(" [%d] \n\n", key_pressed);
    
    // 6. Recursions 101:
    printf("[05] Recursions 101: \n");
    six_main();
    printf("[05] Press any key: "); key_pressed = c_getch(); printf(" [%d] \n\n", key_pressed);
    
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
                   std::string sVarF)
{
#if DEBUG_LOGGING
    printf("%s%s%s%s%s%s%s\n",
           sText.c_str(),
           sVarA.c_str(),
           sVarB.c_str(),
           sVarC.c_str(),
           sVarD.c_str(),
           sVarE.c_str(),
           sVarF.c_str());
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
