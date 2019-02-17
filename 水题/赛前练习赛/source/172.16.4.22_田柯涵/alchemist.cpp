#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("alchemist.in","r",stdin);
	freopen("alchemist.out","w",stdout);
	int a[7],n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int i=0;i<=5;i++)
			cin>>a[i];
		sort(a,a+6);
		cout<<(a[2]*100+a[0]*10+a[3])-(a[1]*100+a[5]*10+a[4])<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
