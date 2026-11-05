#include <stdio.h>
#include "my_utils.h"

void szamlalo(void) {
    static int count = 0; // csak egyszer inicializalodik, hivasok kozott megmarad
    count++;
    printf("count: %d\n", count);
}

void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int *nagyobb(int *x, int *y) {
    return (*x >= *y) ? x : y;
}
