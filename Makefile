CC=clang
OSFLAG :=
CFLAGS=-Wall -lm

ifeq ($(OS),Windows_NT)
	OSFLAG += -D WIN32 
else
	UNAME_S := $(shell uname -s)

	ifeq ($(UNAME_S), OpenBSD)
		OSFLAG += -D OpenBSD
		CFLAGS += -I/usr/local/include -L/usr/local/lib -lcunit
	endif
	ifeq ($(UNAME_S), Linux)
		CFLAGS += 
	endif
endif

make: tests.c vector.h
	$(CC) -o tests tests.c $(CFLAGS) 

examples: examples/triangle.c vector.h
	$(CC) -o examples/triangle examples/triangle.c $(CFLAGS) `sdl2-config --cflags --libs`

.PHONY: all test clean
