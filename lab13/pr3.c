
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct entry {
        void *key;
        void *value;
} entry;

typedef struct map {
        entry **elem; // vectorul de elemente; este alocat si realocat dinamic
        int n_elem; // numarul de elemente din vector
        int cap; // capacitatea vectorului
} map;

void init(map *m, int cap)
{
        m->elem = (entry**) malloc (cap * sizeof(entry*));
        m->cap = cap;
        m->n_elem = 0;
}

void add(map *m, entry *e)
{
        if (m->cap == m->n_elem) {
                m->cap *= 2;
                m->elem = (entry**) realloc (m->elem, m->cap * sizeof(entry*));
        }
        m->elem[m->n_elem] = e;
        m->n_elem++;
}

void printEntry(entry * e)
{
        printf("%s - %s\n", (char*)e->key, (char*)e->value);
}

void print(map *m, void (*printEntry) (entry *))
{
        int i;
        for (i = 0; i < m->n_elem; i++)
                printEntry(m->elem[i]);
}

void sort(map *m, int (*fc) (const void *, const void *))
{
        qsort(m->elem, m->n_elem, sizeof(entry*), fc);
}

// intoarce elementul de pe pozitia eliminata, pentru a putea fi
// eventual dealocata memoria ocupata de acesta
void *del(map *m, void *k, int (*fc)(const void*, const void*))
{
        int i;
        void *aux;
        for (i = 0; i < m->n_elem; i++)
                if (fc(k, m->elem[i]->key) == 0)
                        break;
        if (i < m->n_elem) { //am gasit elementul
                aux = m->elem[i];
                m->elem[i] = m->elem[m->n_elem - 1]; // punem in locul elementului pe care
                // il stergem elementul de pe ultima pozitie
                m->n_elem--;
                return aux;
        }
        else 
                return NULL;
}

void *find(map *m, void *k, int (*fc2)(const void*, const void*))
{
        int i;
        for (i = 0; i < m->n_elem; i++)
                if (fc2(k, m->elem[i]->key) == 0)
                        return m->elem[i];
}

int compareKey(const void *a, const void *b)
{
        return - strcmp((char*)a, (char*)b);
}

// returneaza 0 daca sunt egale, -1 altfel
int compareEntry(const void *a, const void *b)
{
        entry *x = *(entry**)a, *y = *(entry**)b;
        return compareKey(x->key, y->key);
}

void freeEntry(entry * e)
{
        free(e->key);
        free(e->value);
        free(e);
}

void freeMapContent(map *m)
{
        int i;
        for (i = 0; i < m->n_elem; i++)
                freeEntry(m->elem[i]);
        free(m->elem);
}              

int main()      
{
        int op;
        char buffer[1000];
        map m;
        entry *e;

        init(&m, 10);

        do {
                printf("\nMeniu\n");
                printf("1. Afisare dictionar sortat.\n");
                printf("2. Cauta cuvant in dictionar.\n");
                printf("3. Adauga cuvant in dictionar.\n");
                printf("4. Sterge cuvant din dictionar.\n");
                printf("0. Iesire din program.\n");
                printf("Optiunea: ");
                scanf("%d", &op);
                getchar(); // goleste bufferul de "\n"
                printf("\n");

                switch (op) {
                        case 1:
                                sort(&m, compareEntry);
                                print(&m, printEntry);
                                break;
                        case 2:
                                printf("Cuvantul cautat: ");
                                fgets(buffer, 1000, stdin);
                                buffer[strlen(buffer) - 1] = '\0';
                                e = find(&m, buffer, compareKey);
                                if (e == NULL)
                                        printf("Cuvantul nu a fost gasit.\n");
                                else
                                        printEntry(e);
                                break;
                        case 3:
                                e = (entry*) malloc (sizeof(entry));
                                printf("Introduceti cuvantul: ");
                                fgets(buffer, 1000, stdin);
                                buffer[strlen(buffer) - 1] = '\0';
                                e->key = strdup(buffer);
                                printf("Introduceti explicatia: ");
                                fgets(buffer, 1000, stdin);
                                buffer[strlen(buffer) - 1] = '\0';
                                e->value = strdup(buffer);
                                add(&m, e);
                                break;
                        case 4:
                                printf("Cuvantul cautat: ");
                                fgets(buffer, 1000, stdin);
                                buffer[strlen(buffer) - 1] = '\0';
                                e = del(&m, buffer, compareKey);
                                if (e == NULL)
                                        printf("Cuvantul nu a fost gasit.\n");
                                else {
                                        printf("Cuvantul a fost sters din dictionar.\n");
                                        freeEntry(e);
                                }
                                break;  
                                break;
                }

        } while (op);

        freeMapContent(&m);

        return 0;
}
