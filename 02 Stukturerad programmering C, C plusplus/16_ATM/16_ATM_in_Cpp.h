//
//  16_ATM_in_Cpp.h
//  16_ATM_in_Cpp
//
//  Created by Daniel Eftodi on 2021-11-13.
//

#ifndef ATM_in_Cpp_h
#define ATM_in_Cpp_h

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

struct tATM
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
        DEPOSIT,
        DEPOSIT_SUCCESSFULL,
        DEPOSIT_FAILED,
        WITHDRAWAL,
        WITHDRAWAL_SUCCESSFULL,
        WITHDRAWAL_FAILED,
        GET_BALANCE,
        GET_BALANCE_SUCCESSFULL,
        GET_BALANCE_FAILED,
        LOGOUT,
        LOGOUT_SUCCESSFULL,
        LOGOUT_FAILED,
        CREATE,
        CREATE_SUCCESSFULL,
        CREATE_FAILED,
        NEW_ACCOUNT,
        NEW_ACCOUNT_SUCCESSFULL,
        NEW_ACCOUNT_FAILED
    } eATMLastOperation = MAIN_MENU;
    
    // used to convert eOperation operations (currently) available in the ATM --> STRING
    std::string eOperation_str[22] =
    {
        "MAIN_MENU",
        "LOGIN",
        "LOGIN_SUCCESSFULL",
        "LOGIN_FAILED",
        "DEPOSIT",
        "DEPOSIT_SUCCESSFULL",
        "DEPOSIT_FAILED",
        "WITHDRAWAL",
        "WITHDRAWAL_SUCCESSFULL",
        "WITHDRAWAL_FAILED",
        "GET_BALANCE",
        "GET_BALANCE_SUCCESSFULL",
        "GET_BALANCE_FAILED",
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
    
    // Default Accounting Defaults
    struct tAccountingDefaults
    {
        double                dAccountBalance       = 0;
        double                dDepositAmount        = 0;
        double                dBeginningBalance     = 0;
        double                dLastMoneyMovement    = 0;
        double                dWithdrawalAmount     = 0;
    };
    
    // Defaults for a new User Account
    struct tAccountDefaults
    {
        // iAccountID = Swedish Social Security Number
        // In one 'long int' number: YYYYMMDDNNNN
        unsigned long int     uliAccountID;
        std::string           sFirstName = "Default";
        std::string           sLastName = "User";
        std::string           sUsername;
        std::string           sPassword;
        
        double                dAccountBalance   = 0;
        double                dBeginningBalance = dAccountBalance;
        double                dLastMoneyMovement;
        enum tATM::eOperation eLastOperation    = NEW_ACCOUNT;
    };
    
    // Create a vetor to store all of the User Accounts in the ATM
    std::vector <tAccountDefaults> vATMAccounts;

    /* STRUCT - FUNCTIONS */
    
    // Representing the menu of user choices
    void AccountMenu(void);
    
    // Used to login the user using account details
    void AccountLogin(std::string sLoginUsername, std::string sLoginPassword);
    
    // Used to log out the user
    void AccountLogOut(void);
          
    // Func to deposit any amount of money to the account
    void DepositMoney(double dDepositAmount);
    
    // Func to withdraw any amount of money from the account
    void WithdrawMoney(double dWithdrawalAmount);
    
    // Creates the user account
    void CreateNewAccount(std::string sNewUsername, std::string sNewPassword);
    
    // Sets the location for the account information in the vector --> iLoggedInUserAccountID
    void SetAccountLogin(int iSetAccountLocation);

    // Sets what the last action was for that account (dep or withdr)
    void SetLastMoneyMovement(unsigned long int uliAccountID, double dAmount);

    // Func that ensures the users account starts as 0 as well as
    // that it updates when performing withdrawal or deposit
    void SetAccountBalance(unsigned long int uliAccountID, double dAmount);

    // Defines last action made by user
    void SetLastOperation(unsigned long int uliAccountID, eOperation eLastOperation);

    // Makes sure the account login is in the list
    unsigned long int GetLoggedInUserAccountID(void) const;

    // Gets the information on most recently performed transaction
    double GetLastMoneyMovement(unsigned long int uliAccountID) const;

    // Shows the users account balance
    double GetAccountBalance(unsigned long int uliAccountID) const;

    // Retrieves the balance before last performed action
    double GetBeginningBalance(unsigned long int uliAccountID) const;

    // Gets the last action, ex withdrawal or deposit
    char GetLastOperation(unsigned long int uliAccountID) const;

    // Gets the username of the logged in account
    std::string GetUsername(unsigned long int uliAccountID) const;
    
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

#endif /* ATM_in_Cpp_h */
