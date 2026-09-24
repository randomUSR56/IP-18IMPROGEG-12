#include <stdio.h>

int prefixVizsgalat(){
    int a = 1;
    ++a; //+= 1
    a++;
    int b = a++ + ++a; // undefined behaviour mert nincs szekvencia pont meghatarozva, forditotol fugg melyik kerul vegrehajtasra eloszor.
    printf("b = %d", b);
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

int main(){
    // 1. feladat
    // prefixVizsgalat();
    // 2. feladat
    for (int i = 0; i < 5; i++)
    {
        kisbetubolNagybetu();
    }
    return 0;
}