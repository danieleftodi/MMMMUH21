//
//  15_Functions_Templates_in_Cpp.cpp
//  15_Functions_Templates_in_Cpp
//
//  Created by Daniel Eftodi on 2021-10-12.
//

#include "15_Functions_Templates_Classes_in_Cpp.h"

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
    char           cInput                 = '\0';
    int            iVarRand               = 0;
    int            iUserGuessHasGuessed   = 0;
//    int     iUserGuess;
    std::string    iUserGuess             = "";
    int            iUserGuessNumber       = 0;
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

void function_enumeration_example_one (void) {
    
}

void function_enumeration_example_two (void) {
    
//    enum suit cards = diamonds;
    int iWantToCheckFor = 3;
    cards = clubs;
    if (cards == iWantToCheckFor){
        printf("Yes: it is 3\n");
    } else {
        printf("No: it is not 3\n");
    }
}

void function_array_example_two_add_search (void) {
    int iArrayOne[10];
    int iArrayOneCounter = sizeof(iArrayOne)/sizeof(int);
    int iArrayKeywordToSearch;
    
    printf("Array size: %d\n", iArrayOneCounter);
    
    for (int i = 0; i < iArrayOneCounter; i++)
    {
        printf("Enter number %d of %d into the array: ", i, iArrayOneCounter);
        std::cin >> iArrayOne[i];
        printf("\n");
    }
    
    printf("Enter keyword to search for: ");
    std::cin >> iArrayKeywordToSearch;
    
    for (int i = 0; i < iArrayOneCounter; i++)
    {
        if (iArrayKeywordToSearch == iArrayOne[i])
        {
            printf("I have found the keyword (%d) in the array at: %d\n", iArrayKeywordToSearch, i);
        }
    }
}

void function_array_example_three_find_middle (void) {
    int     iArrayOne[10]           = {6, 8, 13, 17, 20, 22, 25, 28, 30, 35};
    int     iArrayOneCounter        = sizeof(iArrayOne)/sizeof(int);
    int     iArrayOneMin            = 0;
    int     iArrayOneMax            = iArrayOneCounter - 1;
    int     iArrayOneMid            = ( (iArrayOneMin + iArrayOneMax)/2 );
    int     iArrayKeywordToSearch   = 28;
    
/* FOR DEBUGGING */
    for (int i = 0; i < iArrayOneCounter; i++)
    {
        printf("Array[%d]: %d\n", i, iArrayOne[i]);
    }
    printf("Array Len : %d\n",              iArrayOneCounter);
    printf("Array Min : %d\n",              iArrayOneMin);
    printf("Array Max : %d\n",              iArrayOneMax);
    printf("Array Mid : %d\n",              iArrayOneMid);
    printf("iArrayKeywordToSearch: %d\n",   iArrayKeywordToSearch);
/* END */

    while ( iArrayOneMin <= iArrayOneMax )
    {
        printf("DBG_LOG :: In-while-loop\n");
        printf("DBG_LOG :: Array Min : %d\n",          iArrayOneMin);
        printf("DBG_LOG :: Array Max : %d\n",          iArrayOneMax);
        printf("DBG_LOG :: Array Mid : %d\n",          iArrayOneMid);
        
        if( iArrayKeywordToSearch == iArrayOne[iArrayOneMid] )
        {
            std::cout << "Found at :" << iArrayOneMid << std::endl;
            break;
        }
        else if ( iArrayKeywordToSearch < iArrayOne[iArrayOneMid] )
        {
            iArrayOneMax = iArrayOneMid - iArrayOneMin;
        }
        else
        {
            iArrayOneMin = iArrayOneMid + iArrayOneMin;
        }
    }
}

