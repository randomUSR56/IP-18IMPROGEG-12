#include "reverse.h"

#include <stdlib.h>
#include <string.h>

char *reverse(const char *str)
{
    if (str == NULL) {
        return NULL;
    }

    size_t len = strlen(str);

    /* len characters + the terminating '\0'. */
    char *result = malloc(len + 1);
    if (result == NULL) {
        return NULL;
    }

    /*
     * No swapping is needed this time: result[i] simply receives the character
     * from the mirrored position of the source. The source is only read.
     */
    for (size_t i = 0; i < len; ++i) {
        result[i] = str[len - 1 - i];
    }

    /* Do not forget the terminator: malloc'ed memory is uninitialised. */
    result[len] = '\0';
    return result;
}
