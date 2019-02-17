#include<bits\stdc++.h>

int seq[2][100002],seq_appear[2][200002],n;
char seq_temp[100002];
using namespace std;

int main()
{
	cin >> n ;
	int c1=0,c0=0;
	scanf("%s",seq_temp+1);
	for(int i=1;i<=n;i++)
	{
		if(seq_temp[i]=='1')
		{
			seq[0][i]=1;
			c1++;
		}
		else seq[0][i]=-1;
	}
	int count_seq=0,count_seq_max=0,count_seq_min=200000;
	for(int i=0;i<=200001;i++)
	{
		seq_appear[0][i]=200002;
		seq_appear[1][i]=0;
	}
	for(int i=1;i<=n+1;i++)
	{
		seq[1][i]=count_seq;
		seq_appear[0][count_seq+100000]=min(seq_appear[0][count_seq+100000],i);//值为count_seq的起始坐标 
		seq_appear[1][count_seq+100000]=max(seq_appear[1][count_seq+100000],i);//值为count_seq的结束坐标 
		count_seq_max=max(count_seq_max,count_seq+100000);
		count_seq_min=min(count_seq_min,count_seq+100000);
		count_seq+=seq[0][i];

	}
	int ans=0; 
	for(int i=count_seq_min;i<=count_seq_max;i++)
	{
		ans=max(ans,seq_appear[1][i]-seq_appear[0][i]);
	}
	cout << ans << endl;
	return 0;
} 
