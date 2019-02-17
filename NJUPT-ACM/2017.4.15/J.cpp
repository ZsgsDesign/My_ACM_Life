#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <iostream> 
#include <algorithm> 

using namespace std;
int t,lenZ,lenG,lenS;
string Z,G,S;
bool ans=false;

void search(int curZ,int curG,int curS)
{
	if(ans)return;
	if(curZ==lenZ-1) for(int j=curS;j<lenS;j++) if(G[curG+j-curS]!=S[j])return;
	else if(curG==lenG-1) for(int j=curS;j<lenS;j++) if(Z[curZ+j-curS]!=S[j])return;
	else for(int j=curS;j<lenS;j++)
	{
		if(Z[curZ]==S[j] && G[curG]==S[j])
		{
			search(curZ+1,curG,j+1);
			search(curZ,curG+1,j+1);
			return;
		}
		if(Z[curZ]==S[j])curZ++;
		else if(G[curG]==S[j])curG++;
		else return;
	}
	ans=true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> t;
	for(int i=1;i<=t;i++)
	{
		cin >> Z >> G >> S;
		ans=true;
		lenZ=Z.length();
		lenG=G.length();
		lenS=S.length();
		int curG,curZ,curS=0;
		for(curZ=0;curZ<lenZ;curZ++)
		{
			if(!ans)break;
			for(;curS<lenS;curS++)
			{
				if(Z[curZ]==S[curS])break;
				if(curS==lenS-1)ans=false;
			}
		}
		curS=0;
		for(curG=0;curG<lenG;curG++)
		{
			if(!ans)break;
			for(;curS<lenS;curS++)
			{
				if(G[curG]==S[curS])break;
				if(curS==lenS-1)ans=false;
			}				
		}
		cout << (ans?"YES,memeda!":"Oh,i want memeda!") << endl;
	}
	return 0;
}
