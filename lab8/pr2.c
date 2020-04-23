#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{ int *v, i, n, cap, nr;
n = 0;
cap = 5;
v=(int*) malloc(cap*sizeof(int));
scanf("%d", &nr);
while(nr != 0){
if ( cap == n) {
		cap *=2;
		v = realloc(v, cap * sizeof(int));
		}
	v[n++] = nr;
	scanf("%d", &nr);
}
for (i =0 ; i < n; i++)
	printf("%d ", v[i]);
printf("\n");
return 0;
}
