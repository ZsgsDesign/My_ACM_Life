#include<bits/stdc++.h>
using namespace std;
int k,numm[10];
int main()
{
	freopen("coin.in","r",stdin);
	freopen("coin.out","w",stdout);
	cin>>k;
	for(k;k>0;k--)
	{
		memset(numm,-1,sizeof(numm));
		int i=0;
		while(cin>>numm[i])
		{
			i++;
		}
		cout<<i;
	}
	return 0;
}
