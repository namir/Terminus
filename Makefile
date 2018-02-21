CC=gcc
CFLAGS=-g -Wall

Terminus: Terminus.c
	$(CC) $(CFLAGS) $@.c -o $@

all: Terminus

clean: 
	rm Terminus




