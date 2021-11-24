//
//  menus/menu_place_backyard.cpp
//  11_Awesome_adventures
//
//  Created by Daniel Eftodi on 2021-10-12.
//

#include "menu_place_backyard.h"    // menu code for backyard

#ifndef menu_place_backyard_opt_h
#define menu_place_backyard_opt_h
#include <string>
#include <iomanip>
//                                  0       1        2            3      4
std::string sCharacterArrayBackyard [5] = {"Stig", "Cindy", "Sebastian", "Ulf", "Jerry" };

#endif /* menu_place_backyard_opt_h */

void menu_place_backyard(int iCharacterChoice)
{
    int cInputExploreBackyard;
    bool bMainMenuExploreBackyardValidSelection = false;
    
    do {
        clearScreen();
        std::cout << "############################################\n";
        std::cout << "## Awesome adventures                     ##\n";
        std::cout << "## of " << std::left << std::setfill(' ') << std::setw(35) << sCharacterArrayBackyard[iCharacterChoice] << " ##\n";
        std::cout << "##                                        ##\n";
        std::cout << "## Backyard                               ##\n";
        std::cout << "############################################\n";
        std::cout << "\n";
        std::cout << "  (1) - Chairs\n";
        std::cout << "  (R) - Return to Explore Menu\n";
        std::cout << "\n  What do you want to explore?: ";
        cInputExploreBackyard = c_getche();

        switch (cInputExploreBackyard) {
            case '1':
    //                            printf("LOG_DBG: %c\n", cInput);
                clearScreen();
                printf("\n\n  You decide to sit in a comfty chair, and take a long nap.\n");
                delay(5);
                bMainMenuExploreBackyardValidSelection = false;
                break;
            case 'r':
            case 'R':
    //                printf("LOG_DBG: %c\n", cInput);
                printf("\n\n  You are going back into the house, lets explore something else in the backyard next time\n");
                delay(4);
                bMainMenuExploreBackyardValidSelection = true;
                break;
            default:
                printf("\n\n  Wrong input, not a menu option: %c\n\n Please try again\n", cInputExploreBackyard);
                delay(3);
                break;
        }
    } while (!bMainMenuExploreBackyardValidSelection);
}