void function_array_example_four_sum_all_elements (void) {
    int     iArrayFour[7]           = {2, 4, 11, 8, 10, 15, 13};
    int     iArrayFourCounter        = sizeof(iArrayFour)/sizeof(int);
    int     iArrayFourMin            = 0;
    int     iArrayFourMax            = iArrayFourCounter - 1;
    int     iArrayFourMid            = ( (iArrayFourMin + iArrayFourMax)/2 );
    int     iArrayFourSum            = 0;
    
/* FOR DEBUGGING */
    printf("##############\n");
    for (int i = 0; i < iArrayFourCounter; i++)
    {
        printf("Array[%d]: %d\n", i, iArrayFour[i]);
    }
    printf("##############\n");
    printf("Array Len : %d\n", iArrayFourCounter);
    printf("Array Min : %d\n", iArrayFourMin);
    printf("Array Max : %d\n", iArrayFourMax);
    printf("Array Mid : %d\n", iArrayFourMid);
    printf("Array Sum : %d\n", iArrayFourSum);
    printf("##############\n");
/* END */
    
    // TASK :: add all elements from Array A to sum
    for (int i = 0; i < iArrayFourCounter; i++)
    {
        printf("Array Sum : %d\n", iArrayFourSum);
        printf("Array Add : %d\n", iArrayFour[i]);
        iArrayFourSum += iArrayFour[i];
        printf("Array Res : %d\n", iArrayFourSum);
        printf("--------------\n");
    }
        
    // TASK :: print sum
    
    printf("Array Final Sum : %d\n", iArrayFourSum);
    printf("==============\n");
    
}

void function_array_example_five_find_max_number (void) {
    int     iArrayFive[]            = { 4, 6, 27, 15, 31, 22, 30, 29, 8, 16};
    int     iArrayFiveCounter       = sizeof(iArrayFive)/sizeof(int);
    int     iArrayFiveMin           = 0;
    int     iArrayFiveMax           = iArrayFiveCounter - 1;
    int     iArrayFiveMaxValue      = iArrayFive[iArrayFiveMin];
    int     iArrayFiveCurrValue;
    
/* FOR DEBUGGING */
    printf("##############\n");
    for (int i = 0; i < iArrayFiveCounter; i++)
    {
        printf("Array[%d]: %d\n", i, iArrayFive[i]);
    }
    printf("##############\n");
    printf("Array Len : %d\n", iArrayFiveCounter);
    printf("Array Min : %d\n", iArrayFiveMin);
    printf("Array Max : %d\n", iArrayFiveMax);
    printf("##############\n");
/* END */
    
    // TASK :: write a loop to find max
    for (int i = 0; i < iArrayFiveCounter; i++)
    {
        printf("Array Index Value : %d\n", i);
        
        iArrayFiveCurrValue = iArrayFive[i];

        printf("Array Curr  Value : %d\n", iArrayFiveCurrValue);
        printf("Array Max   Value : %d\n", iArrayFiveMaxValue);

        if ( iArrayFiveCurrValue >= iArrayFiveMaxValue )
        {
            printf("Curr >= Max\n");
            iArrayFiveMaxValue = iArrayFiveCurrValue;
        }
        else
        {
            printf("Curr < Max\n");
            iArrayFiveMaxValue = iArrayFiveMaxValue;
        }
        
        printf("Array Max   Value : %d\n", iArrayFiveMaxValue);
        printf("--------------\n");
    }
    
    printf("--------------\n");
    printf("Array Final Max Value : %d\n", iArrayFiveMaxValue);
    printf("--------------\n");
    
}

void function_array_example_six_find_min_number (void) {
    int     iArrayFive[]            = { 8, 4, 12, 37, 36, 25, -2, 10, 15, 25};
    int     iArrayFiveCounter       = sizeof(iArrayFive)/sizeof(int);
    int     iArrayFiveMin           = 0;
    int     iArrayFiveMax           = iArrayFiveCounter - 1;
    int     iArrayFiveMaxValue      = iArrayFive[iArrayFiveMin];
    int     iArrayFiveCurrValue;
    
/* FOR DEBUGGING */
    printf("##############\n");
    for (int i = 0; i < iArrayFiveCounter; i++)
    {
        printf("Array[%d]: %d\n", i, iArrayFive[i]);
    }
    printf("##############\n");
    printf("Array Len : %d\n", iArrayFiveCounter);
    printf("Array Min : %d\n", iArrayFiveMin);
    printf("Array Max : %d\n", iArrayFiveMax);
    printf("##############\n");
/* END */
    
    // TASK :: write a loop to find max
    for (int i = 0; i < iArrayFiveCounter; i++)
    {
        printf("Array Index Value : %d\n", i);
        
        iArrayFiveCurrValue = iArrayFive[i];

        printf("Array Curr  Value : %d\n", iArrayFiveCurrValue);
        printf("Array Max   Value : %d\n", iArrayFiveMaxValue);

        if ( iArrayFiveCurrValue <= iArrayFiveMaxValue )
        {
            printf("Curr >= Max\n");
            iArrayFiveMaxValue = iArrayFiveCurrValue;
        }
        else
        {
            printf("Curr < Max\n");
            iArrayFiveMaxValue = iArrayFiveMaxValue;
        }
        
        printf("Array Max   Value : %d\n", iArrayFiveMaxValue);
        printf("--------------\n");
    }
    
    printf("--------------\n");
    printf("Array Final Max Value : %d\n", iArrayFiveMaxValue);
    printf("--------------\n");
    
}

