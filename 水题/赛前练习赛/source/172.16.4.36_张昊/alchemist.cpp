#include<bits/stdc++.h>
using namespace std;
string a[6];
vector<int> vi[6];
vector<int> ans;
int n;
int main(){
	freopen("alchemist,in","r",stdin);
	freopen("alchemist.out","w",stdout);
	cin>>n;
for(int i=1;i<=n;i++)
cin>>a[i];
for(int i=1;i<=n;i++)
{
for(int j=0;j<a[i].length();j++)
{
	if(a[i][j]>='0'&&a[i][j]<='9')
	{
		vi[i].push_back(a[i][j]-48);
	}
}
	
}
for(int i=1;i<=n;i++)
sort(vi[i].begin(),vi[i].end());
for(int i=1;i<=n;i++)
{ans.push_back(0);
	if(vi[i].size()%2==1)
	{int h=1;
		for(int j=vi[i].size()/2;j>=0;j--)
		{
			ans[i-1]+=vi[i][j]*h;
			h*=10;
		}
		h=1;
		for(int j=vi[i].size()-1;j>vi[i].size()/2;j--)
		{
			ans[i-1]-=vi[i][j]*h;
			h*=10;
		}
	}
	else {
		int h=1;
		for(int j=0;j<vi[i].size()-1;j++)
		{
		ans[i-1]+=vi[i][j]+h;
		h*=10;	
		}
		ans[i-1]+=vi[i][vi[i].size()/2];
		h=1;
		for(int j=vi[i].size()-1;j>vi[i].size()/2;j--)
		{
			ans[i-1]-=vi[i][j]*h;
			h*=10;
		}
		ans[i-1]-=vi[i][vi[i].size()/2-1]*h;
	}
}
for(int i=0;i<ans.size();i++)
cout<<ans[i]<<endl;
	return 0;
}
