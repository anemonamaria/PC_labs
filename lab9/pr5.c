#include <stdio.h>

#define NMAX 100

typedef struct complex {
        float re, im;
} complex;

complex adunare(complex a, complex b)
{
        complex c;
        c.re = a.re + b.re;
        c.im = a.im + b.im;
        return c;
}



complex inmultire(complex a, complex b)
{
        complex c;
        c.re = a.re * b.re - a.im * b.im;
        c.im = a.im * b.re + a.re * b.im;
        return c;
}

complex putere(complex a, int putere)
{
        complex c;
        int i;
        c.re = 1;
        c.im = 0;
        for (i = 0; i < putere; i++)
                c = inmultire(c, a);
        return c;
}

void scrie(complex a)
{
        printf("(%.2f, %.2f)\n", a.re, a.im);
}

int main()
{
        int n, i;
        float c[NMAX];
        complex x, p, aux;

        

        printf("x.re = ");
        scanf("%f", &x.re);
        printf("x.im = ");
        scanf("%f", &x.im);

        p.re = p.im = 0;
	scanf("%d", &n);
        printf("Cei n+1 coeficienti: ");
        for (i = 0; i <= n; i++)
                scanf("%f", &c[i]);
        for (i = 0; i <= n; i++) {
                aux.re = c[i];
                aux.im = 0;
                p = adunare(p, inmultire(aux, putere(x, i)));
        }
        scrie(p);
        return 0;
}

