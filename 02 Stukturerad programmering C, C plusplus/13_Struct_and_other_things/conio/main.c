#include <stdio.h>
#include "conio.h"

// sudo service ssh start
//~/projects/Linux/bin/x64/Debug

void Test1()
{
    int i;
    c_clrscr();
    for (i = 0; i < 20; i++)
    {
    printf("%d\r\n", i);
    }
    printf("\r\nTest1 :: Press any key to clear screen");
    c_getch();
    c_clrscr();
    printf("Test1 :: The screen has been cleared!");
    c_getch();
    c_clrscr();
}


void Test2()
{
    struct text_info ti;
    c_gettextinfo(&ti);
    printf("Test2 :: attribute        %2d\r\n", ti.attribute);
    printf("Test2 :: normal attribute %2d\r\n", ti.normattr);
    printf("Test2 :: screen height    %2d\r\n", ti.screenheight);
    printf("Test2 :: screen width     %2d\r\n", ti.screenwidth);
    printf("Test2 :: current x        %2d\r\n", ti.curx);
    printf("Test2 :: current y        %2d\r\n", ti.cury);
    
    printf("\r\nTest2 :: Press any key to continue");
    c_getch();
    c_clrscr();
}

void Test3()
{
    /*
    Gets character from keyboard, does not echo to screen.
    getch reads a single character directly from the keyboard,
    without echoing to the screen
    */

    int c;
    int extended = 0;

    printf("\r\nTest3 :: Press any key to continue\n");
    c = c_getch();

    if (!c)
    extended = c_getch();
    if (extended)
    printf("Test3 :: The character is extended\n");
    else
    printf("Test3 :: The character isn't extended\n");
    
    printf("\r\nTest3 :: Press any key to continue");
    c_getch();
    c_clrscr();
}

void Test4()
{
    int ch;
    printf("Test4 :: Input a character: ");
    ch = c_getche();
    
    if (ch)
    {
        printf("\nYou input a '%c'\n", ch);
    }
    
    printf("\r\nTest4 :: Press any key to continue");
    c_getch();
    c_clrscr();
}

void Test5()
{
    int i;
    c_clrscr();
    
    for (i = 0; i < 9; i++)
    {
        c_textattr(i + ((i + 1) << 4));
        printf("Test5 :: This is a test\r\n");
    }
    
    printf("\r\nTest5 :: Press any key to continue");
    c_getch();
    c_clrscr();
}

void Test6()
{
    c_clrscr();
    c_gotoxy(35, 12);
    printf("Test6 :: Hello world\n");

    printf("\r\nTest6 :: Press any key to continue");
    c_getch();
    c_clrscr();
}

void  Test7()
{
  printf("Test7 :: Press any key to continue: ");
  while (!c_kbhit())
  {
  }
  
  printf("\r\nA key was pressed...\r\n"); 
  
}
int main(void)
{
  Test1();
  Test2();
  Test3();
  Test4();
  Test5();
  Test6();
  Test7();
  return 0;
}
