CFLAGS=-std=c11 -g -static
SRC=test.c
OBJS=$(SRC:.c=.o)

test:
	$(CC) -o test $(SRC) `sdl2-config --cflags --libs`

clean:
	rm -f test

.PHONY:	clean
