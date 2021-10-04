//
//  03_Structures_selections_and_iterations_in_Cpp.cpp
//  03_Structures_selections_and_iterations_in_Cpp
//
//  Created by Daniel Eftodi on 2021-09-22.
//

#include "03_Structures_selections_and_iterations_in_Cpp.h"

const bool bAlwaysTrue = true;
const bool bAlwaysFalse = false;

void func_excersize_week_two_day_5_first_if () {
    if (bAlwaysTrue) {
        printf("Hello, I'm the What-if GOD statement, always true\n\n");
    }

    if (bAlwaysTrue && bAlwaysFalse) {
        printf("You should never see this message\n\n");
    } else {
        printf("Since BOOL people or stubborn, they never compromise\n\n");
    }

}

void func_excersize_week_two_day_5_second_if () {
    
}

int func_excersize_week_two_day_5_third_if () {
   
    return 0;
}

int main(){
    
    int iReturnedThirdIf = 0;
    char cInput = '\0';
    
    char phrase[] = "Charater Phrase";
    printf("\nCharater Phrase: %s\n", phrase);
    
    std::cout << "Press any key: ";
    std::cin >> cInput;
    
    switch (cInput) {
        case 'T':
            printf("MAGIC cInput is: %c\n", cInput);
            break;
        default:
            printf("cInput is: %c\n", cInput);
            break;
        
    }

    func_excersize_week_two_day_5_first_if();
    
    func_excersize_week_two_day_5_second_if();
    
    iReturnedThirdIf = func_excersize_week_two_day_5_third_if();
    printf("iReturnedThirdIf: %d\n", iReturnedThirdIf);

    //Endnig with an extra new line
    std::cout << "\n";
    
    return 0;
}
