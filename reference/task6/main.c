#include <stdio.h>

#include "words.h"

#define ROUNDS 2 /* like task 3: run at least twice in a row */

int main(void)
{
    for (int round = 1; round <= ROUNDS; ++round) {
        char **words = NULL;
        size_t count = 0;

        printf("Round %d - enter words, finish with 0:\n", round);

        if (read_words(&words, &count) != 0) {
            fprintf(stderr, "Out of memory.\n");
            return 1;
        }

        printf("Reversed (%zu words):\n", count);
        print_words_reversed(words, count);

        /* Release this round's memory before the next round starts. */
        free_words(words, count);
    }

    return 0;
}
