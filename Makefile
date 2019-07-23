make: tests.c vector.h
	gcc -Wall -Werror -coverage -o tests tests.c -lcunit 
