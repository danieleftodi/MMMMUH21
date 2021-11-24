//
//  16_ATM_in_Cpp.h
//  16_ATM_in_Cpp
//
//  Created by Daniel Eftodi on 2021-11-13.
//

#ifndef Fstream_exercise_main_h
#define Fstream_exercise_main_h

/* INCLUDES */

#include <stdio.h>
#include <iostream>         //includes I/O
#include <iomanip>          //includes manipulating the I/O
#include <string>           //include working with strings
#include <vector>           //includes dynamic array functionalities
#include <unistd.h>         // system(clear);

/* DEFINITIONS */

// ENABLE-DISABLE debug logging
#define DEBUG_LOGGING true

/* DECLARATIONS */

struct tScreen
// to represent each customer who uses the ATM program
{
    /* STRUCT - DECLARATIONS */
    
    // Track what User is logged in. -1 >= NO_ONE ...
    int  loggedInAccountLocation = -1;
    
    // An enum for all the types of operations (currently) available in the ATM
    enum eOperation
    {
        MAIN_MENU,
        LOGIN,
        LOGIN_SUCCESSFULL,
        LOGIN_FAILED,
        LOGOUT,
        LOGOUT_SUCCESSFULL,
        LOGOUT_FAILED,
        CREATE,
        CREATE_SUCCESSFULL,
        CREATE_FAILED,
        NEW_ACCOUNT,
        NEW_ACCOUNT_SUCCESSFULL,
        NEW_ACCOUNT_FAILED
    } eLastOperation = MAIN_MENU;
    
    // used to convert eOperation operations (currently) available in the ATM --> STRING
    std::string eOperation_str[13] =
    {
        "MAIN_MENU",
        "LOGIN",
        "LOGIN_SUCCESSFULL",
        "LOGIN_FAILED",
        "LOGOUT",
        "LOGOUT_SUCCESSFULL",
        "LOGOUT_FAILED",
        "CREATE",
        "CREATE_SUCCESSFULL",
        "CREATE_FAILED",
        "NEW_ACCOUNT",
        "NEW_ACCOUNT_SUCCESSFULL",
        "NEW_ACCOUNT_FAILED"
    };
    
    // Defaults for Login screen
    struct tLoginDefaults
    {
        std::string           sFirstName = "Default";
        std::string           sLastName = "User";
        std::string           sUsername;
        std::string           sPassword;
    };
        
    // Defaults for a new User Account
    struct tAccountDefaults
    {
        // iAccountID = Swedish Social Security Number
        // In one 'long int' number: YYYYMMDDNNNN
        unsigned long int     uliAccountID;
        std::string           sFirstName = "Default";
        std::string           sLastName = "User";
        std::string           sFullName = sFirstName + " " + sLastName;
        std::string           sUsername;
        std::string           sPassword;
        enum tScreen::eOperation eLastOperation    = NEW_ACCOUNT;
    };
    
    // Create a vetor to store all of the User Accounts in the ATM
    std::vector <tAccountDefaults> vScreenAccounts;

    /* STRUCT - FUNCTIONS */
    
    // Representing the Screen Menu with user choices
    void ScreenMenu(void);
    
    // Used to login the user using account details
    void AccountLogin(std::string sLoginUsername, std::string sLoginPassword);
    
    // Used to log out the user
    void AccountLogOut(void);
    
    // Creates the user account
    void CreateNewAccount(std::string sNewUsername, std::string sNewPassword);
    
    // Sets the location for the account information in the vector --> iLoggedInUserAccountID
    void SetAccountLogin(int iSetAccountLocation);
    
    // Defines last action made by user
    void SetLastOperation(unsigned long int uliAccountID, eOperation eLastOperation);
    
    // Write to a .txt file
    bool WriteRecordToFile (std::string file_name, std::string field_one, std::string field_two, std::string field_three);
    
    // Read from a .txt file
    std::vector<std::string> ReadRecordFromFile (std::string file_name, std::string search_term);
    
    // a common Debug logging function
    void DBG_LOG(std::string sText,
                 std::string sVarA,
                 std::string sVarB = "",
                 std::string sVarC = "",
                 std::string sVarD = "",
                 std::string sVarE = "",
                 std::string sVarF = "") const;
    
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
    /* From our common_lib - END */
};

/* FUNCTIONS */

int main(int argc, char ** argv);

#endif /* Fstream_exercise_main_h */
