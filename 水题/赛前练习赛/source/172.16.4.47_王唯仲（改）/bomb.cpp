#include<bits/stdc++.h>
using namespace std;
long long a[2010],x[2010];
struct score[]{
	long long f;
	long long x;
};
int main()
{
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	memset(x,1,sizeof(x));
	int n,max=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i]<a[j]) x[i]++;
		}
	}
	sort(x,x+n+1);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
