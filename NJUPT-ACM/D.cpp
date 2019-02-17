#include<bits\stdc++.h>

int x;
char ans[102];
using namespace std;

int main()
{
	cin >> x;
	int i=0;
	while(true)
	{
		i++;
		if(x%2==1)//ÆæÊý
		{
			ans[i]='A';
			x=(x-1)/2;
		}
		else
		{
			ans[i]='B';
			x=(x-2)/2;
		}
		
		if(!x)break;
	}
	for(;i>=1;i--)cout << ans[i];
	cout << endl;
	return 0;
}
