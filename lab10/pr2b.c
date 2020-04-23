#include<stdio.h>
#include<stdlib.h>

struct multime {
	unsigned int n;
	unsigned char *a;
}


void init(struct multime *m)
{
        m->a = 0;
}

void add(struct multime *m, int x)
{
        m->a = m->a | (1 << x);
}

void del(struct multime *m, int x)
{
        m->a = m->a & ~(1 << x);
}

int contains(struct multime *m, int x)
{
        return m->a & (1 << x);
}

void print(struct multime *m)
{
        int i;
        printf("{ ");
        for (i = 0; i < 8; i++)
                if (contains(m, i))
                        printf("%d ", i);
        printf("}\n");
}

int main(){

int ord;
int(*cmps[2])(const int, const int) = { cmp_cresc, cmp_desc};
printf("Alegeti tipul functiei; 
    A nr - adaugă numărul nr în mulţime
    D nr - elimină numărul nr din mulţime
    C nr - contains( nr ) - dacă nr se află în mulţime, afişaţi DA, altfel NU
    P  - afişează elementele mulţimii separate prin spaţiu
");
scanf("%d", ord);







}
