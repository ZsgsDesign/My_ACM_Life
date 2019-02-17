#include<bits\stdc++.h>

char seq[200004];
char seq_c[200004]; 
int n,flag;
using namespace std;

int search_prefix(int a)
{
	int ans=0;
    for(int i=0;i<strlen(seq);i++)
    {
        if(seq[i]==seq_c[0])
        {
            int j;
            for(j=1;j<a;j++)
            {
                if(seq[i+j]!=seq_c[j])break;
            }
            if(j==a)ans++;
        }
    }	
	return ans;
} 

int main()
{
	memset(seq,0,sizeof(seq));
	memset(seq_c,0,sizeof(seq_c));
	cin.getline(seq,200000,'\n');
	cin.getline(seq_c,200000,'\n');
	cin >> n;
	int k1=1,k2=strlen(seq_c);
	int ans=0;
	if(search_prefix(1)>=n)
	{
		while(true)
		{
			if(abs(k1-k2)<=1)
			{
				if(search_prefix(k2)>=n)ans=k2;
				else ans=k1;
				break;
			}
			else
			{
				//每次除以2再比较 
				//找出第一个小于的
				// 12345 54 12 10 10 6
				// q=10
				int k=(k1+k2)/2; // 0 4 = 1 
				//search_prefix(k);
			    if(search_prefix(k)>=n)
				{
					k1=k;
				}	
				else
				{
					k2=k-1;
				}
			}
		} 
	}
	else
	{
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	/* 
	for(k=1;k<=strlen(seq_c);k++)
	{
		ans=0;
		flag=0;
		for(int i=0;i<init_seq_len;i++)
		{
			if(k > strlen(seq)-init_seq[i]) break;
			if(seq[init_seq[i]]==seq_c[0])
			{
				init_seq[flag]=init_seq[i];
				flag++;
				//上面先更新下init_seq，下面再执行对比 
				int j;
				for(j=1;j<k;j++)
				{
					if(seq[init_seq[i]+j]!=seq_c[j]) break;
				}
				if(j==k)ans++;
			}
		}
		if(ans<n)
		{
			k--;
			break;
		}
		init_seq_len=flag;
	}
	*/ 
	for(int i=0;i<ans;i++)cout << seq_c[i];
	cout << endl; 
	return 0;
}
