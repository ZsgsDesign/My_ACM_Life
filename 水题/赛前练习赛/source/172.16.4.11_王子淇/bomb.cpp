#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	int n;
	cin>>n;
	int a[n];int x[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		x[i]=1;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		if(a[j]>a[i]) x[i]++;
	}
	for(int i=0;i<n;i++)
	{
		cout<<x[i]<<" ";
	}
	return 0;
}
