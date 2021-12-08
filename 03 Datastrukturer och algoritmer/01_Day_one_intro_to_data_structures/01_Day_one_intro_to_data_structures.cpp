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
    
    five_Rectangle *p = &r;
    
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
void eight_fun(int A[ ], int n)
{
    std::cout << sizeof(A)/sizeof(int) << std::endl;
}

int eight_main()
{
    int A[] = {2,4,6,8,10};
    int n=5;
    
    eight_fun(A, n);
    
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

/* INIT - BEGIN */
int main(int argc, char ** argv){
    
    // 1. Enligt koden ni ser, vad blir resultatet? och varför?
    one_main();
    printf("Press any key\n"); c_getche();
    
    //2.Enligt koden ni ser, vad blir resultatet? och varför?
    two_main();
    printf("Press any key\n"); c_getche();
    
    //3.Enligt koden ni ser, vad blir resultatet? och varför?
    three_main();
    printf("Press any key\n"); c_getche();
    
    //4.Enligt koden ni ser, vad blir resultatet? och varför?
    four_main();
    printf("Press any key\n"); c_getche();
    
    //5.Enligt koden ni ser, vad blir resultatet? och varför?
    five_main();
    printf("Press any key\n"); c_getche();
    
    //6.Enligt koden ni ser, vad blir resultatet? och varför?
    six_main();
    printf("Press any key\n"); c_getche();
    
    //7.Enligt koden ni ser, vad blir resultatet? och varför?
    seven_main();
    printf("Press any key\n"); c_getche();
    
    //8.Enligt koden ni ser, vad blir resultatet? och varför?
    eight_main();
    printf("Press any key\n"); c_getche();
    
    //9.Enligt koden ni ser, vad blir resultatet? och varför?
    nine_main();
    printf("Press any key\n"); c_getche();
    
    //10.Enligt koden ni ser, vad blir resultatet? och varför?
    ten_main();
    printf("Press any key\n"); c_getche();
    
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
    //new.c_lflag &= ~ECHO;
    tcsetattr(0, TCSANOW, &char_new);
    
    ch = getchar();
    
    tcsetattr(0, TCSANOW, &old);
    return ch;
}

/* IMPLEMENTATION OF ALL FUNCTIONS - END */
