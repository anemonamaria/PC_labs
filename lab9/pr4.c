
#include <stdio.h>
#include <stdlib.h>

typedef struct vector {
        int *v;
        int cap;
        int n;
} vector;

void init_vector(vector *a, int nr)
{
        a->cap = nr;
        a->n = 0;
        a->v = (int*) malloc (nr * sizeof(int));
}

void adauga_vector(vector *a, int n)
{
        if (a->cap == a->n) {
                a->cap *= 2;
                a->v = (int*) realloc (a->v, a->cap * sizeof(int));
        }
        a->v[a->n] = n;
        a->n++;
}

void scrie_vector(vector *a)
{
        int i;
        for (i = 0; i < a->n; i++)
                printf("%d ", a->v[i]);
        printf("\n");
}

int main()
{
        vector v;
        int i;
        init_vector(&v, 100);
        for (i = 1; i <= 100; i++)
                adauga_vector(&v, i);
        scrie_vector(&v);
        return 0;
}

