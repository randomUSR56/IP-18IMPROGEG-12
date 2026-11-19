#include <stdio.h>
#include <stdlib.h>

#include "numbers.h"

#define ROUNDS 2 /* the task requires at least two runs in a row */

int main(void)
{
    for (int round = 1; round <= ROUNDS; ++round) {
        int *numbers = NULL;
        size_t count = 0;

        printf("Round %d - enter numbers, finish with a non-number (e.g. x):\n", round);

        if (read_numbers(&numbers, &count) != 0) {
            fprintf(stderr, "Out of memory.\n");
            return 1;
        }

        printf("Reversed (%zu numbers): ", count);
        print_reversed(numbers, count);

        /*
         * Free at the end of *every* round, so memory does not pile up between
         * rounds (the "no memory garbage" requirement). free(NULL) is allowed,
         * so the empty-input case needs no special handling.
         */
        free(numbers);
    }

    return 0;
}
