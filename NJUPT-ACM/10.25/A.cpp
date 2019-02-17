#include<bits\stdc++.h>

long long l;
int a,b,t,r,n;
int coffee[500002];
int coffee_drink[500002],flag=0;
using namespace std;

int main()
{
	cin >> l >> a >> b >> t >> r >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> coffee[i];
	}
	int effect_range_border=0; 
	for(int i=1;i<=n;i++)
	{
		if(effect_range_border<=coffee[i])
		{
			//该吃药了
			if((l-coffee[i])>(a*t))
			{
				flag++;
				coffee_drink[flag]=i;
				effect_range_border=coffee[i]+a*t+b*r;
				if(effect_range_border>l)effect_range_border=l;
			}
		}
		else
		{
			//该不该吃呢
			int x0,x1=effect_range_border+coffee[i]-coffee[i-1],x2=a*t;
			if(x1>l)x1=l;
			for(int j=1;j<=n;j++)
			{
				if(coffee[j]>=effect_range_border)
				{
					x0=coffee[j]-effect_range_border;
					break;
				}
				if(j==n)x0=l-effect_range_border;
			} 
			for(int j=1;j<=n;j++)
			{
				if(coffee[j]>=x1)
				{
					x1=coffee[j]-x1;
					break;
				}
				if(j==n)x1=l-x1;
			} 
			if(x1+x2<x0)
			{
				//该吃药了
				flag++;
				coffee_drink[flag]=i;
				effect_range_border=coffee[i]+a*t+b*r;
				if(effect_range_border>l)effect_range_border=l;
			}
		}
	}
	cout << flag << endl;
	for(int i=1;i<=flag;i++)
	{
		cout << coffee_drink[i]-1;
		if(i==flag)cout << endl;
		else cout << " ";
	} 
	return 0;
 } 
