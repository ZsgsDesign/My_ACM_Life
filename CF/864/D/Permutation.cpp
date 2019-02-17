#include<bits\stdc++.h>

using namespace std;
int seq[200002],num[200002],waste[200002],queue_num[200002];
int n;

int search_first()
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(num[i]==0)break;
	}
	return i;
}
int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		num[i]=0;
	} 
	for(int i=1;i<=n;i++)
	{
		cin >> seq[i];
		num[seq[i]]++;
	}
	int flag=1;
	for(int i=1;i<=n;i++)
	{
		if(!num[i])
		{
			queue_num[flag]=i;
			flag++;
		}
	}
	flag=1;//当前第一个没有被使用的数字的下标 
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(num[seq[i]]>1)
		{
			if(queue_num[flag]<seq[i] || waste[seq[i]]==1)
			{
				num[seq[i]]--;
				//left_num[seq[i]]--;
				seq[i]=queue_num[flag];
				num[queue_num[flag]]++;
				ans++;
				flag++; 
				if(!queue_num[flag])break;
			}
			else if(queue_num[flag]>seq[i]) 
			{
				waste[seq[i]]++;
			}
		}
	} 
	cout << ans << endl;
	for(int i=1;i<=n;i++)
	{
		cout << seq[i];
		if(i==n) cout << endl;
		else cout << " ";
	}
	return 0;
}
