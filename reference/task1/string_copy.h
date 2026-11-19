#ifndef STRING_COPY_H
#define STRING_COPY_H

/*
 * Task 1 - copy a string using exactly as much memory as needed.
 *
 * The header only holds the declaration (the "interface"); the implementation
 * lives in string_copy.c. The include guard above stops the header from being
 * processed twice if it is included from several places.
 */

/*
 * Returns a freshly malloc'ed copy of `src`, or NULL if allocation fails.
 * The caller owns the result and must free() it.
 */
char *copy_string(const char *src);

#endif
