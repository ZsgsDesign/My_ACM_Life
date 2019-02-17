#include<stdio.h>
#include<string.h>

int tri[1002][1002];
int n;
int main()
{
	memset(tri,0,sizeof(tri));
	scanf("%d",&n);
	tri[1][1]=1;
	int i,j;
	for(i=2;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			tri[i][j]=tri[i-1][j]+tri[i-1][j-1];
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf("%5d",tri[i][j]);
		}
		printf("\n");
	}
	return 0;
}
