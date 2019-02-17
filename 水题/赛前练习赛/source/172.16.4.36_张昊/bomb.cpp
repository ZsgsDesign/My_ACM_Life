#include<bits/stdc++.h>
using namespace std;
int n;
struct city{
	int index;
	int impor;
} ci[2001];

int ans[2001];
int main(){
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{ci[i].index=i;
	cin>>ci[i].impor;
	}
for(int i=1;i<=n;i++)
{
	for(int j=1;j<=n;j++)
	{
		if(ci[j].impor>ci[i].impor)ans[i]++;
	}
}
for(int i=1;i<=n;i++)
cout<<ans[i]+1<<' ';
	return 0;
}
