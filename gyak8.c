#include <stdio.h>
#include "my_utils.h"

//-------------------------------------------
// [1]
//-------------------------------------------
int a = 42; // global

//-------------------------------------------
// [6]
//-------------------------------------------
// elore deklaralas (prototipus): a parameternevek itt csak dokumentacio, elhagyhatok is
int osszead(int x, int y);

//-------------------------------------------
// [2]
//-------------------------------------------
void moricka() {
    int b = 1;
    if (b)
    {
        //-------------------------------------------
        // [3]
        //-------------------------------------------
        printf("Elerem b-t mert ugyanazon fuggveny scopejaban vagyok\n");
        printf("b: %d\n", b);

        int c = 0; // if-scope
    }
    else 
    {
        printf("Szinten elerem b-t, bar ez jelen esetben nem fog lefutni mert 1=true\n");
        printf("b: %d\n", b);

        int d = 0; // else-scope
    }
    
    //-------------------------------------------
    // [4]
    //-------------------------------------------
    // undefined-ot ir mindketto valtozonkra hiszen nem csak, hogy nem latjuk oket innen, az sen garantalt hogy letrejonnek egyaltalan.
    // az if-else kimenetetol fugg (de meg ha letre is jonnenek se latnank oket)
    // printf("c: %d\n", c);
    // printf("d: %d\n", d);
}

int main() {
    printf("a: %d\n", a);
    a++;
    printf("a, valtozast kovetoen: %d\n", a);

    // printf("b: %d\n", b);
    // b undefined, hiszen mainbol nem latunk ra. masik scope-ban van, a moricka lokalis valtozoja.

    //-------------------------------------------
    // [5]
    //-------------------------------------------

    // Mikor erdemes scope-okat hasznalni?
    // - rovid elettartam: a valtozo csak addig el, amig kell, kevesebb a hibalehetoseg
    // - nevutkozes elkerulese: ugyanaz a nev (pl. i, tmp) tobb blokkban is hasznalhato
    // - olvashatosag: a valtozo kozel van ahhoz a kodhoz, ahol hasznaljuk
    // - eroforras: a blokk vegen a valtozok memoriaja felszabadul
    // - elkulonites: ideiglenes adatok nem szivarognak ki a kornyezetbe
    // Szabaly: a valtozot mindig a lehet legszukebb scope-ban vezessuk be, globalist csak indokolt esetben.

    // Mi a verem (stack) es hogyan csatlakozik a scope kezeleshez?
    // - a verem LIFO (last in, first out) adatszerkezet: az utoljara betett elem kerul ki eloszor
    // - fuggvenyhivaskor uj stack frame kerul a verem tetejere (parameterek, lokalis valtozok), a fuggveny vegen lekerul
    // - blokkba lepeskor a blokk lokalis valtozoi a verem tetejere kerulnek, kilepeskor megszunnek
    // - a piramisnal: letrehozas a -> b -> c -> d -> e, megszunes e -> d -> c -> b -> a
    // - kifele azert latunk, mert a kulso valtozok lejjebb vannak a veremben es meg elnek;
    //   befele azert nem, mert a belso valtozok meg nem leteznek (vagy mar megszuntek)
    // - main es moricka kulon frame, ezert nem latjuk egymas lokalis valtozoit
    // - a globalis 'a' nem a veremben, hanem a statikus adatteruleten van, a program teljes futasa alatt el

    // Great Pyramid of Giza (of scopes)
    {
        printf("Pyramid of scopes:\n");
        int a = 1; // ez nem a kulso, globalis 'a' a file elejen. shadowing tortent. a piramisokon kivul visszater a jol megszokott global 'a'
        printf("a: %d\n", a);
        // fail printf("b: %d\n", b);
        // fail printf("c: %d\n", c);
        // fail printf("d: %d\n", d);
        // fail printf("e: %d\n", e);
        {
            int b = 2;
            printf("a: %d\n", a);
            printf("b: %d\n", b);
            // fail printf("c: %d\n", c);
            // fail printf("d: %d\n", d);
            // fail printf("e: %d\n", e);
            {
                int c = 3;
                printf("a: %d\n", a);
                printf("b: %d\n", b);
                printf("c: %d\n", c);
                // fail printf("d: %d\n", d);
                // fail printf("e: %d\n", e);
                {
                    int d = 4;
                    printf("a: %d\n", a);
                    printf("b: %d\n", b);
                    printf("c: %d\n", c);
                    printf("d: %d\n", d);
                    // fail printf("e: %d\n", e);
                    {
                        // ekkorra mar az osszes valtozo letrejott igy azokat el is erjuk.
                        // felfele (kifele) latunk, lefele (befele) kintrol, fentrol nem.
                        int e = 5;
                        printf("a: %d\n", a);
                        printf("b: %d\n", b);
                        printf("c: %d\n", c);
                        printf("d: %d\n", d);
                        printf("e: %d\n", e);
                    }
                }
            }
        }
    }

    //-------------------------------------------
    // [6]
    //-------------------------------------------
    // a prototipusnak koszonhetoen a definicio elott is hivhato
    printf("osszead(2, 3): %d\n", osszead(2, 3));

    //-------------------------------------------
    // [8]
    //-------------------------------------------
    // Mi tortenik, ha tobbszor hivjuk a static valtozos fuggvenyt?
    // - a static valtozo a program teljes futasa alatt el (statikus adatterulet, nem a verem), ezert az ertek hivasok kozott megmarad
    // - az inicializalas (= 0) csak egyszer tortenik meg, nem minden hivasnal
    // - a scope viszont tovabbra is a fuggvenyre korlatozott: kivulrol nem latszik
    szamlalo(); // 1
    szamlalo(); // 2
    szamlalo(); // 3

    //-------------------------------------------
    // [9]
    //-------------------------------------------
    // swap: a fuggveny csak a cimek atadasaval tudja modositani a hivo valtozoit (ertek szerinti atadas masolatot adna)
    int x = 3;
    int y = 7;
    printf("swap elott: x=%d, y=%d\n", x, y);
    swap(&x, &y);
    printf("swap utan: x=%d, y=%d\n", x, y);

    //-------------------------------------------
    // [10]
    //-------------------------------------------
    // a visszaadott pointer az eredeti valtozora mutat, nem masolatra, ezert a hivo hasznalhatja is, es modosithatja is
    // figyelem: lokalis valtozo cimet visszaadni hiba lenne, mert a frame a hivas vegen megszunik. itt a cimek a mainbol jonnek, ezert biztonsagos
    int *nagy = nagyobb(&x, &y);
    printf("nagyobb: %d\n", *nagy);
    *nagy = 0;
    printf("a nagyobb nullazasa utan: x=%d, y=%d\n", x, y);

    //-------------------------------------------
    // [11]
    //-------------------------------------------
    // Mukodik-e a swap, ha mainen belul deklaraljuk es definialjuk?
    // - csak deklaralni szabad: blokk scope-ban levo prototipus szabvanyos C, a definicio viszont kulon fuggvenykent a mainen kivul van
    // - definialni main-en belul nem szabvanyos C: GCC-ben mukodik (nested function kiterjesztes), Clang-ben nem
    // - Clang hiba: "function definition is not allowed here" (macOS-en a gcc parancs is Apple Clang, ott sem fordul)
    // - hasznos: a fuggveny csak ott latszik, ahol kell, es a GCC-nel eleri a main lokalis valtozoit is; de nem hordozhato
    // int main() {
    //     int p = 1, q = 2;
    //     void swap_belso(int *a, int *b) { int t = *a; *a = *b; *b = t; }
    //     swap_belso(&p, &q);
    // }
    void swap(int *a, int *b); // szabvanyos: blokk scope-beli deklaracio, a definicio a my_utils.c-ben van
    swap(&x, &y);
    printf("ujra swap: x=%d, y=%d\n", x, y);

    return 0;
}

