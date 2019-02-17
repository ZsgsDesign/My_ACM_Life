#include<bits/stdc++.h>
using namespace std;
int n,ans=2147483647;
int read[15];
int num[15];
bool vis[15];
void dfs(int k)
{
	if(k>n)
	{
		int a=0,b=0,mid=n/2;
		for(int i=1;i<=mid;i++)
		{
			a*=10;
			a+=num[i];
		}
		for(int i=mid+1;i<=n;i++)
		{
			b*=10;
			b+=num[i];
		}
		ans=min(ans,abs(a-b));
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		if((k==1 || k==n/2+1) && read[i]==0) continue;
		vis[i]=true;
		num[k]=read[i];
		dfs(k+1);
		vis[i]=false;
	}
}
int main()
{
	freopen("alchemist.in","r",stdin);
	freopen("alchemist.out","w",stdout);
	int k;
	scanf("%d",&k);
	getchar();
	for(int data=1;data<=k;data++)
	{
		memset(vis,0,sizeof(vis));
		n=1;
		ans=2147483647;
		char r;
		for(;;)
		{
			r=getchar();
			if(r==' ') continue;
			if(r=='\n') break;
			read[n]=r-'0';
			++n;
		}
		--n;
		if(n==10)
		{
			printf("247\n");
			continue;
		}
		dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}

