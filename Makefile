CFLAGS=-std=c99 -Wall -Wextra

all: code

code: Baseline Achievement1 Achievement2 Achievement3

test: test-Baseline test-Achievement1 test-Achievement2 test-Achievement3



Baseline: mainB.o playerB.o boardB.o gameB.o
	gcc $(CFLAGS) $^ -o projectB

mainB.o: Baseline/mainB.c Baseline/game.h
	gcc $(CFLAGS) -c $^

gameB.o: Baseline/gameB.c Baseline/game.h Baseline/board.h
	gcc $(CFLAGS) -c $^

boardB.o: Baseline/boardB.c Baseline/board.h Baseline/player.h Baseline/card.h
	gcc $(CFLAGS) -c $^

playerB.o: Baseline/playerB.c Baseline/player.h Baseline/cst.h
	gcc $(CFLAGS) -c $^

test-Baseline: test-Baseline.o playerB.o boardB.o gameB.o
	gcc $(CFLAGS) $^ -o test-B && ./test-B

test-Baseline.o: Baseline/test-Baseline.c Baseline/game.h
	gcc $(CFLAGS) -c $^



Achievement1: mainA1.o fifoA1.o playerA1.o boardA1.o gameA1.o
	gcc $(CFLAGS) $^ -o projectA1

mainA1.o: Ach-1/mainA1.c Ach-1/game.h
	gcc $(CFLAGS) -c $^

gameA1.o: Ach-1/gameA1.c Ach-1/game.h Ach-1/board.h
	gcc $(CFLAGS) -c $^

boardA1.o: Ach-1/boardA1.c Ach-1/board.h Ach-1/player.h Ach-1/card.h
	gcc $(CFLAGS) -c $^

playerA1.o: Ach-1/playerA1.c Ach-1/player.h Ach-1/cst.h
	gcc $(CFLAGS) -c $^

fifoA1.o: Ach-1/fifoA1.c Ach-1/fifo.h Ach-1/cst.h
	gcc $(CFLAGS) -c $^

test-Achievement1: test-Achievement1.o fifoA1.o playerA1.o boardA1.o gameA1.o
	gcc $(CFLAGS) $^ -o test-A1 && ./test-A1

test-Achievement1.o: Ach-1/test-Achievement1.c Ach-1/game.h
	gcc $(CFLAGS) -c $^




Achievement2: mainA2.o fifoA2.o playerA2.o boardA2.o gameA2.o arenaA2.o
	gcc $(CFLAGS) $^ -o projectA2

mainA2.o: Ach-2/mainA2.c Ach-2/game.h
	gcc $(CFLAGS) -c $^

gameA2.o: Ach-2/gameA2.c Ach-2/game.h Ach-2/board.h
	gcc $(CFLAGS) -c $^

boardA2.o: Ach-2/boardA2.c Ach-2/board.h Ach-2/player.h Ach-2/card.h
	gcc $(CFLAGS) -c $^

playerA2.o: Ach-2/playerA2.c Ach-2/player.h Ach-2/cst.h
	gcc $(CFLAGS) -c $^

fifoA2.o: Ach-2/fifoA2.c Ach-2/fifo.h Ach-2/cst.h
	gcc $(CFLAGS) -c $^

arenaA2.o: Ach-2/arenaA2.c Ach-2/arena.h Ach-2/board.h
	gcc $(CFLAGS) -c $^

test-Achievement2: test-Achievement2.o fifoA2.o playerA2.o boardA2.o gameA2.o arenaA2.o
	gcc $(CFLAGS) $^ -o test-A2 && ./test-A2

test-Achievement2.o: Ach-2/test-Achievement2.c Ach-2/game.h
	gcc $(CFLAGS) -c $^




Achievement3: mainA3.o fifoA3.o playerA3.o boardA3.o gameA3.o arenaA3.o friendA3.o
	gcc $(CFLAGS) $^ -o projectA3

mainA3.o: Ach-3/mainA3.c Ach-3/game.h
	gcc $(CFLAGS) -c $^

gameA3.o: Ach-3/gameA3.c Ach-3/game.h Ach-3/arena.h
	gcc $(CFLAGS) -c $^

boardA3.o: Ach-3/boardA3.c Ach-3/board.h Ach-3/player.h Ach-3/card.h
	gcc $(CFLAGS) -c $^

playerA3.o: Ach-3/playerA3.c Ach-3/player.h Ach-3/fifo.h
	gcc $(CFLAGS) -c $^

fifoA3.o: Ach-3/fifoA3.c Ach-3/fifo.h
	gcc $(CFLAGS) -c $^

arenaA3.o: Ach-3/arenaA3.c Ach-3/arena.h Ach-3/board.h
	gcc $(CFLAGS) -c $^

friendA3.o : Ach-3/friendA3.c Ach-3/friend.h Ach-3/arena.h
	gcc $(CFLAGS) -c $^

test-Achievement3: test-Achievement3.o fifoA3.o playerA3.o boardA3.o gameA3.o arenaA3.o friendA3.o
	gcc $(CFLAGS) $^ -o test-A3 && ./test-A3

test-Achievement3.o: Ach-3/test-Achievement3.c Ach-3/game.h
	gcc $(CFLAGS) -c $^





clean: clean-root clean-Baseline clean-Achievement1 clean-Achievement2 clean-Achievement3

clean-root:
	rm -f project* *.o *.gch *~ *# test*

clean-Baseline:
	rm -f -r  Baseline/*.o Baseline/*.gch Baseline/*~ Baseline/*# 

clean-Achievement1:
	rm -f -r  Ach-1/*.o Ach-1/*.gch Ach-1/*~ Ach-1/*#

clean-Achievement2:
	rm -f -r  Ach-2/*.o Ach-2/*.gch Ach-2/*~ Ach-2/*#

clean-Achievement3:
	rm -f -r  Ach-3/*.o Ach-3/*.gch Ach-3/*~ Ach-3/*#
