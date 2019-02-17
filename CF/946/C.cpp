#include<bits\stdc++.h>

using namespace std;
string s;
int cur;
char verify='a';

int main()
{
	cin >> s;
	int len=s.length(); 
	for(cur=0;cur<len;cur++)
	{
		if(s[cur]<=verify)
		{
			if(s[cur]<verify) s[cur]=verify; 
			verify++;
		}
		if(verify=='z'+1)break;
	}
	if(cur==len)cout << -1 << endl;
	else{
		cout << s << endl;
	}
	return 0;
}
