// Build: cc -std=c99 -W -Wall -Wextra -pedantic -g -o gyak10.out gyak10.c solutions/task*.c
#include "solutions/modules.h"

int main(void)
{
    /* all tasks read from the same stdin, so they run one after the other in order */
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();

    return 0;
}