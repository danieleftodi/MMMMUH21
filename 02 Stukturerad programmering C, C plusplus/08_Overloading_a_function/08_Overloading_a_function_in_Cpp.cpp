//
//  08_Overloading_a_function_in_Cpp.cpp
//  08_Overloading_a_function_in_Cpp
//
//  Created by Daniel Eftodi on 2021-10-06.
//

#include "08_Overloading_a_function_in_Cpp.h"

float multi(float num1, float num2){
    printf("DBG_LOG :: IN>>  :: multi12\n");
    
/*  The vastnes of empty space *pun*
*/
    
    printf("DBG_LOG :: <<OUT :: multi12\n\n");
    return num1*num2;
}

float multi(float numarr[]){
    printf("DBG_LOG :: IN>>  :: multi21\n");
    
    float x = 1;
    
    int arr = (int)( sizeof(numarr) / sizeof(float));
    
    printf("Size of arr: %d", arr);
    
    for(int i=0; i< arr; i++){
        x = x * numarr[i];
    }

    printf("DBG_LOG :: <<OUT :: multi21\n\n");
    return x;
}

int main (int argc, char ** argv){
    printf("DBG_LOG :: IN>>  :: main\n");
    
/*  The vastnes of empty space *pun*
*/
    
    printf("DBG_LOG :: <<OUT :: main\n\n");
    return multi(2.0,3.0);
}
