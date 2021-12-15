//
//  03_Day_three_Array_ADT.cpp
//  03_Day_three_Array_ADT
//
//  Created by Daniel Eftodi on 2021-12-15.
//

#include "03_Day_three_Array_ADT.h"

// 1. Array ADT: Introduction
int one_main()
{
    // Look in the video, screenshoot.
    return 0;
}


// 2. Array ADT: Multi dimension Arrays
int two_main()
{
    int a2D[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12}
    };
    
    int *B[3];
    
    // Look in the video, screenshoot.
    
    return 0;
}


// 3. Array ADT 101: Class and Arrays
class cArrayThree {
    
private:
    int* A;
    int size;
    int length;
    
public:
    cArrayThree(int size)
    {
        this->size=size;
        A = new int [size];
        
    }; // our constructor
    
    void create()
    {
        std::cout << "Enter the number of elements!"<<std::endl;
        std::cin >> length;
        std::cout << "Enter all of the elements"<<std::endl;
        
        for(int i=0; i<length; i++)
        {
            std::cout << "Array element: " << i << " = " << std::endl;
            std::cin >> A[i];
        }
    }; // our user dialog
    
    void display()
    {
        for(int i=0; i<length; i++)
        {
            std::cout << A[i] << " ";
        }
        
    }
    
    ~cArrayThree()
    {
        delete[] A;
        std::cout << "Array is destroyed" << std::endl;
        
    } // our destructor då vi arbetar med class och pointers
    
}; // our class

int three_main()
{
    cArrayThree cArr(10);
    cArr.create();
    cArr.display();
    
    return 0;
}

// 4. Array ADT: Struct and Arrays
struct sStructFour {
    
    int A[10];
    int size;
    int length;
    
    void Display(struct sStructFour arr)
    {
        int i;
        printf("Elements are\n");
        for (i=0; i < arr.length; i++)
        {
            printf("%d ", arr.A[i]);
        }
        
        // End with a new-line
        printf("\n");
    };
    
    void Append(struct sStructFour *arr, int x)
    {
        if(arr->length < arr->size)
        {
            arr->A[arr->length++] = x;
        }
    };
    
    void Insert(struct sStructFour *arr, int index, int x)
    {
        int i;
        
        if ( (index >= 0) && (index <= arr->length) )
        {
            for (i=arr->length; i>index; i--)
            {
                arr->A[i] = arr->A[i-1];
                arr->A[index] = x;
                arr->length++;
            }
        }
    };
    
    void Delete(struct sStructFour *arr, int index)
    {
        int x = 0;
        int i;
        
        if ( (index >= 0) && (index < arr->length) )
        {
            x = arr->A[index];
            
            for (i = index; i < arr->length-1; i++)
            {
                arr->A[i] = arr->A[i+1];
            }
            
            arr->length--;
        }
    };
    
    void LinearSearch ()
    {
        
    };
    
    int BinarySearch(struct sStructFour arr, int key)
    {
        int l, mid, h;
        l = 0;
        h = arr.length - 1;
        
        while ( l <= h )
        {
            mid = ( (l + h) / 2);
            
            if ( key == arr.A[mid] )
            {
                return mid;
            }
            else if ( key < arr.A[mid])
            {
                h = mid - 1;
            }
            else
            {
                h = mid + 1;
            }
        }
        
        return 0;
    };
};

int four_main()
{
//    struct sStructFour sArr0 = {{2,3,4},10,9};
    struct sStructFour sArr0 = {
        .A = {2,3,4},
        .size = 10,
        .length = 9,
    };
    
    //Intial
    sArr0.Display(sArr0);
    
    //Append
    sArr0.Append(&sArr0, 9);
    sArr0.Display(sArr0);
    
    //Insert
    sArr0.Insert(&sArr0, 0, 1);
    sArr0.Display(sArr0);
    
    
//    printf("\nsArr0.A: %d\n", sArr0.A[1]);;
    return 0;
}


// 5. Array ADT:
struct sStructFive {
    
    int *A;
    int size;
    int length;
    
// Användaren skall mötas av en meny som tillåter följande:
// Användaren är även den som definierar vår arrays innehåll och storlek
    
    // Visar upp alla element i vår array
    void Display(struct sStructFour arr)
    {
        int i;
        printf("Elements are\n");
        for (i=0; i < arr.length; i++)
        {
            printf("%d ", arr.A[i]);
        }
        
        // End with a new-line
        printf("\n");
    };
    
    // Tillsätter ett värde i slutet av vår array
    void Append(struct sStructFour *arr, int x)
    {
        if(arr->length < arr->size)
        {
            arr->A[arr->length++] = x;
        }
    };
    
