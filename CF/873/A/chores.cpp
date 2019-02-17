#include<bits\stdc++.h>

int seq[102]={0},n,k,x,ans=0;
using namespace std;

int main()
{
	cin >> n >> k >> x;
	for(int i=1;i<=n-k;i++)
	{
		cin >> seq[i];
		ans+=seq[i];
	}	
	ans+=k*x;
	cout << ans << endl;
	return 0;
} 
