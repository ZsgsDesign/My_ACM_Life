#include<stdio.h>

int a[52]={0};

int main()
{
	int i;
	a[1]=1;
	a[2]=1;
	for(i=3;i<=20;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
	scanf("%d",&i);
	printf("%d\n",a[i]);
	return 0;
}
