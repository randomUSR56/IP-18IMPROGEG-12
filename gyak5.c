#include <stdio.h>
#include <ctype.h> // 7. feladat dependency-je

void array_test() {
    int arr[5] = {0, 0, 0, 0, 0};
    // vagy rovidebben:
    int arr2[5] = {0};

    printf("1. feladat:\ntomb merete: %lu\n", sizeof(arr)/sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        printf("A tomb %d. eleme: %d\n", i+1, arr[i]);
    }
    
}

void sum_arr() {
    int arr[5] = {1, 2, 3, 4, 5};
    
    int sum = 0;
    for (int i = 0; i < (sizeof(arr)/sizeof(arr[0])); i++)
    {
        sum += arr[i];
    }
    printf("\n2. feladat:\ntomb osszege: %d\n", sum);
}

void w_arr_sum() {
    int arr[5] = {1, 2, 3, 4, 5};
    int weights[5] = {1, 1, 2, 3, 5};
    
    int sum = 0;
    for (int i = 0; i < (sizeof(arr)/sizeof(arr[0])); i++)
    {
        sum += arr[i] * weights[i];
    }
    printf("\n2. feladat:\ntomb sulyozott osszege: %d\n", sum);
}

void w_arr_avg() {
    int arr[5] = {1, 2, 3, 4, 5};
    double weights[5] = {1, 1, 2, 3, 5};
    
    double sum = 0;
    double weight_sum = 0;
    for (int i = 0; i < (sizeof(arr)/sizeof(arr[0])); i++)
    {
        sum += arr[i] * weights[i];
        weight_sum += weights[i];
    }
    printf("\n2. feladat:\ntomb sulyozott atlaga: %f\n", sum / weight_sum);
}

void int_max() {
    int arr[9] = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    
    int max = arr[0];
    for (int i = 1; i < (sizeof(arr)/sizeof(arr[0])); i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    printf("\n3. feladat:\nlegnagyobb ertek a tombben: %d\n", max);
}

void char_abc() {
    char string[5] = "hello";
    char string2[5] = "bello";
    
    char *result = NULL;
    for (int i = 0; i < 5; i++) {
        if (toupper(string[i]) != toupper(string2[i])) {
            result = (toupper(string[i]) < toupper(string2[i])) ? string : string2;
            break;
        }
    }
    
    printf("\n7. feladat:\nmelyik szoveg van elorebb az abc sorrendben?: %s\n", result);
}

void char_count() {
    printf("\n8. feladat:\nadjon meg egy stringet: ");

    // leghosszabb magyar szó:
    // eltöredezettségmentesítőtleníttethetetlenségtelenítőtlenkedhetnétek
    // (67 betű)
    // a biztonság kedvéért legyen string[128] (majdnem 2x akkora mint a leghosszabb szó, de szép kerek szám 2^7)
    char string[128] = {0};

    // %127s - legyen a max amit beirhat a user 127 hosszu (a \0-at ez a limit nem befolyasolja)
    scanf("%127s", string);
    
    // strlen helyett
    int i = 0;
    while (1)
    {
        if (string[i] == '\0')
        {
            break;
        }
        else
        {
            i++;
        }
    }
    // vagy ugyanez rövidebben:
    int j = 0;
    while (string[j]) j++;

    // megj.: az ékezetes karakterek sajnos 2 byte-ok
    // erre nem korrigáltam. (UTF-8)
    printf("\n8. feladat:\na szoveg betuszama: %d\n", i);
}

void second_to_last() {
    int arr[5] = {1, 4, 2, 5, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    // buborék-rendezés
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }

    // szó szerin az utolsó előtti elemet hozom el
    printf("\n9. feladat:\nmasodik legkisebb ertek: %d\n", arr[n - 2]);
}

int main() {
    array_test();
    sum_arr();
    w_arr_sum();
    w_arr_avg();
    int_max();
    char_abc();
    char_count();
    second_to_last();
    return 0;
}