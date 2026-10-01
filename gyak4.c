#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void leapyear() {
    int x = 0;

    printf("Inpput a year to determine if leap year or not\n");
    scanf("%d", &x);

    // nincs 'if' de a fordito warning-ot dob, hiszen feleslegesnek talalja a switch hasznalatat
    // minke a switch ha csak 2 esetunk van?
    switch (((x % 4 == 0) && (x % 100 != 0)) || (x % 400 == 0))
    {
    case 1:
        printf("%d -> leap year", x);
        break;

    case 0:
        printf("%d -> not leap year", x);
        break;
    }
}

void leapyear2() {
    // lookup table pointerekkel
    int x = 0;

    printf("Inpput a year to determine if leap year or not\n");
    scanf("%d", &x);

    int isLeap = ((x % 4 == 0) && (x % 100 != 0)) || (x % 400 == 0);
    const char *result[] = { "not leap year", "leap year" };

    printf("%d -> %s", x, result[isLeap]);
}

void leapyear3() {
    // ternary
    int x = 0;

    printf("Inpput a year to determine if leap year or not\n");
    scanf("%d", &x);
    int isLeap = ((x % 4 == 0) && (x % 100 != 0)) || (x % 400 == 0);

    printf("%d -> %s", x, isLeap ? "leap year" : "not leap year");
}

void sizes() {
    printf("sizeof(int) = %lu bytes\n", sizeof(int));
    printf("sizeof(long int) = %lu bytes\n", sizeof(long int));
    printf("sizeof(unsigned int) = %lu bytes\n", sizeof(unsigned int));
    printf("sizeof(unsigned long int) = %lu bytes\n", sizeof(unsigned long int));
    printf("sizeof(char) = %lu bytes\n", sizeof(char));
    printf("sizeof(_Bool) = %lu bytes\n", sizeof(_Bool));
    printf("sizeof(float) = %lu bytes\n", sizeof(float));
    printf("sizeof(double) = %lu bytes\n", sizeof(double));
    printf("sizeof(long double) = %lu bytes\n", sizeof(long double));
}

void int_decrement() {
    printf("signed ------------------\n");
    for (int i = 10; i >= 0; i--)
    {
        printf("%d\n", i);
    }
}

void unsigned_int_decrement() {
    // vegtelen ciklus mert szamunkra nem kedvezo helyen kerul kiertekelesre a 0.
    // elobb nezi meg, hogy lehet-e 0 majd kivon belole. addigra mar tul keso, visszatertunk a 4mrd-hoz es indul elorol a ciklus.
    printf("unsigned ----------------\n");
    for (unsigned int i = 10; i >= 1; i--)
    {
        printf("%u\n", i);
    }
}

void unsigned_int_decrement2() {
    // vizsont ha atrendezzuk, hogy ez a feltetel hol keruljon kiertekelesre akkor kikuszobolhetjuk ezt a problmat.
    printf("unsigned ----------------\n");
    for (unsigned int i = 10; ; i--)
    {
        printf("%u\n", i);
        if (i == 0) break;
    }
}

void dice() {
    srand(time(NULL)); // time as seed for the generator used by rand

    // roll a 6-sided die
    int x = 7;
    while(x > 6) 
        x = 1 + rand()/((RAND_MAX + 1u)/6); // Note: 1+rand()%6 is biased
    printf("%d ",  x);
}

void opchain() {
    int a = 4;
    int b = 3;
    int c = 9;
    int x = a<b<c;
    printf("%d", x);
}

int main() {
    // 4. feladat
    //leapyear();
    leapyear2();
    //leapyear3();

    // 1. feladat
    sizes();

    // 2. feladat
    opchain();

    // 3.feladat
    int_decrement();
    //unsigned_int_decrement();
    unsigned_int_decrement2();

    // 5. feladat
    dice();

    return 0;
}