#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

#define STUD_CNT 10

/* 1. feladat: ket tomb (azonosito, atlag) feltoltese random adatokkal */
static void init(int ids[], double averages[])
{
    for (int i = 0; i < STUD_CNT; i++)
    {
        ids[i] = rand() % 100000;
        averages[i] = 1.0 + (double)rand() / RAND_MAX * 4.0; /* 1.0 - 5.0 */
    }
}

/* 2. feladat: ugyanez, kiegeszitve a hallgatok eletkorat tarolo harmadik tombbel */
static void init_with_age(int ids[], double averages[], short ages[])
{
    for (int i = 0; i < STUD_CNT; i++)
    {
        ids[i] = rand() % 100000;
        averages[i] = 1.0 + (double)rand() / RAND_MAX * 4.0; /* 1.0 - 5.0 */
        ages[i] = (short)(18 + rand() % 12);                 /* 18 - 29 */
    }
}

void elso_feladat(void)
{
    srand((unsigned)time(NULL));

    int ids[STUD_CNT];
    double averages[STUD_CNT];
    short ages[STUD_CNT];

    init(ids, averages);
    printf("1. feladat:\n");
    for (int i = 0; i < STUD_CNT; i++)
    {
        printf("  id: %5d, atlag: %.2f\n", ids[i], averages[i]);
    }

    init_with_age(ids, averages, ages);
    printf("2. feladat:\n");
    for (int i = 0; i < STUD_CNT; i++)
    {
        printf("  id: %5d, atlag: %.2f, kor: %hd\n", ids[i], averages[i], ages[i]);
    }

    /*
     * 3. feladat: Ha tovabbi adatokat kellene tamogatnunk, minden uj attributumhoz
     * ujabb tombot kellene felvenni, es minden fuggvenyt (inicializalas, kiiras, ...)
     * at kellene irni: tobb parameter, tobb helyen modositas, konnyu elrontani.
     * Az osszetartozo adatok kulon tombokben vannak, igy nehezen kezelhetoek.
     * Ezert struktura (struct) kell: osszetett adat tarolasahoz osszetett
     * adatszerkezetet kell definialni, amivel a hallgato minden adata egyben
     * kezelheto, es a kod egyszerubb, atlathatobb es konnyebben bovitheto.
     */
}