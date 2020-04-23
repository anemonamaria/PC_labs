#include<stdio.h>
#include<string.h>

char *substr(char src, int n2, char *dest){
char aux[20];
strncpy(aux, src, n2);
strcpy(src, aux);
return aux;
}

int main()
{
char s[20], s2[20];
int n1, n2;
fgets(s, sizeof(s), stdin);
scanf("%d%d", &n1, &n2);
substr(s+n1, n2, s2);
printf("%s", s2);
return 0;
}
