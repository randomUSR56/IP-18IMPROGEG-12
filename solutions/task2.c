#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "modules.h"

#define LINE_SIZE 256
#define NWORDS 5

void task2(void)
{
    /* the pointer array is tiny and fixed; each word gets exactly its own size */
    char *words[NWORDS] = {NULL};
    int count = 0;

    printf("Task 2 - enter %d words:\n", NWORDS);

    char line[LINE_SIZE];
    while (count < NWORDS && fgets(line, sizeof line, stdin) != NULL) {
        char *p = line;
        while (count < NWORDS) {
            p += strspn(p, " \t\r\n");          /* skip whitespace before the word */
            size_t len = strcspn(p, " \t\r\n"); /* length of the word */
            if (len == 0) {
                break;                          /* no more words on this line */
            }

            char *word = malloc(len + 1);
            if (word == NULL) {
                fprintf(stderr, "Out of memory.\n");
                break;
            }
            memcpy(word, p, len);
            word[len] = '\0';
            words[count++] = word;
            p += len;
        }
    }

    printf("Reversed order:\n");
    for (int i = count - 1; i >= 0; --i) {
        printf("%s\n", words[i]);
    }

    for (int i = 0; i < count; ++i) {
        free(words[i]);
    }
}