void function_array_example_seven_count_pos_neg_number (void) {
    
}

void function_array_example_neight_nested_for_loops (void) {
    int iArrayNeight2D_22[2][2]     = { {0, 1},
                                        {2, 3}
                                    };
    
    int iArrayNeight2D_55[5][5]     = { { 0,  1,  2,  3,  4},
                                        { 6,  7,  8,  9, 10},
                                        {11, 12, 13, 14, 15},
                                        {16, 17, 18, 19, 20},
                                        {21, 22, 23, 24, 25},
                                    };

//    int iArrayNeight3D_222[2][2][2] = { {{0,1}, {2,3}},
//                                        {{4,5}, {6,7}},
//                                    };
//
//    int iArrayNeight3D_552[5][5][2] = { {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}},
//                                        {{1, 0}, {1, 1}, {1, 2}, {1, 3}, {1, 4}},
//                                        {{2, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 4}},
//                                        {{3, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}},
//                                        {{4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}},
//                                    };

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("DBG_LOG :: i: %d j: %d\n", i, j);
        }
    }
    
    printf("\n");
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
//            printf("DBG_LOG :: i: %d j: %d\n", i, j);
            if ( i <= j)
            {
                printf("*");
            }
        }
        printf("\n");
    }
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
//            printf("DBG_LOG :: i: %d j: %d\n", i, j);
            if ( i+j >= 4 - 1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    printf("\n");
    
    for (int x = 0; x <= 1; x++)
    {
        for (int y = 0; y <= 1; y++)
        {
            printf("DBG_LOG :: i: %d j: %d v: %d\n", x, y, iArrayNeight2D_22[x][y] );
        }
    }
    
    printf("\n");
    
    for (int x = 0; x <= 4; x++)
    {
        for (int y = 0; y <= 4; y++)
        {
            printf("DBG_LOG :: i: %d j: %d v: ", x, y);
            
            if (iArrayNeight2D_55[x][y] < 10)
            {
                printf(" ");
            }
            
            printf("%d\n", iArrayNeight2D_55[x][y] );
        }
    }
    
}

void function_array_example_nine_make_array_add_div_avg (void) {
    int     iArrayNineMin = 0;
    float   iArrayNineAvg;
    float   iArrayNineSum = 0.0;
    int     iArrayNineNumElements;

/* ASK FOR ELEMENTS, CREATE ARRAY */
    printf("Enter how many desired elemens: ");
    std::cin >> iArrayNineNumElements;
    
    printf("Creating an array with %d elements\n", iArrayNineNumElements);
    
    float iArrayNine[iArrayNineNumElements];
    
    for (int i = 0; i < iArrayNineNumElements; i++)
    {
        printf("Enter value for Index [%d]: ", i);
        std::cin >> iArrayNine[i];
    }
    
/* FOR DEBUGGING */
    int iArrayNineCounter   = (int) sizeof(iArrayNine)/sizeof(float);
    int iArrayNineMax       = iArrayNineCounter - 1;
    printf("##############\n");
    for (int i = 0; i < iArrayNineCounter; i++)
    {
        printf("Array[%d]: %f\n", i, iArrayNine[i]);
    }
    printf("##############\n");
    printf("Array Len : %d\n", iArrayNineCounter);
    printf("Array Min : %d\n", iArrayNineMin);
    printf("Array Max : %d\n", iArrayNineMax);
    printf("##############\n");
/* END */

/* CALC AVG */
    for (int i = 0; i < iArrayNineNumElements; i++)
    {
        printf("DBG_LOG :: i: %d v: %f\n", i, iArrayNine[i]);
        iArrayNineSum += iArrayNine[i];
    }
    
    iArrayNineAvg = ( iArrayNineSum / iArrayNineNumElements );
    
    printf("==============\n");
    printf("Array Sum : %f\n", iArrayNineSum);
    printf("Array Avg : %f\n", iArrayNineAvg);
    
}

