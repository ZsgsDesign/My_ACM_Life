#include<bits\stdc++.h>

int n,m,k,ans_max=0,ans_mod=0;
int matrix[202][202];
using namespace std;

int main()
{
	memset(matrix,0,sizeof(matrix));
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>matrix[i][j]; 
		}
	}
	// matrix[1][1] matrix[2][1] matrix[3][1] matrix[4][1]
	// matrix[1][2] matrix[2][2] matrix[3][2] matrix[4][2]
	for(int i=1;i<=m;i++) //matrix[][i]
	{
		int maxn=0,max_loc=0;
		for(int j=1;j<=n;j++) //matrix[j][i]
		{
			if(matrix[j][i])
			{
				int temp=0;
				for(int l=j;l<j+k;l++)temp+=matrix[l][i];
				if(temp>maxn)
				{
					maxn=temp;
					max_loc=j;
				}
			}
		}
		for(int l=1;l<max_loc;l++) 
		{
			if(matrix[l][i])
			{
				ans_mod++;
			}	
		}
		ans_max+=maxn;
	}
	cout << ans_max << " " << ans_mod << endl;
	return 0;
} 
