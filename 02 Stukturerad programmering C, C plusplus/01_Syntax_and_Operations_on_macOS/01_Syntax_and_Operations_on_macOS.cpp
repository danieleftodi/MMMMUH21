//
//  01_Syntax_and_Operations_on_macOS.c
//  01_Syntax_and_Operations_on_macOS
//
//  Created by Daniel Eftodi on 2021-09-15.
//

#include "01_Syntax_and_Operations_on_macOS.h"
#include <iostream>
using namespace std;

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
    
    if (!0) {
        printf("I'm true - !x\n\n");
    } else {
        printf("I'm not true - !x\n\n");
    }
    
    // Endnig with an extra new line
    cout << "\n";
    
    return 0;
}
