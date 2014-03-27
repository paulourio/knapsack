CC=clang
CFLAGS=-Wall -Wextra

problem: main.o knapsack.o
	$(CC) $(LDFLAGS) main.o knapsack.o -o problem

main.o: main.c knapsack.h
	$(CC) $(CFLAGS) -c main.c

knapsack.o: knapsack.c knapsack.h
	$(CC) $(CFLAGS) -c knapsack.c

clean:
	$(RM) *.o
