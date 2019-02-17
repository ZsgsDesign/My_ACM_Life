#include<bits/stdc++.h>
using namespace std;
int a[12]={10000};
int main()
{
	freopen("alchemist.in","r",stdin);
	freopen("alchemist.out","w",stdout);
	int k,c=1;
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>a[c];
		c++;
		while(!cin>>EOF) break;
		sort(a,a+k+1);
		if(c%2==0) 
		{
			if(a[1]==0) int sd=a[c/2]
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
