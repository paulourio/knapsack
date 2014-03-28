CFLAGS=-Wall -Wextra
OUT=problem

problem: main.o knapsack.o
	$(CC) $(LDFLAGS) main.o knapsack.o -o $(OUT)

main.o: main.c knapsack.h
	$(CC) $(CFLAGS) -c main.c

knapsack.o: knapsack.c knapsack.h
	$(CC) $(CFLAGS) -c knapsack.c

clean:
	$(RM) *.o $(OUT)
