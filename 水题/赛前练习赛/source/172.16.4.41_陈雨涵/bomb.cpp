#include<bits/stdc++.h>
using namespace std;
int n ,s[2001][3],t,l=2;
int main()
{
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0];
		s[i][1]=i;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
	    {
		    if(s[j][0]<s[j+1][0])
		    {
		        t=s[j][0];
				s[j][0]=s[j+1][0];
				s[j+1][0]=t;
				t=s[j][1];
				s[j][1]=s[j+1][1];
				s[j+1][1]=t;	
			}
	    }
	}
	
	s[1][2]=1;
	for(int i=2;i<=n;i++)
	{
		if(s[i][0]==s[i-1][0])
		{
			s[i][2]=s[i-1][2];
			l++;
		}
		else
		{
			s[i][2]=l;
			l++;
		}
	}
	
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
	    {
		    if(s[j][1]>s[j+1][1])
		    {
		        t=s[j][2];
				s[j][2]=s[j+1][2];
				s[j+1][2]=t;
				t=s[j][1];
				s[j][1]=s[j+1][1];
				s[j+1][1]=t;	
			}
	    }
	}
	for(int i=1;i<=n;i++)
	{
		cout<<s[i][2];
	}
	return 0;
}
