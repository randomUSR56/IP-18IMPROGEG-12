#include "string_copy.h"

#include <stdlib.h>
#include <string.h>

char *copy_string(const char *src)
{
    /*
     * strlen() does not count the terminating '\0', but the copy needs room
     * for it. So the minimum necessary size is strlen + 1 bytes. Not a byte
     * more, which is what the task asks for (compare: a fixed char[21]
     * buffer would waste memory for short inputs).
     */
    size_t size = strlen(src) + 1;

    char *copy = malloc(size);
    if (copy == NULL) {
        /* malloc can fail; never dereference NULL, report it to the caller. */
        return NULL;
    }

    /* memcpy copies `size` bytes, including the terminating '\0'. */
    memcpy(copy, src, size);
    return copy;
}
