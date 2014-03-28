/* Copyright © 2014 Geovane Fedrecheski <geonnave@gmail.com> */
#include "knapsack.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OBJECT_NAME 12

struct object_t {
	char name[MAX_OBJECT_NAME];
	float p;
	float v;
};

void knapsack_init(struct problem_t *p)
{
	assert(p != NULL);
	memset(p, 1, sizeof(*p));
}

static int read_object(FILE *fp, struct object_t *obj)
{
	int ret = fscanf(fp, "%s %f %f", obj->name, &obj->p, &obj->v);
	if (ret != 3)
		printf("Invalid input format. Aborting.\n");
	return ret == 3;
}

/* Opens |filename| and read the problem into |p|.  Returns whether the 
 * problem has been loaded correctly. */
int knapsack_open(const char *filename, struct problem_t *p)
{
	FILE *fp;
	int i, ret;

	fp = fopen(filename, "r");
	assert(fp != NULL);

	ret = fscanf(fp, "%d %d", &p->n, &p->k);
	assert(ret == 2);
	
	p->objs = malloc(sizeof(p->objs[0]) * ((size_t) p->n));
	assert(p->objs != NULL);

	for (i = 0; i < p->n; i++)
		if (!read_object(fp, &p->objs[i]))
			return 0;
	fclose(fp);
	return 1;
}

void knapsack_free(struct problem_t *p)
{
	free(p->objs);
}

static int compare_objects(const void *a, const void *b)
{
	const struct object_t *obj_a = a;
	const struct object_t *obj_b = b;
	const float delta = obj_a->p - obj_b->p;

	if (delta > 0)
		return 1;
	if (delta < 0)
		return -1;
	return 0;
}

static void selection_sort(struct problem_t *p)
{
	int i;
	
	for (i = 0; i < p->n - 1; ++i) {
		int j, min; 
		
		min = i;
		for (j = i + 1; j < p->n; ++j)
			if (compare_objects(&p->objs[i], &p->objs[j]) > 0)
				min = j;
		if (min != i) {
			struct object_t aux;
			
			memcpy(&aux, &p->objs[i], sizeof(p->objs[0]));
			memcpy(&p->objs[i], &p->objs[min], sizeof(p->objs[0]));
			memcpy(&p->objs[min], &aux, sizeof(p->objs[0]));
		}
	}
}

static void quick_sort(struct problem_t *p)
{
	qsort(p->objs, (size_t) p->n, sizeof(p->objs[0]), compare_objects);
}

static void sort_objects(struct problem_t *p)
{
	selection_sort(p);
	quick_sort(p);
}

static void print_objects(const struct problem_t *p)
{
	int i;
	
	printf("Object list:\n");
	for (i = 0; i < p->n; i++) {
		const struct object_t *o = &p->objs[i];
		
		printf("%d: %s %f %f\n", i + 1, o->name, o->p, o->v);
	}
}

void knapsack_solve(struct problem_t *p)
{
	assert(p->n > 0);
	
	print_objects(p);
	sort_objects(p);
	print_objects(p);
}

void knapsack_print_solution(const struct problem_t *p)
{
	printf("Not implemented yet. %p.\n", p);
}
