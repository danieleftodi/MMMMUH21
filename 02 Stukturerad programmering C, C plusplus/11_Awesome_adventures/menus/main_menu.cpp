//
//  menus/main_menu.cpp
//  11_Awesome_adventures
//
//  Created by Daniel Eftodi on 2021-10-12.
//

#include "main_menu.h"    // main menu code

void main_menu (void){
    char cInput                  = '\0';
    char cInputExplore           = '\0';
    bool bMainMenuValidSelection = false;
    bool bMainMenuExploreValidSelection = false;

    do {
        system("clear");
        std::cout << "############################################\n";
        std::cout << "## Awesome adventures                     ##\n";
        std::cout << "## of Stig, Cindy, Sebastian, Ulf & Jerry ##\n";
        std::cout << "##                                        ##\n";
        std::cout << "## Main Menu                              ##\n";
        std::cout << "############################################\n";
        std::cout << "\n";
        std::cout << "  (P) - Play a game of: Guess what Stig is thinking\n";
        std::cout << "  (E) - Explore\n";
        std::cout << "  (A) - Activity\n";
        std::cout << "  (Q) - Quit\n";
        std::cout << "\n";
        std::cout << "  Press any key: ";
        std::cin >> cInput;

        switch (cInput) {
            case 'p':
            case 'P':
                guess_what_stig_it_thinking ();
                bMainMenuValidSelection = true;
                break;
            case 'e':
            case 'E':
//                printf("LOG_DBG: %c\n", cInput);
                bMainMenuExploreValidSelection = false;
                
                do {
                    system("clear");
                    std::cout << "############################################\n";
                    std::cout << "## Awesome adventures                     ##\n";
                    std::cout << "## of Stig, Cindy, Sebastian, Ulf & Jerry ##\n";
                    std::cout << "##                                        ##\n";
                    std::cout << "## Let's explore our surroundings         ##\n";
                    std::cout << "############################################\n";
                    std::cout << "\n";
                    std::cout << "  (1) - The Backyard\n";
                    std::cout << "  (2) - The Bed\n";
                    std::cout << "  (3) - The Cardboard Box\n";
                    std::cout << "  (4) - Cat tree\n";
                    std::cout << "  (5) - Place closet\n";
                    std::cout << "  (6) - Litter box\n";
                    std::cout << "  (7) - Masters shoes\n";
                    std::cout << "  (8) - Neighbours\n";
                    std::cout << "  (9) - Sofa\n";
                    std::cout << "  (W) - Window sill\n";
                    std::cout << "  (R) - Return to Main Menu\n";
                    std::cout << "\n";
                    std::cout << "\nWhat do you want to explore?: ";
                    std::cin >> cInputExplore;

                    switch (cInputExplore) {
                        case '1':
//                            printf("LOG_DBG: %c\n", cInput);
                            printf("\nYou are entering: The Backyard\n");
                            sleep(3);
                            menu_place_backyard();
                            bMainMenuExploreValidSelection = true;
                            break;
                        case '2':
                        case '3':
                        case '4':
                        case '5':
                        case '6':
                        case '7':
                        case '8':
                        case '9':
                        case 'w':
                        case 'W':
//                            printf("LOG_DBG: %c\n", cInput);
                            printf("\nThis is not completed, explore something else in the mean while.\n");
                            sleep(3);
                            bMainMenuExploreValidSelection = false;
                            break;
                        case 'r':
                        case 'R':
            //                printf("LOG_DBG: %c\n", cInput);
                            printf("\nThanks for Exploring, lets explre some more next time");
                            bMainMenuExploreValidSelection = true;
                            break;
                        default:
                            printf("\nWrong input, not a menu option: %c\n\nPlease try again\n", cInputExplore);
                            sleep(3);
                            break;
                    }
                } while (!bMainMenuExploreValidSelection);
                
                
                printf("\nThis is not completed, play something else in the mean while.\n");
                sleep(3);
                bMainMenuValidSelection = false;
                break;
            case 'a':
            case 'A':
//                printf("LOG_DBG: %c\n", cInput);
                printf("\nThis is not completed, play something else in the mean while.\n");
                sleep(3);
                bMainMenuValidSelection = false;
                break;
            case 'q':
            case 'Q':
//                printf("LOG_DBG: %c\n", cInput);
                printf("\nThanks for playing, see you next time");
                bMainMenuValidSelection = true;
                break;
            default:
                printf("\nWrong input, not a menu option: %c\n\nPlease try again\n", cInput);
                sleep(3);
                break;
        }
    } while (!bMainMenuValidSelection);
}
