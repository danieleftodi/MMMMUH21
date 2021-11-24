//
//  activities/activity_play.c
//  11_Awesome_adventures
//
//  Created by Daniel Eftodi on 2021-10-12.
//

#include "../activities/activity_play.h"


#ifndef menu_place_activity_opt_h
#define menu_place_activity_opt_h
#include <string>
#include <iomanip>
//                                  0       1        2            3      4
std::string sCharacterArrayActivity [5] = {"Stig", "Cindy", "Sebastian", "Ulf", "Jerry" };

#endif /* menu_place_activity_opt_h */

void guess_what_stig_it_thinking (int iCharacterChoice) {
    int            cInput;
    int            iVarRand               = 0;
    std::string    sVarRandString         = "";
    int            iUserGuessHasGuessed   = 0;
//    int     iUserGuess;
    std::string    iUserGuess             = "";
    int            iUserGuessNumber       = 0;
    std::string    sUserGuessNumberString = "";
    bool           iUserGuessIsNumbers    = true;
    bool           iUserGuessIsInRange    = false;
    bool           bGameOneValidGuess     = false;


    // StackOverflow :: https://stackoverflow.com/questions/7560114/random-number-c-in-some-range
    std::random_device rd;                              // obtain a random number from hardware

    do {
        /*
         * Move this code to common_lib.h
         */
        std::mt19937 gen(rd());                         // seed the generator
        std::uniform_int_distribution<> distr(0, 9);    // define the range
//        for (int n=0; n<1; ++n) {
            iVarRand = distr(gen);                      // generate numbers
//        }

        clearScreen();
        std::cout << "############################################\n";
        std::cout << "## Awesome adventures                     ##\n";
        std::cout << "## of " << std::left << std::setfill(' ') << std::setw(35) << sCharacterArrayActivity[iCharacterChoice] << " ##\n";
        std::cout << "##                                        ##\n";
        std::cout << "## Guess what " << sCharacterArrayActivity[iCharacterChoice] << std::left << std::setfill(' ') << std::setw(27 - (int) sCharacterArrayActivity[iCharacterChoice].length()) << " is thinking" << " ##\n";
        std::cout << "############################################\n";
        std::cout << "\n";
        std::cout << "  (0) - Food\n";
        std::cout << "  (1) - Have to pee\n";
        std::cout << "  (2) - Pats are the greatest, human *wink*!\n";
        std::cout << "  (3) - That looks comfy!\n";
        std::cout << "  (4) - Oh, what was that?\n";
        std::cout << "  (5) - Is someone behind me?\n";
        std::cout << "  (6) - Run quick as lightning!\n";
        std::cout << "  (7) - Curiousity tickled my wiskers\n";
        std::cout << "  (8) - I see a ball of yarn, playtime!\n";
        std::cout << "  (9) - I want to sleep\n";
        std::cout << "\n  What is your guess: ";
        iUserGuess = c_getche();
//        std::cin.ignore( std::numeric_limits<std::streamsize>::max() ) >> iUserGuess;

        // We have to try to convert string input with stoi, and catch if it cannot convort it. Ergo it's not a number.
        try { iUserGuessNumber = std::stoi(iUserGuess); }
        catch (const std::exception& e) {
//            printf("\nDBG_LOG :: Try-Catch :: stoi Error: %s\n", e.what());
            iUserGuessIsNumbers = false;
        }

        if ( iUserGuessIsNumbers ) {
//            printf("\nDBG_LOG :: iUserGuessIsNumbers i a number (%d)\n", iUserGuessNumber);
            if ( iUserGuessNumber >= 0 && iUserGuessNumber <= 10) {
                iUserGuessIsInRange = true;
            } else {
                printf("\nThe number you are guessing (%d) is not in allowed number range (0 -> 10), try again.\n", iUserGuessNumber);
                iUserGuessIsInRange = false;
            }
        } else {
            printf("\nSorry, but your guess (%s) is not a number, try again.\n", iUserGuess.c_str() );
        }

        // Check if the Number is in the range between 0 -> 10 ...
        if ( iUserGuessIsInRange ) {
//            printf("\nYou guessed the number %s, and the computer guesseed the number: %d\n", iUserGuess.c_str(), iVarRand );
            
            switch (iUserGuessNumber) {
                case 0:
                    sUserGuessNumberString = "Food";
                    break;
                case 1:
                    sUserGuessNumberString = "Have to pee";
                    break;
                case 2:
                    sUserGuessNumberString = "Pats are the greatest, human *wink*!";
                    break;
                case 3:
                    sUserGuessNumberString = "That looks comfy!";
                    break;
                case 4:
                    sUserGuessNumberString = "Oh, what was that?";
                    break;
                case 5:
                    sUserGuessNumberString = "Is someone behind me?";
                    break;
                case 6:
                    sUserGuessNumberString = "Run quick as lightning!";
                    break;
                case 7:
                    sUserGuessNumberString = "Curiousity tickled my wiskers";
                    break;
                case 8:
                    sUserGuessNumberString = "I see a ball of yarn, playtime!";
                    break;
                case 9:
                    sUserGuessNumberString = "I want to sleep";
                    break;
                default:
                    break;
            }

            switch (iVarRand) {
                case 0:
                    sVarRandString = "Food";
                    break;
                case 1:
                    sVarRandString = "Have to pee";
                    break;
                case 2:
                    sVarRandString = "Pats are the greatest, human *wink*!";
                    break;
                case 3:
                    sVarRandString = "That looks comfy!";
                    break;
                case 4:
                    sVarRandString = "Oh, what was that?";
                    break;
                case 5:
                    sVarRandString = "Is someone behind me?";
                    break;
                case 6:
                    sVarRandString = "Run quick as lightning!";
                    break;
                case 7:
                    sVarRandString = "Curiousity tickled my wiskers";
                    break;
                case 8:
                    sVarRandString = "I see a ball of yarn, playtime!";
                    break;
                case 9:
                    sVarRandString = "I want to sleep";
                    break;
                default:
                    break;
            }
            
            printf("\n\n  You guessed the number (%d) %s,\n  and %s was thinking of (%d) %s\n", iUserGuessNumber, sUserGuessNumberString.c_str(), sCharacterArrayActivity[iCharacterChoice].c_str(), iVarRand, sVarRandString.c_str() );

            if ( iUserGuessNumber == iVarRand ) {
                printf("\n  Congratulations!\n");
                printf("  *Whoop *Whoop*!\n");
                bGameOneValidGuess = true;
                delay(3);
            } else {
                printf("\n  Sorry, wrong guess. Try again.\n");
                bGameOneValidGuess = false;
            }
        }

        // Increment iUserGuessHasGuessed ...
        iUserGuessHasGuessed++;

        // Check how many tries, ask after five tries ..
        if ( iUserGuessHasGuessed >= 5 ) {
            printf("\n...noticed that you have tried: %d times ... want to give up? *wink*  (y/n): ", iUserGuessHasGuessed);

            cInput = c_getche();

            switch (cInput) {
                case 'y':
                    printf("\n  (%s) Thanks for playing with me .\n", sCharacterArrayActivity[iCharacterChoice].c_str());
                    bGameOneValidGuess = true;
                    iUserGuessHasGuessed = 0;
                    break;
                case 'n':
                    printf("\n  Okelidokelli\n");
                    bGameOneValidGuess = false;
                    iUserGuessHasGuessed = 0;
                default:
                    break;
            }
        }

        // wait for a few seconds
        delay(3);

        // Reset varibales ...
        iVarRand    = 0;
        cInput      = '\0';
        iUserGuess  = '\0';
        iUserGuessIsNumbers = true;
        iUserGuessIsInRange = false;

    } while (!bGameOneValidGuess);

    // Return to Main Menu
    main_menu ();
}
