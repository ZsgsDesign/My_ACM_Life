#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <iostream> 
#include <algorithm> 
#include <string> 

using namespace std;
string temp;
int temp_len;
int val[100005][2];
int ans=1,ansi=1,ansj=1; 

int main()
{
	ios::sync_with_stdio(false);
	cin >> temp;
	temp_len=temp.length();
	int vb=0,vr=0;
	for(int i=1;i<=temp_len;i++)
	{
		val[i][0]=vb;
		val[i][1]=vr;
		if(temp[i-1]=='B'){
			vb++;
		}else vr++;
	}
	val[temp_len+1][0]=vb;
	val[temp_len+1][1]=vr;
	for(int i=1;i<=temp_len;i++)
	{
		for(int j=i+1;j<=temp_len;j++)
		{
			vb=val[j+1][0]-val[i][0];
			vr=val[j+1][1]-val[i][1];
			int ans_temp=abs(vb-vr);
			if(ans_temp>ans) {
				ans=ans_temp;
				ansi=i;
				ansj=j;
			}
		} 
	}
	cout << ansi << " " << ansj << endl; 
	return 0;
}
