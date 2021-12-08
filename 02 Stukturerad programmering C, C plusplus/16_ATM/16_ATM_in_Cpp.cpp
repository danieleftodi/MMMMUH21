//
//  16_ATM_in_Cpp.cpp
//  16_ATM_in_Cpp
//
//  Created by Daniel Eftodi on 2021-11-13.
//

#include "16_ATM_in_Cpp.h"

/* INIT - BEGIN */
int main(int argc, char ** argv){
    
    // init ATM - with some default User Accounts
    tATM tFirstATM =
    {
        .vATMAccounts =
        {
            {
                .uliAccountID = 198104011122,
                .sFirstName = "Root",
                .sLastName = "Admin",
                .sUsername = "root",
                .sPassword = "root",
                .dAccountBalance = 10000,
                .eLastOperation = tATM::NEW_ACCOUNT_SUCCESSFULL
            },
            {
                .uliAccountID = 198107222233,
                .sFirstName = "Daniel",
                .sLastName = "Eftodi",
                .sUsername = "deft",
                .sPassword = "test",
                .dAccountBalance = 0,
                .eLastOperation = tATM::NEW_ACCOUNT_SUCCESSFULL
            },
            {
                .uliAccountID = 199502113344,
                .sFirstName = "Felicia",
                .sLastName = "Bornudd",
                .sUsername = "fbor",
                .sPassword = "test",
                .dAccountBalance = 0,
                .eLastOperation = tATM::NEW_ACCOUNT_SUCCESSFULL
            },
            {
                .uliAccountID = 199704015566,
                .sFirstName = "Ludwig",
                .sLastName = "Simonsson",
                .sUsername = "lsim",
                .sPassword = "test",
                .dAccountBalance = 10000,
                .eLastOperation = tATM::NEW_ACCOUNT_SUCCESSFULL
            },
        }
    };
    
    // RTFM       :: https://iq.opengenus.org/ways-to-remove-elements-from-vector-cpp/
    // DEBUG_CODE :: Remove the third (2) element with the vector-struct-array
    // PURPOSE    :: To test and see that we can delete from our vector-struct-array
//    tFirstATM.vATMAccounts.erase(tFirstATM.vATMAccounts.begin() + 2);

    // Start ATM
    tFirstATM.AccountMenu();
    
    //Endnig with an extra new line
    std::cout << "\n";
    
    return 0;
}
/* INIT - END */

