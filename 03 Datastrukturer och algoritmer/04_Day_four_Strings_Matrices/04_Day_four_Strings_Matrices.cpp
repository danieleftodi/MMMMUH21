//
//  04_Day_four_Strings_Matrices.cpp
//  04_Day_four_Strings_Matrices
//
//  Created by Daniel Eftodi on 2021-12-17.
//

#include "04_Day_four_Strings_Matrices.h"

// 1. Strings & Matrices: Introduction
struct sStructOne {
    
    int A[10];
    int size;
    int length;
    
    void Display(struct sStructOne *arr)
    {
        int i;
        printf("Elements are\n");
        for (i=0; i < arr->length; i++)
        {
            printf("%d ", arr->A[i]);
        }
        
        // End with a new-line
        printf("\n");
    };
    
    void Append(struct sStructOne *arr, int x)
    {
        if(arr->length < arr->size)
        {
            arr->A[arr->length++] = x;
        } else {
            printf("ERROR: Can not append (%d) to the array, array is allready filled to the max\n", x);
        }
    };
    
    void Insert(struct sStructOne *arr, int index, int x)
    {
        DBG_LOG("\nDBG:: RealSize: ", std::to_string((sizeof(arr->A)/sizeof(int))),
                "  ::  FakeSize: ", std::to_string(arr->size),
                "  ::  Length: ", std::to_string(arr->length),
                "  ::  First: ", std::to_string(arr->A[0]),
                "  ::  Last: ", std::to_string(arr->A[ ((int) (sizeof(arr->A)/sizeof(int)) ) - 1 ]),
                "  ::  INT");
        
        int i;
                
        if ( (index >= 0) && (index < arr->size) && (arr->length < arr->size) )
        {
            for (i=arr->length++; i > index; i--)
            {
                arr->A[i] = arr->A[i-1];
                                
                DBG_LOG("DBG:: RealSize: ", std::to_string((sizeof(arr->A)/sizeof(int))),
                        "  ::  FakeSize: ", std::to_string(arr->size),
                        "  ::  Length: ", std::to_string(arr->length),
                        "  ::  First: ", std::to_string(arr->A[0]),
                        "  ::  Last: ", std::to_string(arr->A[ ((int) (sizeof(arr->A)/sizeof(int)) ) - 1 ]),
                        "  ::  for-loop  :: i: ", std::to_string(i),
                        " arr->A[i-1]: ", std::to_string(arr->A[i-1]));
            }
            
            arr->A[index] = x;
        }
        else
        {
            printf("ERROR: Can not insert (%d) into array, array is allready filled to the max\n", x);
        }
        
        DBG_LOG("DBG:: RealSize: ", std::to_string((sizeof(arr->A)/sizeof(int))),
                "  ::  FakeSize: ", std::to_string(arr->size),
                "  ::  Length: ", std::to_string(arr->length),
                "  ::  First: ", std::to_string(arr->A[0]),
                "  ::  Last: ", std::to_string(arr->A[ ((int) (sizeof(arr->A)/sizeof(int)) ) - 1 ]),
                "  ::  END");
    };
    
    void Delete(struct sStructOne *arr, int index)
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
    
    int BinarySearch(struct sStructOne arr, int key)
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
    
    int Get (struct sStructOne arr, int index=0)
    {
        if ( (index >= 0) &&
             (index < arr.length) )
        {
            return arr.A[index];
        }
        return -1337;
    }
    
    void Set (struct sStructOne *arr, int index, int x)
    {
        if ( (index >= 0) &&
            (index < arr->length) )
        {
            arr->A[index] = x;
        }
    }
    
    int Max (struct sStructOne arr)
    {
        int max = arr.A[0];
        int i;
        
        for (i=1; i < arr.length;i++)
        {
            if (arr.A[i] > max)
            {
                max=arr.A[i];
            }
        }
        return max;
    }
    
    int Min (struct sStructOne arr)
    {
        int min = arr.A[0];
        int i;
        
        for (i=1; i < arr.length;i++)
        {
            if (arr.A[i] < min)
            {
                min=arr.A[i];
            }
        }
        return min;
    }
    
    int Sum (struct sStructOne arr)
    {
        int sum = 0;
        
        for (int i=0; i < arr.length; i++)
        {
            sum = sum + arr.A[i];
        }
        
        return sum;
    }
    
