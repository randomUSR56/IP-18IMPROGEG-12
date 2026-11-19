#ifndef NUMBERS_H
#define NUMBERS_H

#include <stddef.h>

/*
 * Task 3 - read an arbitrary amount of integers into dynamic memory.
 */

/*
 * Reads integers from stdin until the user enters something that is not a
 * number (or input ends). The offending rest of the line is discarded so the
 * next call starts on a clean line.
 *
 * On success returns 0, stores the array in *out and its length in *count.
 * *out is NULL when no number was entered (nothing to free in that case).
 * On allocation failure returns -1, frees everything it allocated and sets
 * *out = NULL, *count = 0.
 *
 * The array is exactly *count ints big. The caller must free(*out).
 */
int read_numbers(int **out, size_t *count);

/* Prints the numbers in reverse order, separated by spaces, ending with '\n'. */
void print_reversed(const int *numbers, size_t count);

#endif
