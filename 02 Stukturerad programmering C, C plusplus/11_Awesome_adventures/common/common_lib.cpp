//
//  common/common_lib.h
//  MMMMUH21_COMMON_LIB

#include "../common/common_lib.h"

/*
 *  Every common function code that is shared in the classrom, goes here
 */

void clearScreen(void)
{
	#ifdef __WIN32__
		system("cls");
	#else
	    system("clear");
	#endif
}

void pauseScreen(void)
{
	#ifdef __WIN32__
	    system("pause");
	#else
        char cInputPause = '\0';
        std::cout << "Press any key to continue [Followed by Enter]: \n";
        std::cin >> (cInputPause);
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

int is_in_GBro_main(void)
{

    //example usage

    //strings to look for
    std::string str_1 = "Hello";
    std::string str_2 = "Goodbye";
    std::vector<std::string> look_for {str_1, str_2};
    
    //string vector to look in
    std::vector<std::string> look_in = {"Hello", "World"};

    for (int i = 0; i < look_for.size(); i++)
    {
        if (is_in_GBro(look_in, look_for[i]))
        {
            std::cout << "'" << look_for[i] << "' is in the vector." << std::endl;
        } 
        else
        {
            std::cout << "'" << look_for[i] << "' is not in the vector." << std::endl;
        }
        
    }
    
    return 0;
}

bool is_in_GBro(std::vector<std::string> inp_vector, std::string inp_element)
{
    
    for (auto test_element : inp_vector)
    {
        if (test_element == inp_element)
        {
            return true;
        }
    }
    return false;
}

int main_AJon(void)
{
    //numberGenerator
    int randomNumRange = 10;
    int randomNum = numberGenerator_AJon(randomNumRange);
    std::cout << randomNum << std::endl;
    
    oneDArray_AJon();
    twoDArray_AJon();
    threeDArray_AJon();
    return 0;
}

int numberGenerator_AJon(int randomNumRange)
{
    int random;
    srand( (unsigned int) (rand() ^ time(NULL)) );
    return random = rand() % (randomNumRange);
    //Random number within randomNumRange.
}

void oneDArray_AJon(void)
{
    printf("1D Array\n");
    int array1D[5]{ 1, 2, 3, 4, 5 };
    for (size_t i = 0; i < 5; i++)
    {
        printf("Index[%zu] Value: %d\t", i, array1D[i]);
    }
    printf("\n");
}

void twoDArray_AJon(void)
{
    printf("\n2D Array\n");
    int array2D[2][5] = {
        {1, 2, 3, 4, 5},  //Row 0
        {6, 7, 8, 9, 10}    //Row 1
    };
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            printf("Index[%zu][%zu] Value: %d\n", i, j, array2D[i][j]);
        }
    }
}

void threeDArray_AJon(void)
{
    printf("\n3D Array\n");
    int array3D[3][3][3] =
    {
        {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},                 //Row 0
        {{10, 11, 12}, { 13, 14, 15 }, { 16, 17, 18}},     //Row 1
        {{19, 20, 21}, { 22, 23, 24 }, { 25, 26, 28}}     //Row 2
    };
    //Nested for loop
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t x = 0; x < 3; x++)
        {
            for (size_t y = 0; y < 3; y++)
            {
                printf("Index[%zu][%zu][%zu]: Value: %d\n", i, x, y, array3D[i][x][y]);
            }
        }
    }
}

std::string NumToText_KTim(int num)
{
    if (num == 0) { return "zero"; }
    if (num == 1) { return "one"; }
    if (num == 2) { return "two"; }
    if (num == 3) { return "three"; }
    if (num == 4) { return "four"; }
    if (num == 5) { return "five"; }
    if (num == 6) { return "six"; }
    if (num == 7) { return "seven"; }
    if (num == 8) { return "eight"; }
    if (num == 9) { return "nine"; }
    return "";
}

int NumToText_MBer_main(void)
{
    std::cout << "Hello World!\n";
    std::cout << NumToText_MBer(10) << "\n\n";
   
    return 0;
}

