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
                .iAccountID = 0,
                .sName = "Root",
                .sUsername = "root",
                .sPassword = "root",
                .dAccountBalance = 10000,
                .eLastOperation = tATM::NEW_ACCOUNT_SUCCESSFULL
            },
            {
                .iAccountID = 1,
                .sName = "Daniel",
                .sUsername = "deft",
                .sPassword = "test",
                .dAccountBalance = 0,
                .eLastOperation = tATM::NEW_ACCOUNT_SUCCESSFULL
            },
            {
                .iAccountID = 2,
                .sName = "Felicia",
                .sUsername = "fbor",
                .sPassword = "test",
                .dAccountBalance = 0,
                .eLastOperation = tATM::NEW_ACCOUNT_SUCCESSFULL
            },
        }
    };
    
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
        if (iLoggedInATMAccountsID > -1)
        {
            printf("## Main Menu  ::  %s                    ##\n", vATMAccounts[iLoggedInATMAccountsID].sUsername.c_str());
        }
        else
        {
            std::cout << "## Main Menu                              ##\n";
        }
        
        std::cout << "############################################\n";
        std::cout << "\n";
        if (iLoggedInATMAccountsID > -1)
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
        std::cin >> cUserInput;
        
        switch (cUserInput) {
            case 'l':
            case 'L':
//                printf("LOG_DBG: %c\n", cUserInput);
                if (iLoggedInATMAccountsID < 0)
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
                break;
            case 'd':
            case 'D':
//                printf("LOG_DBG: %c\n", cUserInput);
                if (iLoggedInATMAccountsID > -1)
                {
                    // Track Last Operation
                    SetLastOperation(vATMAccounts[iLoggedInATMAccountsID].iAccountID, DEPOSIT);
                    
                    // temp accounting struct
                    tATM::tAccountingDefaults tAccountingTemp;
                    
                    // ask for --> dDepositAmount
                    printf("\n  How much would you like to deposit: ");
                    std::cin >> tAccountingTemp.dDepositAmount;
                    
                    // try to login --> eATMLastOperation
                    DepositMoney(tAccountingTemp.dDepositAmount);
                    
                    // Let users know if they logged in
                    if (eATMLastOperation == DEPOSIT_SUCCESSFULL) {
                        printf("  Deposit succesfull\n");
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
                    delay(3);
                }
                break;
            case 'w':
            case 'W':
//                printf("LOG_DBG: %c\n", cUserInput);
                if (iLoggedInATMAccountsID > -1)
                {
                    // Track Last Operation
                    SetLastOperation(vATMAccounts[iLoggedInATMAccountsID].iAccountID,
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
                        printf("  Withdrawal succesfull\n");
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
                    delay(3);
                }
                break;
            case 'v':
            case 'V':
//                printf("LOG_DBG: %c\n", cUserInput);
                if (iLoggedInATMAccountsID > -1)
                {
                    // Track Last Operation
                    SetLastOperation(vATMAccounts[iLoggedInATMAccountsID].iAccountID,
                                     GET_BALANCE);
                                                   
                    // temp accounting struct
                    tATM::tAccountingDefaults tAccountingTemp;
                    
                    // try to GetAccountBalance
                    tAccountingTemp.dAccountBalance = GetAccountBalance(vATMAccounts[iLoggedInATMAccountsID].iAccountID);
                    
                    if ( (int) tAccountingTemp.dAccountBalance != -12341337)
                    {
                        // Human UI/UX ...
                        printf("\n  Account Balance : %d\n", (int) tAccountingTemp.dAccountBalance);
                        
                        // Track Last Operation
                        SetLastOperation(vATMAccounts[iLoggedInATMAccountsID].iAccountID,
                                         GET_BALANCE_SUCCESSFULL);
                    }
                    else
                    {
                        // Track Last Operation
                        SetLastOperation(vATMAccounts[iLoggedInATMAccountsID].iAccountID,
                                         GET_BALANCE_FAILED);
                    }
                    
                    // Let users know if they logged in
                    if (eATMLastOperation == GET_BALANCE_SUCCESSFULL) {
                        printf("  View balance succesfull\n");
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
                    delay(3);
                }
                break;
            case 'c':
            case 'C':
//                printf("LOG_DBG: %c\n", cUserInput);
                if (iLoggedInATMAccountsID < 0)
                {
                    // Track Last Operation
                    eATMLastOperation = CREATE;
                    
                    CreateNewAccount("Test", "Test");
                    
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
//                printf("LOG_DBG: %c\n", cUserInput);
                if (iLoggedInATMAccountsID > -1)
                {
                    // Track Last Operation
                    SetLastOperation(vATMAccounts[iLoggedInATMAccountsID].iAccountID, LOGOUT);
                    
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
//                printf("LOG_DBG: %c\n", cUserInput);
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
            // Set iAccountID --> iLoggedInATMAccountsID
            iLoggedInATMAccountsID = vATMAccounts[i].iAccountID;

            // Track Last Operation
            SetLastOperation(vATMAccounts[i].iAccountID, LOGIN_SUCCESSFULL);
            
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
    SetLastOperation(vATMAccounts[iLoggedInATMAccountsID].iAccountID, LOGOUT_SUCCESSFULL);
    iLoggedInATMAccountsID = -1;
}

void tATM::DepositMoney(double dDepositAmount)
{
    DBG_LOG( "tATM::DepositMoney :: IN  :: ", std::to_string( (int) dDepositAmount) );
    
    // Update dAccountBalance --> dBeginningBalance
    vATMAccounts[iLoggedInATMAccountsID].dBeginningBalance = vATMAccounts[iLoggedInATMAccountsID].dAccountBalance;
    
    // Add dDepositAmount --> dAccountBalance
    vATMAccounts[iLoggedInATMAccountsID].dAccountBalance += dDepositAmount;
    
    // Set dLastMoneyMovement = dDepositAmount
    vATMAccounts[iLoggedInATMAccountsID].dLastMoneyMovement = dDepositAmount;

    // Human UI/UX ...
    printf("  Opening Balance  : %d\n", (int) vATMAccounts[iLoggedInATMAccountsID].dBeginningBalance);
    printf("  Deposited Amount : %d\n", (int) dDepositAmount);
    printf("  Ending Balance   : %d\n", (int) vATMAccounts[iLoggedInATMAccountsID].dAccountBalance);
    
    // Track Last Operation
    SetLastOperation(vATMAccounts[iLoggedInATMAccountsID].iAccountID, DEPOSIT_SUCCESSFULL);
    
    DBG_LOG("tATM::DepositMoney :: OUT  :: ", eOperation_str[eATMLastOperation]);
}

void tATM::WithdrawMoney(double dWithdrawalAmount)
{
    DBG_LOG( "tATM::WithdrawMoney :: IN  :: ", std::to_string( (int) -dWithdrawalAmount) );
    
    // Update dAccountBalance --> dBeginningBalance
    vATMAccounts[iLoggedInATMAccountsID].dBeginningBalance = vATMAccounts[iLoggedInATMAccountsID].dAccountBalance;
    
    // Check if User has deposited clearance on the account, before doing a withdrawal
    if ( vATMAccounts[iLoggedInATMAccountsID].dAccountBalance >= dWithdrawalAmount)
    {
        // Remove -dWithdrawalAmount --> dAccountBalance
        vATMAccounts[iLoggedInATMAccountsID].dAccountBalance -= dWithdrawalAmount;
        
        // Set dLastMoneyMovement = -dWithdrawalAmount
        vATMAccounts[iLoggedInATMAccountsID].dLastMoneyMovement = -dWithdrawalAmount;
        
        // Human UI/UX ...
        printf("  Opening Balance  : %d\n", (int) vATMAccounts[iLoggedInATMAccountsID].dBeginningBalance);
        printf("  Deposited Amount : %d\n", (int) -dWithdrawalAmount);
        printf("  Ending Balance   : %d\n", (int) vATMAccounts[iLoggedInATMAccountsID].dAccountBalance);
        
        // Track Last Operation
        SetLastOperation(vATMAccounts[iLoggedInATMAccountsID].iAccountID,
                         WITHDRAWAL_SUCCESSFULL);
    }
    else
    {
        // Human UI/UX ...
        printf("\n  You don't have   : %d\n", (int) dWithdrawalAmount);
        printf("  disposable on your account\n\n");
        printf("  Maximum withdraw : %d\n", (int) vATMAccounts[iLoggedInATMAccountsID].dAccountBalance);
               
        // Track Last Operation
        SetLastOperation(vATMAccounts[iLoggedInATMAccountsID].iAccountID,
                         WITHDRAWAL_FAILED);
    }
    
    DBG_LOG("tATM::WithdrawMoney :: OUT  :: ", eOperation_str[eATMLastOperation]);
}

int tATM::GetLoggedInUserAccountID(void) const
{
    return vATMAccounts[iLoggedInATMAccountsID].iAccountID;
}

double tATM::GetAccountBalance(int iAccountID) const
{
    DBG_LOG("tATM::GetAccountBalance :: IN   ::  accoundID: ", std::to_string(iAccountID) );
    
    /* FOR-LOOP - BEGIN */
    for (int i = 0; i < vATMAccounts.size(); i++)
    {
        
        DBG_LOG("tATM::GetAccountBalance :: ","[", std::to_string(i),"]  ::  accoundID: ",
                std::to_string(vATMAccounts[i].iAccountID));
        
        if (vATMAccounts[i].iAccountID == iAccountID)
        {
            
            return (double) vATMAccounts[i].dAccountBalance;
            // when match is found, break the for-loop
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
    printf("\n\nHello CreateNewAccount\n");
    printf("Add code to CreateNewAccount for: %s:%s\n\n", sNewUsername.c_str(), sNewPassword.c_str());
}

void tATM::SetLastOperation(int iAccountID, eOperation eLastOperation)
{
    /* FOR-LOOP - BEGIN */
    for (int i = 0; i < vATMAccounts.size(); i++)
    {
        DBG_LOG("tATM::SetLastOperation :: ","[", std::to_string(i),"]  ::  accoundID: ",
                std::to_string(vATMAccounts[i].iAccountID));
        
        if (vATMAccounts[i].iAccountID == iAccountID)
        {
            
            // Track Last Operation
            eATMLastOperation = eLastOperation;
            vATMAccounts[i].eLastOperation = eATMLastOperation;
            
            // when match is found, break the for-loop
            break;
        }
        else
        {
            DBG_LOG("tATM::SetLastOperation :: ","[", std::to_string(i),"]  ::  No Match: iAccountID != iAlccountID");
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

/* IMPLEMENTATION OF ALL FUNCTIONS - END */
