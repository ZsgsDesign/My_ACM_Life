#include<bits\stdc++.h>

char seq[200004];
char seq_c[200004];
int init_seq[200004];
int n,ans,flag;
using namespace std;

int main()
{
	memset(seq,0,sizeof(seq));
	memset(seq_c,0,sizeof(seq_c));
	memset(init_seq,0,sizeof(init_seq));
	cin.getline(seq,200000,'\n');
	cin.getline(seq_c,200000,'\n');
	for(int i=0;i<strlen(seq);i++)init_seq[i]=i;
	cin >> n;
	int k,init_seq_len=strlen(seq);
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
	if(k==strlen(seq_c)+1) k--;
	if(k) for(int i=0;i<k;i++)cout << seq_c[i];
	else cout << "IMPOSSIBLE";
	cout << endl; 
	return 0;
}
