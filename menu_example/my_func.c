#include <stdio.h>
#include <windows.h>
#include "./my_func.h"
void my_func1(void)
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", i);
    }
    printf("\n\n");
    Sleep(1000); // do something
}

void my_func2(void)
{
    printf("I'm calculating 2+4... \n");
    printf("The answer is ...\n");
    printf("...\n");
    printf("5!\n\n");
    Sleep(1000); // do something
}

void my_func3(void)
{
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n");
    Sleep(1000); // do something
}
void my_func4(void)
{
    printf("#########################\n\n");
    Sleep(1000); // do something
}
