//
//  05_Functions_part_one_in_C.h
//  05_Functions_part_one_in_C
//
//  Created by Daniel Eftodi on 2021-09-14.
//

#ifndef Functions_part_one_in_C_h
#define Functions_part_one_in_C_h

#include <stdio.h>
#include <iostream>
#include <climits>          // CHAR_BIT
//#include <stdlib.h>         // rand
#include <unistd.h>         // system(clear);
#include <random>           // random
#include <limits>           // This is important!
#include <string>           // stoi
#include <sstream>          // stringstream

void function_one_size_of_datatype (void);

void function_two_argc_argv_main (int f_argc, char ** f_argv);

void function_three_exercise_five (void);

void function_three_exercise_five_main_menu (void);

void function_three_exercise_five_gameOne_guess_number (void);

void function_three_exercise_five (void);

void function_four_playing_with_arrays (void);

void function_five_possible_roads_a_frog_can_jump_to_rome (int iNumRequireSteps);

int main (int argc, char ** argv);

#endif /* Functions_part_one_in_C_h */
