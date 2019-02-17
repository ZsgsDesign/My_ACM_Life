#include<bits/stdc++.h>
using namespace std;
int n ,s[250][2],t,minn,maxx,l,h;

int main()
{
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	cin>>n;
	l=n-1;
	for(int i=0;i<n;i++)
	{
		cin>>s[i][0]>>s[i][1];
	}
	maxx=s[0][0];
	minn=s[0][0];
	for(int i=0;i<n-1;i++)
	{h=0;
		for(int j=0;j<n-1;j++)
	    {
		    if(s[j][1]>s[j+1][1])
		    {
		        t=s[j][0];
				s[j][0]=s[j+1][0];
				s[j+1][0]=t;
				t=s[j][1];
				s[j][1]=s[j+1][1];
				s[j+1][1]=t;	
			}
			else(h++);
	    }
	    if(h==n-1)
	    break;
	   
	}
	for(int i=0;i<n;i++)
	{
		if(s[i][0]>maxx)
		maxx=s[i][0];
		if(s[i][0]<minn)
		minn=s[i][0];
	}

	for(int i=s[n-1][1];i>=s[0][1];i--)
	{
		for(int j=minn;j<=maxx;j++)
		{
			if(i==s[l][1]&&j==s[l][0])
			{
				printf("*");
				l--;
			}
			else
			if(i==0&&j==0)
			{
				printf("+");
			}
			else
			if(j==0&&i!=0)
			{
				printf("|");
			}
			else
			if(i==0&&j!=0)
			{
				printf("-");
			}
			
			else
				printf(".");
		}
		printf("\n");
	}	
	return 0;
}





