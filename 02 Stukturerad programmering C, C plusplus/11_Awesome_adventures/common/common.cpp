//
//  common/common.cpp
//  11_Awesome_adventures
//
//  Created by Daniel Eftodi on 2021-10-12.
//

#include "common.h"


//void function_one_size_of_datatype () {
//    unsigned int usDataSize = 128;
//
//    printf("Data size of usDataSize (%d) is: %lu bytes\n", usDataSize, sizeof(usDataSize) );
//
//    printf("Data size of usDataSize (%d) is: %lu bits\n", usDataSize, sizeof(usDataSize) * 8 );
//
//    printf("Data size of usDataSize (%d) is: %lu bits\n\n", usDataSize, sizeof(usDataSize) * CHAR_BIT );
//}
//
//void function_two_argc_argv_main (int f_argc, char ** f_argv) {
//
//    printf("There are %d number of arguments (f_argc)\n", f_argc - 1);
//
//    char cf_argv;
//    std::string sf_argv;
//
//    for (int i = 1; i < f_argc; i++) {
//
//        // Felmeddelande:
////        cf_argv = f_argv[i];
//        // Lösninagr:
//        cf_argv = *f_argv[i];
////        cf_argv = f_argv[i][0];
//
//        switch ( cf_argv ) {
//            case '-':
//                printf("Input is: %s\n", f_argv[i]);
//                break;
//            case 'i':
//                printf("f_argv[%d]: %s\n", i, f_argv[i+1]);
//                break;
//            case 'e':
//                printf("f_argv[%d]: %s\n", i, f_argv[i+1]);
//                break;
//            case 'c':
//                printf("f_argv[%d]: %s\n", i, f_argv[i+1]);
//                break;
//            case 'h':
//                printf("f_argv[%d]: %s\n", i, f_argv[i+1]);
//                break;
//            default:
////                printf("f_argv[%d]: %s\n", i, f_argv[i]);
//                break;
//        }
//
////        printf("f_argv[%d]: %s\n", i, f_argv[i]);
//
//        // reset cf_argv to NULL
//        cf_argv = NULL;
//    }
//
//}
//
//

//
//void function_four_playing_with_arrays (void) {
//    /*
//       There are four ways to implement an array
//       RTFM: https://www.geeksforgeeks.org/array-strings-c-3-different-ways-create/
//     */
//
//    // clear the screen
//    system("clear");
//
//    // Way one :: Using the string class
//    std::string words_one[2];   // let's just make an empty array of two
//    words_one[0] = "Hello";     // add first word to array
//    words_one[1] = "World";     // add second word to array
//
//    printf("First word is: %s\nSecond word is: %s\n", words_one[0].c_str(), words_one[1].c_str());
//    printf("Size of the arary is: %lu\n", ( sizeof(words_one) / sizeof(std::string) ) );
//    printf("Size of first word is: %lu\n", words_one[0].size());
//    printf("Size of second word is: %lu\n\n", words_one[1].size());
//
//    // Way one :: Using the string class - at defenition
//    std::string wordz_one[2] = { "World",
//                             "Hello" };
//
//    printf("First word is: %s\nSecond word is: %s\n", wordz_one[0].c_str(), wordz_one[1].c_str());
//    printf("Size of first word is: %lu\n", wordz_one[0].size());
//    printf("Size of second word is: %lu\n\n", wordz_one[1].size());
//
//
//    // Way two :: Using 2D array
//    char words_two[2][10] = { "Zombie",
//                             "World" };
//
//    printf("First word is: %s\nSecond word is: %s\n\n", words_two[0], words_two[1]);
//
//    //ERRORs *hmm*
////    printf("Size of the arary is: %lu\n", words_two.size());
////    printf("Size of first word is: %d\n", words_two[0].size());
////    printf("Size of second word is: %d\n\n", words_two[1].size());
//
//    // Way two :: Using 2D array - Why does it fail to build?
////    char words_three[3][19] = { "Zombie",
////                             "World",
////                             "Way to many letters" };
////
////    printf("First word is: %s\nSecond word is: %s\nThird word is: %s\n\n", words_three[0], words_three[1], words_three[2]);
//
//
//    // Way three :: Using the vector class
//#include <vector>
//    std::vector<std::string> words_three;
////    = { "Zoro", "Rulez" };
//
//    words_three.push_back("Zoro");
//    words_three.push_back("Rulez");
//
//    printf("First word is: %s\nSecond word is: %s\n", words_three[0].c_str(), words_three[1].c_str());
//    printf("Size of the arary is: %lu\n", words_three.size());
//    printf("Size of first word is: %lu\n", words_three[0].size());
//    printf("Size of second word is: %lu\n", words_three[1].size());
//}
//
//void function_five_possible_roads_a_frog_can_jump_to_rome (int iNumRequireSteps) {
//    /*
//    Uppgift:    En groda kan hoppa 1 steg eller 2 steg åt gången.
//
//                Man vill veta på hur många olika sätt som grodan
//                kan hoppa fram för att nå 50 steg bort.
//
//    Assignment: A frog can either jump 1 or 2 steps at a time.
//
//                How many different ways can the frog jump, in 50 steps?
//
//                Think: What are all of the possible "Roads to Rome" the
//                       frog can jump in 50 steps.
//     */
//
//    // clear screen
//    system("clear");
//
//    printf("Lets figure out all of the possbile permutations a frog can jump 1 or 2 steps at a time, in %d steps.", iNumRequireSteps);
//}
//
//void function_enumeration_example_one (void) {
//
//}
//
//void function_enumeration_example_two (void) {
//
////    enum suit cards = diamonds;
//    int iWantToCheckFor = 3;
//    cards = clubs;
//    if (cards == iWantToCheckFor){
//        printf("Yes: it is 3\n");
//    } else {
//        printf("No: it is not 3\n");
//    }
//}
//
//// Function :: Returns "Hearts", "Spades" etc
//const char* get_suit2  (enum suit a_suit){
//    const char *suit_strs[] = {"Hearts", "Spades", "Clubs", "Diamonds", "Unknown" };
//    return suit_strs[a_suit];
//}

