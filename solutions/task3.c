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
            /* grow by one element; temp pointer so a failed realloc doesn't leak the old block */
            int *bigger = realloc(numbers, (size + 1) * sizeof *numbers);
            if (bigger == NULL) {
                fprintf(stderr, "Out of memory.\n");
                free(numbers);
                return;
            }
            numbers = bigger;
            numbers[size++] = value;
        }

        /* eat the rest of the terminator's line, so the next read starts on a clean line */
        scanf("%*[^\n]%*c");

        printf("Reversed:");
        /* size_t is unsigned: `i >= 0` would always be true, so loop on i > 0 and use i - 1 */
        for (size_t i = size; i > 0; --i) {
            printf(" %d", numbers[i - 1]);
        }
        printf("\n");

        free(numbers); /* free every round so memory doesn't pile up (free(NULL) is fine) */
    }
}
