#include<bits\stdc++.h>

using namespace std;
string s;
int ans[10]={0};

int main()
{
	cin >> s;
	int ans=0;
	if(s.rfind("Danil")!=string::npos)
	{
		if(s.rfind("Danil")==s.find("Danil"))ans+=1;
		else ans+=2;
	}
	if(s.rfind("Olya")!=string::npos)
	{
		if(s.rfind("Olya")==s.find("Olya"))ans+=1;
		else ans+=2;
	}
	if(s.rfind("Slava")!=string::npos)
	{
		if(s.rfind("Slava")==s.find("Slava"))ans+=1;
		else ans+=2;
	}
	if(s.rfind("Ann")!=string::npos)
	{
		if(s.rfind("Ann")==s.find("Ann"))ans+=1;
		else ans+=2;
	}
	if(s.rfind("Nikita")!=string::npos)
	{
		if(s.rfind("Nikita")==s.find("Nikita"))ans+=1;
		else ans+=2;
	}
	if(ans==1)cout << "YES";
	else cout << "NO";
	cout << endl;
	return 0; 
}
