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

// 4. Recursions 101: Static Variables in Recursion
int four_fun(int n)
{
    // 'static int' is what makes this to work!
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
    if ( n > 0)
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
    
    if ( n > 0)
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

// 7. Recursions 101:
int seven_fun(int n)
{
    if ( n > 0)
    {
        printf("n: %d\n", n);
        return five_fun(n-1)+n;
    }
    
    return 0;
}

int seven_main()
{
    int a = 5;
    printf("r: %d\n", five_fun(a) );
    
    return 0;
}


// 8. Recursions 101:
int eight_fun(int n)
{
    if ( n > 0)
    {
        printf("n: %d\n", n);
        return five_fun(n-1)+n;
    }
    
    return 0;
}

int eight_main()
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
        std::cout << "############################################\n";
        std::cout << "## Recursions 101                         ##\n";
        std::cout << "##                                        ##\n";
        std::cout << "## Main Menu                              ##\n";
        std::cout << "############################################\n";
        std::cout << "\n";
        std::cout << "  (1) - Introduction\n";
        std::cout << "  (2) - Head Recursion\n";
        std::cout << "  (3) - Tail Recursion\n";
        std::cout << "  (4) - Static Variables in Recursion\n";
        std::cout << "  (5) - Global Variabels in Recursion\n";
        std::cout << "  (6) - Tree Recursion\n";
        std::cout << "  (7) - \n";
        std::cout << "  (8) - \n";
        std::cout << "  (9) - \n";
        std::cout << "  (A) - \n";
        std::cout << "  (B) - \n";
        std::cout << "  (Q) - Quit\n";
        std::cout << "\n";
        std::cout << "  Press a key: ";
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
                
                printf("[07] Recursions 101: \n");
                seven_main();
                printf("[07] Press any key: "); key_pressed = c_getch();
                
                break;
            case '8':
                clearScreen();
                
                printf("[08] Recursions 101: \n");
                eight_main();
                printf("[08] Press any key: "); key_pressed = c_getch();
                
                break;
            case 'q':
            case 'Q':
                bMainMenuValidSelection = true;
                break;
            default:
                printf("\nWrong input, not a menu option: %c\n\nPlease try again\n", cUserInput);
                
                // Human UI/UX ...
                delay(3);
                break;
        }
    } while (!bMainMenuValidSelection);
    
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
