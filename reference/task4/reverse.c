#include "reverse.h"

#include <string.h>

void reverse(char *str)
{
    if (str == NULL) {
        return;
    }

    size_t len = strlen(str);
    if (len < 2) {
        return; /* empty and 1-char strings are already their own reverse */
    }

    /*
     * Two indices walk towards each other from both ends, swapping characters.
     * They meet in the middle after len / 2 swaps. For an odd length the middle
     * character stays where it is, which is correct.
     *
     * A palindrome ("racecar") swaps equal characters with each other, so the
     * content is unchanged - exactly the example mentioned in the task.
     *
     * We stop at `left < right` rather than at len, otherwise every pair would
     * be swapped twice and the string would end up unchanged.
     */
    size_t left = 0;
    size_t right = len - 1;
    while (left < right) {
        char tmp = str[left];
        str[left] = str[right];
        str[right] = tmp;
        ++left;
        --right;
    }
}
