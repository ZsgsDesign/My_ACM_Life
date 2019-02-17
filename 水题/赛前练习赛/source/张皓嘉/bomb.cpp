#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("bomb.in", "r", stdin);
	freopen("bomb.out", "w", stdout);
	int n;
	cin >> n;
	int a[n+1], b[n+1];
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b+1,b+1+n);
	for(int i = 1; i <= n; i++)
	{
		for(int j = n; j >= 1; j--)
		{
			if(a[i] == b[j]) 
			{
				cout << n - j + 1 << ' ';
				break;
			}
		}
	}
	cout << endl;
	return 0;
}
