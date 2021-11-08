#include <stdio.h>

enum my_bools{
    is_false,
    is_true,
};

int card = 1;

enum my_bools cardd = is_true;

void print_state(enum my_bools state){
    
    if (state == is_true) {
        puts("The truth, the whole truth and nothing but the truth!");
    }else{
        puts("It\'s all a lie!");
    }
}

int main(){
    enum my_bools state;

    if (state == is_true){
        printf("true");
    }else{
        printf("not my truth");
    }

    enum my_bools another_state = is_true;
    print_state(another_state);
    print_state(state);


    printf("\n");



    return 0;
}
