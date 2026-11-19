#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TMP_SIZE 256
#define NWORDS 5

int main() {
    char* words[NWORDS] = {NULL};
    int count = 0;

    printf("Enter %d words:\n", NWORDS);

    char line[TMP_SIZE];
    while (count < NWORDS && fgets(line, sizeof line, stdin) != NULL) {
        char *p = line;
        while (count < NWORDS) {
            p += strspn(p, " \t\r\n");          // skip whitespace
            int len = strcspn(p, " \t\r\n"); // basically length
            if (len == 0) {
                break;                          // no more words in line
            }

            char *word = malloc(len + 1);
            if (word == NULL) {
                fprintf(stderr, "Out of memory.\n");
                for (int i = 0; i < count; ++i) {
                    free(words[i]);
                }
                return 1;
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

    return 0;
}