void function_pointer_example_one_basic_declaration (void) {
    int iPointerAWillPointTo    = 10;                       // give it a value
    int *pPointerA              = &iPointerAWillPointTo;    // points to the address of iPointerAWillPointTo

/* DEBUG LOG */
    printf("iPointerAWillPointTo Value  : %d\n", iPointerAWillPointTo);
    printf("iPointerAWillPointTo Address: %p\n", &iPointerAWillPointTo);
    printf("pPointerA  : %p\n", pPointerA);
    printf("&pPointerA : %p\n", &pPointerA);
    printf("*pPointerA : %d\n\n", *pPointerA);
/* END */
    
    int iArrayOne[] = {2, 4, 6, 8, 10, 12};   // create an array in stack
    int *p = iArrayOne;
    int *q = &iArrayOne[0];
  
/* DISABLED CODE :: Since the task evolved and didn't need this piece,
                    but didn't want to throw it away ... just-in-case */
//    int iArrayTwoSize;
//    printf("Enter number of elements: ");
//    std::cin >> iArrayTwoSize;
//    int *pPointerB = new int[iArrayTwoSize];
//    int iArrayTwo[*pPointerB];
//    printf("Size of iArrayTwo: %lu", sizeof(iArrayTwo) );
/* END */
    
    printf("Index:  0  1  2  3   4   5 \n");
    printf("Array: {2, 4, 6, 8, 10, 12}\n");
    printf(" p: %p\n", p);
    printf(" q: %p\n", q);
    
    printf("&p: %p\n", &p);
    printf("&q: %p\n", &q);
    
    printf("*p: %d\n", *p);
    printf("*q: %d\n", *q);
      
    // Increment p++; p += 3;
    p++;
    p += 3;
    
    printf("\nIncrement p += 3\n");
    printf(" p: %p\n", p);
    printf(" q: %p\n", q);
    
    printf("&p: %p\n", &p);
    printf("&q: %p\n", &q);
    
    printf("*p: %d\n", *p);
    printf("*q: %d\n", *q);
    
    // Increment p-3
    p -= 4;
    
    printf("\nIncrement p -= 3\n");
    printf(" p: %p\n", p);
    printf(" q: %p\n", q);
    
    printf("&p: %p\n", &p);
    printf("&q: %p\n", &q);
    
    printf("*p: %d\n", *p);
    printf("*q: %d\n", *q);
    
    char cString[20];
    printf("\nenter your name: ");
    std::cin.getline(cString, 20);
    printf("Welcome %s [%zu]\n", cString, strlen(cString));
    
    for (int i = 0; i < strlen(cString); i++)
    {
        printf("[");
        if ( i < 10 ) { printf("0");}
        printf("%d] %c\n", i, cString[i]);
    }
    

/* strtok */
    char input[] = "one + two * (three - four)!";
    std::cout << input << std::endl;
    const char* delimiters = "! +- (*)";
    char *token = std::strtok(input, delimiters);
    while (token) {
        std::cout << token << " ## ";
        token = std::strtok(nullptr, delimiters);
    }
 
    std::cout << "\nContents of the input string now:\n\"";
    for (std::size_t n = 0; n < sizeof input; ++n) {
        if (const char c = input[n]; c != '\0')
            std::cout << c;
        else
            std::cout << "\\0";
    }
    std::cout << "\"\n";

    
/* Vowel or Consonant */
    int vowelsCount = 0, wordCount = 1 , consonantCount = 0;
    std::string str = "WORD ONE TWO";
    
    printf("\n");
    
    for ( char c : str )
    {
        switch (c) {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
                vowelsCount++;
                printf("Is a vowel: %c\n", c);
                break;
            case ' ':
                wordCount++;
                printf("Found a space: %c\n", c);
                break;
            default:
                consonantCount++;
                printf("Not a vowel: %c\n", c);
                break;
        }
    }
    
    printf("Found %d vowels\n", vowelsCount);
    printf("Found %d consonants\n", consonantCount);
    printf("Found %d words\n", wordCount);
    
}

