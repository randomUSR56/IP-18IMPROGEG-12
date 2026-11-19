#include <stdio.h>
#include <string.h>

#include "reverse.h"

#define MAX_LEN 100

int main(void)
{
    /*
     * Note `char[]` and not `char *`: initialising an array copies the literal
     * into writable memory. `char *p = "racecar"` would point at read-only
     * memory and reverse(p) would crash.
     */
    char palindrome[] = "racecar";
    char text[] = "hello";

    reverse(palindrome);
    reverse(text);
    printf("palindrome after reverse: %s\n", palindrome); /* racecar */
    printf("\"hello\" after reverse:    %s\n", text);      /* olleh */

    /* Same with user input. Buffer: MAX_LEN chars + '\n' + '\0'. */
    char input[MAX_LEN + 2];
    printf("Enter a text: ");
    if (fgets(input, sizeof input, stdin) == NULL) {
        return 1;
    }
    input[strcspn(input, "\n")] = '\0'; /* remove the trailing newline */

    reverse(input);
    printf("Reversed: %s\n", input);

    return 0;
}
