#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "modules.h"

#define MAX 100

char *reverse_new(const char *str)
{
    if (str == NULL) {
        return NULL;
    }

    int len = strlen(str);
    char *result = malloc(len + 1);
    if (result == NULL) {
        return NULL;
    }

    for (int i = 0; i < len; ++i) {
        result[i] = str[len - 1 - i];
    }
    result[len] = '\0';
    return result;
}

void task5(void)
{
    char buffer[MAX + 2];

    printf("Task 5 - enter a text: ");
    if (fgets(buffer, sizeof buffer, stdin) == NULL) {
        return;
    }
    buffer[strcspn(buffer, "\n")] = '\0';

    char *reversed = reverse_new(buffer);
    if (reversed == NULL) {
        perror("malloc");
        return;
    }

    printf("Original: %s\nReversed: %s\n", buffer, reversed);
    free(reversed);
}