/* MAKE THESE

 void function_pointer_example_two_ (void);
 
 void function_chars_and_strings_example_one_basic_stuff (void);
 
 */

template <class ftWhichIsMax>
ftWhichIsMax ftWhichIsMax (ftWhichIsMax a, ftWhichIsMax b) {
    return a > b ? a : b;
}

void function_template_example_one_basic_declaration (void) {
    
    printf("Which is Max? 10 or 5: %d\n", ftWhichIsMax(10, 5));
    printf("Which is Max? 12.5f or 17.3f?: %f\n", ftWhichIsMax(12.5f, 17.3f));
    
}

void function_template_example_two_going_static (void) {
    
    static int s = 10; // Our declared static variable
    if (s < 11 ) { printf("Value is [INIT]: %d\n", s); }
    s++;
    printf("Value is [s++] : %d\n", s);
}

void function_template_example_three_find_element_in_array (void) {
    
    int iArrayThree[11] = { 0, 1, 2, 3, 4 , 5 , 6, 7, 8, 9, 10};
    int iArrayThreeSize = sizeof(iArrayThree)/sizeof(int);
    int iInputUser      = 0;
    
    printf("Size of iArrayThree[]: %d\n", iArrayThreeSize );
//  printf("Size of compB[]      : %lu\n", (sizeof(compB)      /sizeof(int)) );
    
    printf("Guess a value betwenn 0 --> 10: ");
    
    std::cin >> iInputUser;
    
    printf("Please wait, while we are processing your requst ...\n");
    sleep(3);
    
    if (function_template_example_three_find_element_in_array_loop(iInputUser, iArrayThree, iArrayThreeSize ))
    {
        printf("Hope you are happy with your answer\n");
    }
    else
    {
        printf("I don't seem to have what you are searching for in my records\n");
    }
    
}

int function_template_example_three_find_element_in_array_loop (int compA, int compB[], int compBSize) {
    printf("Size of compB[]: %d\n", compBSize );
    
    for (int i = 0; i < compBSize ; i++)
    {
        printf("[%d]: %d \n", i, compB[i]);
        
        if (compB[i] == compA)
        {
            printf("Found %d, at index[%d]\n", compA, i);
            return 1;
            
        }
    }
    
    return 0;
}

void function_class_example_one_basic_declaration (void) {
    class cOneRectangle
    {
        public:
            int lenght;
            int breadth;
            
            int area ()
            {
                return lenght * breadth;
            };
            
            int perimiter ()
            {
                return 2 * (lenght + breadth);
            }
    };
    
    cOneRectangle r1;
    r1.lenght   = 10;
    r1.breadth  = 10;
    
    printf("The area of r1 is %d, and the perimiter is %d\n", r1.area(), r1.perimiter());
}

void function_class_example_two_public_private_declaration (void) {
    class cOneRectangle
    {
    public:
        int lenght;
        int breadth;
        
        int area ()
        {
            return lenght * breadth;
        }
        
        int perimiter ()
        {
            return 2 * (lenght + breadth);
        }
        
        float get_the_hypotenuse ()
        {
            return hypotenuse();
        }
    private:
        float hypotenuse ()
        {
            return sqrt((lenght*lenght) + (breadth*breadth));
        }
    };
    
    cOneRectangle r1;
    r1.lenght   = 10;
    r1.breadth  = 10;
    
    printf("The hypotenuse is %f", r1.get_the_hypotenuse());
}

