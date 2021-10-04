//
//  02_Variables_Constants_and_Datatypes.c
//  02_Variables_Constants_and_Datatypes
//
//  Created by Daniel Eftodi on 2021-09-14.
//

#include "02_Variables_Constants_and_Datatypes_in_Cpp.h"

void func_excersize_week_two_part_one () {
/*
Övningsuppgifter
  1. Skriv ett program som skriver ut meddelandet ”Hello World” till konsolen.
 */
    printf("\nHello Bonjio,\n\n");
    
/*
 2. Skriv ett program där användaren kan skriva in sitt namn och ålder.
    Namnet skall sparas i en String variabel och åldern skall sparas i en Int variabel.
    Sedan skall följande meddelande skrivas ut till användaren via konsol:
 
    ”Hejsan <namn>. Du är <ålder> år gammal.” där <namn> och <ålder> är utbytt till dina 2 sparade variabler.
*/
    std::string sName;
    unsigned int iAlder;
    
    std::cout << "What is your name: ";
    std::cin >> sName;
    std::cout << "What is your age:  ";
    std::cin >> iAlder;
    
    printf("\nHi %s!\n\nInteresting, you are %d years old.\n", sName.c_str(), iAlder);
 
/*
 3. Skriv ett program där användaren matar in 2 heltal som sparas i 2 variabler.
    Programmet skall sedan spara och skriva ut resultatet av de 4 matematiska operationerna;
    addition, subtraktion, multiplikation och division.
 
    Tips: Spara resultatet från division som datatyp double för att kunna hantera decimaler.
 */
    double iVarOne;
    double iVarTwo;
    
    printf("\nLet have some fun with maths %s,\n\n", sName.c_str());
    
    std::cout << "What is the first value you would like to use: ";
    std::cin >> iVarOne;
    std::cout << "and, what is the second value you would like to use: ";
    std::cin >> iVarTwo;
    
    signed int iResultAdd = iVarOne + iVarTwo;
    printf("\nAddition:       %f + %f = %d", iVarOne, iVarTwo, iResultAdd);
    
    signed int iResultSub = iVarOne - iVarTwo;
    printf("\nSubstraction:   %f - %f = %d", iVarOne, iVarTwo, iResultSub);
    
    double iResultMul = iVarOne * iVarTwo;
    printf("\nMultiplication: %f * %f = %f", iVarOne, iVarTwo, iResultMul);
    
    float iResultDiv = (iVarOne / iVarTwo);
    printf("\nDivision:       %f / %f = %f", iVarOne, iVarTwo, iResultDiv);
    
}

void func_excersize_week_two_part_two () {
/*
 Lite mer utmanande Googla gärna på en lösning om du kör fast.
 4. Skriv ett program där användaren matar in en sträng. */
    
    std::string sCheckLenght = "Hello World";
//    printf("The lenght of the string sCheckLenght (%s) is: %lu\n\n", sCheckLenght.c_str(), sCheckLenght.length());
    
    std::cout << "\nEnter a string: ";
    std::getline(std::cin, sCheckLenght);
 
 /* Programmet skall sedan skriva ut hur lång strängen är. Använd den inbyggda metoden .length för detta. */
    
    printf("The lenght of the string sCheckLenght (%s) is: %lu\n\n", sCheckLenght.c_str(), sCheckLenght.length());
    
}

void func_excersize_week_two_part_three () {

/* 5. Skapa ett meny-val för användaren:
        1. Hälsning till användaren - Användaren matar in sitt namn och får en hälsning
        2. Summera två tal - Användaren matar in 2 nummer och får ut en summa
        3. Skriv ut värdet Pi - Systemet skriver ut värdet Pi.
 
    Användaren skall kunna välja ett menyval med att skriva in 1, 2 eller 3 och trycker på Enter. Använd dig av en SwitchCase för detta. */
    char cInput = '\0';
    bool bMainMenuValidSelection = false;

    do {
        system("clear");
        std::cout << "###############\n";
        std::cout << "## Main Menu ##\n";
        std::cout << "###############\n";
        std::cout << "\n";
        std::cout << "  (0) - \n";
        std::cout << "  (1) - \n";
        std::cout << "  (2) - \n";
        std::cout << "  (3) - \n";
        std::cout << "  (Q) - Quit\n";
        std::cout << "\n";
        std::cout << "  Press any key: ";
        std::cin >> cInput;

        switch (cInput) {
            case '1':
                printf("MAGIC: %c\n", cInput);
                func_excersize_week_two_part_one();
                bMainMenuValidSelection = true;
                break;
            case '2':
                printf("MAGIC: %c\n", cInput);
                func_excersize_week_two_part_two();
                bMainMenuValidSelection = true;
                break;
            case '3':
                printf("MAGIC: %c\n", cInput);
                bMainMenuValidSelection = true;
                break;
            case 'Q':
                printf("MAGIC: %c\n", cInput);
                break;
            default:
                printf("\nWrong input, not a menu option: %c\n\nPlease try again\n", cInput);
                sleep(3);
                break;
        }
    } while (!bMainMenuValidSelection);
    
 
}

