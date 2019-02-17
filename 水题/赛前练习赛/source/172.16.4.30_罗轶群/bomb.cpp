#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b)
{
	return a>b;
}
int n;
int a[2010]={0};
int c[2010]={0};
int m,b[2010][2]={0};
int main()
{
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		c[i]=a[i];
	}
	sort(a,a+n,cmp);
	b[0][0]=1;
	b[0][1]=a[0];
	m=2;
	for(int i=1;i<n;i++)
	{
		if(a[i]==a[i-1])
		{
			b[i][0]=b[i-1][0];
			m++;
		}
		else
		{
			b[i][0]=m;
		}
		b[i][1]=a[i];
	}
	for(int i=0;i<n;i++)
	{
		if(i!=n-1)
		{
			for(int j=0;j<n;j++)
		{
			if(c[i]==b[j][1])
			{
				cout<<b[j][0]<<' ';
			    b[j][1]=0;
			    break;
			}
		}
		}
		else
		{
				for(int j=0;j<n;j++)
		{
			if(c[i]==b[j][1])
			{
				cout<<b[j][0];
			    b[j][1]=0;
			    break;
			}
		}
	}
	}
	return 0;
}
