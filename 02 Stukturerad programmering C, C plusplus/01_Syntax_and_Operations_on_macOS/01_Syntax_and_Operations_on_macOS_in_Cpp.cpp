//
//  01_Syntax_and_Operations_on_macOS_in_Cpp.c
//  01_Syntax_and_Operations_on_macOS_in_Cpp
//
//  Created by Daniel Eftodi on 2021-09-15.
//

#include "01_Syntax_and_Operations_on_macOS_in_Cpp.h"

using namespace std;

int function_eleven(int a, int b) {
    // 11
    cout << "Inside function_eleven:\n\n";
    printf("Den här funktionen tar två variabler, %d och %d och räknar\nut vad %d multiplicerat med %d blir och returnerar det.\n\n", a, b, a, b);
    return (a * b);
}

int main(){
    // Maknig the HelloWorld print example with the printf()-command ...
    printf("Hello Syntax\n");

    // Making the HelloWorld print example with the std::cout-command ...
    cout << "\nHello cout Syntax\n\n";
    
    // cout without end-line chars ...
    cout << "Hello cout Line 2";
    cout << "Hello cout Line 3";
    
    // cout with end-line chars ...
    cout << endl << "Hello cout Line 4" << endl;
    cout << "Hello cout Line 5" << endl;
    
    // Printing a CHAR varibale with printf ...
    char ch = 'N';
    printf("\nVi har valt bokstaven %c.\n", ch);

    // Printing a INT varibale with printf ...
    int x = 22;
    printf("\nx är lika med %d.\n", x);
    
    // Logical operators - example from slides (page 26 / 40)
    x = 5;
    printf("\nx is: %d\n\n", x);
    
    if (x < 8 && x < 16) {
        printf("I'm true - (x is less then 8) AND (less then 16)\n\n");
    } else {
        printf("I'm not true - (x is not less then 8) AND (not less then 16)\n\n");
    }

    if (x < 5 && x < 10) {
        printf("I'm true - (x is less then 5) AND (less then 10)\n\n");
    } else {
        printf("I'm not true - (x is not less then 5) AND (not less then 10)\n\n");
    }
    
    if (x > 3 && x > 5) {
        printf("I'm true - (x is more then 3) AND (more then 5)\n\n");
    } else {
        printf("I'm not true - (x is not more then 3) AND (not more then 5)\n\n");
    }
    
    
    if (x || 0 ) {
        printf("I'm true - ( %d ) OR ( 0 )\n\n", x);
    } else {
        printf("I'm not true - ( %d ) OR ( 0 )\n\n", x);
    }

    if (x == 6 || x > 6 ) {
        printf("I'm true - (x is equal to 6) OR (x is greater than 6)\n\n");
    } else {
        printf("I'm not true - (x is not equal to 6) OR (x is not greater than 6)\n\n");
    }
    
    if (x - 5 || x > 1 ) {
        printf("I'm true - (x minus 5 = %d) OR (x is greater than 1)\n\n", (x - 5));
    } else {
        printf("I'm not true - (x minus 5 = %d) OR (x is not greater than 1)\n\n", (x - 5));
    }
    
    if (!x) {
        printf("I'm true - !x\n\n");
    } else {
        printf("I'm not true - !x\n\n");
    }
    
    if ((!0)) {
        printf("I'm true - !x\n\n");
    } else {
        printf("I'm not true - !x\n\n");
    }
    
    // Calucalte modulus of: a. 10 % 9 =
    double val = 10;
    int    wal = 10;
    printf("%f \n", (val / 9) );
    printf("%d \n\n", (wal % 9) );
    
    // Calucalte modulus of: b. 12 % 6 =
    double zal = 12;
    int    xal = 12;
    printf("%f \n", (zal / 6) );
    printf("%d \n\n", (xal % 6) );
    
    // Same xval for all excersises:
    int xval = 10;
    
    // 8a. !x && 1
    if ( !x && 1 ) {
        printf("8a = True\n");
    } else {
        printf("8a = False\n");
    }

    // 8b. (x - 5) % 2
    printf("8b Result is: %d\n", (xval - 5) % 2 );
    
    // 8c. (x - 2) / 2 + 9
    printf("8c Result is: %d\n", (xval - 2) / 2 + 9 );
    
    // 8d. x - 100 / (x * 2) || !0
    if ( x - 100 / (x * 2) || /* DISABLES CODE */ (!0) ) {
        printf("8d = True\n");
    } else {
        printf("8d = False\n");
    }
    
    // 8e. x /= 2
    printf("8e Result is: %d\n\n", xval /= 2 );
    
    // Same yval for all excersises:
    int yval = 6;
    
    // 9a. 3 * y % 5
    printf("9a Result is: %d\n", 3 * yval % 5 );
    
    // 9b. y * y - 30
    printf("9b Result is: %d\n", yval * yval - 30 );
    
    // 9c. 144 - 4 * y > 800 % (15 - y)
    printf("9c Result is: %d\n\n", 144 - 4 * yval > 800 % (15 - yval) );
    
    // 10
    cout << "10:";
    printf("\n\
    Would you like to play a game?\n\
        A game of war and peace?\n\
    Chess perhaps? Or tic tac toe?\n\
        No, Global Thermonuclear War.\n\
    A strange game, but ok.\n\
        Is it real or is it fake?\n\
    Only winners do not play.\n\
    Players always lose.\n\
        Chess it is then, my old friend!\n\n");

    // call funktion eleven
    cout << "11:\n";
    int result_func_eleven = function_eleven(10, 20);
    printf("Result is: %d\n", result_func_eleven);
    
    // Endnig with an extra new line
    cout << "\n";
    
    return 0;
}
