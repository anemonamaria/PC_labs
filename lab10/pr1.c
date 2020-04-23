#include <stdio.h>
#include <math.h>

double integrala(double (*func)(double x), double a, double b, int n)
{
        double sum = 0, x1, x2, pas = (a - b) / n;
        int i;
        for (i = 1; i < n; i++) {
                x1 = pas * (i - 1);
                x2 = pas * i;
                //aria trapezului = (b + B) * H / 2
                sum += (func(x1) + func(x2)) * pas / 2;
        }
        return sum;
}            

int main()
{	double a, b;
	int n;
	scanf("%lf %lf %d", &a, &b, &n);
        printf("Integrala din sin(x) de la 0 la PI = %.2f\n",
                        integrala(sin, a, b, n));
        printf("Integrala din cos(x) de la 0 la PI = %.2f\n",
                        integrala(cos, a, b, n));
        return 0;
}

