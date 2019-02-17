#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("coordinate.in", "r", stdin);
	freopen("coordinate.out", "w", stdout);
	int n;
	cin >> n;
	int a[3][n+1], bx = -99999, sx = 99999, by = -99999, sy = 99999;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[1][i] >> a[2][i];
		if(a[1][i] > bx) bx = a[1][i];
		if(a[1][i] < sx) sx = a[1][i];
		if(a[2][i] > by) by = a[2][i];
		if(a[2][i] < sy) sy = a[2][i];
	}
	int x = bx - sx + 1, y = by - sy + 1;
		char ans[y][x];
	for(int i = 1; i <= y; i++)
		for(int j = 1; j <= x; j++)
		{
			ans[i][j] = '.';
			if(j == abs(sx) + 1) ans [i][j] = '|';
			if(i == abs(by) + 1) ans [i][j] = '-';
			if(j == abs(sx) + 1 && i == abs(by) + 1) ans [i][j] = '+';
		}
	for(int i = 1; i <= n; i++)
    	ans[abs(by)-a[2][i]+1][abs(sx)+a[1][i]+1] = '*';
	for(int i = 1; i <= y; i++)
	{
		for(int j = 1; j <= x; j++)
			cout << ans[i][j];
		cout << endl;
	}
	return 0;
}
