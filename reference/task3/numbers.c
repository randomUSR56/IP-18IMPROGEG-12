#include "numbers.h"

#include <stdio.h>
#include <stdlib.h>

/* Consume the rest of the current line, including the '\n'. */
static void discard_line(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /* only consuming */
    }
}

int read_numbers(int **out, size_t *count)
{
    int *numbers = NULL; /* realloc(NULL, n) behaves like malloc(n): a good start */
    size_t size = 0;
    int value;
    int status;

    /*
     * scanf returns the number of successfully converted items:
     *   1   -> a number was read
     *   0   -> input is there but it is not a number  (the user's "end" signal)
     *   EOF -> no more input at all (Ctrl+D)
     * So looping while it returns 1 stops on both kinds of "not a number".
     */
    while ((status = scanf("%d", &value)) == 1) {
        /*
         * Grow the array by exactly one element: memory use always equals the
         * amount of data ("only as much as necessary"). The price is a realloc
         * per number; real programs usually grow geometrically instead, but
         * this matches the wording of the task.
         *
         * IMPORTANT: assign realloc's result to a *temporary* first. If it
         * fails it returns NULL while the old block is still valid; writing
         * NULL directly into `numbers` would lose that pointer -> memory leak.
         */
        int *bigger = realloc(numbers, (size + 1) * sizeof *numbers);
        if (bigger == NULL) {
            free(numbers);
            *out = NULL;
            *count = 0;
            return -1;
        }
        numbers = bigger;
        numbers[size++] = value;
    }

    if (status == 0) {
        /*
         * The terminator (e.g. "x") is still in the input buffer. Remove the
         * rest of its line; otherwise the next round would fail immediately on it.
         */
        discard_line();
    }

    *out = numbers;
    *count = size;
    return 0;
}

void print_reversed(const int *numbers, size_t count)
{
    /*
     * Walk backwards with an unsigned index. `i >= 0` would be always true for
     * size_t, so we loop on `i > 0` and use i - 1 as the real index.
     */
    for (size_t i = count; i > 0; --i) {
        printf("%d ", numbers[i - 1]);
    }
    printf("\n");
}
