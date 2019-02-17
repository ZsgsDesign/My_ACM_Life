#include<bits\stdc++.h>

char seq[200004];
char seq_c[200004]; 
int n,flag,ans[200004]={0};
using namespace std;

int main()
{
	memset(seq,0,sizeof(seq));
	memset(seq_c,0,sizeof(seq_c));
	cin.getline(seq,200000,'\n');
	cin.getline(seq_c,200000,'\n');
	cin >> n;
	int seq_len=strlen(seq),seq_c_len=strlen(seq_c);
    for(int i=0;i<seq_len;i++)
    {
    	for(int j=0;j<seq_c_len;j++)
    	{
    		if(!seq[i+j]) break;
    		else if(seq[i+j]==seq_c[j])ans[j+1]++; 
    		else break;
		}
    }		
	if(ans[1]<n)
	{
		cout << "IMPOSSIBLE" << endl;
		return 0;		
	}
	else
	{
		for(int i=seq_c_len;i>=1;i--)
		{
			if(ans[i]>=n)
			{
				for(int j=0;j<i;j++)cout << seq_c[j];
				cout << endl; 
				return 0;
			}
		}
	}
}
