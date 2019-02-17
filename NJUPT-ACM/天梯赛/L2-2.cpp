#include<iostream>  
#include<algorithm>  
#include<vector>
#include<cstring>
  
using namespace std;  
struct People{
	int money;
	int id;
	int num;
} people[10002];
int n,count_n,rbperson,rbvalue;
bool status[10002];
bool compare(People a,People b)
{
	if(a.money>b.money) return true;
	else if(a.money==b.money)
	{
		if(a.num>b.num)return true;
		else if(a.num==b.num)
		{
			if(a.id<b.id)return true;
			else return false;
		}
		else return false;
	}
	else return false;
}

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++) people[i].id=i;
	for(int i=1;i<=n;i++)
	{
		cin >> count_n;
		memset(status,false,sizeof(status));
		for(int j=1;j<=count_n;j++)
		{ 
			cin >> rbperson >> rbvalue;
			if(status[rbperson]==false)
			{
				status[rbperson]=true;
				people[rbperson].money+=rbvalue;
				people[rbperson].num++;
				people[i].money-=rbvalue;
			}	
		}
	}
	sort(people+1,people+n+1,compare);
	for(int i=1;i<=n;i++)
	{
		printf("%d %.2f\n",people[i].id,people[i].money/100.0);
	}
    return 0;
}  
