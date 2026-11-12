#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 256 // buffer az fgets-nek meg barmi string olvasonak
#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"

static void readLine(const char *prompt, char *buf, size_t size)
{
    printf("%s", prompt);
    if (fgets(buf, (int)size, stdin) == NULL)
    {
        buf[0] = '\0';
        return;
    }
    buf[strcspn(buf, "\n")] = '\0';
}

static void toUpperString(char *s)
{
    for (; *s != '\0'; s++)
    {
        *s = (char)toupper((unsigned char)*s);
    }
}

// Beolvassa az INPUT_FILE-t soronként, nagybetűsíti, és az out-ba írja.
static int uppercaseInputFileTo(FILE *out)
{
    FILE *in = fopen(INPUT_FILE, "r");
    if (in == NULL)
    {
        perror(INPUT_FILE);
        return 0;
    }

    char line[MAX];
    while (fgets(line, MAX, in) != NULL)
    {
        toUpperString(line);
        fprintf(out, "%s", line);
    }

    fclose(in);
    return 1;
}

void countCharsAndWords(void)
{
    char s[MAX] = {0};

    printf("Írj be egy sor szöveget: ");
    if (fgets(s, MAX, stdin) == NULL)
    {
        return;
    }

    s[strcspn(s, "\n")] = '\0';
    printf("\nKarakterek száma: %zu\n", strlen(s));

    char *start = s;
    while (isspace((unsigned char)*start))
    {
        start++;
    }

    size_t len = strlen(start);
    while (len > 0 && isspace((unsigned char)start[len - 1]))
    {
        len--;
    }
    start[len] = '\0';

    int word_count = 0;
    if (len > 0)
    {
        word_count = 1;
        for (size_t i = 0; i < len; i++)
        {
            if (isspace((unsigned char)start[i]))
            {
                word_count++;
            }
        }
    }

    printf("Szavak száma: %d\n", word_count);
}

void compareTwoStrings(void)
{
    char first[MAX] = {0};
    char second[MAX] = {0};

    readLine("Első string: ", first, MAX);
    readLine("Második string: ", second, MAX);

    int result = strcmp(first, second);
    if (result == 0)
    {
        printf("A két string egyezik.\n");
    }
    else
    {
        printf("A két string különbözik (strcmp = %d).\n", result);
    }
}

void copyStringToThird(void)
{
    char source[MAX] = {0};
    char third[MAX] = {0};

    readLine("Írj be egy stringet: ", source, MAX);
    strcpy(third, source); // third mérete megegyezik source-éval, ezért belefér

    printf("Másolat: %s\n", third);
}

void swapCharInArrayAndPointerString(void)
{
    char array[] = "alma";
    char *pointer = "alma";

    array[0] = 'A';
    printf("Tömb módosítás után: %s\n", array);

    // pointer[0] = 'A'; // UB: a pointer a csak olvasható string literálra mutat (segfault)
    printf("Pointer (nem módosítható): %s\n", pointer);

    // A pointer átirányítható, a tömb neve nem.
    pointer = array;
    pointer[1] = 'L';
    printf("Pointer a tömbre állítva, módosítva: %s\n", pointer);
}

void readFileAndPrintUppercase(void)
{
    uppercaseInputFileTo(stdout);
}

void readFileAndWriteUppercaseToFile(void)
{
    FILE *out = fopen(OUTPUT_FILE, "w");
    if (out == NULL)
    {
        perror(OUTPUT_FILE);
        return;
    }

    if (uppercaseInputFileTo(out))
    {
        printf("Kész: %s\n", OUTPUT_FILE);
    }

    fclose(out);
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
