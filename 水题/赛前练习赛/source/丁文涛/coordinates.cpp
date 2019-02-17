#include<bits/stdc++.h>
using namespace std;
const int maxn = 101;
int main ()
{
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	bool A[202][202]{0};
	int n;
	int l=maxn,r=maxn,u=maxn,d=maxn;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		A[x+maxn][y+maxn]=1;
		if(x+maxn<l)
		l=x+maxn;
		if(x+maxn>r)
		r=x+maxn;
		if(y+maxn<d)
		d=y+maxn;
		if(y+maxn>u)
		u=y+maxn;
	}
	for(int i=u;i>=d;i--)
	{
		for(int j=l;j<=r;j++)
		{
			if(A[j][i]==1)
			cout<<"*";
			else
			if(i==maxn&&j==maxn)
			cout<<"+";
			else
			if(j==maxn)
			cout<<"|";
			else
			if(i==maxn)
			cout<<"-";
			else
			cout<<".";
		}
		cout<<endl;
	}
	
	
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
