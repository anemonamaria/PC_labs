#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXN 1000
#define MAX_VALUE 200

int cmp(const void * a, const void *b)
{
    return (*(int*)a - *(int*)b);
}


int comp(const void *a, const void *b)
{
        return *(int*)a - *(int*)b; // cast la pointer la intreg mai intai
        // apoi accesam valoarea si returnam rezultatul
}

int main(void)
{
    int N, i, x, *poz;
    int *v;
    printf("Introduceti dimensiunea vectorului:\n");
    scanf("%d", &N);

    v = calloc(N, sizeof(int));
    if (!v) printf("Nu am putut aloca memorie pentru v!\n");

    srand(time(NULL));
    for (i = 0; i < N; ++i)
        v[i] = (rand() % MAX_VALUE)+1;

    for (i = 0; i < N; ++i)
        printf("%d ", *(v+i));
    printf("\n");

    qsort(v, N, sizeof(int), cmp);

    for (i = 0; i < N; ++i)
        printf("%d ", *(v+i));
    printf("\n");

    printf("x = ");
    scanf("%d", &x);
    poz = (int*)bsearch(&x, v, N, sizeof(int), comp);
    printf("Pozitia pe care se afla %d: %ld\n", x, poz - v);    

    free(v);
    return 0;
}