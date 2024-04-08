# This makefile is used as follows to regenerate files for the register program:
#   make test_rational.o   			--  Regenerates test_rational.o by compiling
#   make rational.o   				--  Regenerates rational.o by compiling
#   make rational_math   			--  Regenerates the executable rational_math file by compiling
#   make            				--  Same as "make rational_math"
#

rational_math: rational.o test_rational.o
	gcc -g -Wall test_rational.o rational.o -lm -o rational_math

rational.o: rational.h rational.c
	gcc -g -Wall -c rational.c

test_rational.o: rational.h test_rational.c
	gcc -g -Wall -c test_rational.c

clean:
	rm -f .o test_rational.o rational.o rational_math

all: rational_math