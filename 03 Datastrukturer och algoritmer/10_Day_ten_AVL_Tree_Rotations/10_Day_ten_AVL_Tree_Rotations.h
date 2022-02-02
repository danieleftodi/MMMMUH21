//
//  10_Day_ten_AVL_Tree_Rotations.h
//  10_Day_ten_AVL_Tree_Rotations
//
//  Created by Daniel Eftodi on 2021-01-20.
//

#ifndef Day_ten_AVL_Tree_Rotations_h
#define Day_ten_AVL_Tree_Rotations_h

/* INCLUDES */

/* C Include Headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>         // system(clear);
#include <termios.h>        // include for c_getche()

/* Cpp Include Headers */
#include <iostream>         // include I/O
#include <iomanip>          // include manipulating the I/O
#include <string>           // include working with strings
#include <vector>           // include dynamic array functionalities
#include <iomanip>          // include to manipulate std::cout outputs

/* DEFINITIONS */

// ENABLE-DISABLE debug logging
#define DEBUG_LOGGING true

/* DECLARATIONS */


// a common Debug logging function
void DBG_LOG(std::string sText,
          std::string sVarA,
          std::string sVarB = "",
          std::string sVarC = "",
          std::string sVarD = "",
          std::string sVarE = "",
          std::string sVarF = "",
          std::string sVarG = "",
          std::string sVarH = "",
          std::string sVarI = "",
          std::string sVarJ = "",
          std::string sVarK = "",
          std::string sVarL = "",
          std::string sVarM = ""
          );
    
/* From our common_lib - BEGIN */
void clearScreen(void)
    {
#ifdef __WIN32__
        system("cls");
#else
        system("clear");
#endif
    }
    
void delay(int iDelayTime)
    {
#ifdef __WIN32__
        Sleep(iDelayTime);
#else
        sleep(iDelayTime);
#endif
    }

/* Read 1 character without echo */
int c_getch(void);

/* Read 1 character with echo */
int c_getche(void);

/* From our common_lib - END */

/* FUNCTIONS */

int main(int argc, char ** argv);

#endif /* Day_ten_AVL_Tree_Rotations_h */