/* IMPLEMENTATION OF ALL FUNCTIONS - BEGIN */
void tATM::AccountMenu(void)
{
    char cUserInput              = '\0';
    bool bMainMenuValidSelection = false;
    
    do
    {
        clearScreen();
        std::cout << "############################################\n";
        std::cout << "## Auto Teller Machine                    ##\n";
        std::cout << "##                                        ##\n";
        if (loggedInAccountLocation > -1)
        {
            std::cout << "## Main Menu  ::  " << std::left << std::setfill(' ') << std::setw(23) << vATMAccounts[loggedInAccountLocation].sFullname.c_str() << " ##\n";
        }
        else
        {
            std::cout << "## Main Menu                              ##\n";
        }
        
        std::cout << "############################################\n";
        std::cout << "\n";
        if (loggedInAccountLocation > -1)
        {
            std::cout << "  (D) - Deposite money\n";
            std::cout << "  (W) - Withdraw money\n";
            std::cout << "  (V) - View balance\n";
            std::cout << "  (O) - Log out\n";
        }
        else
        {
            std::cout << "  (L) - Login\n";
            std::cout << "  (C) - Create new account\n";
        }
        std::cout << "  (Q) - Quit\n";
        std::cout << "\n";
        std::cout << "  Press a key: ";
u        std::cin >> cUserInput;
        
        switch (cUserInput) {
            case 'l':
            case 'L':
                DBG_LOG("LOG_DBG: ",  std::to_string(cUserInput));
                if (loggedInAccountLocation < 0)
                {
                    // Track Last Operation
                    eATMLastOperation = LOGIN;
                    
                    // temp login struct
                    tATM::tLoginDefaults tLoginTemp;

                    // ask for inputs
                    printf("\n  Enter Username: ");
                    std::cin >> tLoginTemp.sUsername;
                    printf("  Enter Password: ");
                    std::cin >> tLoginTemp.sPassword;
                    
                    // try to login --> eATMLastOperation
                    AccountLogin(tLoginTemp.sUsername, tLoginTemp.sPassword);
                    
                    // Let users know if they logged in
                    if (eATMLastOperation == LOGIN_SUCCESSFULL) {
                        printf("  Login succesfull\n");
                    }
                    else
                    {
                        printf("  Login failed, try again ...\n");
                    }
                    
                    // Human UI/UX ...
                    delay(3);
                }
                else
                {
                    printf("  Operation is not allow, You are already logged in\n");
                    
                    // Human UI/UX ...
                    delay(3);
                }
                break;
            case 'd':
            case 'D':
                DBG_LOG("LOG_DBG: ",  std::to_string(cUserInput));
                if (loggedInAccountLocation > -1)
                {
                    // Track Last Operation
                    SetLastOperation(vATMAccounts[loggedInAccountLocation].uliAccountID, DEPOSIT);
                    
                    // temp accounting struct
                    tATM::tAccountingDefaults tAccountingTemp;
                    
                    // ask for --> dDepositAmount
                    printf("\n  How much would you like to deposit: ");
                    std::cin >> tAccountingTemp.dDepositAmount;
                    
                    // try to login --> eATMLastOperation
                    DepositMoney(tAccountingTemp.dDepositAmount);
                    
                    // Let users know if they logged in
                    if (eATMLastOperation == DEPOSIT_SUCCESSFULL) {
                        DBG_LOG("tATM::DepositMoney :: ", "Deposit succesfull");
                    }
                    else
                    {
                        printf("  Deposit failed, try again ...\n");
                    }
                    
                    // Human UI/UX ...
                    delay(3);
                }
                else
                {
                    printf("  Operation is not allow, 1st login\n");
                    
                    // Human UI/UX ...
                    delay(3);
                }
                break;
            case 'w':
            case 'W':
                DBG_LOG("LOG_DBG: ",  std::to_string(cUserInput));
                if (loggedInAccountLocation > -1)
                {
                    // Track Last Operation
                    SetLastOperation(vATMAccounts[loggedInAccountLocation].uliAccountID,
                                     WITHDRAWAL);
                    
                    // temp accounting struct
                    tATM::tAccountingDefaults tAccountingTemp;
                    
                    // ask for --> dDepositAmount
                    printf("\n  How much would you like to withdraw: ");
                    std::cin >> tAccountingTemp.dWithdrawalAmount;
                    
                    // try to login --> eATMLastOperation
                    WithdrawMoney(tAccountingTemp.dWithdrawalAmount);
                    
                    // Let users know if they logged in
                    if (eATMLastOperation == WITHDRAWAL_SUCCESSFULL) {
                        DBG_LOG("tATM::DepositMoney :: ", "Withdrawal succesfull");
                    }
                    else
                    {
                        printf("  Withdrawal failed, try again ...\n");
                    }
                    
                    // Human UI/UX ...
                    delay(3);
                }
                else
                {
                    printf("  Operation is not allow, 1st login\n");
                    
                    // Human UI/UX ...
                    delay(3);
                }
                break;
            case 'v':
            case 'V':
                DBG_LOG("LOG_DBG: ",  std::to_string(cUserInput));
                if (loggedInAccountLocation > -1)
                {
                    // Track Last Operation
                    SetLastOperation(vATMAccounts[loggedInAccountLocation].uliAccountID,
                                     GET_BALANCE);
                                                   
                    // temp accounting struct
                    tATM::tAccountingDefaults tAccountingTemp;
                    
                    // try to GetAccountBalance
                    tAccountingTemp.dAccountBalance = GetAccountBalance(vATMAccounts[loggedInAccountLocation].uliAccountID);
                    
                    if ( (int) tAccountingTemp.dAccountBalance != -12341337)
                    {
                        // Human UI/UX ...
                        printf("\n  Account Balance : %d\n", (int) tAccountingTemp.dAccountBalance);
                        
                        // Track Last Operation
                        SetLastOperation(vATMAccounts[loggedInAccountLocation].uliAccountID,
                                         GET_BALANCE_SUCCESSFULL);
                    }
                    else
                    {
                        // Track Last Operation
                        SetLastOperation(vATMAccounts[loggedInAccountLocation].uliAccountID,
                                         GET_BALANCE_FAILED);
                    }
                    
                    // Let users know if they logged in
                    if (eATMLastOperation == GET_BALANCE_SUCCESSFULL) {
                        DBG_LOG("tATM::GetAccountBalance :: ", std::to_string(tAccountingTemp.dAccountBalance));
                    }
                    else
                    {
                        printf("  View balance failed, try again ...\n");
                    }
                    
                    // Human UI/UX ...
                    delay(3);
                }
                else
                {
                    printf("  Operation is not allow, 1st login\n");
                    
                    // Human UI/UX ...
                    delay(3);
                }
                break;
            case 'c':
            case 'C':
                DBG_LOG("LOG_DBG: ",  std::to_string(cUserInput));
                if (loggedInAccountLocation < 0)
                {
                    // Track Last Operation
                    eATMLastOperation = CREATE;
                    
                    // temp NewUser struct
                    tATM::tLoginDefaults tNewUserTemp;
                    
                    // ask for inputs
                    printf("\n  Enter Username: ");
                    std::cin >> tNewUserTemp.sUsername;
                    printf("  Enter Password: ");
                    std::cin >> tNewUserTemp.sPassword;
                    
                    // try to CreateNewAccount --> eATMLastOperation
                    CreateNewAccount(tNewUserTemp.sUsername, tNewUserTemp.sPassword);
                    
                    // Let users know if they logged in
                    if (eATMLastOperation == CREATE_SUCCESSFULL) {
                        printf("  Create new user succesfull\n");
                    }
                    else
                    {
                        printf("  Create new user failed, try again ...\n");
                    }
                    
                    // Human UI/UX ...
                    delay(3);
                }
                else
                {
                    printf("  Operation is not allow, You are already logged in\n");
                    
                    // Human UI/UX ...
                    delay(3);
                }
                break;
            case 'o':
            case 'O':
                DBG_LOG("LOG_DBG: ",  std::to_string(cUserInput));
                if (loggedInAccountLocation > -1)
                {
                    // Track Last Operation
                    SetLastOperation(vATMAccounts[loggedInAccountLocation].uliAccountID, LOGOUT);
                    
                    // Log out the user
                    AccountLogOut();
                    
                    // Human UI/UX ...
                    delay(1);
                }
                else
                {
                    printf("  Operation is not allow, 1st login\n");
                    
                    // Human UI/UX ...
                    delay(3);
                }
                break;
            case 'q':
            case 'Q':
                DBG_LOG("LOG_DBG: ",  std::to_string(cUserInput));
                bMainMenuValidSelection = true;
                break;
            default:
                printf("\nWrong input, not a menu option: %c\n\nPlease try again\n", cUserInput);
                
                // Human UI/UX ...
                delay(3);
                break;
        }
    } while (!bMainMenuValidSelection);
}


