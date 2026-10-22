#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomReals(double arr[100]) {
    for (int i = 0; i < 100; i++) {
        arr[i] = 1.0 + (double)rand() / RAND_MAX * (100.0 - 1.0);
    }
}

void multable(int n, int table[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            table[i][j] = (i + 1) * (j + 1);
        }
    }
}

void sumOfPositiveInts(int n, int* out) {
    for (int i = 1; i <= n; i++)
    {
        *out += i;
    }
}

int main(int argc, char *argv[]) {
    if (argv[1] != NULL)
    {
        int n = atoi(argv[1]);
        n ? printf("Provided argument: %d\n", n) : printf("Argument provided was invalid (not a positive number)\n");
    }
    else
    {
        printf("Program started running without arguments.\n");
    }

    int n = 10;
    int table[n][n];
    multable(n, table);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d x %d = %d\n", i + 1, j + 1, table[i][j]);
        }
    }

    printf("how many posint to sum?\n");
    int howMany = 0;
    scanf("%3d", &howMany);
    int out = 0;
    int* out_ptr = &out;
    sumOfPositiveInts(howMany, out_ptr);
    printf("sum of that many posints: %d\n", out);

    srand((unsigned)time(NULL));   // seed once, at program start
    double reals[100] = {0};
    randomReals(reals);
    int over50 = 0;
    for (int i = 0; i < 100; i++) over50 += reals[i] > 50.0;
    printf("elements over 50: %d\n", over50);
    
    return 0;
}