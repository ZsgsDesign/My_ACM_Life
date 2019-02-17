#include<bits\stdc++.h>

using namespace std;
char seq[202];
int main()
{
	int n,ans=0;
	cin >> n;
	//getchar();
	//getchar();
	/*
	for(int i=1;i<=n;i++)
	{
		char temp=getchar();
		seq[i]=temp;
	}
	*/
	scanf("%s",seq+1);
	int i=1;
	while(i<=n)
	{
		if(seq[i]>=97)
		{
			int j=0;
			for(int k=i;k<=n;k++)
			{
				//iÆðµã£¬jÖÕµã
				if(seq[k]<97)
				{
					j=k-1;
					break;
				}
				if(k==n)j=n;
			}
			if(j==0)break;
			int num[128],ans_temp=0;
			for(int o=0;o<=127;o++)num[o]=0;
			for(int k=i;k<=j;k++)
			{
				num[seq[k]]++;
				if(num[seq[k]]==1)ans_temp++;
			}
			if(ans_temp>ans)ans=ans_temp;
			i=j+2;
		}
		else
		{
			i++;
		}
	}
	cout << ans << endl;
	return 0;
} 
