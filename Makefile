CFLAGS= -O2 -Wall -Werror
MAIN=main.c
CC=cc

all:
	$(CC) $(CFLAGS) $(MAIN) -o bin 

clean:
	rm *.o
	rm bin/calendario
