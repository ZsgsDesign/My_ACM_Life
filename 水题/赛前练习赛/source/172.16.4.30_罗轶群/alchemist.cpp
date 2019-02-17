#include<bits/stdc++.h>
using namespace std;
int k;
long long a[10]={1234567890};
int c=0;
int ans=0;
int an=1;
int main()
{
	freopen("alchemist.in","r",stdin);
	freopen("alchemist.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>k;
//	long long b[k]={0};
	for(int i=0;i<k;i++)
	{
		cin>>a[i];
	}
	sort(a,a+k);
	if(k%2==0)
	{
		if(a[0]!=0)
		{
			if(a[1]!=a[2])
			{
				for(int i=2;i<=k/2+1;i++)
				{
					an=an*10;
					ans=ans+a[i]*an;
				}
				an=an*10;
				ans=ans+a[1]*an;
				an=1;
				for(int i=k-1;i>=k/2-1;i--)
				{
					an=an*10;
					ans=ans-a[i]*an;
				}
				an=an*10;
				ans=ans-a[0]*an;
			}
		}
	}
	cout<<ans;
	return 0;
}
