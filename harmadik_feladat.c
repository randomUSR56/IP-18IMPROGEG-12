#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

#define STUD_CNT 10 // fantazia-ertek

typedef enum
{
    BSC,
    MSC,
    PHD
} Type;

typedef struct
{
    double impact_factor;
    int erdos_number;
} PhdData;

// egyszerre mindig csak egy tag ervenyes, a Type donti el, melyik
typedef union
{
    int courses; // Bsc data
    double credit_idx; // Msc data
    PhdData phd;        // PhD data
} Extra;

typedef struct
{
    int id;
    double avg;
    short age;
    Type type;
    Extra extra;
} AdvStudent;

// mi lenne ha struct-ot hasznalnank?
typedef struct
{
    int id;
    double avg;
    short age;
    Type type;
    struct
    {
        int courses;
        double credit_idx;
        PhdData phd;
    } extra;
} AdvStudentStruct;

static const char *type_name(Type type)
{
    switch (type)
    {
    case BSC:
        return "BSc";
    case MSC:
        return "MSc";
    default:
        return "PhD";
    }
}

static void student_init(AdvStudent hallgatok[])
{
    for (int i = 0; i < STUD_CNT; i++)
    {
        hallgatok[i].id = rand() % 100000;
        hallgatok[i].avg = 1.0 + (double)rand() / RAND_MAX * 4.0; /* 1.0 - 5.0 */
        hallgatok[i].age = (short)(18 + rand() % 12);             /* 18 - 29 */
        hallgatok[i].type = (Type)(rand() % 3);

        switch (hallgatok[i].type)
        {
        case BSC:
            hallgatok[i].extra.courses = 1 + rand() % 40;
            break;
        case MSC:
            hallgatok[i].extra.credit_idx = (double)rand() / RAND_MAX * 100.0;
            break;
        case PHD:
            hallgatok[i].extra.phd.impact_factor = (double)rand() / RAND_MAX * 10.0;
            hallgatok[i].extra.phd.erdos_number = 1 + rand() % 6;
            break;
        }
    }
}

static void student_print(const AdvStudent *s)
{
    printf("  id: %5d, atlag: %.2f, kor: %hd, tipus: %s, ",
           s->id, s->avg, s->age, type_name(s->type));

    switch (s->type)
    {
    case BSC:
        printf("kurzusok: %d\n", s->extra.courses);
        break;
    case MSC:
        printf("kreditindex: %.2f\n", s->extra.credit_idx);
        break;
    case PHD:
        printf("impaktfaktor: %.2f, Erdos-szam: %d\n",
               s->extra.phd.impact_factor, s->extra.phd.erdos_number);
        break;
    }
}

// visszaadja a legmagasabb atlagu hallgatot
static AdvStudent student_search(const AdvStudent hallgatok[], int count)
{
    AdvStudent best = hallgatok[0];

    for (int i = 1; i < count; i++)
    {
        if (hallgatok[i].avg > best.avg)
        {
            best = hallgatok[i];
        }
    }
    return best;
}

void harmadik_feladat(void)
{
    srand((unsigned)time(NULL)); // random seed beallitasa
    AdvStudent hallgatok[STUD_CNT];

    printf("III. ---------------\n");

    student_init(hallgatok);

    printf("1-2. feladat:\n");
    for (int i = 0; i < STUD_CNT; i++)
    {
        student_print(&hallgatok[i]);
    }

    printf("legmagasabb atlagu hallgato:\n");
    AdvStudent best = student_search(hallgatok, STUD_CNT);
    student_print(&best);

    printf("memoriaigeny: union-nal %zu bajt, structnal %zu bajt (hallgatonkent)\n",
           sizeof(AdvStudent), sizeof(AdvStudentStruct));
}