#ifndef WORD_READER_H
#define WORD_READER_H

/*
 * Task 2 - read a word and store it in exactly as much memory as it needs.
 */

/*
 * Reads one whitespace-delimited word from stdin and returns it in a
 * malloc'ed block of exactly strlen(word) + 1 bytes.
 *
 * Returns NULL on end of input or if allocation fails.
 * The caller must free() the result.
 *
 * Limitation: words longer than 255 characters are split into several words
 * (the temporary buffer is fixed). Task 6 shows how to lift this limit.
 */
char *read_word(void);

#endif
