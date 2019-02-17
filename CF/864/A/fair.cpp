#include<bits\stdc++.h>

using namespace std;
int seq[102];
int count2[102];
int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=100;i++) count2[i]=0;
	for(int i=1;i<=n;i++)
	{
		cin >> seq[i];
		count2[seq[i]]++;
	}
	int ans[3];
	int flag=0;
	for(int i=1;i<=100;i++)
	{
		//Ñ­»·²éÕÒ
		if(count2[i])
		{
			ans[flag]=i;
			flag++;
			if(flag==3)
			{
				cout << "NO" << endl;
				return 0;
			}
		} 
	}
	if(count2[ans[0]]!=count2[ans[1]])cout << "NO" << endl;
	else cout << "YES" << endl << ans[0] << " " << ans[1] << endl;
	return 0;
} 
