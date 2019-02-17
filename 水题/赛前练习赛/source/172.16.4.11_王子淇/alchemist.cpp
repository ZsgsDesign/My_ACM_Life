#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("alchemist.in","r",stdin);
	freopen("alchemist.out","w",stdout);
	int k;
	cin>>k;
	int n;
	char a[25];
	int b[10];
	int x[10];
	for(int i=0;i<k;i++)
	{
		cin>>a;int f=0;
		for(int j=0;j<n;j++)
		{
			b[j]=a[f]-48;
			f+=2;
		}
		int n=strlen(a)/2+1;
		sort(b,b+n);
		if(b[0]==0)
		{
			b[0]=b[1];
			b[1]=0;
		}
		int m1=0,m2=0,t=n/2;
		for(int j=0;j<=n/2+1;j++)
		{
			m1+=pow(10,t)*b[j];
			t--;
		}
		t=n/2-1;
		for(int j=n-1;j>n/2+1;j--)
		{
			m2+=pow(10,t)*b[j];
			t--;
		}
		x[i]=m1-m2;
	}
	for(int i=0;i<n;i++)
	cout<<x[i]<<endl;

	
	return 0;
}
