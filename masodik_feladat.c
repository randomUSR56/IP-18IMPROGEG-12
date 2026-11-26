#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

#define STUD_CNT 10 // fantazia-ertek

typedef struct
{
    int id;
    double avg;
    short age;
} Student;

static void student_init(Student hallgatok[])
{
    for (int i = 0; i < STUD_CNT; i++)
    {
        hallgatok[i].id = rand() % 100000;
        hallgatok[i].avg = 1.0 + (double)rand() / RAND_MAX * 4.0; /* 1.0 - 5.0 */
        hallgatok[i].age = (short)(18 + rand() % 12);                 /* 18 - 29 */
    }
}

static void student_print(const Student *s)
{
    printf("  id: %5d, atlag: %.2f, kor: %hd\n", s->id, s->avg, s->age);
}

// visszaadja a legmagasabb atlagu hallgatot
static Student student_search(const Student hallgatok[], int count)
{
    Student best = hallgatok[0];

    for (int i = 1; i < count; i++)
    {
        if (hallgatok[i].avg > best.avg)
        {
            best = hallgatok[i];
        }
    }
    return best;
}

void masodik_feladat(void)
{
    srand((unsigned)time(NULL)); // random seed beallitasa
    Student hallgatok[STUD_CNT];

    printf("II. ---------------\n");

    student_init(hallgatok);

    printf("1. feladat:\n");
    for (int i = 0; i < STUD_CNT; i++)
    {
        student_print(&hallgatok[i]);
    }

    printf("4-5. feladat: legmagasabb atlagu hallgato:\n");
    Student best = student_search(hallgatok, STUD_CNT);
    student_print(&best);
}