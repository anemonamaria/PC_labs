#include<stdio.h>

void count(int n, int *v, int *zero, int *poz, int *neg){
 int i;
*zero=0;
*poz=0;
*neg=0;
for(i=0;i<n;i++)
{ if (v[i]==0) *zero=*zero+1;
	else if (v[i]>0) *poz=*poz+1;
		else *neg=*neg+1;
}

}

int main()
{int n, v[50], i, zero, poz, neg;
scanf("%d", &n);
for(i=0;i<n;i++){
	 scanf("%d", &v[i]);}

count(n, v, &zero, &poz, &neg);

printf(" nule:%d\n", zero);
printf(" pozitive:%d\n", poz);
printf("negative:%d \n", neg);
return 0;
}
