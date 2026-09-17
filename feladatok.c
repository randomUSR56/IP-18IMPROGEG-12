/*
Kötelező feladatok:

1. Deklarálj egy `int` típusú változót, és írd ki az értékét. Figyeld meg, hogy mi egy változó kezdőértéke!
2. Adj új értéket az előző változónak, majd írd ki, hogy a változó értéke páros vagy páratlan.
> - Próbáld ki mi történik, ha használod a változó előtt a `const` kulcsszót
3. Írj programot, amely egy számot kér a felhasználótól ( pl `scanf()`-el beolvasva a billentyűzetről ), de csak páratlant fogad el. Addig várakozik bemenetre, amíg megfelelő értéket nem kap.
4. Próbálj meg értékül adni az `int` típusú változónak egy valós számot, egy karaktert, egy logikai ( `bool` ) értéket, és egy karakter láncot (*stringet*). Ha sikerül az értékadás, akkor írd ki a változó értékét.
5. Határozd meg két szám átlagát. Figyelj arra, hogy az eredmény valós szám!
6. Írd ki 0-tól 1-ig a valós számokat 0.1-es lépésközzel.
7. Határozd meg, hogy melyik a legnagyobb és legkisebb ábrázolható egész szám ( `sizeof()` ). A legnagyobb ábrázolható egész számot tedd egy változóba, majd adj a változóhoz 1-et. Figyeld meg mi lett az eredmény!

*/

#include <stdio.h>
#include <stdbool.h>

bool paros(int n) {

        if (n % 2 == 0)
        {
            printf("Az %d szam erteke: paros \n", n);
            return true;
        }
        else
        {
            printf("Az %d szam erteke: paratlan \n", n);
            return false;
        }
    }

int main() {
    //1.
    int x; //volt benne.. valami
    printf("x erteke: %d\n", x);

    //2.
    //adjunk neki erteket!
    //nezzuk meg paros-e vagy paratlan

    x = 56;
    paros(x);
    
    //3.
    //kerjunk be szamot ameddig paratlan nem lesz

    do
    {
        printf("adj meg egy paratlan szamot (probalkozz): ");
        scanf("%d", &x);
    } while (paros(x));
    
    //4. szemlelet

    //5 ket szam atlaga
    int k = 3;
    int m = 5;

    float atlag = (m + k)/2;
    printf("k es m atlaga %.1f\n", atlag);

    //6
    //irasd ki a szamokat 0.0-tol 1-ig tizedesevel
    for (float i = 0.0f; i < 1.0f; i += 0.1f)
    {
        printf("szam: %.1f\n", i);
    }
    
    //7 legnagyobb legkisebb int (es uint)
    unsigned int legnagyobb_unsigned_integer = ~0;
    printf("Max u: %u\n", legnagyobb_unsigned_integer);

    int legnagyobb_integer = ~(1 << 31);
    printf("Min: %d\n", legnagyobb_integer);

    int legkisebb_integer = 1 << 31;
    printf("Min: %d\n", legkisebb_integer);

    return 0;
}
