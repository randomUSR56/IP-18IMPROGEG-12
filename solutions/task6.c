#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "modules.h"

#define ROUNDS 2

/* Reads one word of any length into an exactly sized block; NULL on EOF or no memory. */
static char *read_word(void)
{
    int c;
    while ((c = getchar()) != EOF && isspace(c)) {
    }
    if (c == EOF) {
        return NULL;
    }

    char *word = NULL;
    size_t len = 0;
    do {
        /* room for the chars so far + this one + '\0'; stays exact because we grow per char */
        char *bigger = realloc(word, len + 2);
        if (bigger == NULL) {
            free(word);
            return NULL;
        }
        word = bigger;
        word[len++] = (char)c;
    } while ((c = getchar()) != EOF && !isspace(c));

    word[len] = '\0';
    return word;
}

static void free_words(char **words, size_t count)
{
    /* strings first, then the array that held their pointers */
    for (size_t i = 0; i < count; ++i) {
        free(words[i]);
    }
    free(words);
}

void task6(void)
{
    for (int round = 1; round <= ROUNDS; ++round) {
        char **words = NULL;
        size_t count = 0;
        char *word;

        printf("Task 6, round %d - enter words, end with 0:\n", round);

        while ((word = read_word()) != NULL) {
            if (strcmp(word, "0") == 0) {
                free(word); /* the terminator isn't stored, don't leak it */
                break;
            }

            char **bigger = realloc(words, (count + 1) * sizeof *words);
            if (bigger == NULL) {
                fprintf(stderr, "Out of memory.\n");
                free(word);
                free_words(words, count);
                return;
            }
            words = bigger;
            words[count++] = word;
        }

        printf("Reversed:\n");
        for (size_t i = count; i > 0; --i) {
            printf("%s\n", words[i - 1]);
        }

        free_words(words, count);
    }
}
