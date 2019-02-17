#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
int n,a[10005],b[10005],c[10005],i;
bool cmp(int x,int y)
{
	return a[x]>a[y];
}
int main()
{
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<=n;i++)b[i]=i;
	sort(b+1,b+n+1,cmp);
	for(i=1;i<=n;i++)if(a[b[i]]==a[b[i-1]])c[b[i]]=c[b[i-1]];
	else c[b[i]]=i;
	for(i=1;i<=n;i++)printf("%d ",c[i]); 
	return 0;
}

