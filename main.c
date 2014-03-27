/*
 ============================================================================
 Name        : main.c
 Author      : Geovane Fedrecheski
 Version     : 0.0.1
 Copyright   : This software is licensed under MIT license - 
 				(http://opensource.org/licenses/MIT)
 Description : 
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../../../array_int/array_int.h"
#include "knapsack.h"

int main(int argc, char *argv[]) 
{
	char *filename;
	int i, n, k;
	int *x;
	k_obj *objs;

	if (argv[1]) 
		filename = argv[1];
	else
		filename = "../data/test1.in";

	open_problem(filename, &n, &k, &objs);

	solve_problem(n, k, &objs, &x);

	free(objs);
	return EXIT_SUCCESS;
}
