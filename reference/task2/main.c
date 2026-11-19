#include <stdio.h>
#include <stdlib.h>

#include "word_reader.h"

#define WORD_COUNT 5

int main(void)
{
    /*
     * The number of words is known (5), so an array of 5 *pointers* is enough;
     * the array itself is tiny and fixed. The memory the task cares about is
     * the one the pointers point to: each word gets exactly what it needs.
     * Zero-initialising makes it safe to free() every slot even if we stop early.
     */
    char *words[WORD_COUNT] = {NULL};
    int count = 0;

    printf("Enter %d words:\n", WORD_COUNT);

    for (; count < WORD_COUNT; ++count) {
        words[count] = read_word();
        if (words[count] == NULL) {
            /* EOF or allocation failure: stop reading and use what we have. */
            fprintf(stderr, "Only %d word(s) could be read.\n", count);
            break;
        }
    }

    /* Reverse order: walk from the last stored word back to the first. */
    printf("Reversed order:\n");
    for (int i = count - 1; i >= 0; --i) {
        printf("%s\n", words[i]);
    }

    /* Free every word. free(NULL) would be harmless, but we only free filled slots. */
    for (int i = 0; i < count; ++i) {
        free(words[i]);
    }

    return 0;
}
