#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* my_replace(char *s, char *s1, char *s2){
	char *result;
	char *ins;
	char *tmp;
	int len_s1;
	int len_s2;
	int len_front;
	int count;

if (!s || !s1)
	return 	NULL;
len_s1 = strlen(s1);
if (len_s1 == 0)
	return NULL;
if (!s2)
	s2= " ";
len_s2=strlen(s2);

ins=s;
for(count=0; tmp = strstr(ins,s1); ++count) {
	ins = tmp +len_s1;
}

tmp = result = malloc(strlen(s) + (len_s2 -len_s1) * count +1);

if (!result)
	return NULL;

while (count--){
	ins=strstr(s, s1);
	len_front= ins - s;
	tmp = strncpy(tmp, s, len_front) + len_front;
	tmp = strcpy(tmp,s2) +len_s2;
	s+= len_front + len_s1;
}

strcpy(tmp, s);
return result;
}

int main()
{ char s[100], s1[100], s2[100];
fgets(s, sizeof(s), stdin);
fgets(s1, sizeof(s1), stdin);
fgets(s2, sizeof(s2), stdin);

puts (my_replace(s, s1, s2));

return 0;
}
