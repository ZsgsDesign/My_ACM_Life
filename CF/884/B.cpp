#include<bits\stdc++.h>

using namespace std;
int n,x,temp,ans=0;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> x;
	for(int i=1;i<=n;i++)
	{
		cin >> temp;
		ans+=temp;
	}
	ans+=n-1;
	if(ans==x)cout << "YES";
	else cout << "NO";
	cout << endl;
	return 0;
}

