#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <iostream> 
#include <algorithm> 

using namespace std;
int T,n,temp_a,temp_b;
int cargo[202],cMin,cMax;
int timeA,timeB,sum;
int ans=99999999;
int dp[102][10002];
int temp[10002];


int main()
{
	ios::sync_with_stdio(false);
	cin >> T;
	for(int i=1;i<=T;i++)
	{
		cin >> n;
		memset(cargo,0,sizeof(cargo));
		cargo[0]=1;
		sum=0;
		for(int j=1;j<=n;j++)
		{
			cin >> temp_a >> temp_b;
			for(int k=1;k<=temp_b;k++)
			{
				cargo[cargo[0]]=temp_a;
				cargo[0]++;
				sum+=temp_a;
			}
		}
		cargo[0]--;
		//cMax=cargo[0];
		//cMin=1;
		//sort(cargo+1,cargo+1+cargo[0]);
		//timeA=0;
		//timeB=0;  
	    memset(dp,0,sizeof(dp));
	    memset(temp,0,sizeof(temp));
	    for (int j=1; j<=cargo[0];j++)
		{
	        for (int k=1; k<=sum/2;k++)
			{
				if(k>=cargo[j]) dp[j][k]=max(dp[j-1][k],dp[j-1][k-cargo[j]]+cargo[j]);  
	    		else dp[j][k]=dp[j-1][k];  
	        }
	    }
	    ans=sum-dp[cargo[0]][sum/2]; 
		cout << ans << endl;
	}
	return 0;
}
