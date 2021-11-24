//
//  menus/main_menu.cpp
//  11_Awesome_adventures
//
//  Created by Daniel Eftodi on 2021-10-12.
//

#include "../common/common.h"       // common code

#ifndef main_menu_opt_h
#define main_menu_opt_h
#include <string>
#include <iomanip>
//                                  0       1        2            3      4
std::string sCharacterArray [5] = {"Stig", "Cindy", "Sebastian", "Ulf", "Jerry" };
int         cCharacterChoice[1] = {0};
bool        bMainMenuCharacterValidSelection = false;

#endif /* main_menu_opt_h */

void main_menu (void){
    int  cInput;
    int  cInputExplore;
    int  cInputCharacter;
    bool bMainMenuValidSelection = false;
    bool bMainMenuExploreValidSelection = false;

    // Choose character menu
    while (!bMainMenuCharacterValidSelection)
    {
        clearScreen();
        std::cout << "############################################\n";
        std::cout << "## Awesome adventures                     ##\n";
        std::cout << "## of " << std::left << std::setfill(' ') << std::setw(35) << "????" << " ##\n";
        std::cout << "##                                        ##\n";
        std::cout << "## Choose a Character                     ##\n";
        std::cout << "############################################\n";
        std::cout << "\n";
        std::cout << "  (0) - Stig\n";
        std::cout << "  (1) - Cindy\n";
        std::cout << "  (2) - Sebastian\n";
        std::cout << "  (3) - Ulf\n";
        std::cout << "  (4) - Jerry\n";
        std::cout << "\n  Who do you choose?: ";
        cInputCharacter = c_getche();
        
        switch (cInputCharacter) {
            case '0':
                cCharacterChoice[0] = 0;
                bMainMenuCharacterValidSelection = true;
                break;
            case '1':
                cCharacterChoice[0] = 1;
                bMainMenuCharacterValidSelection = true;
                break;
            case '2':
                cCharacterChoice[0] = 2;
                bMainMenuCharacterValidSelection = true;
                break;
            case '3':
                cCharacterChoice[0] = 3;
                bMainMenuCharacterValidSelection = true;
                break;
            case '4':
                cCharacterChoice[0] = 4;
                bMainMenuCharacterValidSelection = true;
                break;
            default:
                printf("\n\n  Wrong input, not a menu option: %c\n\n  Please try again\n", cInputCharacter);
                delay(1);
                bMainMenuCharacterValidSelection = false;
                break;
        }
    };
        
    // Main Game Menu
    do {
        clearScreen();
        std::cout << "############################################\n";
        std::cout << "## Awesome adventures                     ##\n";
        std::cout << "## of " << std::left << std::setfill(' ') << std::setw(35) << sCharacterArray[cCharacterChoice[0]] << " ##\n";
        std::cout << "##                                        ##\n";
        std::cout << "## Main Menu                              ##\n";
        std::cout << "############################################\n";
        std::cout << "\n";
        std::cout << "  (P) - Play a game of: Guess what " << sCharacterArray[cCharacterChoice[0]] << " is thinking\n";
        std::cout << "  (E) - Explore\n";
        std::cout << "  (Q) - Quit\n";
        std::cout << "\n  Press any key: ";
        cInput = c_getche();

        switch (cInput) {
            case 'p':
            case 'P':
                bMainMenuValidSelection = true;
                guess_what_stig_it_thinking(cCharacterChoice[0]);
                break;
            case 'e':
            case 'E':
                bMainMenuExploreValidSelection = false;
                bMainMenuValidSelection = true;
                do {
                    clearScreen();
                    std::cout << "############################################\n";
                    std::cout << "## Awesome adventures                     ##\n";
                    std::cout << "## of " << std::left << std::setfill(' ') << std::setw(35) << sCharacterArray[cCharacterChoice[0]] << " ##\n";
                    std::cout << "##                                        ##\n";
                    std::cout << "## Let's explore our surroundings         ##\n";
                    std::cout << "############################################\n";
                    std::cout << "\n";
                    std::cout << "  (1) - The Backyard\n";
                    std::cout << "  (R) - Return to Main Menu\n";
                    std::cout << "\n  What do you want to explore?: ";
                    cInputExplore = c_getche();

                    switch (cInputExplore) {
                        case '1':
                            printf("\n\n  You are entering: The Backyard\n");
                            delay(3);
                            bMainMenuExploreValidSelection = false;
                            menu_place_backyard(cCharacterChoice[0]);
                            break;
                        case 'r':
                        case 'R':
                            printf("\n\n  Thanks for exploring, lets explore some more next time\n");
                            delay(3);
                            bMainMenuExploreValidSelection = true;
                            break;
                        default:
                            printf("\n\n  Wrong input, not a menu option: %c\n\n  Please try again\n", cInputExplore);
                            delay(3);
                            break;
                    }
                } while (!bMainMenuExploreValidSelection);
                
                bMainMenuValidSelection = false;
                break;
            case 'q':
            case 'Q':
                printf("\n\n  Thanks for playing, see you next time");
                bMainMenuValidSelection = true;
                break;
            default:
                printf("\n  Wrong input, not a menu option: %c\n\n  Please try again\n", cInput);
                delay(3);
                break;
        }
    } while (!bMainMenuValidSelection);
}
