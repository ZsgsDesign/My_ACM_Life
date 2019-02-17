#include<bits/stdc++.h>

using namespace std;
int a[15];

void huan(int &a, int &b)
{
	int x = a; a = b; b = x;
}

int main()
{
	freopen("alchemist.in","r",stdin);
	freopen("alchemist.out","w",stdout);
	int n;
	scanf("%d",&n);
	string s;
	getchar();
	for(int i = 1; i <= n; ++ i)
	{
		getline(cin,s);
		int tot = 0;
		int ans = 1000000;
		for(int j = 0; j < s.size(); ++ j)
		{
			if(s[j] != ' ') a[++ tot] = (int)(s[j] - 48);
		}
		if(tot == 1)
		{
			printf("%d\n",a[1]);
			continue;
		}
		if(tot == 2)
		{
			printf("%d\n",abs(a[1] - a[2]) );
			continue;
		}
		sort(a + 1,a + tot + 1);
		if(tot == 3) ans = a[2] * 10 + a[3];
		if(a[1] == 0) huan(a[1],a[2]);
		a[0] = 0;
		/*for(int j = 1; j <= tot; ++ j)
		{
			printf("%d ",a[j]);
		}
		printf("\n");*/
		
		while (a[0] == 0)
		{
			if(tot % 2 == 0)
			{
				int s1 = 0,s2 = 0;
				for(int j = 1; j <= tot / 2; ++ j)
				{
					s1 *= 10;
					s1 += a[j];
				}
				for(int j = tot / 2 + 1; j <= tot; ++ j)
				{
					s2 *= 10;
					s2 += a[j];
				}
				//printf("%d\n",abs(s1 - s2));
				if(a[tot / 2 + 1] != 0) ans = min(ans,abs(s1 - s2));
			}
			else
			{
				int s1 = 0,s2 = 0;
				int mo = 1;
				for(int j = 1; j <= tot / 2; ++ j)
				{
					s1 *= 10;
					s1 += a[j];
					mo *= 10;
				}
				for(int j = tot / 2 + 1; j <= tot; ++ j)
				{
					s2 *= 10;
					s2 += a[j];
				}
				if(tot == 3)
				{
					if(a[2] == 0) ans = min(ans,a[1] * 10 + a[2] - a[3]); else 
					{
						ans = min(ans,a[2] * 10 + a[3] - a[1]);
						ans = min(ans,a[1] * 10 + a[2] - a[3]);
					}
				}
				//printf("%d %d\n",s1,s2);
				if(a[tot / 2 + 1] != 0) ans = min(ans,s2 - s1);
				s1 *= 10;
				s1 += a[tot / 2 + 1];
				s2 %= mo;
				//printf("%d %d\n",s1,s2);
				if(a[tot / 2 + 2] != 0) ans = min(ans,s1 - s2);
			}
			
			int j = tot;
			while (a[j - 1] > a[j]) j --;
			j --;
			if(j == 0) break;
			//printf("%d\n",j);
			int p = tot + 1;
			while (a[p - 1] < a[j])
			{
				p --;
			}
			//printf("%d\n",p);
			huan(a[p - 1],a[j]);
			
			/*for(int j = 1; j <= tot; ++ j)
			{
				printf("%d ",a[j]);
			}
			printf("\n\n\n");*/
			
			for(int k = tot; k >= (j + 1 + tot) / 2 + 1; -- k)
			{
				huan(a[k],a[j + tot - k + 1]);
			}
			
			/*for(int j = 1; j <= tot; ++ j)
			{
				printf("%d ",a[j]);
			}
			printf("\n............\n");*/
		}
		printf("%d\n",ans);
	}
	return 0;
}

