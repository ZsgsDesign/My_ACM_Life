#include<bits\stdc++.h>

using namespace std;
int main()
{
	int a,b,f,k,ans=0;
	cin >> a >> b >> f >> k;
	int tank=b;
	
	for(int m=1;m<=k;m++)
	{
		//m奇数是去的路上，每次加油站状态
		int temp=2;
		if(m==k)temp=1;
		if(m%2==1)
		{
			tank-=f;
			if(tank<0)
			{
				cout << "-1" << endl;
				return 0;
			} 
			if(tank<(a-f)*temp)
			{
				tank=b;
				ans++;
			}
			tank=tank-(a-f);
			if(tank<0)
			{
				cout << "-1" << endl;
				return 0;
			} 
		}
		if(m%2==0)
		{
			tank=tank-(a-f);
			if(tank<0)
			{
				cout << "-1" << endl;
				return 0;
			} 
			if(tank<f*temp)
			{
				tank=b;
				ans++;
			}
			tank-=f;
			if(tank<0)
			{
				cout << "-1" << endl;
				return 0;
			} 
		}
	}
	cout << ans << endl;
	return 0;
} 
