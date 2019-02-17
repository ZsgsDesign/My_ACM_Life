#include<bits/stdc++.h>
using namespace std;
int main()
{   freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	int n;
	cin>>n;
	int a[n+1],ans[n+1];
	for(int i=1;i<=n;i++)
	{ans[i]=1;}
	for(int i=1;i<=n;i++)
	{
	cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
	for(int j=1;j<=n;j++)
	{
	if(a[j]>a[i]) ans[i]++;
	}
	}
	for(int i=1;i<=n;i++) 
	{
	cout<<ans[i]<<" ";
	}
	return 0;
}
