CC = gcc
CFLAGS = -g -Wall

all: server

server: server.c
	$(CC) $(CFLAGS) -o server server.c 

.PHONY: all clean

clean:
	rm -f *.o server