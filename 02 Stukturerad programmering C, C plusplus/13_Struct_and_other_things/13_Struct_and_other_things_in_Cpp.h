//
//  13_Struct_and_other_things_in_Cpp.h
//  13_Struct_and_other_things_in_Cpp
//
//  Created by Daniel Eftodi on 2021-10-12.
//

#ifndef Struct_and_other_things_in_Cpp_h
#define Struct_and_other_things_in_Cpp_h

#include <stdio.h>
#include <iostream>
#include <climits>          // CHAR_BIT
//#include <stdlib.h>         // rand
#include <unistd.h>         // system(clear);
#include <random>           // random
#include <limits>           // This is important!
#include <string>           // stoi
#include <sstream>          // stringstream

//*/ function_enumeration_example_two
enum suit {
    hearts   = 1,
    spades   = 2,
    clubs    = 3,
    diamonds = 4,
} cards;

// Definitions :: Returns "Hearts", "Spades" etc
const char* get_suit  (enum suit a_suit);
const char* get_suit2 (enum suit a_suit);

//*/

void function_one_size_of_datatype (void);

void function_two_argc_argv_main (int f_argc, char ** f_argv);

void function_three_exercise_five (void);

void function_three_exercise_five_main_menu (void);

void function_three_exercise_five_gameOne_guess_number (void);

void function_three_exercise_five (void);

void function_four_playing_with_arrays (void);

void function_five_possible_roads_a_frog_can_jump_to_rome (int iNumRequireSteps);

void function_enumeration_example_one (void);

void function_enumeration_example_two (void);

void Walk_Main(void);

int main (int argc, char ** argv);

#endif /* Struct_and_other_things_in_Cpp_h */
