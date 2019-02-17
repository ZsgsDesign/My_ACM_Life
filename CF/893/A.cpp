#include<bits\stdc++.h>

using namespace std;
int n,temp,winable[4]={0,1,1,0}; 

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	
	for(int i=1;i<=n;i++)
	{
		cin>> temp;
		if(winable[temp])
		{
			for(int i=1;i<=3;i++) if(i!=temp) winable[i]=abs(winable[i]-1);
		}
		else
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}
