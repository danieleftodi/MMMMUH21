//
//  common/common.h
//  11_Awesome_adventures
//
//  Created by Daniel Eftodi on 2021-10-12.
//

#ifndef common_h
#define common_h

#include <stdio.h>
#include <iostream>
#include <climits>        // CHAR_BIT
#include <stdlib.h>       // rand
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>       // system(clear);
                          // sleep($SECS);
#endif
#include <random>         // random
#include <limits>         // This is important!
#include <string>         // stoi
#include <sstream>        // stringstream

#include "common.h"                // common code
#include "../menus/main_menu.h"    // main menu code

////*/ function_enumeration_example_two
//enum suit {
//    hearts   = 1,
//    spades   = 2,
//    clubs    = 3,
//    diamonds = 4,
//} cards;
//
//// Definitions :: Returns "Hearts", "Spades" etc
//const char* get_suit  (enum suit a_suit);
//const char* get_suit2 (enum suit a_suit);
//
////*/
//
//void function_one_size_of_datatype (void);
//
//void function_two_argc_argv_main (int f_argc, char ** f_argv);
//

//
//void function_three_exercise_five (void);
//
//void function_four_playing_with_arrays (void);
//
//void function_five_possible_roads_a_frog_can_jump_to_rome (int iNumRequireSteps);
//
//void function_enumeration_example_one (void);
//
//void function_enumeration_example_two (void);

#endif /* common_h */
