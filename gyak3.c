#include <stdio.h>

int prefixVizsgalat(){
    int a = 1;
    ++a; //+= 1
    a++;
    int b = a++ + ++a; // undefined behaviour mert nincs szekvencia pont meghatarozva, forditotol fugg melyik kerul vegrehajtasra eloszor.
    printf("b = %d\n", b);
    return 0;
}

int kisbetubolNagybetu(){
    /*
    'a' (97) - 32 = 65 = 'A'
    'A' (65) + 32 = 97 = 'a'
    'z' (122) - 32 = 90 = 'Z'
    'Z' (90) + 32 = 122 = 'z'
    */
    char c;
    char o;
    int valid = 0;
    
    // loop ameddig nem adsz karaktert
    // (ameddig nem esik megfelelo ascii tartomanyba az inputod)
    do
    {
        printf("Adjon meg egy karaktert: ");
        c = getchar();
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            valid = 1;
        } else {
            printf("Hiba, nem karaktert adtal meg!\nUjraprobalas..\n");
        }
    } while (!valid);
    
    // amint valid dontsuk el, hogy upper-e vagy lower-e a bemenet majd toljuk el az erteket a kis vagy nagybetus parjaig
    if (c >= 'a' && c <= 'z') {
        o = c - 32;  // lower -> UPPER
    } else if (c >= 'A' && c <= 'Z') {
        o = c + 32;  // UPPER -> lower
    }

    // kiiratas
    printf("Eredeti input: %c\nModositott output: %c\n", c, o);
    return 0;
}

int arithmethics(){
    int a = 0;
    int b = 0;

    printf("adja meg az elso szamot\na = \n");
    scanf("%d", &a);
    printf("adja meg a masodik szamot\nb = \n");
    scanf("%d", &b);

    printf("Osszeadas (a+b):\t%d\n", a + b);
    printf("Kivonas (a-b):\t%d\n", a - b);
    printf("Szorzas (a*b):\t%d\n", a * b);
    printf("Osztas (a/b):\t%d\n", a / b);
    printf("Maradek (a%%b):\t%d\n", a % b);

    return 0;
}

int szamcsere(){
    int a = 0;
    int b = 0;
    printf("add meg 'a' erteket: \n");
    scanf("%d", &a);
    printf("add meg 'b' erteket: \n");
    scanf("%d", &b);

    printf("a erteke csere elott: %d\n", a);
    printf("b erteke csere elott: %d\n", b);

    a = a+b;
    b = a-b;
    a = a-b;

    printf("a erteke csere utan: %d\n", a);
    printf("b erteke csere utan: %d\n", b);

    return 0;
}

int main(){
    // 1. feladat
    prefixVizsgalat();
    // 2. feladat
    for (int i = 0; i < 5; i++)
    {
        kisbetubolNagybetu();
    }
    // 7. feladat
    szamcsere();
    return 0;
}