#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "reverse.h"

#define MAX_LEN 100

int main(void)
{
    /* A literal is fine here because reverse() takes const char * and only reads. */
    const char *original = "racecar";
    char *reversed = reverse(original);
    if (reversed == NULL) {
        fprintf(stderr, "Out of memory.\n");
        return 1;
    }
    printf("\"%s\" -> \"%s\"\n", original, reversed);
    free(reversed);

    char input[MAX_LEN + 2];
    printf("Enter a text: ");
    if (fgets(input, sizeof input, stdin) == NULL) {
        return 1;
    }
    input[strcspn(input, "\n")] = '\0';

    reversed = reverse(input);
    if (reversed == NULL) {
        fprintf(stderr, "Out of memory.\n");
        return 1;
    }

    /* Both strings are printed to show that the original stayed intact. */
    printf("Original: %s\n", input);
    printf("Reversed: %s\n", reversed);

    free(reversed);
    return 0;
}
