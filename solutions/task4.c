#include <stdio.h>
#include <string.h>

#include "modules.h"

#define MAX 100

void reverse(char *str)
{
    if (str == NULL) {
        return;
    }

    /* swap from both ends until the indices meet; the middle char of an odd length stays */
    size_t len = strlen(str);
    for (size_t left = 0, right = len; left + 1 < right; ++left, --right) {
        char tmp = str[left];
        str[left] = str[right - 1];
        str[right - 1] = tmp;
    }
}

void task4(void)
{
    /* char[] (not char *): needs writable memory, a literal pointer would crash */
    char buffer[MAX + 2];

    printf("Task 4 - enter a text: ");
    if (fgets(buffer, sizeof buffer, stdin) == NULL) {
        return;
    }
    buffer[strcspn(buffer, "\n")] = '\0';

    reverse(buffer);
    printf("Reversed in place: %s\n", buffer);
}
