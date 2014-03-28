/* Copyright © 2014 Geovane Fedrecheski <geonnave@gmail.com> */
#include <stdlib.h>

#include "knapsack.h"

#define DEFAULT_FILENAME "../data/test1.in"

int main(int argc, char *argv[]) 
{
	const char *filename = (argc > 1)? argv[1]: DEFAULT_FILENAME;
	struct problem_t problem;
	
	knapsack_init(&problem);
	if (knapsack_open(filename, &problem)) {
		knapsack_solve(&problem);
		knapsack_print_solution(&problem);
	}
	knapsack_free(&problem);
	return EXIT_SUCCESS;
}
