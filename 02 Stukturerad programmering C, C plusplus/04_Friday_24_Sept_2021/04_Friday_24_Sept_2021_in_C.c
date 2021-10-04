//
//  04_Friday_24_Sept_2021_in_C.c
//  04_Friday_24_Sept_2021_in_C
//
//  Created by Daniel Eftodi on 2021-09-24.
//

#include "04_Friday_24_Sept_2021_in_C.h"


void function_one_size_of_datatype () {
    unsigned int usDataSize = 128;
    
    printf("Data size of usDataSize (%d) is: %lu bytes\n", usDataSize, sizeof(usDataSize) );
    
    printf("Data size of usDataSize (%d) is: %lu bits\n", usDataSize, sizeof(usDataSize) * 8 );
    
    printf("Data size of usDataSize (%d) is: %lu bits\n\n", usDataSize, sizeof(usDataSize) * CHAR_BIT );
}

void function_two_argc_argv_main (int f_argc, char ** f_argv) {
    
    printf("There are %d number of arguments (f_argc)\n", f_argc - 1);
    
    char cf_argv;
    std::string sf_argv;
    
    for (int i = 1; i < f_argc; i++) {
        
        // Felmeddelande:
//        cf_argv = f_argv[i];
        // Lösninagr:
        cf_argv = *f_argv[i];
//        cf_argv = f_argv[i][0];
        
        switch ( cf_argv ) {
            case '-':
                printf("Input is: %s\n", f_argv[i]);
                break;
            case 'i':
                printf("f_argv[%d]: %s\n", i, f_argv[i+1]);
                break;
            case 'e':
                printf("f_argv[%d]: %s\n", i, f_argv[i+1]);
                break;
            case 'c':
                printf("f_argv[%d]: %s\n", i, f_argv[i+1]);
                break;
            case 'h':
                printf("f_argv[%d]: %s\n", i, f_argv[i+1]);
                break;
            default:
//                printf("f_argv[%d]: %s\n", i, f_argv[i]);
                break;
        }
        
//        printf("f_argv[%d]: %s\n", i, f_argv[i]);
        
        // reset cf_argv to NULL
        cf_argv = NULL;
    }
    
}

void function_three_exercise_five () {
    
    function_three_exercise_five_main_menu();
    
}

void function_three_exercise_five_main_menu (){
    char cInput                  = '\0';
    bool bMainMenuValidSelection = false;

    do {
        system("clear");
        std::cout << "###############\n";
        std::cout << "## Main Menu ##\n";
        std::cout << "###############\n";
        std::cout << "\n";
        std::cout << "  (1) - Guess what number, I'm thinking of between 1-10\n";
        std::cout << "  (2) - <Game not completed>\n";
        std::cout << "  (Q) - Quit\n";
        std::cout << "\n";
        std::cout << "  Press any key: ";
        std::cin >> cInput;

        switch (cInput) {
            case '1':
                function_three_exercise_five_gameOne_guess_number ();
                bMainMenuValidSelection = true;
                break;
            case '2':
//                printf("MAGIC: %c\n", cInput);
                printf("\nGame 02 :: This game is note completed, play something else in the mean while.\n");
                sleep(3);
                bMainMenuValidSelection = false;
                break;
            case 'q':
            case 'Q':
//                printf("MAGIC: %c\n", cInput);
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

void function_three_exercise_five_gameOne_guess_number () {
    char    cInput                 = '\0';
    int     iVarRand               = 0;
    int     iUserGuessHasGuessed   = 0;
//    int     iUserGuess;
    std::string    iUserGuess             = "";
    int     iUserGuessNumber       = 0;
    bool    iUserGuessIsNumbers    = true;
    bool    iUserGuessIsInRange    = false;
    bool    bGameOneValidGuess     = false;
    

    // StackOverflow :: https://stackoverflow.com/questions/7560114/random-number-c-in-some-range
    std::random_device rd;                              // obtain a random number from hardware
    
    do {
        std::mt19937 gen(rd());                         // seed the generator
        std::uniform_int_distribution<> distr(0, 10);   // define the range
        for (int n=0; n<1; ++n) {
            iVarRand = distr(gen);                      // generate numbers
        }
    
        system("clear");
        printf("\nGame 01 :: Guess what number, I'm thinking of between 0 -> 10\n");
        
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
            printf("\nYou guessed the number %d, and the computer guesseed the number: %d\n", iUserGuessNumber, iVarRand );
            
            if ( iUserGuessNumber == iVarRand ) {
                printf("\nCongratulations!\n");
                printf("*Whoop *Whoop*!\n");
                bGameOneValidGuess = true;
                sleep (3);
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
                    printf("\nThanks for trying your best.\n");
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
    function_three_exercise_five_main_menu ();
}

int main(int argc, char ** argv){

    // Call :: function_one_size_of_datatype ()
    function_one_size_of_datatype ();

    // Call :: function_two_argc_argv_main ()
    function_two_argc_argv_main (argc, argv);
    
    // Call :: function_three_exercise_five ()
    function_three_exercise_five ();

    //Endnig with an extra new line
    std::cout << "\n";
    
    return 0;
}
