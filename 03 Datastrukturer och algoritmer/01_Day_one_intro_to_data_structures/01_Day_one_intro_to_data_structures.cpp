//
//  16_ATM_in_Cpp.cpp
//  16_ATM_in_Cpp
//
//  Created by Daniel Eftodi on 2021-11-13.
//

#include "01_Day_one_intro_to_data_structures.h"

// 1. Enligt koden ni ser, vad blir resultatet? och varför?
int one_main()
{
    int A[5];
    
    A[0] = 12;
    A[1] = 15;
    A[2] = 25;
    
    std::cout<<sizeof(A)<<std::endl;
    
    std::cout<<A[1];
    
    for (int i = 0;i<5;i++)
    {
        std::cout<<A[i]<<std::endl;
    }
    
    return 0;
}


//2.Enligt koden ni ser, vad blir resultatet? och varför?
struct two_Rectangle
{
    int length;
    int breadth;
    char x;
} two_r1;

int two_main()
{
    struct two_Rectangle two_r1 = {10,5};
    std::cout << two_r1.length << std::endl;
    std::cout << two_r1.breadth << std::endl;
    return 0;
}


//3.Enligt koden ni ser, vad blir resultatet? och varför?
int three_main()
{
    int *p;
    p=new int[5];
    p[0]=10; p[1]=7; p[2]=8;
    for(int i=0;i<5;i++)
    std::cout << p[i] << std::endl;
    delete [ ] p;
    
    return 0;
}


//4.Enligt koden ni ser, vad blir resultatet? och varför?
int four_main()
{
    int a=10;
    
    int &r=a;
    
    std::cout << a << std::endl << r << std::endl;
    
    return 0;
}


//5.Enligt koden ni ser, vad blir resultatet? och varför?
struct five_Rectangle
{
    int length;
    int breadth;
};

int five_main()
{
    five_Rectangle *p;
    p=new five_Rectangle;
    p->length=10;
    p-> breadth=5;
    
//    five_Rectangle *p = &r;
    
    std::cout << p->length << std::endl;
    std::cout << p->breadth << std::endl;
    return 0;
}


//6.Enligt koden ni ser, vad blir resultatet? och varför?
int six_add(int a, int b)
{
    int c;
    c=a+b;
    return c;
};
int six_main()
{
    int num1=10, num2=20, sum;
    
    sum = six_add(num1,num2);
    std::cout<<"sum is: "<<sum<<std::endl;
    return 0;
}


//7.Enligt koden ni ser, vad blir resultatet? och varför?
void seven_swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

int seven_main()
{
    int num1=10, num2=20, sum;
    
    seven_swap(&num1,&num2);
    
    std::cout << num1 <<std::endl;
    std::cout << num2;
    
    return 0;
}


//8.Enligt koden ni ser, vad blir resultatet? och varför?
void eight_fun(int *A, int n=0)
{
    std::cout << "Size of A: " << sizeof(*A)/sizeof(int) << std::endl;
}

int eight_main()
{
    int A[] = {2,4,6,8,10};
    int n=5;
    
    eight_fun(A);
    
    for (int x:A)
        std::cout << x << std::endl;
    return 0;
}


//9.Enligt koden ni ser, vad blir resultatet? och varför?
struct nine_Rectangle
{
    int length;
    int breadth;
};

void nine_fun(struct nine_Rectangle r)
{
    r.length=20;
    std::cout << "Length: " << r.length << std::endl << "Breadth: "<< r.breadth << std::endl;
}

int nine_main()
{
    struct nine_Rectangle r={10,5};
    nine_fun(r);
    printf("length: %d \nbreadth %d\n",r.length,r.breadth);
    return 0;
}


//10.Enligt koden ni ser, vad blir resultatet? och varför?
template<class T>
class ten_Arithmetic
{
private:
    T a;
    T b;
    
public:
    ten_Arithmetic(T a,T b);
    T add();
    T sub();
};

template<class T>
ten_Arithmetic<T>::ten_Arithmetic(T a,T b)
{
    this->a=a;
    this->b=b;
}
template<class T>
T ten_Arithmetic<T>::add()
{
    T c;
    c=a+b;
    return c;
}

template<class T>
T ten_Arithmetic<T>::sub()
{
    T c;
    c=a-b;
    return c;
}

int ten_main()
{
    ten_Arithmetic<float> ar(10.99,5.44);
    std::cout << ar.add() << std::endl;
    std::cout << ar.sub() << std::endl;
    return 0;
}

struct eleven_Rectangle
{
    int lenght;
    int breadth;
    
};

void eleven_initialize(struct eleven_Rectangle *r, int l, int b)
{
    r->lenght = l;
    r->breadth = b;
}

