#include <stdio.h>

void change() {
    int x = 4;
    printf("eredeti x= %d\n", x);
    int *p = &x;
    *p = *p + 1;
    printf("pointeren at egyel novelt x= %d\n", x);
}

void nptr() {
    int *p = NULL;
    printf("deref nptr= %p\n", p);
}

void ptr_to_ptr() {
    int x = 4;
    int y = 7;
    int *p = &x;
    int **pp = &p;
    printf("eredetileg p altal mutatott ertek: %d\n", *p);
    *pp = &y;
    printf("pp-n keresztul p mostantol y-ra mutat: %d\n", *p);
    **pp = **pp + 1;
    printf("pp-n keresztul megnovelt y= %d\n", y);
}

void self_ptr() {
    // int *p = &p; nem fordul, mert &p tipusa int **
    void *p = &p;
    printf("sizeof(char *)=%zu, sizeof(int *)=%zu, sizeof(double *)=%zu, sizeof(void *)=%zu\n",
           sizeof(char *), sizeof(int *), sizeof(double *), sizeof(void *));
    printf("p sajat cime: %p, p erteke: %p\n", (void *)&p, p);
}

int sum_ptr(int *first, int len) {
    int s = 0;
    for (int *q = first; q < first + len; q++)
        s += *q;
    return s;
}

int sum_end(int *begin, int *end) {
    int s = 0;
    for (int *q = begin; q < end; q++)
        s += *q;
    return s;
}

double avg_end(int *begin, int *end) {
    return (double)sum_end(begin, end) / (end - begin);
}

int is_before(int *a, int *b) {
    // csak ugyanazon tomb elemeire mutato pointerekre ertelmes
    return a < b;
}

int *return_local() {
    int x = 42;
    return &x;
}

void deref_null() {
    int *p = NULL;
    // UB: szegmentalasi hiba varhato
    printf("null dereferalas: %d\n", *p);
}

int read_int() {
    // nem jo ha n-et adsz oda siman mert a scaf irni akar a valtozo helyen tarolt ertekre.
    // ezert kell a & hogy tudjuk hol van es szigoruan azon a helyen tarolt erteket valtoztassa
    // ha nem rakod ele a & jelet akkor BELE akarja irni mert azt hiszi rola hogy memoriacim
    // memory address-kent kezeli a nyers int valtozot es nem sikerul neki
    int n;
    scanf("%d", &n);
    return n;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    change();
    ptr_to_ptr();
    self_ptr();
    printf("sum_ptr: %d\n", sum_ptr(arr, 5));
    printf("sum_end: %d\n", sum_end(arr, arr + 5));
    printf("atlag: %.2f\n", avg_end(arr, arr + 5));
    printf("is_before(&arr[1], &arr[3]) = %d\n", is_before(&arr[1], &arr[3]));

    // printf("return_local erteke: %d\n", *return_local());
    // szegény 42-őt produkál de nem jó szándékból csak mert még nem sikerült felülírní a stack memoryt
    // (utána rögvest segmentation fault lett belőle, hiszen a lokális változó csak a stack-ben él és a függvény életével egyenértékű. ha nincs függvény nincs stackje, nincs valtózó se semmi)
    
    printf("beolvasott szam: %d\n", read_int());
    
    //deref_null();
    // segmentation fault mert a NULL 0 memory sosem program memory. oda nyul ahova nem kene

    nptr();
    // null helyet mondja: azt tartolja p. az elozo peldanal derefelni akarja de nem sikerul
    // null valodi jelenteset sosem kreheted le (nem a tied)
    return 0;
}