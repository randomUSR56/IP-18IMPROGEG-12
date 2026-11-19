#ifndef REVERSE_H
#define REVERSE_H

/*
 * Task 5 - reverse a string into a NEW string.
 *
 * Differences from task 4: the parameter is const (the original is never
 * modified, so even a string literal is fine) and the result is returned in
 * newly allocated memory.
 *
 * Returns a malloc'ed, reversed copy of `str` (exactly strlen + 1 bytes), or
 * NULL if `str` is NULL or allocation fails. The caller must free() it.
 */
char *reverse(const char *str);

#endif
