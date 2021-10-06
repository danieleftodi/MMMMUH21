//
//  08_Overloading_a_function_in_Cpp_Dagmara.cpp
//  08_Overloading_a_function_in_Cpp_Dagmara
//
//  Created by Dagmara Gotlib on 2021-10-06.
//

#include <stdio.h>



float multi(float num1, float num2){

return num1*num2;

}



float multi(float numarr[], int arrsize){

float x = 1;

//int arr = (int)(sizeof(numarr)/ sizeof(numarr[0]));

for(int i=0; i< arrsize; i++){

x = x * numarr[i];

}

return x;

}



int main(){

float mul1 = multi(1.2, 400);

printf("två: %f \n", mul1);



float arr[] = {4.2, 6.3, 73};

float mul2 = multi(arr, 3);

printf("flera: %f\n", mul2);

return 0;

}
