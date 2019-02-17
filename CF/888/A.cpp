#include<bits\stdc++.h>

using namespace std;
int n,ans=0,seq[1002]={0};

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)cin >> seq[i];
	for(int i=2;i<n;i++)
	{
		if((seq[i]-seq[i-1])*(seq[i]-seq[i+1])>0)ans++;
	}
	cout << ans << endl;
	return 0;
}
