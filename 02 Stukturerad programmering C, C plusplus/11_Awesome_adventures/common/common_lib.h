//
//  common/common_lib.h
//  MMMMUH21_COMMON_LIB

/*
 *  Every common header code that is shared in the classrom, goes here
 */

/*
Source: Daniel Eftodi on 2021-10-26.
Bulk coder: Daniel Eftodi on 2021-10-26.
Assister: 
Syfte: Win/Mac/Unix kompabilitet
C++ Concept som utforskas: 
*/

#ifndef common_lib_h
#define common_lib_h

#define DEBUG_LOGGING 0

#ifdef __WIN32__
    #include <Windows.h>
#else
    #include <unistd.h>   // system(clear);
                          // sleep($SECS);
#endif

#include <climits>        // CHAR_BIT
#include <stdlib.h>       // rand
#include <stdio.h>

#include <random>         // random
#include <limits>         // This is important!
#include <string>         // stoi
#include <sstream>        // stringstream

#include <iostream>       // cout / cin
#include <string.h>       // C version
#include <string>         // C++ version
#include <vector>


/*
 Source: Daniel Eftodi on 2021-10-26.
 Bulk coder: Daniel Eftodi on 2021-10-26.
 Assister:
 Syfte: Win/Mac/Unix kompabilitet
 C++ Concept som utforskas:
 */
void clearScreen(void);

void pauseScreen(void);

void delay(int iDelayTime);

int c_getche(void);


/*
 Source: Daniel Eftodi
 Bulk coder:
 Assister:
 Syfte:
 C++ Concept som utforskas: Fokus på C.
 */
char *returnTextNumber(int num);


/*
 Source: Gustav Brolin
 Bulk coder:
 Assister:
 Syfte:
 C++ Concept som utforskas:
 */
int is_in_GBro_main(void);

bool is_in_GBro(std::vector<std::string> inp_vector, std::string inp_element);


/*
 Source: Alexander Jönsson
 Bulk coder:
 Assister:
 Syfte:
 C++ Concept som utforskas: Arrayer 1D,2D och 3D samt numberGenerator
 */
int main_AJon(void);

int numberGenerator_AJon(int randomNumRange);

void oneDArray_AJon(void);

void twoDArray_AJon(void);

void threeDArray_AJon(void);


/*
 Source: Kristian Timmermand
 Bulk coder:
 Assister:
 Syfte:
 C++ Concept som utforskas:
 */
//First direct version med catch all felhantering
std::string NumToText_KTim(int num);


/*
 Source: Melina Bertosa
 Bulk coder:
 Assister:
 Syfte:
 C++ Concept som utforskas:
 */
//A more generalized version
int NumToText_MBer_main(void);

std::string NumToText_MBer(int num);


/*
 Source: Erik Holm
 Bulk coder:
 Assister:
 Syfte: val-inläsning och Sanitising your inputs
 C++ Concept som utforskas:
 */

/* Why use this non-crossplatform way?
    ... of include the entire STD Lib C++?
    ... this works with GNU C++
    ... but not with Clang++ ...
*/
//#include <bits/stdc++.h>

int input_EHol_main(void);

int input_EHol(int lower_L, int upper_L);

std::string check_if_input_is_digit_EHol(std::string s);


/*
 Source: Rachid Benzhair
 Bulk coder:
 Assister:
 Syfte: användaren kan fylla i antal värden och presenterar det i en tabell kan tillämpas på olika sätt
 C++ Concept som utforskas:
 TODO: Undersök hur denna koden kan integreras (hitta ett generellare koncept än båda) med Alexander Jönsson:s kod
 */
int printmatrix_RBen_main(void);

// skriv ut 2D aaray som user mattar in
void printmatrix_RBen(int matrix[5][3]);


/*
 Source: Rachid Benzhair
 Bulk coder:
 Assister:
 Syfte:
 C++ Concept som utforskas: Array
 
 */
int omkrets_RBen_main(void);

bool omkrets_RBen(int omk[], int size, int serchitm);

#endif /* common_lib_h */
