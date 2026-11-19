# Builds every reference solution with the flags required by the assignment.
# Usage:  make          (build all)
#         make task3.out (build one, e.g. task 3)
#         make clean

CC      = cc
# -W -Wall -Wextra -pedantic: the warning flags the assignment demands.
# -std=c99 keeps us on portable standard C; -g adds debug info.
CFLAGS  = -std=c99 -W -Wall -Wextra -pedantic -g

TASKS   = task1 task2 task3 task4 task5 task6
BINS    = $(addsuffix .out,$(TASKS))

all: $(BINS)

# One pattern rule for all tasks: compile every .c file of the directory
# together. The binary ends in .out so the repository's .gitignore skips it.
# The wildcard is expanded by make, so adding a .c file needs no Makefile edit.
%.out: %/*.c %/*.h
	$(CC) $(CFLAGS) -o $@ $(wildcard $*/*.c)

clean:
	rm -f $(BINS)

.PHONY: all clean
