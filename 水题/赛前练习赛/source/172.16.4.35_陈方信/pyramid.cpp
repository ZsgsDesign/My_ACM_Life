//pyramid
#include<iostream>
#include<cstdio>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
const int MAXN=20001+10;
const int RANGE=5+1;
struct tPerson{
	string name_person;
	int a[RANGE];
}person[MAXN];
struct tKind{
	string name_ability;
}ability[RANGE];
string ti[RANGE];
bool cmp1(tPerson x,tPerson y)
{
	if(x.a[1]!=y.a[1])return x.a[1]>y.a[1];
	else return x.name_person<y.name_person;
}
bool cmp2(tPerson x,tPerson y)
{
	if(x.a[2]!=y.a[2])return x.a[2]>y.a[2];
	else return x.name_person<y.name_person;
}
bool cmp3(tPerson x,tPerson y)
{
	if(x.a[3]!=y.a[3])return x.a[3]>y.a[3];
	else return x.name_person<y.name_person;
}
bool cmp4(tPerson x,tPerson y)
{
	if(x.a[4]!=y.a[4])return x.a[4]>y.a[4];
	else return x.name_person<y.name_person;
}
bool cmp5(tPerson x,tPerson y)
{
	if(x.a[5]!=y.a[5])return x.a[5]>y.a[5];
	else return x.name_person<y.name_person;
}
int main()
{
	freopen("pyramid.in","r",stdin);
	freopen("pyramid.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m,k;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>ability[i].name_ability;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>person[i].name_person;
		for(int j=1;j<=m;j++)
		{
			cin>>person[i].a[j];
		}
	}
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>ti[i];
	}
	for(int i=1;i<=k;i++)
	{
		bool flag=false;
		{
			for(int j=1;j<=m;j++)
			{
				if(ti[i]==ability[j].name_ability)
				{
					if(i==1)sort(person+1,person+n+1,cmp1);
					if(i==2)sort(person+1,person+n+1,cmp2);
					if(i==3)sort(person+1,person+n+1,cmp3);
					if(i==4)sort(person+1,person+n+1,cmp4);
					if(i==5)sort(person+1,person+n+1,cmp5);
					for(int l=1;l<=n;l++)
					{
						flag=true;
						cout<<person[l].name_person<<endl;
					}
				}
			}
		}
		if(!flag)cout<<"It's not a problem a panda can deal with!"<<endl;
		cout<<endl;
	}
	return 0;
}
