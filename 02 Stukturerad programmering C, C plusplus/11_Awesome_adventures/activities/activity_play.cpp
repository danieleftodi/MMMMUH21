//
//  activities/activity_play.c
//  11_Awesome_adventures
//
//  Created by Daniel Eftodi on 2021-10-12.
//

#include "activity_play.h"

void guess_what_stig_it_thinking (void) {
    char           cInput                 = '\0';
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
        std::mt19937 gen(rd());                         // seed the generator
        std::uniform_int_distribution<> distr(0, 10);   // define the range
        for (int n=0; n<1; ++n) {
            iVarRand = distr(gen);                      // generate numbers
        }

        system("clear");
        std::cout << "############################################\n";
        std::cout << "## Awesome adventures                     ##\n";
        std::cout << "## of Stig, Cindy, Sebastian, Ulf & Jerry ##\n";
        std::cout << "##                                        ##\n";
        std::cout << "## Guess what Stig is thinking            ##\n";
        std::cout << "############################################\n";
        std::cout << "\n";
        std::cout << "  ( 1) - Food\n";
        std::cout << "  ( 2) - Have to pee\n";
        std::cout << "  ( 3) - Pats are the greatest, human *wink*!\n";
        std::cout << "  ( 4) - That looks comfy!\n";
        std::cout << "  ( 5) - Oh, what was that?\n";
        std::cout << "  ( 6) - Is someone behind me?\n";
        std::cout << "  ( 7) - Run quick as lightning!\n";
        std::cout << "  ( 8) - Curiousity tickled my wiskers\n";
        std::cout << "  ( 9) - I see a ball of yarn, playtime!\n";
        std::cout << "  (10) - I want to sleep\n";
        std::cout << "\n";
        std::cout << "\nWhat is your guess: ";
        std::cin >> iUserGuess;
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
                case 1:
                    sUserGuessNumberString = "Food";
                    break;
                case 2:
                    sUserGuessNumberString = "Have to pee";
                    break;
                case 3:
                    sUserGuessNumberString = "Pats are the greatest, human *wink*!";
                    break;
                case 4:
                    sUserGuessNumberString = "That looks comfy!";
                    break;
                case 5:
                    sUserGuessNumberString = "Oh, what was that?";
                    break;
                case 6:
                    sUserGuessNumberString = "Is someone behind me?";
                    break;
                case 7:
                    sUserGuessNumberString = "Run quick as lightning!";
                    break;
                case 8:
                    sUserGuessNumberString = "Curiousity tickled my wiskers";
                    break;
                case 9:
                    sUserGuessNumberString = "I see a ball of yarn, playtime!";
                    break;
                case 10:
                    sUserGuessNumberString = "I want to sleep";
                    break;
                default:
                    break;
            }

            switch (iVarRand) {
                case 1:
                    sVarRandString = "Food";
                    break;
                case 2:
                    sVarRandString = "Have to pee";
                    break;
                case 3:
                    sVarRandString = "Pats are the greatest, human *wink*!";
                    break;
                case 4:
                    sVarRandString = "That looks comfy!";
                    break;
                case 5:
                    sVarRandString = "Oh, what was that?";
                    break;
                case 6:
                    sVarRandString = "Is someone behind me?";
                    break;
                case 7:
                    sVarRandString = "Run quick as lightning!";
                    break;
                case 8:
                    sVarRandString = "Curiousity tickled my wiskers";
                    break;
                case 9:
                    sVarRandString = "I see a ball of yarn, playtime!";
                    break;
                case 10:
                    sVarRandString = "I want to sleep";
                    break;
                default:
                    break;
            }
            
            printf("\nYou guessed the number (%d) %s,\n\and Stig was thinking of (%d) %s\n", iUserGuessNumber, sUserGuessNumberString.c_str(), iVarRand, sVarRandString.c_str() );

            if ( iUserGuessNumber == iVarRand ) {
                printf("\nCongratulations!\n");
                printf("*Whoop *Whoop*!\n");
                bGameOneValidGuess = true;
                sleep (5);
            } else {
                printf("\nSorry, wrong guess. Try again.\n");
                bGameOneValidGuess = false;
            }
        }

        // Increment iUserGuessHasGuessed ...
        iUserGuessHasGuessed++;

        // Check how many tries, ask after five tries ..
        if ( iUserGuessHasGuessed >= 5 ) {
            printf("\n...noticed that you have tried: %d times ... want to give up? *wink*  (y/n): ", iUserGuessHasGuessed);

            std::cin >> cInput;

            switch (cInput) {
                case 'y':
                    printf("\n(Stig) Thanks for playing with me .\n");
                    bGameOneValidGuess = true;
                    iUserGuessHasGuessed = 0;
                    break;
                case 'n':
                    printf("\nOkelidokelli\n");
                    bGameOneValidGuess = false;
                    iUserGuessHasGuessed = 0;
                default:
                    break;
            }
        }

        // wait for a few seconds
        sleep (3);

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