    // Ersätter ett värde i vår array med önskat värde
    void Insert(struct sStructFour *arr, int index, int x)
    {
        int i;
        
        if ( (index >= 0) && (index <= arr->length) )
        {
            for (i=arr->length; i>index; i--)
            {
                arr->A[i] = arr->A[i-1];
                arr->A[index] = x;
                arr->length++;
            }
        }
    };
    
    // Tar bort efterfrågat index
    int Delete(struct sStructFour *arr, int index)
    {
        int x = 0;
        int i;
        
        if ( (index >= 0) && (index < arr->length) )
        {
            x = arr->A[index];
            
            for (i = index; i < arr->length-1; i++)
            {
                arr->A[i] = arr->A[i+1];
            }
            
            arr->length--;
        }
        return 0;
    };
    
    // Söker ifrån start till slut efter key
    int LinearSearch ()
    {
        
        return 0;
    };
    
    // Finner mid och utgår sedan efter detta
    int BinarySearch(struct sStructFour arr, int key)
    {
        int l, mid, h;
        l = 0;
        h = arr.length - 1;
        
        while ( l <= h )
        {
            mid = ( (l + h) / 2);
            
            if ( key == arr.A[mid] )
            {
                return mid;
            }
            else if ( key < arr.A[mid])
            {
                h = mid - 1;
            }
            else
            {
                h = mid + 1;
            }
        }
        
        return 0;
    };
    
    // Samma som 'BinarySearch' fast med recursive functions
    int RbinSearch()
    {
        
        return 0;
    }
};
int five_main()
{
    
    return 0;
}

// 6. Array ADT:
int six_main()
{
    
    return 0;
}

/* INIT - BEGIN */
int main(int argc, char ** argv){
    
    int key_pressed = '\0';
    
    // 1. Array ADT: Introduction
//    printf("[01] Array ADT: Introduction\n");
//    one_main();
//    printf("[01] Press any key: "); key_pressed = c_getche(); printf(" [%d] \n\n", key_pressed);

    // 2. Array ADT: Multi dimension Arrays
//    printf("[02] Array ADT: Multi dimension Arrays\n");
//    two_main();
//    printf("[02] Press any key: "); key_pressed = c_getche(); printf(" [%d] \n\n", key_pressed);
    
    // 3. Array ADT: Class and Arrays
//    printf("[03] Array ADT 101: Class and Arrays\n");
//    three_main();
//    printf("[03] Press any key: "); key_pressed = c_getch(); printf(" [%d] \n\n", key_pressed);
    
    // 4. Array ADT:
    printf("[04] Array ADT 101: \n");
    four_main();
    printf("[04] Press any key: "); key_pressed = c_getch(); printf(" [%d] \n\n", key_pressed);
    
    // 5. Array ADT: Excersize
//    printf("[05] Array ADT: Excersize \n");
//    five_main();
//    printf("[05] Press any key: "); key_pressed = c_getch(); printf(" [%d] \n\n", key_pressed);
    
    // 6. Array ADT:
//    printf("[06] Array ADT: \n");
//    six_main();
//    printf("[06] Press any key: "); key_pressed = c_getch(); printf(" [%d] \n\n", key_pressed);
    
    //Endnig with an extra new line
    std::cout << "\n";
    
    return 0;
}
/* INIT - END */

/* IMPLEMENTATION OF ALL FUNCTIONS - BEGIN */

void DBG_LOG(std::string sText,
                   std::string sVarA,
                   std::string sVarB,
                   std::string sVarC,
                   std::string sVarD,
                   std::string sVarE,
                   std::string sVarF)
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

/* Read 1 character without echo */
int c_getch(void)
{
    struct termios old, char_new;
    int ch;
    
    tcgetattr(0, &old);
    
    char_new = old;
    char_new.c_lflag &= ~ICANON;
    char_new.c_lflag &= ~ECHO;
    
    tcsetattr(0, TCSANOW, &char_new);
    
    ch = getchar();
    
    tcsetattr(0, TCSANOW, &old);
    
    return ch;
}

/* Read 1 character with echo */
int c_getche(void)
{
    struct termios old, char_new;
    int ch;
    
    tcgetattr(0, &old);
    
    char_new = old;
    char_new.c_lflag &= ~ICANON;
//    char_new.c_lflag &= ~ECHO;

    tcsetattr(0, TCSADRAIN, &char_new);
    
    ch = getchar();
    
    tcsetattr(0, TCSADRAIN, &old);
    return ch;
}

/* IMPLEMENTATION OF ALL FUNCTIONS - END */
