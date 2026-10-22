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

void swap_in_place(int size, int arr[]) {
    int tmp = 0;
    for (int i = 0; i < size/2; i++)
    {
        tmp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = tmp;
    }
}

void countSigns(int size, const int arr[], int counts[3]) {
    counts[0] = counts[1] = counts[2] = 0;   // pos, neg, zero
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0)      counts[0]++;
        else if (arr[i] < 0) counts[1]++;
        else                 counts[2]++;
    }
}

void fillRandomInts(int size, int arr[], int lo, int hi) {
    for (int i = 0; i < size; i++) {
        arr[i] = lo + rand() % (hi - lo + 1);   // inclusive range
    }
}

#define MAX_NUMS 100

int readNumbers(int arr[], int capacity) {
    int count = 0;
    printf("How many numbers (max %d)? ", capacity);
    if (scanf("%d", &count) != 1 || count < 0 || count > capacity) {
        printf("Invalid count.\n");
        return 0;
    }

    for (int i = 0; i < count; i++) {
        printf("Number %d: ", i + 1);
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid number, stopping.\n");
            return i;   // only the first i elements are valid
        }
    }
    return count;
}

#define MAX_POW 20

void powers(double x, int n, double out[]) {
    out[0] = 1.0;
    for (int i = 1; i <= n; i++) {
        out[i] = out[i - 1] * x;   // reuse the previous power instead of calling pow()
    }
}

int main(int argc, char *argv[]) {
    // 0. feladat
    if (argv[1] != NULL)
    {
        int n = atoi(argv[1]);
        if (n) {
            printf("Provided argument: %d\n", n);
        } else {
            printf("Argument provided was invalid (or literal 0)\n");
        }
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

    srand((unsigned)time(NULL));
    double reals[100] = {0};
    randomReals(reals);
    int over50 = 0;
    for (int i = 0; i < 100; i++) over50 += reals[i] > 50.0;
    printf("elements over 50: %d\n", over50);

    int to_swap[5] = {3, 2, 6, 8, 9};
    int size = sizeof(to_swap)/sizeof(to_swap[0]);
    swap_in_place(size, to_swap);
    printf("reversed array:\n[");
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", to_swap[i]);
    }
    printf("]\n");
    
    int nums[20];
    fillRandomInts(20, nums, -2, 2);

    int counts[3];
    countSigns(20, nums, counts);
    printf("positive: %d, negative: %d, zero: %d\n", counts[0], counts[1], counts[2]);

    int input[MAX_NUMS];
    int read = readNumbers(input, MAX_NUMS);

    printf("Read %d numbers:\n", read);
    for (int i = 0; i < read; i++) {
        printf("%d ", input[i]);
    }
    printf("\n");

    double base;
    printf("Number: ");
    if (scanf("%lf", &base) != 1) {
        printf("No valid number was given.\n");
        return 1;
    }

    int n = 10;
    double pw[MAX_POW + 1];
    powers(base, n, pw);

    for (int i = 0; i <= n; i++) {
        printf("%g^%d = %g\n", base, i, pw[i]);
    }

    return 0;
}