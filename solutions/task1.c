#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "modules.h"

#define MAX 20

void task1(void)
{
    /* 20 chars + '\n' + '\0': a full-length line always fits */
    char buffer[MAX + 2];

    printf("Task 1 - enter a text (max %d chars): ", MAX);
    if (fgets(buffer, sizeof buffer, stdin) == NULL) {
        return;
    }

    size_t len = strcspn(buffer, "\n");
    if (buffer[len] == '\0') {
        /* no newline: line was too long, drop the rest so later tasks read cleanly */
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {
        }
    }
    if (len > MAX) {
        len = MAX;
    }
    buffer[len] = '\0';

    /* strlen doesn't count '\0', so the exact size is len + 1 */
    char *copy = malloc(len + 1);
    if (copy == NULL) {
        fprintf(stderr, "Out of memory.\n");
        return;
    }
    memcpy(copy, buffer, len + 1);

    printf("Copy: %s\n", copy);
    free(copy); /* we own the block, so we free it */
}
