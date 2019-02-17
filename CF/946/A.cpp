#include<bits\stdc++.h>

using namespace std;
int n,sum,temp;

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin>>temp;
		sum+=abs(temp);
	}
	cout << sum << endl;
	return 0;
}