void tATM::AccountLogin(std::string sLoginUsername, std::string sLoginPassword)
{
    DBG_LOG( "tATM::AccountLogin :: IN  :: ", sLoginUsername, ":", sLoginPassword);
    
    /* FOR-LOOP - BEGIN */
    for (int i = 0; i < vATMAccounts.size(); i++)
    {
        
        DBG_LOG("tATM::AccountLogin :: ","[", std::to_string(i),"] ",
                vATMAccounts[i].sUsername, ":",
                vATMAccounts[i].sPassword);
        
        if ((vATMAccounts[i].sUsername == sLoginUsername) &&
            (vATMAccounts[i].sPassword == sLoginPassword))
        {
            // Set i --> loggedInAccountLocation
            loggedInAccountLocation = i;

            // Track Last Operation
            SetLastOperation(vATMAccounts[i].uliAccountID, LOGIN_SUCCESSFULL);
            
            DBG_LOG("tATM::AccountLogin :: ", eOperation_str[eATMLastOperation]);
            
            // when match is found, break the for-loop
            break;
        }
        else
        {
            DBG_LOG("tATM::AccountLogin :: ","credentials don't match");
            // Track Last Operation
            eATMLastOperation = LOGIN_FAILED;
        }
    }
    /* FOR-LOOP - END */

    DBG_LOG("tATM::AccountLogin :: OUT  :: ", eOperation_str[eATMLastOperation]);
}

