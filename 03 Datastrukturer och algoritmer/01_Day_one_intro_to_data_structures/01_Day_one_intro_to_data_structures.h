//
//  16_ATM_in_Cpp.h
//  16_ATM_in_Cpp
//
//  Created by Daniel Eftodi on 2021-11-13.
//

#ifndef Day_one_intro_to_data_structures_h
#define Day_one_intro_to_data_structures_h

/* INCLUDES */

#include <stdio.h>
#include <iostream>         // include I/O
#include <iomanip>          // include manipulating the I/O
#include <string>           // include working with strings
#include <vector>           // include dynamic array functionalities
#include <unistd.h>         // system(clear);
#include <iomanip>          // include to manipulate std::cout outputs
#include <termios.h>        // include for c_getche()

/* DEFINITIONS */

// ENABLE-DISABLE debug logging
#define DEBUG_LOGGING false

/* DECLARATIONS */


// a common Debug logging function
void DBG_LOG(std::string sText,
             std::string sVarA,
             std::string sVarB = "",
             std::string sVarC = "",
             std::string sVarD = "",
             std::string sVarE = "",
             std::string sVarF = "");
    
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
    
int c_getche(void);
/* From our common_lib - END */

/* FUNCTIONS */

int main(int argc, char ** argv);

#endif /* Day_one_intro_to_data_structures_h */
