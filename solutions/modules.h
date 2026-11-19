#ifndef MODULES_H
#define MODULES_H

/* Each task is a self-contained module with one entry point, called from gyak10.c. */
void task1(void); /* copy a string (max 20 chars) into exactly sized memory */
void task2(void); /* read 5 words, print them in reverse order              */
void task3(void); /* read any amount of numbers, print them reversed (x2)   */
void task4(void); /* reverse a string in place                              */
void task5(void); /* reverse a string into a new string                     */
void task6(void); /* read words until "0", print them reversed (x2)         */

/*
 * Task 4 and 5 both ask for a function called reverse(), but one program can
 * only contain one function of a given name, so task 5's version is renamed.
 * Declared here because they are defined in task4.c / task5.c and are
 * reusable on their own.
 */
void reverse(char *str);            /* in place, task4.c; str must be writable */
char *reverse_new(const char *str); /* new malloc'ed string, task5.c; caller frees */

#endif
