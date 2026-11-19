#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "numbers.h"

int read_numbers(int **out, size_t *count)
{
    int *numbers = NULL;
    size_t size = 0;
    int value;

    while (scanf("%d", &value) == 1) {
        // grow by one element; temp pointer so a failed realloc doesn't leak
        int *bigger = realloc(numbers, (size + 1) * sizeof *numbers);
        if (bigger == NULL) {
            free(numbers);
            return -1;
        }
        numbers = bigger;
        numbers[size++] = value;
    }

    scanf("%*s"); // eat the terminator token (e.g. "x") so the next round can start

    *out = numbers;
    *count = size;
    return 0;
}

void print_reversed(const int *numbers, size_t count)
{
    for (size_t i = count; i > 0; --i) {
        printf("%d ", numbers[i - 1]);
    }
    printf("\n");
}

