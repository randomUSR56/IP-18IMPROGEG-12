#include <stdio.h>

int main() {

    int alma = 42;
    float korte = 137.0f;

    printf("alma = %d, %f, %c, %s\n", alma, korte, 'C', "Hello");
    scanf("%d", &alma);
    printf("alma new = %d\n", alma);

    printf("hello world\n");
    return 0;
}