void func_bool_one (){
    /////////////////////////////////////////////////////////
    // add some BOOL:ians variables
    double bVarOne = true;
    double bVarTwo = false;
    
    // print value of double variables
    printf("Initial bVarOne variable value is: %f\n", bVarOne);
    printf("Initial bVarTwo variable value is: %f\n\n", bVarTwo);
    
    if (bVarOne) {
        printf("bVarOne value is: True\n");
    } else {
        printf("bVarOne value is: False\n");
    };
    
    if (bVarTwo) {
        printf("bVarTwo value is: True\n");
    } else {
        printf("bVarTwo value is: False\n");
    };
    
    std::cout << "(T)rue or (F)alse?: ";
    char cTemp;
    std::cin >> cTemp;
    //std::cout << "You enterd: " << cTemp << std::endl;
    
    switch (cTemp) {
        case 'T':
            printf("True\n");
            bVarTwo = true;
            break;
        case 't':
            printf("True\n");
            bVarTwo = true;
            break;
        case 'f':
            printf("False\n");
            bVarTwo = false;
            break;
        case 'F':
            printf("False\n");
            bVarTwo = false;
            break;
        default:
            printf("\nYEEHH ... don't be a git!\n\nthe charater you entered: %c, is not T or F\n\n", cTemp);
            break;
    };
    
    if (bVarOne && bVarTwo) {
        printf("\nBoth bVarOne & bVarTwo are: True\n");
    } else {
        printf("\nOne of both of the bVarOne & bVarTwo is: False\n");
    }
    
}

