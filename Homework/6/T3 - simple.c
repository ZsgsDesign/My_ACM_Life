#include<stdio.h>
#include<string.h>

int seq[22];

int main()
{
	int i,sum=0,count=20;
	for(i=1;i<=count;i++)
	{
		scanf("%d",&seq[i]);
		sum+=seq[i];
	}
	int seq_max=seq[1],seq_min=seq[1];
	for(i=1;i<=20;i++)
	{
		if(seq[i]>seq_max)seq_max=seq[i];
		if(seq[i]<seq_min)seq_min=seq[i];
	}
	for(i=1;i<=20;i++)
	{
		if(seq[i]==seq_max)
		{
			count--;
			sum-=seq_max;
		}
		if(seq[i]==seq_min)
		{
			count--;
			sum-=seq_min;
		}
	}
	printf("count=%d,average=%.2f\n",count,(double)sum/count);
	return 0;
}
