//
//  05_Functions_part_one.c
//  05_Functions_part_one
//
//  Created by Daniel Eftodi on 2021-09-28.
//

#include "05_Functions_part_one.h"

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

void function_three_exercise_five (void) {
    
    function_three_exercise_five_main_menu();
    
}

void function_three_exercise_five_main_menu (void){
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

void function_three_exercise_five_gameOne_guess_number (void) {
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

void function_four_playing_with_arrays (void) {
    /*
       There are four ways to implement an array
       RTFM: https://www.geeksforgeeks.org/array-strings-c-3-different-ways-create/
     */
    
    // clear the screen
    system("clear");
    
    // Way one :: Using the string class
    std::string words_one[2];   // let's just make an empty array of two
    words_one[0] = "Hello";     // add first word to array
    words_one[1] = "World";     // add second word to array
    
    printf("First word is: %s\nSecond word is: %s\n", words_one[0].c_str(), words_one[1].c_str());
    printf("Size of the arary is: %lu\n", ( sizeof(words_one) / sizeof(std::string) ) );
    printf("Size of first word is: %lu\n", words_one[0].size());
    printf("Size of second word is: %lu\n\n", words_one[1].size());
    
    // Way one :: Using the string class - at defenition
    std::string wordz_one[2] = { "World",
                             "Hello" };

    printf("First word is: %s\nSecond word is: %s\n", wordz_one[0].c_str(), wordz_one[1].c_str());
    printf("Size of first word is: %lu\n", wordz_one[0].size());
    printf("Size of second word is: %lu\n\n", wordz_one[1].size());
    
    
    // Way two :: Using 2D array
    char words_two[2][10] = { "Zombie",
                             "World" };

    printf("First word is: %s\nSecond word is: %s\n\n", words_two[0], words_two[1]);
    
    //ERRORs *hmm*
//    printf("Size of the arary is: %lu\n", words_two.size());
//    printf("Size of first word is: %d\n", words_two[0].size());
//    printf("Size of second word is: %d\n\n", words_two[1].size());
    
    // Way two :: Using 2D array - Why does it fail to build?
//    char words_three[3][19] = { "Zombie",
//                             "World",
//                             "Way to many letters" };
//
//    printf("First word is: %s\nSecond word is: %s\nThird word is: %s\n\n", words_three[0], words_three[1], words_three[2]);
    
    
    // Way three :: Using the vector class
#include <vector>
    std::vector<std::string> words_three;
//    = { "Zoro", "Rulez" };
    
    words_three.push_back("Zoro");
    words_three.push_back("Rulez");

    printf("First word is: %s\nSecond word is: %s\n", words_three[0].c_str(), words_three[1].c_str());
    printf("Size of the arary is: %lu\n", words_three.size());
    printf("Size of first word is: %lu\n", words_three[0].size());
    printf("Size of second word is: %lu\n", words_three[1].size());
}

void function_five_possible_roads_a_frog_can_jump_to_rome (int iNumRequireSteps) {
    /*
    Uppgift:    En groda kan hoppa 1 steg eller 2 steg åt gången.
     
                Man vill veta på hur många olika sätt som grodan
                kan hoppa fram för att nå 50 steg bort.

    Assignment: A frog can either jump 1 or 2 steps at a time.
     
                How many different ways can the frog jump, in 50 steps?
                
                Think: What are all of the possible "Roads to Rome" the
                       frog can jump in 50 steps.
     */
    
    // clear screen
    system("clear");
    
    printf("Lets figure out all of the possbile permutations a frog can jump 1 or 2 steps at a time, in %d steps.", iNumRequireSteps);
}

int main(int argc, char ** argv){

    // Being a dick, obfuscating code writing
//    std::cout << "Hello" << std::endl;std::cout << "World" << "\n";
    
    // Call :: function_one_size_of_datatype ()
//    function_one_size_of_datatype ();

    // Call :: function_two_argc_argv_main ()
//    function_two_argc_argv_main (argc, argv);
    
    // Call :: function_three_exercise_five ()
//    function_three_exercise_five ();
    
    // Call :: function_four_playing_with_arrays ()
    function_four_playing_with_arrays();
    
    // Call :: function_five_possible_roads_a_frog_can_jump_to_rome ()
//    function_five_possible_roads_a_frog_can_jump_to_rome(50);
    
    //Endnig with an extra new line
    std::cout << "\n";
    
    return 0;
}
