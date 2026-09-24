#include <stdio.h>
#include <math.h>

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

    for (int i = 0; i < 3; i++)
    {
        char c;
        char o;
        int valid = 0;
        
        // loop ameddig nem adsz karaktert
        // (ameddig nem esik megfelelo ascii tartomanyba az inputod)
        do
        {
            printf("Adjon meg egy karaktert: \n");
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
    }
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

int negalas(){
    unsigned int a = 4;
    printf("Az elojel nelkuli '4' szám ha megforditjuk (negaljuk) a bijeit: %u\n", ~a);
    return 0;
}

int kor(){
    double r = 0;
    printf("Add meg a kor sugarat: \n");
    scanf("%lf", &r);
    
    double terulet = M_PI * r * r;
    double kerulet = 2 * M_PI * r;
    double atmero = 2*r;
    
    printf("A kor sugara: %.2f\n", r);
    printf("A kor terulete: %.2f\n", terulet);
    printf("A kor kerulete: %.2f\n", kerulet);
    printf("A kor atmerejo: %.2f\n", atmero);
    
    return 0;
}

int merolegesek(){
    // ket egyenes akkor meroleges egymasra, amennyiben a meredekseguk szorzata -1
    double x1, y1, x2, y2, x3, y3, x4, y4;
    
    printf("Elso egyenes elso pontja (x1, y1): ");
    scanf("%lf %lf", &x1, &y1);
    printf("Elso egyenes masodik pontja (x2, y2): ");
    scanf("%lf %lf", &x2, &y2);
    
    printf("Masodik egyenes elso pontja (x3, y3): ");
    scanf("%lf %lf", &x3, &y3);
    printf("Masodik egyenes masodik pontja (x4, y4): ");
    scanf("%lf %lf", &x4, &y4);
    
    double m1 = (y2 - y1) / (x2 - x1);
    double m2 = (y4 - y3) / (x4 - x3);
    
    if (m1 * m2 == -1.0) {
        printf("Az egyenesek merolegesek!\n");
    } else {
        printf("Az egyenesek nem merolegesek. m1*m2 = %.2f\n", m1 * m2);
    }
    
    return 0;
}

int datumKonvert(){
    int datum;
    printf("adja meg a datumot (pl.: 20260323)\n");
    scanf("%d", &datum);
    int ev;
    int honap;
    int nap;

    ev = datum/10000;
    honap = 0;
    nap = datum % 100;

    printf("A datum formazva: %d. %d. %d.", ev, honap, nap);
    return 0;
}

int main(){
    // 1. feladat
    prefixVizsgalat();
    // 2. feladat
    kisbetubolNagybetu();
    // 3. feladat
    arithmethics();
    // 4. feladat
    kor();
    // 5. feladat

    // 6. feladat
    merolegesek();
    // 7. feladat
    szamcsere();
    // 8. feladat
    negalas();
    return 0;
}