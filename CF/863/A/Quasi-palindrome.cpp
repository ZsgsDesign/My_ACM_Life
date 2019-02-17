#include<bits\stdc++.h>

using namespace std;
int seq[12],ans=1;
int main()
{
	int flag=1;
	char temp;
	while(temp=getchar())
	{
		if(temp>=48 && temp<=57)
		{
			seq[flag]=temp-48;
			flag++;
		}
		else break;
	}
	flag--;
	for(int i=flag;i>=1;i--)
	{
		if(!seq[i])flag--;
		else break;
	}
	for(int i=1;i<=flag/2;i++)
	{
		if(seq[i]!=seq[flag-i+1])
		{
			ans=0;
			break;
		}
	}
	if(ans) cout << "YES";
	else cout << "NO";
	cout << endl;
	return 0;
}
