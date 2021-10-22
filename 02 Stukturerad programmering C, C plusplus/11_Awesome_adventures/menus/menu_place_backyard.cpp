//
//  menus/menu_place_backyard.cpp
//  11_Awesome_adventures
//
//  Created by Daniel Eftodi on 2021-10-12.
//

#include "menu_place_backyard.h"    // menu code for backyard

void menu_place_backyard(void) {
    char cInputExploreBackyard                  = '\0';
    bool bMainMenuExploreBackyardValidSelection = false;

    do {
        system("clear");
        std::cout << "############################################\n";
        std::cout << "## Awesome adventures                     ##\n";
        std::cout << "## of Stig, Cindy, Sebastian, Ulf & Jerry ##\n";
        std::cout << "##                                        ##\n";
        std::cout << "## Backyard                               ##\n";
        std::cout << "############################################\n";
        std::cout << "\n";
        std::cout << "  (1) - Chairs\n";
        std::cout << "  (R) - Return to Explore Menu\n";
        std::cout << "\n";
        std::cout << "\nWhat do you want to explore?: ";
        std::cin >> cInputExploreBackyard;

        switch (cInputExploreBackyard) {
            case '1':
    //                            printf("LOG_DBG: %c\n", cInput);
                printf("\nThis is not completed, explore something else in the mean while.\n");
                sleep(3);
                bMainMenuExploreBackyardValidSelection = false;
                break;
            case 'r':
            case 'R':
    //                printf("LOG_DBG: %c\n", cInput);
                printf("\nThanks for Exploring, lets explre some more next time");
                bMainMenuExploreBackyardValidSelection = true;
                break;
            default:
                printf("\nWrong input, not a menu option: %c\n\nPlease try again\n", cInputExploreBackyard);
                sleep(3);
                break;
        }
    } while (!bMainMenuExploreBackyardValidSelection);
}
