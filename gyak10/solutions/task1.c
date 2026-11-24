#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "modules.h"

#define MAX 20

void task1(void)
{
    char buffer[MAX + 2];

    printf("Task 1 - enter a text (max %d chars): ", MAX);
    if (fgets(buffer, sizeof buffer, stdin) == NULL) {
        return;
    }

    int len = strcspn(buffer, "\n");
    if (buffer[len] == '\0') {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {
        }
    }
    if (len > MAX) {
        len = MAX;
    }
    buffer[len] = '\0';

    char *copy = malloc(len + 1);
    if (copy == NULL) {
        perror("malloc");
        return;
    }
    memcpy(copy, buffer, len + 1);

    printf("Copy: %s\n", copy);
    free(copy);
}
