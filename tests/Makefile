.PHONY: t1 t2 t3 t4

CC = gcc
CFLAGS = -Wall -O0 -g

all: build run

build: t1 t2 t3 t4
t1:
	$(CC) $(CFLAGS) -o t1 t1.c

t2:
	$(CC) $(CFLAGS) -o t2 t2.c

t3:
	$(CC) $(CFLAGS) -o t3 t3.c

t4:
	$(CC) $(CFLAGS) -o t4 t4.c

run:
	./t1
	./t2
	./t3
	./t4