void tATM::AccountLogOut(void)
{
    SetLastOperation(vATMAccounts[loggedInAccountLocation].uliAccountID, LOGOUT_SUCCESSFULL);
    loggedInAccountLocation = -1;
}

void tATM::DepositMoney(double dDepositAmount)
{
    DBG_LOG( "tATM::DepositMoney :: IN  :: ", std::to_string( (int) dDepositAmount) );
    
    // Update dAccountBalance --> dBeginningBalance
    vATMAccounts[loggedInAccountLocation].dBeginningBalance = vATMAccounts[loggedInAccountLocation].dAccountBalance;
    
    // Add dDepositAmount --> dAccountBalance
    vATMAccounts[loggedInAccountLocation].dAccountBalance += dDepositAmount;
    
    // Set dLastMoneyMovement = dDepositAmount
    vATMAccounts[loggedInAccountLocation].dLastMoneyMovement = dDepositAmount;

    // Human UI/UX ...
    printf("  Opening Balance  : %d\n", (int) vATMAccounts[loggedInAccountLocation].dBeginningBalance);
    printf("  Deposited Amount : %d\n", (int) dDepositAmount);
    printf("  Ending Balance   : %d\n", (int) vATMAccounts[loggedInAccountLocation].dAccountBalance);
    
    // Track Last Operation
    SetLastOperation(vATMAccounts[loggedInAccountLocation].uliAccountID, DEPOSIT_SUCCESSFULL);
    
    DBG_LOG("tATM::DepositMoney :: OUT  :: ", eOperation_str[eATMLastOperation]);
}

void tATM::WithdrawMoney(double dWithdrawalAmount)
{
    DBG_LOG( "tATM::WithdrawMoney :: IN  :: ", std::to_string( (int) -dWithdrawalAmount) );
    
    // Update dAccountBalance --> dBeginningBalance
    vATMAccounts[loggedInAccountLocation].dBeginningBalance = vATMAccounts[loggedInAccountLocation].dAccountBalance;
    
    // Check if User has deposited clearance on the account, before doing a withdrawal
    if ( vATMAccounts[loggedInAccountLocation].dAccountBalance >= dWithdrawalAmount)
    {
        // Remove -dWithdrawalAmount --> dAccountBalance
        vATMAccounts[loggedInAccountLocation].dAccountBalance -= dWithdrawalAmount;
        
        // Set dLastMoneyMovement = -dWithdrawalAmount
        vATMAccounts[loggedInAccountLocation].dLastMoneyMovement = -dWithdrawalAmount;
        
        // Human UI/UX ...
        printf("  Opening Balance  : %d\n", (int) vATMAccounts[loggedInAccountLocation].dBeginningBalance);
        printf("  Deposited Amount : %d\n", (int) -dWithdrawalAmount);
        printf("  Ending Balance   : %d\n", (int) vATMAccounts[loggedInAccountLocation].dAccountBalance);
        
        // Track Last Operation
        SetLastOperation(vATMAccounts[loggedInAccountLocation].uliAccountID,
                         WITHDRAWAL_SUCCESSFULL);
    }
    else
    {
        // Human UI/UX ...
        printf("\n  You don't have   : %d\n", (int) dWithdrawalAmount);
        printf("  disposable on your account\n\n");
        printf("  Maximum withdraw : %d\n", (int) vATMAccounts[loggedInAccountLocation].dAccountBalance);
               
        // Track Last Operation
        SetLastOperation(vATMAccounts[loggedInAccountLocation].uliAccountID,
                         WITHDRAWAL_FAILED);
    }
    
    DBG_LOG("tATM::WithdrawMoney :: OUT  :: ", eOperation_str[eATMLastOperation]);
}

unsigned long int tATM::GetLoggedInUserAccountID(void) const
{
    return vATMAccounts[loggedInAccountLocation].uliAccountID;
}

