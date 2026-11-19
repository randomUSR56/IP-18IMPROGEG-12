#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 21

int main() {
    char buffer[MAX] = {0};

    printf("Input at most 20 chars: ");
    if (fgets(buffer, sizeof buffer, stdin) == NULL)
    {
        perror("Nem sikerult az olvasas!");
        return 1;
    }

    int len = strcspn(buffer, "\n");
    buffer[len] = '\0';

    len = strlen(buffer);

    // accomodate for the '\0'
    char* copy = malloc(len + 1);
    // check if allocation was succesfull
    if (copy == NULL) {
        perror("out of memory");
        return 1;
    }

    // give both buffers (buffer and copy) to a memcpy
    memcpy(copy, buffer, len + 1);
    printf("\nOG input (truncated) %s\n", buffer);
    printf("Copied: %s\n", copy);
    // free the memory when done
    free(copy);
    // note: we are the owner and are responsible for the memory we give it

    return 0;
}