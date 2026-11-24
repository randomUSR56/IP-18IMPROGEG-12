#include <stdio.h>
#include <stdlib.h>

#include "modules.h"

#define ROUNDS 2

void task3(void)
{
    for (int round = 1; round <= ROUNDS; ++round) {
        int *numbers = NULL;
        size_t size = 0;
        int value;

        printf("Task 3, round %d - enter numbers, end with a non-number (e.g. x):\n", round);

        while (scanf("%d", &value) == 1) {
            int *bigger = realloc(numbers, (size + 1) * sizeof *numbers);
            if (bigger == NULL) {
                perror("realloc");
                free(numbers);
                return;
            }
            numbers = bigger;
            numbers[size++] = value;
        }

        scanf("%*[^\n]%*c");

        printf("Reversed:");

        for (size_t i = size; i > 0; --i) {
            printf(" %d", numbers[i - 1]);
        }
        printf("\n");

        free(numbers);
    }
}