std::string NumToText_MBer(int num)
{
    std::string numbers[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    
    //return numbers[num];// Variant utan felhantering
    
    if (num >= 0 && num < 10)
    {
        return numbers[num];
    }
    else
    {
        return "";
    }
    
    /*    for (int i = 0; i < num; i++) //Variant med for-sats
     {
     if (i == num)
     return numbers[i];
     }
     return "";
     */
    return "";
}

char *returnTextNumber(int num)
{
    char* returnResult = new char;
    
    char arrayTextNumber[11][10] = {    "Zero",
                                        "One",
                                        "Two",
                                        "Three",
                                        "Four",
                                        "Five",
                                        "Six",
                                        "Seven",
                                        "Eight",
                                        "Nine",
                                        "Ten"
    };

/* THIS IS FOR DEBUGING PURPOSE */
/*
    printf("First word is: %s\nSecond word is: %s\n\n", arrayTextNumber[0], arrayTextNumber[1]);
    printf("Size of the arary is: %lu\n", (sizeof(arrayTextNumber) / sizeof(char)) / 10);
    printf("Size of first word is: %lu\n", (sizeof(arrayTextNumber[0]) / sizeof(char)));
    printf("Size of second word is: %lu\n\n", (sizeof(arrayTextNumber[1]) / sizeof(char)));
*/

/* FIRST IMPLEMENTATION - WITH SWITCH CASE */
//    switch (num)
//    {
//        case  0:
//            strcpy(returnResult, arrayTextNumber[0]);
//            break;
//        case  1:
//            strcpy(returnResult, arrayTextNumber[1]);
//            break;
//        case  2:
//            strcpy(returnResult, arrayTextNumber[2]);
//            break;
//        case  3:
//            strcpy(returnResult, arrayTextNumber[3]);
//            break;
//        case  4:
//            strcpy(returnResult, arrayTextNumber[4]);
//            break;
//        case  5:
//            strcpy(returnResult, arrayTextNumber[5]);
//            break;
//        case  6:
//            strcpy(returnResult, arrayTextNumber[6]);
//            break;
//        case  7:
//            strcpy(returnResult, arrayTextNumber[7]);
//            break;
//        case  8:
//            strcpy(returnResult, arrayTextNumber[8]);
//            break;
//        case  9:
//            strcpy(returnResult, arrayTextNumber[9]);
//            break;
//        case 10:
//            strcpy(returnResult, arrayTextNumber[10]);
//            break;
//        default:
//            printf("The number is not in the array\n");
//            returnResult = 0;
//            break;
//    }

/* SECOND IMPLEMENTATION - WITH IF STATEMENT */
    if (num >= 0 && num <= 10)
    {
        strcpy(returnResult, arrayTextNumber[num]);
    }
    else
    {
        printf("The number is not in the array\n");
        returnResult = 0;
    }

    return returnResult;
}

int input_EHol_main(void)
{
    int inp;
    const int lower_limit = 1;
    const int upper_limit = 2;    
        
    do
    {
        std::cout << "¤ Press 1 if you want A." << std::endl;
        std::cout << "¤ Press 2 if you don't want A." << std::endl;
        inp = input_EHol(lower_limit, upper_limit);
        std::cout << "Your input is:  " << inp << std::endl << std::endl;
         
    }    
    while (inp != 1 && inp != 2);

    return 0;
}

int input_EHol(int lower_L, int upper_L)
{    
    int num = 0;
    std::string a;
    std::string str;
    std::cout << ">>  ";
    std::cin >> str;
    std::cout << "" << std::endl;
    a = check_if_input_is_digit_EHol(str);
    std::stringstream my_st(a);
    my_st >> num;

    if(num != 1 && num != 2) //if(1 <= num <= 2)
    { 
        std::cout << "Wrong input." << std::endl;
        std::cout << "Try again!" << std::endl;
        return input_EHol(lower_L, upper_L);
    }    
    return num;
}

std::string check_if_input_is_digit_EHol(std::string s)
{ 
    int flag = 0; //flag
    for(int i = 0; i < s.size(); i++) 
    { 
        if(!isdigit(s[i]))
        {
            flag = 1;
            break;
        } 
    }
    return s; 
}

int printmatrix_RBen_main(void)
{
	int matrix[5][3];

	for (int rad = 0; rad < 5; rad++)
	{
		for (int col = 0; col < 3; col++)
		{
            std::cout << "Skriv dina vikt: " << rad << "," << col << std::endl;
            std::cin >> matrix[rad][col];
		}

	}
    printmatrix_RBen(matrix);

    return 0;
}

void printmatrix_RBen(int matrix[5][3])
{
	for (int rad = 0; rad < 5; rad++)
	{
		for (int col = 0; col < 3; col++)
		{
            std::cout << matrix[rad][col] << "\t";
		}
        std::cout << std::endl;
	}
}

int omkrets_RBen_main(void)
{
	int xIn;
	int hitta[] = { 10, 30, 20, 30, 40 };

    std::cout << "hitta din bokstav" << std::endl;
    std::cin >> xIn;

	if (omkrets_RBen(hitta, 5, xIn) == true)
        std::cout << xIn << " its found" <<  std::endl;
	else
        std::cout << xIn << " its not found" << std::endl;

    return 0;
}

bool omkrets_RBen(int omk[], int size, int serchitm)
{
	bool found = false;
	for (int i = 0; i < size; i++)	
	{
		if (omk[i] == serchitm)
		found = true;
	}
	return found;
}
