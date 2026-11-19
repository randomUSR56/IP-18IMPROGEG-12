#include "words.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 16

/*
 * Reads one word of any length. Returns a malloc'ed, exactly sized string, or
 * NULL on EOF-before-any-character or on allocation failure.
 *
 * A word can be arbitrarily long, so no fixed buffer will do. We collect the
 * characters in a buffer that doubles when full (few reallocs even for long
 * words) and, once the word is complete, shrink it to the exact size so the
 * stored word wastes no memory.
 */
static char *read_word(void)
{
    int c;

    /* Skip whitespace before the word. */
    while ((c = getchar()) != EOF && isspace(c)) {
        /* skipping */
    }
    if (c == EOF) {
        return NULL;
    }

    size_t capacity = INITIAL_CAPACITY;
    size_t length = 0;
    char *word = malloc(capacity);
    if (word == NULL) {
        return NULL;
    }

    /* `c` already holds the first character of the word. */
    do {
        /* length + 1: keep one byte free for the terminating '\0'. */
        if (length + 1 >= capacity) {
            capacity *= 2;
            char *bigger = realloc(word, capacity); /* temp pointer: see numbers.c in task 3 */
            if (bigger == NULL) {
                free(word);
                return NULL;
            }
            word = bigger;
        }
        word[length++] = (char)c;
    } while ((c = getchar()) != EOF && !isspace(c));

    word[length] = '\0';

    /*
     * Shrink to the exact size. If this realloc fails the old (bigger) block is
     * still valid, so just keep using it - a failed shrink is not an error.
     */
    char *exact = realloc(word, length + 1);
    return exact != NULL ? exact : word;
}

void free_words(char **words, size_t count)
{
    /* Free in the reverse direction of allocation: the strings first, the array last. */
    for (size_t i = 0; i < count; ++i) {
        free(words[i]);
    }
    free(words);
}

int read_words(char ***out, size_t *count)
{
    char **words = NULL;
    size_t size = 0;
    char *word;

    /* read_word() returns NULL at EOF, which also ends the loop. */
    while ((word = read_word()) != NULL) {
        if (strcmp(word, "0") == 0) {
            free(word); /* the terminator is not stored; do not leak it */
            break;
        }

        /* Grow the pointer array by one element (same idea as task 3). */
        char **bigger = realloc(words, (size + 1) * sizeof *words);
        if (bigger == NULL) {
            free(word); /* not yet in the array, so free_words would miss it */
            free_words(words, size);
            *out = NULL;
            *count = 0;
            return -1;
        }
        words = bigger;
        words[size++] = word;
    }

    *out = words;
    *count = size;
    return 0;
}

void print_words_reversed(char *const *words, size_t count)
{
    for (size_t i = count; i > 0; --i) {
        printf("%s\n", words[i - 1]);
    }
}
