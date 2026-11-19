#include "word_reader.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TMP_SIZE 256

char *read_word(void)
{
    /*
     * We do not know the word length before reading it, so the word first goes
     * into a temporary buffer on the stack. This buffer disappears when the
     * function returns; it is NOT the storage the task talks about.
     *
     * "%255s" limits the number of stored characters to TMP_SIZE - 1, leaving
     * room for '\0'. Without the limit scanf could overflow the buffer.
     * %s skips leading whitespace and stops at the next whitespace.
     */
    char tmp[TMP_SIZE];
    if (scanf("%255s", tmp) != 1) {
        return NULL; /* EOF (or input error): there was no word */
    }

    /* The permanent storage: exactly the word + its '\0'. */
    size_t size = strlen(tmp) + 1;
    char *word = malloc(size);
    if (word == NULL) {
        return NULL;
    }
    memcpy(word, tmp, size);
    return word;
}
