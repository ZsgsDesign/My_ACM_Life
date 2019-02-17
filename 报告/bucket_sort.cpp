#include<string.h>
#include<stdio.h>

int seq[100002]={9,5,1,6,3,6,5,7,4,7,5,8,3,1,4,6,2},bucket[1000002];

int main()
{
	memset(bucket,0,sizeof(bucket));
	//只有整数可以 
	for(int i=0;i<17;i++) bucket[seq[i]]++;
	int cur=0,flag=0;
	while(1)
	{
		if(cur==17)break;
		if(!bucket[flag])flag++;
		else
		{
			seq[cur]=flag; 
			bucket[flag]--;
			cur++;
		}
	}
	for(int i=0;i<17;i++)printf("%d ",seq[i]);
	return 0;
}
