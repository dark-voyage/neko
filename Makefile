all: server

clean:
	@rm -rf *.o
	@rm -rf neko

server: main.o http.o
	gcc -o neko $^

main.o: main.c http.h
	gcc -c -o main.o main.c

http.o: http.c http.h
	gcc -c -o http.o http.c