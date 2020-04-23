#include<stdio.h>
#include<stdlib.h>

int main(){

int n1, *vim1;
int n0, *vi;
int i, j, k, n, *p;

vim1 = (int*) malloc(n1 * sizeof(int));
vi = (int*) malloc(n * sizeof(int));

vim1[0] = 1; n1 = 1;
vi[0] == 1; vi[1] = 1; n0 = 2;

scanf("%d%d", &n, &k);
i=1;

while(i < n) {
	p=vim1; vim1 = vi; vi = p;
	n1 = n0;

	n0++;
	vi =(int*)realloc(vi, n0 * sizeof(int));
	vi[0] = 1;
		for(j = 1; j < n0; j++)
			vi[j] = vim1[j-1];
	vi[n0 -1] = 1;
	i++;
}
 printf("%d\n", vi[k]);
return 0;

}