void function_ludwig_week_two_check_that_we_can (void) {
//    Uppgift 1;
//    Write an expression for calculating Distance with the parameters;
//
//    dInitVelocity  (u) -- initial velocity
//    dFinalVelocity (v) -- final velocity
//    dAcceleration  (a) -- acceleration
//
//    Formeln för detta lyder; (v*v-u*u)/(2*a)
    
    double dInitVelocity = 0.0;
    double dFinalVelocity = 100.0;
    double dAcceleration = 9.82;
    double dResult = 0;
    
    dResult = ( (dFinalVelocity * dFinalVelocity) - (dInitVelocity * dInitVelocity) ) / ( 2 * dAcceleration );
    printf("[01] Your distance traveled is: %f m\n", dResult);
    
    
//    Uppgift 2;
//    Beräkna en triangles area
    
    int iBase = 7;
    int iHeight = 5;
    float fArea;
    
    //Write a expression to find Area as float using typecasting
    fArea = (float) iBase * iHeight;
    
    printf("[02] The Area is: %f\n", fArea);
    
    
//    Uppgift 3;
//    Hitta största angedda siffran
    
    int iAxisX = 10;
    int iAxisY = 20;
    
    //write conditions here to print maximum of 2 numbers
    printf("[03] The Maximum value is: %d\n", ( iAxisX > iAxisY ? iAxisX : iAxisY ));

    
//    Uppgift 4;
//    Urskilja positiva och negativa tal
    
    int iSign = -10;
    
    //write conditional statement here to print "positive" or "negative"
    if (iSign > 0)
    {
        printf("[04] iSign is positive\n");
    }
    else
    {
        printf("[04] iSign is negative\n");
    }
    

//    Uppgift 5;
//    Urskilja jämna och udda nummer.
    
    int iOddEven = 3;
    
    //write condition here to check "odd" or "even"
     if ( iOddEven % 2 == 0)
     {
         printf("[05] iOddEven is even\n");
     }
     else
     {
         printf("[05] iOddEven is odd\n");
     }

    
//    Uppgift 6;
//    Om det är mellan klockan 9 och 17 skall man printa working.
    
    int iWorkStart      =  9;
    int iWorkEnd        = 17;
    int iWorkCheckHour  = 10;
    
    //write condition here to print "working" or "leisure"
    if (( iWorkCheckHour >= iWorkStart ) && ( iWorkCheckHour <= iWorkEnd ))
    {
        printf("[06] Hour is working\n");
    }
    else
    {
        printf("[06] Hour is leisure\n");
    }
    
    
//    Uppgift 7;
//    Om variabeln ålder är lägre än 12 eller större än 50, printa eligible;
    
    int iEligibleFirstAge   = 12;
    int iEligibleSecondAge  = 50;
    int iEligibleAgeCheck   = 10;
    
    //write condition here to check if person is eligible
    if (( iEligibleAgeCheck < iEligibleFirstAge ) || ( iEligibleAgeCheck > iEligibleSecondAge ))
    {
        printf("[06] You are eligible\n");
    }
    else
    {
        printf("[06] Sorry, you are NOT eligible\n");
    }

    
//    Uppgift 8;
//    Hitta största talet av tre olika med en nested if
    
    int iValueA = 54;
    int iValueB = 77;
    int iValueC = 23;
    
    //write nested if statements to print maximum of 3 numbers
    if (iValueA > iValueB)
    {
        if (iValueA > iValueC)
        {
            printf("[08] iValueA (%d) is largest\n", iValueA);
        }
        else
        {
            printf("[08] iValueC (%d) is largest\n", iValueC);
        }
    }
    else
    {
        if (iValueB > iValueC)
        {
            printf("[08] iValueB (%d) is largest\n", iValueB);
        }
        else
        {
            printf("[08] iValueC (%d) is largest\n", iValueC);
        }
    }

    
//    Uppgift 9;
//    Ta emot en siffra och printa dess ordform, ex 8=eight;
    
    int  iDigitToWord            = 10;
    char arrayTextNumber[11][10] = {"Zero",
                                    "One",
                                    "Two",
                                    "Three",
                                    "Four",
                                    "Five",
                                    "Six",
                                    "Seven",
                                    "Eight",
                                    "Nine",
                                    "Ten" };
    
    //display digit to word using else if ladder
    // Using SWITCH case :-)
    switch (iDigitToWord)
    {
        case  0:
        case  1:
        case  2:
        case  3:
        case  4:
        case  5:
        case  6:
        case  7:
        case  8:
        case  9:
        case 10:
            printf("[09] Digit %d with letters is: %s\n\n", iDigitToWord, arrayTextNumber[iDigitToWord] );
            break;
        default:
            printf("[09] The number is not in the array\n\n");
            break;
    }
    
    
//    Uppgift 10;
//    Check for Prime numbers
    
    int  iCheckPrimeToNumber    = 20;   // Number to chech for all primes ...
    int  iCheckifNumberIsPrime  =  0;   // init
    int  iPrimeCounter          =  0;   // init
    bool bIsPrime               = true; // default: assume it's a prime
    
    //Write a for loop to count factors
    //check if number is prime

    for (int i = 0; i <= iCheckPrimeToNumber; i++)
    {
        iCheckifNumberIsPrime = i;
        
        if (iCheckifNumberIsPrime < 2)
        {
            printf("[10] %d is not a prime number\n", iCheckifNumberIsPrime);
        }
        else
        {
            for (int j = 2; j <= (iCheckifNumberIsPrime / 2); j++)
            {
                if (iCheckifNumberIsPrime % j == 0) {
                    bIsPrime = false;
                    break;
                }
            }
            
            if (bIsPrime)
            {
                iPrimeCounter++;
                printf("[10] %d is a prime number\n", iCheckifNumberIsPrime);
            }
            else
            {
                printf("[10] %d is not a prime number\n", iCheckifNumberIsPrime);
            }
        }
        
        // reset
        bIsPrime = true;
    }
    printf("[10] Prime counter: %d\n", iPrimeCounter);
    
}

