#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 256 // buffer az fgets-nek meg barmi string olvasonak

void countCharsAndWords(void)
{
}

void compareTwoStrings(void)
{
}

void copyStringToThird(void)
{
}

void swapCharInArrayAndPointerString(void)
{
}

void readFileAndPrintUppercase(void)
{
}

void readFileAndWriteUppercaseToFile(void)
{
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Használat: %s <feladat száma>\n", argv[0]);
        printf("  1 - karakterek és szavak száma\n");
        printf("  2 - két string összehasonlítása\n");
        printf("  3 - string másolása\n");
        printf("  4 - tömb és pointer string karaktercseréje\n");
        printf("  5 - fájl nagybetűs kiírása\n");
        printf("  6 - fájl nagybetűs mentése fájlba\n");
        return 1;
    }

    switch (atoi(argv[1])) {
        case 1: countCharsAndWords(); break;
        case 2: compareTwoStrings(); break;
        case 3: copyStringToThird(); break;
        case 4: swapCharInArrayAndPointerString(); break;
        case 5: readFileAndPrintUppercase(); break;
        case 6: readFileAndWriteUppercaseToFile(); break;
        default:
            printf("Ismeretlen menüpont: %s\n", argv[1]);
            return 1;
    }
    return 0;
}
