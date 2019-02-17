#include<bits\stdc++.h>

using namespace std;
string seq;
int ans=0;

int main()
{
	cin >> seq;
	int n=seq.size();
	for(int i=0;i<n;i++)
	{
		if(seq[i]=='Q')
		{
			for(int j=i+1;j<n;j++)
			{
				if(seq[j]=='A')
				{
					for(int k=j+1;k<n;k++)
					{
						if(seq[k]=='Q') ans++;
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
