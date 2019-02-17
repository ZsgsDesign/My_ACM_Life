#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("coordinates","r",stdin);
	freopen("coordinates","w",stdout);
	int n;
	cin>>n;
	int a[n],b[n];
	int max1,min1,max2,min2;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
	}
	max1=a[0];max2=b[0];
	min1=a[0];min2=b[0];
	for(int i=0;i<n;i++)
	{
		if(a[i]>max1) max1=a[i];
		if(a[i]<min1) min1=a[i];
		if(b[i]>max2) max2=b[i];
		if(b[i]<min2) min2=b[i];
	}
	
	int m=max1-min1+1;
	int l=max2-min2+1;
	char zbx[l][m];

	for(int i=0;i<l;i++)
	{
		for(int j=0;j<m;j++)
		{
			zbx[i][j]='.';
			if(i==max2) zbx[i][j]='-';
			if(j==abs(min1)) zbx[i][j]='|';
			if((i==max2)&&(j==abs(min1))) zbx[i][j]='+';
		}
	}
	for(int i=0;i<l;i++)
		a[i]=a[i]+abs(min1);
	for(int i=0;i<m;i++)
		b[i]=max2-b[i];
	for(int i=0;i<l;i++)
		for(int j=0;j<m;j++)	
			zbx[a[i]][b[j]]='*';

	for(int i=0;i<l;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<zbx[i][j];
			if(j==m-1) cout<<endl;
		}
	
	}
	return 0;
}
