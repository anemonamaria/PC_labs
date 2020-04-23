#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef enum { C, S, A } tip;

typedef struct MATERIA {
        char nume[16];
        int ore_curs;
        tip tip_examen;
} MATERIA;

int citire_MAT(MATERIA *mat)
{
        int i, n;
        char ch;

        getchar(); // golim bufferul de "\n"

        printf("Nume: ");
        fgets(mat->nume, 16, stdin);
        n = strlen(mat->nume);
        mat->nume[n - 1] = '\0';
        n--;
        for (i = 0; i < n; i++)
                if (!isalpha(mat->nume[i]) && !isblank(mat->nume[i]))
                        return -1;

        printf("Ore curs: ");
        scanf("%d", &mat->ore_curs);
        if (mat->ore_curs <= 0)
                return -1;
        getchar(); // golim bufferul de "\n"
        printf("Tip examen (C / S / A): ");
        scanf("%c", &ch);
        switch (tolower(ch)) {
                case 'c': mat->tip_examen = C; break;
                case 's': mat->tip_examen = S; break;
                case 'a': mat->tip_examen = A; break;
                default: return -1;
        }
        return 0;
}

void citire_PROGRAMA(MATERIA prog[], int n)
{
        int i, ok;
        for (i = 0; i < n; i++) {
                printf("Introduceti datele pentru materia %d.\n", i);
                ok = citire_MAT(&prog[i]);
                while (ok == -1) {
                        printf("Date gresite. Reintroduceti datele.\n");
                        ok = citire_MAT(&prog[i]);
                }
        }
}

void afisare(char ch, int nr, MATERIA prog[], int n)
{
        int i;
        tip tp;
        switch (tolower(ch)) {
                case 'c': tp = C; break;
                case 's': tp = S; break;
                case 'a': tp = A; break;
        }
        printf("Materiile care au tipul %c si numarul de ore egal cu %d:\n", ch, nr);
        for (i = 0; i < n; i++)
                if (prog[i].tip_examen == tp && prog[i].ore_curs == nr)
                        printf("%s\n", prog[i].nume);
}

int main()
{
        MATERIA PROGRAMA[MAX];
        int n, nr;
        char ch;
        printf("Introduceti numarul de materii: ");
        scanf("%d", &n);
        citire_PROGRAMA(PROGRAMA, n);
        getchar(); //golim bufferul de "\n"
        printf("Tipul examenului: ");
        scanf("%c", &ch);
        printf("Numarul de ore: ");
        scanf("%d", &nr);
        afisare(ch, nr, PROGRAMA, n);
        return 0;
}

