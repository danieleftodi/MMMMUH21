//
//  HelloWorld.c
//  HelloXcode_in_C
//
//  Created by Daniel Eftodi on 2021-09-14.
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
    
    // 
    
    // Endnig with an extra new line
    cout << "\n";
    
    return 0;
}