void func_slides (){
    /////////////////////////////////////////////////////////
    // add some int variables
    unsigned int iVarOne = 32;
    signed int iVarTwo = 20;
    
    // print value of int variable
    printf("Initial iVarOne variable value is: %d\n", iVarOne);

    // change int variable
    iVarOne++;

    // print value of variable
    printf("Altered iVarOne variable value is: %d\n\n", iVarOne);

    // print value of variables
    printf("The result of %d multiplied by %d is: %d\n\n", iVarOne, iVarTwo, iVarOne * iVarTwo);

    
    
    /////////////////////////////////////////////////////////
    // add some float variables
    float fVarOne = 10.5;
    float fVarTwo = 22.5;
    
    // print value of float variables
    printf("Initial fVarOne variable value is: %f\n", fVarOne);
    printf("Initial fVarTwo variable value is: %f\n\n", fVarTwo);
    
    // change float variables
    fVarOne++;
    fVarTwo++;
    
    // print value of variables
    printf("Altered fVarOne variable value is: %f\n", fVarOne);
    printf("Altered fVarTwo variable value is: %f\n\n", fVarTwo);
    
    // print value of variable
    printf("The result of %f multiplied by %f is: %f\n\n", fVarOne, fVarTwo, fVarOne * fVarTwo);
    
    // Lets try to induce an overflow error
    fVarOne = -(1.17549e+038);
    fVarTwo = +(3.40282e+038);
    
    // print values of variables
    printf("Altered fVarOne variable value is: %f\n", fVarOne);
    printf("Altered fVarTwo variable value is:  %f\n\n", fVarTwo);
    
    // print values of variables
    printf("The result of %f multiplied by %f i: %f\n\n", fVarOne, fVarTwo, fVarOne * fVarTwo);
    
    
    
    /////////////////////////////////////////////////////////
    // add some double variables
    double dVarOne = 40.55;
    double dVarTwo = 22.55;
    
    // print value of double variables
    printf("Initial dVarOne variable value is: %f\n", dVarOne);
    printf("Initial dVarTwo variable value is: %f\n\n", dVarTwo);
    
    // change double variables
    dVarOne *= dVarOne;
    dVarTwo *= dVarTwo;
    
    // print value of variables
    printf("Altered dVarOne variable value is: %f\n", dVarOne);
    printf("Altered dVarTwo variable value is: %f\n\n", dVarTwo);
    
    // print value of variables
    printf("The result of %f multiplied by %f is: %f\n\n", dVarOne, dVarTwo, dVarOne * dVarTwo);

    // Lets try to induce an overflow error
    dVarOne = -(1.17549e+038);
    dVarTwo = +(3.40282e+038);
    
    // print values of variables
    printf("Altered dVarOne variable value is: %f\n", dVarOne);
    printf("Altered dVarTwo variable value is:  %f\n\n", dVarTwo);
    
    // print values of variables
    printf("The result of %f multiplied by %f i: %f\n\n", dVarOne, dVarTwo, dVarOne * dVarTwo);
    
    
    
    /////////////////////////////////////////////////////////
    // add some double variables
    long double ldVarOne = -(1.17549e+038)*(3.40282e+038)*(3.40282e+038)*(3.40282e+038)*(3.40282e+038)*(3.40282e+038)*(3.40282e+038)*(3.40282e+038);
    long double ldVarTwo = +(3.40282e+038)*(3.40282e+038)*(3.40282e+038)*(3.40282e+038)*(3.40282e+038)*(3.40282e+038)*(3.40282e+038)*(3.40282e+038);
    
    // print value of double variables
    printf("Initial ldVarOne variable value is: %Lf\n", ldVarOne);
    printf("Initial ldVarTwo variable value is: %Lf\n\n", ldVarTwo);
    
    // change double variables
    ldVarOne *= -(ldVarOne);
    ldVarTwo *= ldVarTwo;
    
    // print value of variables
    printf("Altered ldVarOne variable value is: %Lf\n", ldVarOne);
    printf("Altered ldVarTwo variable value is: %Lf\n\n", ldVarTwo);
    
    // print value of variables
    printf("The result of\n %Lf \n\n multiplied by \n %Lf \n\n is:\n %Lf\n\n", ldVarOne, ldVarTwo, ldVarOne * ldVarTwo);
    
    // Lets try to induce an overflow error
    ldVarOne = -(1.17549e+038)*(3.40282e+038)*(3.40282e+038)*(3.40282e+038)*(3.40282e+038)*(3.40282e+038)*(3.40282e+038)*(3.40282e+038)*(3.40282e+038);
    ldVarTwo = +(3.40282e+038)*(3.40282e+038)*(3.40282e+038)*(3.40282e+038)*(3.40282e+038)*(3.40282e+038)*(3.40282e+038)*(3.40282e+038)*(3.40282e+038);
    
    // print values of variables
    printf("Altered ldVarOne variable value is: %Lf\n", ldVarOne);
    printf("Altered ldVarOne variable value is:  %Lf\n\n", ldVarTwo);
    
    // print values of variables
    printf("The result of %Lf multiplied by %Lf i: %Lf\n\n", ldVarOne, ldVarTwo, ldVarOne * ldVarTwo);
    
    
    
    /////////////////////////////////////////////////////////
    // If we want to goto / execute function: func_bool_one()
    //func_bool_one();

    
    
    /////////////////////////////////////////////////////////
    // add some string variables
    std::string sGreeting = "Hello";
    std::string sReply    = "Hi, how are you?";
    std::string sEnd      = "EY ... Yo!?!";
    
    // print strings
    printf(">> %s \n<< %s \n>> %s \n\n", sGreeting.c_str(), sReply.c_str(), sEnd.c_str());
    
    
    
    /////////////////////////////////////////////////////////
    // let's set some varibales in stone ...
    const int    ciVarOne = 10;
    const int    ciVarTwo = 20;
    const bool   cbVarOne = true;
    const double cdVarOne = (3.40282e+038);
    
    // print variables
    printf("The following varibales are set in stone:\n\
 ciVarOne: %d\n\
 ciVarTwo: %d\n\
 cbVarOne: %d\n\
 cdVarOne: %f\n\n", ciVarOne, ciVarTwo, cbVarOne, cdVarOne);
    
    // check if we can change a const
//    printf("Trying to change a constant, ciVarTwo: ", ++ciVarTwo);
    
    // print variables ...
    if (cbVarOne) {
        printf("Doing some addition, %d + %d : %d\n\n", ciVarOne, ciVarTwo, ciVarOne + ciVarTwo);
    }
    
}

int main(){
    
    // call function: func_slides()
    func_slides ();
    
    // call function: func_excersize_week_two_part_one()
//    func_excersize_week_two_part_one();

    // call function: func_excersize_week_two_part_two()
//    func_excersize_week_two_part_two();
    
    // call function: func_excersize_week_two_part_three()
//    func_excersize_week_two_part_three();
    
    //Endnig with an extra new line
    std::cout << "\n";
    
    return 0;
}
