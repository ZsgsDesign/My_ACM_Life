#include <bits/stdc++.h>
using namespace std;
int a[3000][3]={},b[10000]={0},n;
int main()
{
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	int tot=0;
	int maxn=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1];
		b[a[i][1]]++;
	}
	for(int i=1;i<=n;i++)
		maxn=max(maxn,a[i][1]);
	tot=1;
	for(int i=maxn;i>=1;i--)
	{
		if(b[i]>0)
		{
			for(int j=1;j<=n;j++)
				if(a[j][1]==i) a[j][2]=tot;
			tot+=b[i];
		}
	}
	for(int i=1;i<=n;i++)
		cout<<a[i][2]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
