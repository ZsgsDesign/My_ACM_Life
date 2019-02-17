#include<bits\stdc++.h>

using namespace std;
bool status[100002];
int n,temp;

int main()
{
	ios::sync_with_stdio(false); 
	for(int i=0;i<=34;i++) //3
	{
		for(int j=0;j<=34;j++) //7
		{
			status[3*i+7*j]=true;
		}
	}
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> temp;
		string temp2=status[temp]?"YES":"NO";
		cout << temp2 << endl; 
	} 
	return 0; 
}
