#ifndef WORDS_H
#define WORDS_H

#include <stddef.h>

/*
 * Task 6 - an arbitrary number of words of arbitrary length, modelled on task 3.
 */

/*
 * Reads whitespace-separated words from stdin until the word "0" is entered
 * (or input ends). The "0" itself is not stored.
 *
 * On success returns 0, stores the array of words in *out and its length in
 * *count. *out is NULL when no word was stored.
 * On allocation failure returns -1 and releases everything it allocated.
 *
 * Release the result with free_words().
 */
int read_words(char ***out, size_t *count);

/* Prints the words in reverse order, one per line. */
void print_words_reversed(char *const *words, size_t count);

/* Frees every word and then the array holding them. */
void free_words(char **words, size_t count);

#endif