double tATM::GetAccountBalance(unsigned long int uliAccountID) const
{
    DBG_LOG("tATM::GetAccountBalance :: IN   ::  accoundID: ", std::to_string(uliAccountID) );
    
    /* FOR-LOOP - BEGIN */
    for (int i = 0; i < vATMAccounts.size(); i++)
    {
        
        DBG_LOG("tATM::GetAccountBalance :: ","[", std::to_string(i),"]  ::  accoundID: ",
                std::to_string(vATMAccounts[i].uliAccountID));
        
        if (vATMAccounts[i].uliAccountID == uliAccountID)
        {
            DBG_LOG("tATM::GetAccountBalance :: ","[", std::to_string(i),"]  ::  Account Match");
            // when match is found, break the for-loop
            return (double) vATMAccounts[i].dAccountBalance;
        }
        else
        {
            DBG_LOG("tATM::GetAccountBalance :: ","[", std::to_string(i),"]  ::  No Match: iAccountID != iAlccountID");
        }
    }
    /* FOR-LOOP - END */
    
    DBG_LOG("tATM::GetAccountBalance :: OUT  :: ", eOperation_str[GET_BALANCE_FAILED]);
    return (int) -12341337;
}

void tATM::CreateNewAccount(std::string sNewUsername, std::string sNewPassword)
{
    DBG_LOG( "tATM::CreateNewAccount :: IN  ::  ", sNewUsername.c_str(), ":", sNewPassword.c_str());
    
    // NewUser struct
    tATM::tAccountDefaults tNewUser =
    {
        .sUsername      = sNewUsername,
        .sPassword      = sNewPassword,
        .eLastOperation = NEW_ACCOUNT_SUCCESSFULL
    };
    
    // Ask for Users name
    printf("  What is your name: ");
    std::cin >> tNewUser.sFirstName;

    // Append new user to the vATMAccounts vector
    vATMAccounts.push_back(tNewUser);
    
    // Track Last Operation
    eATMLastOperation = CREATE_SUCCESSFULL;
    
    DBG_LOG("\ntATM::CreateNewAccount :: OUT  :: ", eOperation_str[eATMLastOperation]);
}

void tATM::SetLastOperation(unsigned long int uliAccountID, eOperation eLastOperation)
{
    /* FOR-LOOP - BEGIN */
    for (int i = 0; i < vATMAccounts.size(); i++)
    {
        DBG_LOG("tATM::SetLastOperation :: ","[", std::to_string(i),"]  ::  accoundID: ",
                std::to_string(vATMAccounts[i].uliAccountID));
        
        if (vATMAccounts[i].uliAccountID == uliAccountID)
        {
            // Track Last Operation
            eATMLastOperation = eLastOperation;
            vATMAccounts[i].eLastOperation = eATMLastOperation;
            
            // when match is found, break the for-loop
            break;
        }
        else
        {
            DBG_LOG("tATM::SetLastOperation :: ","[", std::to_string(i),"]  ::  No Match: uliAccountID != uliAccountID");
        }
    }
    /* FOR-LOOP - END */
}

void tATM::DBG_LOG(std::string sText,
                   std::string sVarA,
                   std::string sVarB,
                   std::string sVarC,
                   std::string sVarD,
                   std::string sVarE,
                   std::string sVarF) const
{
#if DEBUG_LOGGING
    printf("%s%s%s%s%s%s%s\n",
           sText.c_str(),
           sVarA.c_str(),
           sVarB.c_str(),
           sVarC.c_str(),
           sVarD.c_str(),
           sVarE.c_str(),
           sVarF.c_str());
#endif
}

/* Read 1 character with echo */
int tATM::c_getche(void)
{
    struct termios old, char_new;
    int ch;
    
    tcgetattr(0, &old);
    
    char_new = old;
    char_new.c_lflag &= ~ICANON;
    //new.c_lflag &= ~ECHO;
    tcsetattr(0, TCSANOW, &char_new);
    
    ch = getchar();
    
    tcsetattr(0, TCSANOW, &old);
    return ch;
}

/* IMPLEMENTATION OF ALL FUNCTIONS - END */
