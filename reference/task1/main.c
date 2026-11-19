#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "string_copy.h"

#define MAX_LEN 20

/* Throw away the rest of the current input line (up to and including '\n'). */
static void discard_line(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /* nothing: we only consume characters */
    }
}

int main(void)
{
    /*
     * The *input* buffer may be fixed-size: we know the upper bound (20).
     * Needed room: 20 characters + '\n' + '\0' = 22 bytes. With this size a
     * line of at most 20 characters always arrives completely, newline included.
     * Only the *copy* has to be exactly sized.
     */
    char input[MAX_LEN + 2];

    printf("Enter a text (at most %d characters): ", MAX_LEN);

    /* fgets (unlike gets/scanf("%s")) never writes beyond the buffer size. */
    if (fgets(input, sizeof input, stdin) == NULL) {
        fprintf(stderr, "No input.\n");
        return 1;
    }

    /* strcspn returns the index of the first '\n' (or the length if none). */
    size_t len = strcspn(input, "\n");

    if (input[len] == '\0') {
        /*
         * No newline found: the line was longer than the buffer, so the rest is
         * still waiting in stdin. Leave it out of the buffer (the text is
         * truncated) and consume it so it does not disturb later reads.
         */
        discard_line();
    }

    if (len > MAX_LEN) {
        len = MAX_LEN; /* keep at most 20 characters */
    }
    input[len] = '\0'; /* overwrites the '\n' (or cuts the over-long text) */

    char *copy = copy_string(input);
    if (copy == NULL) {
        fprintf(stderr, "Out of memory.\n");
        return 1;
    }

    printf("Original: \"%s\"\n", input);
    printf("Copy:     \"%s\" (%zu bytes allocated)\n", copy, strlen(copy) + 1);

    /* Every malloc needs exactly one free, otherwise memory leaks. */
    free(copy);
    return 0;
}
