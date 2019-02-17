#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("alchemist.in", "r", stdin);
	freopen("alchemist.out", "w", stdout);
	int n;
	cin >> n;
	char ch = getchar();
	for(int k = 1; k <= n; k++)
	{
		int t, cnt = 0, ans1 = 0, ans2 = 0;
		int a[11];
		while((ch = getchar()) != '\n')
		{
			if(ch == ' ')
				continue;
			a[++cnt] = ch - '0';
		}
		sort(a+1, a+1+cnt);
		if(cnt % 2 != 0)
		{
			if(a[1] = 0)
			{
				a[1] = a[2];
				a[2] = 0;
			}
			ans2 = a[1];
			ans1 = a[cnt];
			for(int i = 2; i <= (cnt + 1) / 2; i++)
				ans2 = ans2 * 10 + a[i];
			for(int i = cnt - 1; i >= (cnt + 1) / 2 + 1; i--)
				ans1 = ans1 * 10 + a[i];
			cout << ans2 - ans1 << endl;
		}
		else
		{
			if(a[1] = 0)
			{
				a[1] = a[2];
				a[2] = a[3];
				a[3] = 0;
			}
			ans1 = a[1];
			ans2 = a[2];
			for(int i = 3; i <= cnt / 2 + 1; i++)
				ans2 = ans2 * 10 + a[i];
			for(int i = n; i <= cnt / 2 + 2; i--)
				ans1 = ans1 * 10 + a[i];
			cout << ans2 - ans1 << endl;
		}
	}
	return 0;
}

