#include<bits/stdc++.h>
using namespace std;
int main ()
{
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	int n;
	int A[2001];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	for(int i=0;i<n;i++)
	{
		int temp=1;
		for(int j=0;j<n;j++)
		{
			if(A[j]>A[i])
			temp++;
		}
		cout<<temp<<" ";
	}

	return 0;
}
