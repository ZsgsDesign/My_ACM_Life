#include<bits\stdc++.h>

int n,t,seq[102]={0},sum=0;
using namespace std;

int main()
{
	cin >> n >> t;
	for(int i=1;i<=n;i++) cin >> seq[i];
	for(int i=1;i<=n;i++)
	{
		sum+=86400-seq[i];
		if(sum>=t)
		{
			cout << i << endl;
			return 0;
		}
	}
}

