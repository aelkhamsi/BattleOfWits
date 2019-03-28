CFLAGS=-std=c99 -Wall -Wextra

all: code

code: code-Baseline

code-Baseline: main.o fifo.o player.o card.o board.o game.o
	gcc $(CFLAGS) main.o fifo.o player.o card.o board.o game.o -o project

main.o: main.c game.h
	gcc $(CFLAGS) -c $^

game.o: game.c game.h board.h
	gcc $(CFLAGS) -c $^

board.o: board.c board.h player.h card.h
	gcc $(CFLAGS) -c $^

card.o: card.c card.h
	gcc $(CFLAGS) -c $^

player.o: player.c player.h fifo.h
	gcc $(CFLAGS) -c $^

fifo.o: fifo.c fifo.h
	gcc $(CFLAGS) -c $^

test: test-achievement1

test-achievement1: test-achievement1.o fifo.o player.o card.o board.o game.o
	gcc $(CFLAGS) test-achievement1.o fifo.o player.o card.o board.o game.o -o test-0 && ./test-0

test-achievement1.o: test-achievement1.c game.h
	gcc $(CFLAGS) -c $^

clean:
	rm -f project *.o *.gch *~ *# test-0