    float Avg (struct sStructOne arr)
    {
        return (float) Sum(arr) / arr.length;
    }
    
    void Swap (int *x, int *y)
    {
        int temp = *x;
        
        *x = *y;
        *y = temp;
    }
    
    void Reverse1 (struct sStructOne *arr)
    {
        for (int i=0, j=(arr->length - 1); i < j; i++, j--)
        {
            Swap(&arr->A[i], &arr->A[j]);
        }
    }
    
    void Reverse2 (struct sStructOne *arr)
    {
        int *B;
        int i, j;
        
        B=(int *) malloc(arr->length * sizeof(int));
        
        for (i=(arr->length - 1), j=0; i >= 0; i--, j++)
        {
            B[j] = arr->A[i];
        }
        
        for (i=0; i < arr->length; i++)
        {
            arr->A[i] = B[i];
        }
        
        free(B);
    }
    
};

int one_main()
{
    struct sStructOne sArr0 = {
        //    0 1 2 3 4 5 6 7  8  9   [COMPUTER]
        //    1 2 3 4 5 6 7 8  9  10  [HUMAN]
        .A = {2,3,4,5,6,7,1,9},
        .size = 10,
        .length = 8,
    };
    
    //Intial
    std::cout << "Initial: ";
    sArr0.Display(&sArr0);    
    
    //Get
    std::cout << "Get: ";
    printf("%d \n", sArr0.Get(sArr0, 0));
    
    //Set
    std::cout << "Set: ";
    sArr0.Set(&sArr0, 0, 10);
    sArr0.Display(&sArr0);
    
    //Max
    std::cout << "Max: ";
    printf("%d \n", sArr0.Max(sArr0));
    
    //Min
    std::cout << "Min: ";
    printf("%d \n", sArr0.Min(sArr0));
    
    //Sum
    std::cout << "Sum: ";
    printf("%d \n", sArr0.Sum(sArr0));
    
    //Avg
    std::cout << "Avg: ";
    printf("%f \n", sArr0.Avg(sArr0));
    
    //Sum
    std::cout << "Swap: ";
    sArr0.Swap(&sArr0.A[0], &sArr0.A[sArr0.length - 1]);
    sArr0.Display(&sArr0);
    
    //Reverse1
    std::cout << "Reverse1: ";
    sArr0.Reverse1(&sArr0);
    sArr0.Display(&sArr0);
    
    //Reverse2
    std::cout << "Reverse2: ";
    sArr0.Reverse2(&sArr0);
    sArr0.Display(&sArr0);
    
//    printf("\nsArr0.A: %d\n", sArr0.A[1]);;
    return 0;
}


// 2. Strings & Matrices:
int two_main()
{
    
    return 0;
}

// 3. Strings & Matrices:
int three_main()
{
    
    return 0;
}

/* INIT - BEGIN */
int main(int argc, char ** argv){
    
    int key_pressed = '\0';
    
    // 1. Strings & Matrices: Introduction
    printf("[01] Sparse Matrix & Polymonial Functions: Introduction\n");
    one_main();
    printf("[01] Press any key: "); key_pressed = c_getche(); printf(" [%d] \n\n", key_pressed);

    // 2. Strings & Matrices:
    printf("[02] Strings & Matrices: \n");
    two_main();
    printf("[02] Press any key: "); key_pressed = c_getche(); printf(" [%d] \n\n", key_pressed);
    
    // 3. Sparse Matrix & Polymonial Functions:
    printf("[03] Strings & Matrices: \n");
    three_main();
    printf("[03] Press any key: "); key_pressed = c_getch(); printf(" [%d] \n\n", key_pressed);

    
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
             std::string sVarF,
             std::string sVarG,
             std::string sVarH,
             std::string sVarI,
             std::string sVarJ,
             std::string sVarK,
             std::string sVarL,
             std::string sVarM)
{
#if DEBUG_LOGGING
    printf("%s%s%s%s%s%s%s%s%s%s%s%s%s%s\n",
           sText.c_str(),
           sVarA.c_str(),
           sVarB.c_str(),
           sVarC.c_str(),
           sVarD.c_str(),
           sVarE.c_str(),
           sVarF.c_str(),
           sVarG.c_str(),
           sVarH.c_str(),
           sVarI.c_str(),
           sVarJ.c_str(),
           sVarK.c_str(),
           sVarL.c_str(),
           sVarM.c_str());
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
