#include <stdio.h>
#include<string.h>


char *strins(char *p, char *s)
{	char aux[20];
	strcpy(aux,p);
	strcpy(p,s);
	strcat(p,aux);}

char *strdel(char *p, int n) //sterge n caractere din poz p
{	char aux[20];
	if ( n< strlen(p)){
		strcpy(aux,p+n);
		strcpy(p,aux);}
	else *p='\0';
	return 0;}

int main()
{ char s1[20], s2[20], s3[20];
	fgets(s1, sizeof(s1), stdin);
	fgets(s2, sizeof(s2), stdin);
	fgets(s3, sizeof(s3), stdin);
strdel(s1, s2);
strins(s1, s3);
printf("%s", s1);
return 0;}