int eleven_area(struct eleven_Rectangle r)
{
    return r.lenght * r.breadth;
}

void eleven_change_lenght(struct eleven_Rectangle *r, int l)
{
    r->lenght = l;
}

int eleven_main()
{
    struct eleven_Rectangle r;
    eleven_initialize(&r, 10, 5);
    eleven_area(r);
    eleven_change_lenght(&r, 20);
    return 0;
}

class twelve_Rectangle
{
private:
    int lenght;
    int breadth;
    
public:
    void initialize(int l, int b)
    {
        lenght = l;
        breadth = b;
    }
    
    int area()
    {
        return lenght * breadth;
    }
    
    void change_lenght(int l)
    {
        lenght = l;
    }
};

int twelve_main()
{
    class twelve_Rectangle r;
    r.initialize(10, 5);
    r.area();
    r.change_lenght(20);
    return 0;
}

int thirteen_main()
{
    int lenght = 0, breadth = 0;
    printf("Enter lenght: ");
    std::cin >> lenght;
    printf("Enter breadth: ");
    std::cin >> breadth;
    
    int area = lenght * breadth;
    int peri = 2 * (lenght + breadth);
    
    printf("Area: %d\n", area);
    printf("Perimeter: %d\n", peri);
    
    return 0;
}

/* INIT - BEGIN */
int main(int argc, char ** argv){
    
    int key_pressed = '\0';
    
//    // 1. Enligt koden ni ser, vad blir resultatet? och varför?
//    one_main();
//    printf("[01] Press any key: "); key_pressed = c_getche(); printf(" [%d] \n\n", key_pressed);
//
//    //2.Enligt koden ni ser, vad blir resultatet? och varför?
//    two_main();
//    printf("[02] Press any key: "); key_pressed = c_getche(); printf(" [%d] \n\n", key_pressed);
//
//    //3.Enligt koden ni ser, vad blir resultatet? och varför?
//    three_main();
//    printf("[03] Press any key: "); key_pressed = c_getche(); printf(" [%d] \n\n", key_pressed);
//
//    //4.Enligt koden ni ser, vad blir resultatet? och varför?
//    four_main();
//    printf("[04] Press any key: "); key_pressed = c_getche(); printf(" [%d] \n\n", key_pressed);
//
//    //5.Enligt koden ni ser, vad blir resultatet? och varför?
//    five_main();
//    printf("[05] Press any key: "); key_pressed = c_getche(); printf(" [%d] \n\n", key_pressed);
//
//    //6.Enligt koden ni ser, vad blir resultatet? och varför?
//    six_main();
//    printf("[06] Press any key: "); key_pressed = c_getche(); printf(" [%d] \n\n", key_pressed);
//
//    //7.Enligt koden ni ser, vad blir resultatet? och varför?
//    seven_main();
//    printf("[07] Press any key: "); key_pressed = c_getche(); printf(" [%d] \n\n", key_pressed);
//
//    //8.Enligt koden ni ser, vad blir resultatet? och varför?
//    eight_main();
//    printf("[08] Press any key: "); key_pressed = c_getche(); printf(" [%d] \n\n", key_pressed);
//
//    //9.Enligt koden ni ser, vad blir resultatet? och varför?
//    nine_main();
//    printf("[09] Press any key: "); key_pressed = c_getche(); printf(" [%d] \n\n", key_pressed);
//
//    //10.Enligt koden ni ser, vad blir resultatet? och varför?
//    ten_main();
//    printf("[10] Press any key: "); key_pressed = c_getche(); printf(" [%d] \n\n", key_pressed);
    
    //11. Re-write to C code --> C++ code
    eleven_main();
    printf("[11] Press any key: "); key_pressed = c_getche(); printf(" [%d] \n\n", key_pressed);
    
    //12. Re-written code in C++
    twelve_main();
    printf("[12] Press any key: "); key_pressed = c_getche(); printf(" [%d] \n\n", key_pressed);
    
    //13. Re-written code in C++
    thirteen_main();
    printf("[13] Press any key: "); key_pressed = c_getche(); key_pressed = c_getche(); printf(" [%d] \n\n", key_pressed);
    
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

/* Read 1 character with echo */
int c_getche(void)
{
    struct termios old, char_new;
    int ch;
    
    tcgetattr(0, &old);
    
    char_new = old;
    char_new.c_lflag &= ~ICANON;

    tcsetattr(0, TCSADRAIN, &char_new);
    
    ch = getchar();
    
    tcsetattr(0, TCSADRAIN, &old);
    return ch;
}

/* IMPLEMENTATION OF ALL FUNCTIONS - END */
