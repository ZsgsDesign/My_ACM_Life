//bomb
#include<iostream>
#include<cstdio>
#include<fstream>
using namespace std;
const int MAXN=2000+10;
struct tBomb{
	int importance,
		more_important_number;
}bomb[MAXN];
int main()
{
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>bomb[i].importance;
		bomb[i].more_important_number=1;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(bomb[i].importance>bomb[j].importance)bomb[j].more_important_number++;
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<bomb[i].more_important_number<<' ';
	}
	return 0;
}
