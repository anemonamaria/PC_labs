#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
int n, i;
char (*cuvinte_u)[20] = NULL, (*cuvinte)[20];
int *aparitii;
scanf("%d\n", &n);
cuvinte= (char (*)[20]) malloc (n * sizeof(char[20]));

i=0;
while(i<n) {
	scanf("%s", cuvinte[i]);
	i++;
}
int dim = 4, unice =0,  k;
cuvinte_u = (char (*)[20]) malloc(dim * sizeof(char[20]));
for(i = 0; i<n; i++){
	int found = 0;
	for(k=0;k< unice; k++){
		if (strcmp(cuvinte_u[k], cuvinte[i]) == 0) {
			aparitii[k]++;
			found = 1;
}
}
	if (found != 1) {
		if (unice >= dim) {
			dim *= 2;
			aparitii = (int *) realloc(aparitii, dim * sizeof(int));
			cuvinte_u = (char (*)[20]) realloc(cuvinte_u, dim * sizeof(char[20]));
}
		strcpy(cuvinte_u[unice], cuvinte[i]);
		aparitii[unice] = 1;
		unice++;

}
}
for (i=0; i < unice; i++) {
	printf("%s %d\n", cuvinte_u[i], aparitii[i]);
}
free(aparitii);
free(cuvinte_u);
free(cuvinte);
return 0;
}
