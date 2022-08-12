#include <stdio.h>
#include <conio.h>
#include "my_func.h"

#define NUM_MENU 4

char *menu_names[NUM_MENU] = { // an array of strings(menu name)
    "calibration",
    "first drive",
    "second drive",
    "motor test"};
void (*menu_funcs[NUM_MENU])(void) = { //  an array of functions
    my_func1,
    my_func2,
    my_func3,
    my_func4};

int waitKey()
{
    int ch;
    while (1)
    {
        ch = getch();
        if ('a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z')
            return ch;
    }
}

void show_menu()
{
    printf(" (a: prev menu, d: next menu, y: execute the menu function, q: quit)\n");
    int i = 0; // menu index
    while (1)
    {
        printf("%d. %s\n", i + 1, menu_names[i]);
        int ch = waitKey(); // get key command (a, d, y, q)

        if (ch == 'y' || ch == 'Y') // yes
        {
            if (menu_funcs[i] != NULL)
                menu_funcs[i]();
            else
                printf("ERR: the menu function is NULL");
        }
        else if (ch == 'a' || ch == 'A') // prev
            i--;
        else if (ch == 'd' || ch == 'D') // next
            i++;
        else if (ch == 'q' || ch == 'Q') // quit
            break;

        i = (i + NUM_MENU) % NUM_MENU;
    }

    printf("show menu is ended. bye~ \n");
}
