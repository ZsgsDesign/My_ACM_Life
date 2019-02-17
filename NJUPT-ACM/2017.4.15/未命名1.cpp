#include<bits\stdc++.h>

using namespace std;
string str;
int diff[3]={-1,-1,-1};
string ans="YES";

int main()
{
	//abcbc
	ios::sync_with_stdio(false);
	cin >> str;
	int strLen=str.length();
	for(int i=1;i<=strLen/2;i++) //123456789 //01234567
	{
		if(str[i-1]!=str[strLen-i])
		{
			if(diff[1]==-1)diff[1]=i;
			else if(diff[2]==-1)diff[2]=i;
			else{
				ans="NO";
				break;
			}
		}
	}
	if(ans!="NO")
	{
		if(diff[1]==-1 && diff[2]==-1) ans="YES";
		else if(diff[1]>=0 && diff[2]==-1){
			 if(strLen%2==0)ans="NO";
			 else
			 {
			 	if(str[diff[1]-1]==str[strLen/2])ans="YES";
			 }
		}
		else
		{
			if(str[diff[1]-1]==str[strLen-diff[2]] && str[diff[2]-1]==str[strLen-diff[1]])ans="YES";
			else ans="NO";
		}
	}
	cout << ans << endl;
	return 0;
}
