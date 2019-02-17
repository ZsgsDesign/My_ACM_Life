#include<stdio.h>
#include<string.h>

int n,min,min_cur;
int seq[105];

int main()
{
	memset(seq,0,sizeof(seq));
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&seq[i]);
		if(i==1 || seq[i]>min)
		{
			min=seq[i];
			min_cur=i;		
		}
	}
	if(min_cur!=1)
	{
		int temp=seq[1];
		seq[1]=seq[min_cur];
		seq[min_cur]=temp;
	}
	for(i=1;i<=n;i++)
	{
		printf("%d%c",seq[i],i==n?'\n':' ');
	}
	return 0;
}
