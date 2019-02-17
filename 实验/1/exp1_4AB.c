#include<stdio.h>

int is_prime(int num)
{
	if(num<=1)return 0;
	int i;
	for(i=2;i<num;i++) if(num%i == 0) return 0;
    return 1;
}

int a,b,flag=1;

int main()
{
	while(flag)
	{
		scanf("%d%d",&a,&b); 
		if(a>=10 && b>=a && b<=1000)flag=0;
	}
	int n=1,i;
	for(i=a+1;i<b;i++)
	{
		if(is_prime(i))
		{
			printf("%d",i);
			if(!(n%5))printf("\n");
			else printf(" ");
			n++;
		}
	}
	printf("\n");
	return 0;
}
