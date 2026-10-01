#include <stdio.h>

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
    int x = 0;

    printf("Inpput a year to determine if leap year or not\n");
    scanf("%d", &x);

    int isLeap = ((x % 4 == 0) && (x % 100 != 0)) || (x % 400 == 0);
    const char *result[] = { "not leap year", "leap year" };

    printf("%d -> %s", x, result[isLeap]);
}

int main() {
    //leapyear();
    leapyear2();
    return 0;
}