#include<stdio.h>
#include<string.h>

int seq[22];
int comp(const void*a,const void*b){return *(int*)a-*(int*)b;}

int main()
{
	int i,sum=0;
	for(i=0;i<20;i++)
	{
		scanf("%d",&seq[i]);
		sum+=seq[i];
	}
	qsort(seq,20,sizeof(int),comp);
	int seq_min=seq[0],seq_max=seq[19];
	int j=0;
	while(seq[j]==seq_min)
	{
		i--;
		j++;
		sum-=seq_min;
	}
	j=19;
	while(seq[j]==seq_max)
	{
		i--;
		j--;
		sum-=seq_max;
	}
	printf("count=%d,average=%.2f\n",i,(double)sum/i);
	return 0;
}
