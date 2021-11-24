//
//  16_ATM_in_Cpp.cpp
//  16_ATM_in_Cpp
//
//  Created by Daniel Eftodi on 2021-11-13.
//

#include "17_Fstream_exercise_main.h"

#include <string>
#include <iostream>
// #include <map>
#include <vector>
#include <fstream>
// #include <sstream>
#include <iomanip>
#include <unistd.h>	// system(clear);

/* INIT - BEGIN */
int main(int argc, char ** argv){
    
    // init Screen - with some default User Accounts
    tScreen tFirstScreen =
    {
        .vScreenAccounts =
        {
            {
                .uliAccountID = 198104011122,
                .sFirstName = "Root",
                .sLastName = "Admin",
                .sUsername = "root",
                .sPassword = "root",
                .eLastOperation = tScreen::NEW_ACCOUNT_SUCCESSFULL
            },
            {
                .uliAccountID = 198107222233,
                .sFirstName = "Daniel",
                .sLastName = "Eftodi",
                .sUsername = "deft",
                .sPassword = "test",
                .eLastOperation = tScreen::NEW_ACCOUNT_SUCCESSFULL
            },
            {
                .uliAccountID = 199502113344,
                .sFirstName = "Felicia",
                .sLastName = "Bornudd",
                .sUsername = "fbor",
                .sPassword = "test",
                .eLastOperation = tScreen::NEW_ACCOUNT_SUCCESSFULL
            },
        }
    };

/*
 // Step 1: Write to a .txt file
 bool writeToFile = writeRecordToFile("fstream_exempel.txt", "1234", "Ludwig", "1997");
 
 // Step 2: Read from a .txt file
 vector<string> Result = readRecordFromFile("fstream_exempel.txt", "1234");
 
 // Step 3: Print result ...
 cout << "Result: " << endl << Result[0] << endl << Result[1] << endl << Result [2] << endl;
 */
    
    // Start Screen
    tFirstScreen.ScreenMenu();
    
    //Endnig with an extra new line
    std::cout << "\n";
    
    return 0;
}
/* INIT - END */

/* IMPLEMENTATION OF ALL FUNCTIONS - BEGIN */
void tScreen::ScreenMenu(void)
{
    char cUserInput              = '\0';
    bool bMainMenuValidSelection = false;
    
    do
    {
        clearScreen();
        std::cout << std::left;
        std::cout << "############################################\n";
        std::cout << "## " << std::setfill('-') << std::setw(38) << "Screen" << " ##" << std::endl;
        std::cout << "## " << std::setfill('-') << std::setw(38) << "" << " ##" << std::endl;
        if (loggedInAccountLocation > -1)
        {
            
//            printf("## Main Menu  ::  %s                    ##\n", vScreenAccounts[loggedInAccountLocation].sUsername.c_str());
            std::cout << "## " << std::setfill('-') << std::setw(11) << "Main Menu  ::  " << std::setw(23) << vScreenAccounts[loggedInAccountLocation].sFullName << " ##" << std::endl;
        }
        else
        {
            std::cout << "## " << std::setfill('-') << std::setw(38) << "Main Menu" << " ##" << std::endl;
        }
        
        std::cout << "############################################\n";
        std::cout << "\n";
        if (loggedInAccountLocation > -1)
        {
//            std::cout << "  (D) - Deposite money\n";
//            std::cout << "  (W) - Withdraw money\n";
//            std::cout << "  (V) - View balance\n";
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
                DBG_LOG("LOG_DBG: ",  std::to_string(cUserInput));
                if (loggedInAccountLocation < 0)
                {
                    // temp login struct
                    tScreen::tLoginDefaults tLoginTemp;
                    
                    // ask for inputs
                    printf("\n  Enter Username: ");
                    std::cin >> tLoginTemp.sUsername;
                    printf("  Enter Password: ");
                    std::cin >> tLoginTemp.sPassword;
                    
                    // try to login --> eATMLastOperation
//                    AccountLogin(tLoginTemp.sUsername, tLoginTemp.sPassword);
                    
                    // Let users know if they logged in
                    if (eLastOperation == LOGIN_SUCCESSFULL) {
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
                
                // Human UI/UX ...
                delay(3);
                
                break;
            case 'w':
            case 'W':
                DBG_LOG("LOG_DBG: ",  std::to_string(cUserInput));
                                    
                // Human UI/UX ...
                delay(3);
                
                break;
            case 'v':
            case 'V':
                DBG_LOG("LOG_DBG: ",  std::to_string(cUserInput));

                // Human UI/UX ...
                delay(3);
                
                break;
            case 'c':
            case 'C':
                DBG_LOG("LOG_DBG: ",  std::to_string(cUserInput));
                if (loggedInAccountLocation < 0)
                {
                    // Track Last Operation
                    eLastOperation = CREATE;
                    
                    // temp NewUser struct
                    tScreen::tLoginDefaults tNewUserTemp;
                    
                    // ask for inputs
                    printf("\n  Enter Username: ");
                    std::cin >> tNewUserTemp.sUsername;
                    printf("  Enter Password: ");
                    std::cin >> tNewUserTemp.sPassword;
                    
                    // try to CreateNewAccount --> eATMLastOperation
//                    CreateNewAccount(tNewUserTemp.sUsername, tNewUserTemp.sPassword);
                    
                    // Let users know if they logged in
                    if (eLastOperation == CREATE_SUCCESSFULL) {
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
//                    SetLastOperation(vScreenAccounts[loggedInAccountLocation].uliAccountID, LOGOUT);
                    
                    // Log out the user
//                    AccountLogOut();
                    
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

bool tScreen::WriteRecordToFile (std::string file_name, std::string field_one, std::string field_two, std::string field_three)
{
    std::ofstream file;
    file.open(file_name, std::ios_base::app);    //
    file.open(file_name, std::ios::trunc);         // over-write file
    file << field_one << ";" << field_two << ";" << field_three << std::endl;
    file.close();
    
    return 0;
}

std::vector<std::string> tScreen::ReadRecordFromFile (std::string file_name, std::string search_term)
{
    std::vector<std::string> record;
    std::ifstream file;
    file.open(file_name);
    
    bool found_record = false;
    
    std::string field_one;
    std::string field_two;
    std::string field_three;
    
    while ( getline(file, field_one, ';') && !found_record)
    {
        getline(file, field_two, ';');
        getline(file, field_three, '\n');
        
        std::cout << "VEC: " << field_one << std::endl;
        std::cout << "VEC: " << field_two << std::endl;
        std::cout << "VEC: " << field_three << std::endl;
        
        if(field_one == search_term)
        {
            found_record = true;
            record.push_back(field_one);
            record.push_back(field_two);
            record.push_back(field_three);
        }
    }
    
    file.close();
    return record;
}

void tScreen::DBG_LOG(std::string sText,
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
