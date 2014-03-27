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

void solve_problem(int n, int k, k_obj **objs, int **x)
{
	int i;

	sel_sort(n, &objs);
}

void sel_sort(int n, k_obj ***objs)
{
	int i, j, m;
	printf("%f\n", (*(*objs))[0].p);
	// for (i = 0; i < n-1; i++) {
	// 	m = i;
	// 	for (j = i+1; j < n; j++) {
	// 		if (coef((*objs)[j]) < coef((*objs)[m]))
	// 			m = j;
	// 	}

	// }
}

float coef(k_obj obj)
{
	return (obj.v/obj.p);
}

void open_problem(char *filename, int *n, int *k, k_obj **objs)
{
	FILE *ifp;
	int i;
	float p, v;
	char name[10];

	ifp = fopen(filename, "r");

	if (ifp == NULL) {
		fprintf(stderr, "Cannot open file %s!\n", filename);
		exit(0);
	}

	fscanf(ifp, "%d %d", n, k);

	(*objs) = malloc(sizeof(k_obj) * *n);

	for (i = 0; i < *n; i++) {
		fscanf(ifp, "%s %f %f", name, &p, &v);
		(*objs)[i].name = malloc(sizeof(char));
		strcpy((*objs)[i].name, name);
		(*objs)[i].p = p;
		(*objs)[i].v = v;
	}

	fclose(ifp);
}
