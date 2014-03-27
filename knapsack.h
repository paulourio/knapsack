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

#ifndef KNAPSACK_H_INCLUDED
#define KNAPSACK_H_INCLUDED

typedef struct KObj
{
	float p;
	float v;
	char *name;
} k_obj;

float coef(k_obj obj);
void open_problem(char *filename, int *n, int *k, k_obj **obj);
void solve_problem(int n, int k, k_obj **objs, int **x);
void sel_sort(int n, k_obj ***objs);

#endif /* KNAPSACK_H_INCLUDED */
