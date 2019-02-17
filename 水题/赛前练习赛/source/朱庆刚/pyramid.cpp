#include<cstdio>
#include<map>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
struct person
{
	string name;
	int vaule[6];
};
int n,m;
person p[20001];
map <string,int> vaule;
string qst;
bool cmp(person a,person b)
{
	if(a.vaule[vaule[qst]]==b.vaule[vaule[qst]])
		return a.name<b.name;
	else return a.vaule[vaule[qst]]>b.vaule[vaule[qst]];
}
int main()
{
	freopen("pyramid.in","r",stdin);
	freopen("pyramid.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		string r;
		cin>>r;
		vaule[r]=i;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].name;
		for(int j=1;j<=m;j++) scanf("%d",&p[i].vaule[j]);
	}
	int k;
	scanf("%d",&k);
	for(int dat=1;dat<=k;dat++)
	{
		cin>>qst;
		if(!vaule.count(qst))
		{
			printf("It's not a problem a panda can deal with!\n\n");
			continue;
		}
		sort(p+1,p+1+n,cmp);
		for(int i=1;i<=n;i++)
			cout<<p[i].name<<endl;
		printf("\n");
	}
	return 0;
}