// Function :: Returns "Hearts", "Spades" etc
const char* get_suit2  (enum suit a_suit){
    const char *suit_strs[] = {"Hearts", "Spades", "Clubs", "Diamonds", "Unknown" };
    return suit_strs[a_suit];
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
//    function_four_playing_with_arrays();
    
    // Call :: function_five_possible_roads_a_frog_can_jump_to_rome ()
//    function_five_possible_roads_a_frog_can_jump_to_rome(50);
    
    // Call :: function_enumeration_example_one ()
//    function_enumeration_example_one ();
    
    // Call :: function_enumeration_example_two ()
//    function_enumeration_example_two ();
    
    // Call :: function_array_example_two_add_search ()
//    function_array_example_two_add_search ();
    
    // Call :: function_array_example_three_find_middle ()
//    function_array_example_three_find_middle ();
    
    // Call :: function_array_example_four_sum_all_elements ()
//    function_array_example_four_sum_all_elements ();
    
    // Call :: function_array_example_five_find_max_number ()
//    function_array_example_five_find_max_number ();
    
    // Call :: function_array_example_six_find_min_number ()
//    function_array_example_six_find_min_number ();
    
    // Call :: function_array_example_seven_count_pos_neg_number ()
//    function_array_example_seven_count_pos_neg_number ();
    
    // Call :: function_array_example_neight_nested_for_loops ()
//    function_array_example_neight_nested_for_loops ();
    
    // Call :: function_array_example_nine_make_array_add_div_avg ()
//    function_array_example_nine_make_array_add_div_avg ();
    
    // Call :: function_pointer_example_one_basic_declaration ()
//    function_pointer_example_one_basic_declaration ();
    
    // Call :: function_template_example_one_basic_declaration ()
//    function_template_example_one_basic_declaration ();
/**/
    // Call :: function_template_example_two_going_static ()
//    function_template_example_two_going_static ();
//    function_template_example_two_going_static ();
    
    // Call :: function_template_example_three_find_element_in_array ()
    function_template_example_three_find_element_in_array ();
    
    // Call :: function_class_example_one_basic_declaration ()
//    function_class_example_one_basic_declaration ();
    
    // Call :: function_class_example_two_public_private_declaration ()
//    function_class_example_two_public_private_declaration ();
/**/
    // Call :: function_ludwig_week_two_check_that_we_can ()
//    function_ludwig_week_two_check_that_we_can ();
    
    //Endnig with an extra new line
    std::cout << "\n";
    
    return 0;
}
