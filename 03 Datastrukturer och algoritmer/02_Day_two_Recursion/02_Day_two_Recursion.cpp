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
    if (n > 0)
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
    if (n > 0)
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
    if (n > 0)
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

// 4. Recursions 101: Static Variables in Recursion
int four_fun(int n)
{
    // 'static int' is what makes this to work!
    static int x = 0;
    
    if (n > 0)
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
    
    r = four_fun(5);
    printf("r: %d\n", r );
    
    r = four_fun(5);
    printf("r: %d\n", r );
    
    return 0;
}

// 5. Recursions 101: Global Variabels in Recursion
int five_x = 0;

int five_fun(int n)
{
    if (n > 0)
    {
        five_x++;
        printf("n: %d  x: %d\n", n, five_x);
        return five_fun(n - 1) + five_x;;
    }
    
    return 0;
}

int five_main()
{
    int r;
    r = five_fun(5);
    printf("r: %d\n", r );
    
    r = five_fun(5);
    printf("r: %d\n", r );
    
    r = five_fun(5);
    printf("r: %d\n", r );
    
    return 0;
}

// 6. Recursions 101: Tree Recursion
void six_fun(int id, int n)
{
    static int trkA=1;
    static int trkB=1;
    static int trkC=1;
    
    if (id == 0) {
        printf("id: %d  trkA: %d  n: %d  *\n", id, trkA++, n);
        printf("--------------------------\n");
    };
    
    if (n > 0)
    {
        if (id == 1) {
            printf("id: %d  trkB: %d  n: %d  ##\n", id, trkB++, n);
        }; delay(1);
        six_fun(1, n-1);

        if (id == 2) {
            printf("id: %d  trkC: %d  n: %d  $$$\n", id, trkC++, n);
        }; delay(1);
        six_fun(2, n-1);
    }
}

int six_main()
{
    six_fun(0, 3);
    
    return 0;
}

// 7. Recursions 101: Indirect Recursion
void seven_funA(float n)
{
    if (n > 0)
    {
        printf("[A] n: %6.3f\n", n);
        seven_funB(n - 1);
    }
}

void seven_funB(float n)
{
    if (n > 1)
    {
        printf("[B] n: %6.3f\n", n);
        seven_funA(n / 2);
    }
}

int seven_main()
{
    seven_funA(20);
    
    return 0;
}


// 8. Recursions 101: Nested Recursion
int eight_fun(int n)
{
    if (n > 100)
    {
        printf("[A] n: %d\n", n);
        return n-10;
    }
    
    printf("[B] n: %d\n", n);
    return eight_fun( eight_fun(n + 11) );
}

int eight_main()
{
    int r;
    r = eight_fun(95);
    printf("r: %d\n", r);
    
    return 0;
}


// 9. Recursions 101: Sum of n
int nine_sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    
    printf("[sum] n: %d\n", n);
    return (nine_sum(n - 1) + n);
}

int nine_iSum(int n) {
    int s = 0,i;
    
    for (i=1; i <= n; i++)
    {
        s = (s + i);
        printf("[iSum] s: %d\n", s);
    }
    
    return s;
}

int nine_main()
{
    int r = nine_sum(6);
    printf("r: %d\n", r );
    
    r = nine_iSum(6);
    printf("r: %d\n", r );
    
    return 0;
}

// 10. Recursions 101: Factorials
int ten_fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    
    printf("[fact] n: %d\n", n);
    return (ten_fact(n - 1) * n);
}

int ten_iFact(int n)
{
    int f = 1,i;
    
    for (i=1; i <= n; i++)
    {
        f = (f * i);
        printf("[iFact] f: %d\n", f);
    }
    
    return f;
}

int ten_main()
{
    int r = ten_fact(5);
    printf("r: %d\n", r );
    
    r = ten_iFact(5);
    printf("r: %d\n", r );
    
    return 0;
}


// 11. Recursions 101: Power of
int eleven_power(int m,int n) {
    if(n == 0)
    {
        return 1;
    }
    
    printf("[power] m: %d  n: %d\n", m, n);
    return (eleven_power(m,n - 1) * m);
}
int eleven_power1(int m,int n) {
    if(n == 0)
    {
        return 1;
    }
    
    if(n%2 == 0)
    {
        printf("[power1] m: %d  n: %d\n", m, n);
        return eleven_power1(m * m,n / 2);
    }
    
    printf("[power1] m: %d  n: %d\n", m, n);
    return (m * eleven_power1((m * m), (n - 1) / 2) );
}

int eleven_main()
{
    int r = eleven_power(9,3);
    printf("r: %d\n", r );
    
    r = eleven_power1(9,3);
    printf("r: %d\n", r );
    
    return 0;
}


