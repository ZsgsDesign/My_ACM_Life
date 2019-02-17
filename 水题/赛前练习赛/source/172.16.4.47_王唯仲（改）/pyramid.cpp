#include<bits/stdc++.h>
using namespace std;
char c[2005];
int b[2005],d[2005];
struct tstu{
	char c[];
	int b[];
	int d[];
};
int main()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	int n,m,k;
	cin>>n>>m;
	char a[m+2];
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		for(int j=1;i<=m;j++)
		{
			cin>>b[j]>>d[j];
			if(b[i]=b[j]&&i!=j) strcmp(c[i],c[j])
		}
	}
	cin>>k;
	char e[m+2];
	for(int i=1;i<=k;i++)
	{
		cin>>e[i];
		for(int j=1;j<=m;j++)
		{
			if(a[j]=e[i]) {
				sort(b,b+n+1);
				 
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
