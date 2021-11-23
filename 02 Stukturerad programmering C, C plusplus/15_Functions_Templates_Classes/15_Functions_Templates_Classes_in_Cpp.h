//
//  15_Functions_Templates_in_Cpp.h
//  15_Functions_Templates_in_Cpp
//
//  Created by Daniel Eftodi on 2021-10-12.
//

#ifndef Functions_Templates_Classes_in_Cpp_h
#define Functions_Templates_Classes_in_Cpp_h

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

void function_array_example_two_add_search (void);

void function_array_example_three_find_middle (void);

void function_array_example_four_sum_all_elements (void);

void function_array_example_five_find_max_number (void);

void function_array_example_six_find_min_number (void);

void function_array_example_seven_count_pos_neg_number (void);

void function_array_example_neight_nested_for_loops (void);

void function_array_example_nine_make_array_add_div_avg (void);

void function_pointer_example_one_basic_declaration (void);

void function_pointer_example_two_ (void);

void function_chars_and_strings_example_one_basic_stuff (void);

template <class ftWhichIsMax>
ftWhichIsMax ftWhichIsMax (ftWhichIsMax a, ftWhichIsMax b);

void function_template_example_one_basic_declaration (void);

void function_template_example_two_going_static (void);

int function_template_example_three_find_element_in_array_loop (int compA, int compB[], int compBSize = 0);

void function_template_example_three_find_element_in_array (void);

void function_class_example_one_basic_declaration (void);

void function_class_example_two_public_private_declaration (void);

void function_ludwig_week_two_check_that_we_can (void);

void function_max_values_for_data_types (void);

int main (int argc, char ** argv);

#endif /* Functions_Templates_Classes_in_Cpp_h */
