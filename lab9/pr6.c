#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pereche {
        char *cuv;
        int ap;
} Pereche;

int find(Pereche **vec, int n, char *cuv)
{
        int i;
        for (i = 0; i < n; i++)
                if (strcmp(vec[i]->cuv, cuv) == 0)
                        return i;
        return -1;
}

Pereche *newPereche(char *a)
{
        Pereche *p = (Pereche*) malloc (sizeof(Pereche));
        p->cuv = strdup(a);
        p->ap = 1;
        return p;
}

int main()
{
        int i, idx, n, nd = 0, cap = 4;
        char cuv[1000];
        Pereche **vec;
        int *ap;

        printf("n = ");
        scanf("%d", &n);

        /* initializare vectori */
        vec = (Pereche**) malloc (cap * sizeof(Pereche*));

        for (i = 0; i < n; i++) {
                scanf("%s", cuv);
                idx = find(vec, nd, cuv);

                if (idx != -1)
                        vec[idx]->ap++;
                else {

                        if (cap == nd) {
                                /* realocare */
                                cap *= 2;
                                vec = (Pereche**) realloc (vec, cap * sizeof(Pereche*));
                        }

                        /* adaugare la vector */
                vec[nd] = newPereche(cuv);
                nd++;
                }
        }
        
        /* afisare rezultat */
        for (i = 0; i < nd; i++)
                printf("%s %d\n", vec[i]->cuv,vec[i]->ap);

        /* eliberare memorie */
        for (i = 0; i < nd; i++) {
                free(vec[i]->cuv);
                free(vec[i]);
        }
        free(vec);

        return 0;
}
