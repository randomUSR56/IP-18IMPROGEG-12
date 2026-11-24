#include <stdio.h>
#include <string.h>

#include "modules.h"

#define MAX 100

void reverse(char *str)
{
    if (str == NULL) {
        return;
    }

    int len = strlen(str);
    for (int left = 0, right = len; left + 1 < right; ++left, --right) {
        char tmp = str[left];
        str[left] = str[right - 1];
        str[right - 1] = tmp;
    }
}

void task4(void)
{

    char buffer[MAX + 2];

    printf("Task 4 - enter a text: ");
    if (fgets(buffer, sizeof buffer, stdin) == NULL) {
        return;
    }
    buffer[strcspn(buffer, "\n")] = '\0';

    reverse(buffer);
    printf("Reversed in place: %s\n", buffer);
}
