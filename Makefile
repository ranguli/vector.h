CC=gcc
CFLAGS=-Wall -coverage -lcunit -lm

make: tests.c vector.h
	$(CC) -o tests tests.c $(CFLAGS) 

examples: examples/triangle.c vector.h
	$(CC) $(CFLAGS) -o examples/triangle examples/triangle.c $(CFLAGS) `sdl2-config --cflags --libs`

.PHONY: all test clean
