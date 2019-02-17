#include<stdio.h>

int count[1002]={0},ans[1002]={0}; 
int i,maxn,flag,temp;

int main()
{
	while(1)
	{
		scanf("%d",&temp);
		if(temp==-1)break;
		count[temp]++;
	}
	maxn=count[0];
	flag=1;
	for(i=1;i<=999;i++)
	{
		if(count[i]>maxn)
		{
			maxn=count[i];
			flag=0;
		}
		if(count[i]==maxn)
		{
			ans[flag]=i;
			flag++;
		}
	}
	for(i=0;i<flag;i++)
	{
		printf("%d",ans[i]);
		if(i==flag-1) printf("\n");
		else printf(" ");
	}
	return 0;
}
