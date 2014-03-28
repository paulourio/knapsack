/* Copyright © 2014 Geovane Fedrecheski <geonnave@gmail.com> */
#ifndef KNAPSACK_H_
#define KNAPSACK_H_

struct object_t;

struct problem_t {
    int n;   /* Object count */
    int k;   /* Knapsack capacity */
    int* x;  /* Solution */
    struct object_t *objs;  /* Object list */
};

extern void knapsack_init(struct problem_t *p);

extern void knapsack_free(struct problem_t *p);

extern int knapsack_open(const char *filename, struct problem_t *p);

extern void knapsack_solve(struct problem_t *p);

extern void knapsack_print_solution(const struct problem_t *p);

#endif /* KNAPSACK_H_ */
