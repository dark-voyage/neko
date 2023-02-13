#!/usr/bin/env just --justfile

all: server

clean:
	@rm -rf *.o
	@rm -rf server

server: main.o http.o route.o file.o
	gcc -o server $^

main.o: main.c http.h
	gcc -c -o main.o main.c

http.o: http.c http.h
	gcc -c -o http.o http.c

route.o: route.c route.h
	gcc -c -o route.o route.c

file.o: file.c file.h
	gcc -c -o file.o file.c
