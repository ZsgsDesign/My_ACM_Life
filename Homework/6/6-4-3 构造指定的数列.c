#include<stdio.h>
#include<string.h>

int ans[1002];
int a,b;

int fun(int a,int b)
{
	int i,j=1;
	for(i=a;i<=b;i++)
	{
		if( (!(i%7) || !(i%11)) && i%77)
		{
			ans[j]=i;
			j++;
		}
	}
	return j-1;
}


int main()
{
	scanf("%d%d",&a,&b);
	int count=fun(a,b);
	int i;
	for(i=1;i<=count;i++)
	{
		printf("%d",ans[i]);
		if(i==count)printf("\n");
		else printf(" "); 
	}
	return 0;
}