// 12. Recursions 101:
int twelve_fun(int n)
{
    if (n > 0)
    {
        printf("n: %d\n", n);
        return five_fun(n-1)+n;
    }
    
    return 0;
}

int twelve_main()
{
    int a = 5;
    printf("r: %d\n", five_fun(a) );
    
    return 0;
}

/* INIT - BEGIN */
int main(int argc, char ** argv){
    
    int  key_pressed             = '\0';
    int  cUserInput              = '\0';
    bool bMainMenuValidSelection = false;
    
    do
    {
        clearScreen();
        printf("############################################\n");
        printf("## Recursions 101                         ##\n");
        printf("##                                        ##\n");
        printf("## Main Menu                              ##\n");
        printf("############################################\n");
        printf("\n");
        printf("  (1) - Introduction\n");
        printf("  (2) - Head Recursion\n");
        printf("  (3) - Tail Recursion\n");
        printf("  (4) - Static Variables in Recursion\n");
        printf("  (5) - Global Variabels in Recursion\n");
        printf("  (6) - Tree Recursion\n");
        printf("  (7) - Indirect Recursion\n");
        printf("  (8) - Nested Recursion\n");
        printf("  (9) - Sum of n\n");
        printf("  (A) - Factorials\n");
        printf("  (B) - Power of\n");
        printf("  (C) - \n");
        printf("  (Q) - Quit\n");
        printf("\n");
        printf("  Press a key: ");
        cUserInput = c_getche();
        
        switch (cUserInput) {
            case '1':
                clearScreen();

                // 1. Recursions 101: Introduction
                printf("[01] Recursions 101: Introduction\n");
                one_main();
                printf("[01] Press any key: "); key_pressed = c_getch();

                break;
            case '2':
                clearScreen();
                
                // 2. Recursions 101: Head Recursion
                printf("[02] Recursions 101: Head Recursion\n");
                two_main();
                printf("[02] Press any key: "); key_pressed = c_getch();

                break;
            case '3':
                clearScreen();
                
                // 3. Recursions 101: Tail Recursion
                printf("[03] Recursions 101: Tail Recursion\n");
                three_main();
                printf("[03] Press any key: "); key_pressed = c_getch();
                
                break;
            case '4':
                clearScreen();
                
                // 4. Recursions 101: Static Variables in Recursion
                printf("[04] Recursions 101: Static Variables in Recursion\n");
                four_main();
                printf("[04] Press any key: "); key_pressed = c_getch();
                
                break;
            case '5':
                clearScreen();
                
                // 5. Recursions 101: Global Variabels in Recursion
                printf("[05] Recursions 101: Global Variabels in Recursion\n");
                five_main();
                printf("[05] Press any key: "); key_pressed = c_getch();

                break;
            case '6':
                clearScreen();
                
                // 6. Recursions 101: Tree Recursion
                printf("[06] Recursions 101: Tree Recursion\n");
                six_main();
                printf("[06] Press any key: "); key_pressed = c_getch();
                
                break;
            case '7':
                clearScreen();
                
                printf("[07] Recursions 101: Indirect Recursion\n");
                seven_main();
                printf("[07] Press any key: "); key_pressed = c_getch();
                
                break;
            case '8':
                clearScreen();
                
                printf("[08] Recursions 101: Nested Recursion\n");
                eight_main();
                printf("[08] Press any key: "); key_pressed = c_getch();
                
                break;
            case '9':
                clearScreen();
                
                printf("[08] Recursions 101: Sum of n\n");
                nine_main();
                printf("[08] Press any key: "); key_pressed = c_getch();
                
                break;
            case 'a':
            case 'A':
                clearScreen();
                
                printf("[08] Recursions 101: Factorials\n");
                ten_main();
                printf("[08] Press any key: "); key_pressed = c_getch();
                
                break;
            case 'b':
            case 'B':
                clearScreen();
                
                printf("[08] Recursions 101: Power of\n");
                eleven_main();
                printf("[08] Press any key: "); key_pressed = c_getch();
                
                break;
            case 'c':
            case 'C':
                clearScreen();
                
                printf("[08] Recursions 101: \n");
                twelve_main();
                printf("[08] Press any key: "); key_pressed = c_getch();
                
                break;
            case 'q':
            case 'Q':
                bMainMenuValidSelection = true;
                break;
            default:
                printf("\n\n  Wrong input, not a menu option: %c\n\n  Please try again", cUserInput);
                
                // Human UI/UX ...
                delay(3);
                break;
        }
    } while (!bMainMenuValidSelection);
    
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