//-------------------------------------------
// [6]
//-------------------------------------------
// Mi tortenik, ha mas parameterneveket hasznalunk?
// - hibatlanul lefordul: a fordito a prototipusnal csak a tipusok szamat es sorrendjet ellenorzi, a neveket nem
// - a definicio nevei ervenyesek a torzsben (elso, masodik), a prototipus nevei (x, y) nem leteznek itt
// - ha a tipus vagy a parameterek szama elter, az hiba (conflicting types)
// Mikor hasznos?
// - fuggveny hasznalata a definicioja elott (pl. main fent, a fuggvenyek lent)
// - header (.h) fajlok: a deklaracio a .h-ban, a definicio a .c-ben
// - a prototipusban beszedes nevek dokumentaljak a jelenteset, a definicioban a megvalositashoz illok
int osszead(int elso, int masodik) {
    return elso + masodik;
}

//-------------------------------------------
// [7]
//-------------------------------------------
// Mi tortenik, ha ket parameternek ugyanazt a nevet adjuk?
// - forditasi hiba: redefinition of parameter 'x'
// - a parameterek a fuggveny torzsenek scope-jaban ugyanolyan lokalis valtozok, egy scope-ban egy nev csak egyszer szerepelhet
// - ha elfogadna, a torzsben nem lehetne eldonteni, hogy az x melyik parametert jelenti
// - prototipusban sem szabad ismetelni a nevet (int f(int x, int x);), ott is hiba
// int ketszer(int x, int x) {
//     return x + x;
// }