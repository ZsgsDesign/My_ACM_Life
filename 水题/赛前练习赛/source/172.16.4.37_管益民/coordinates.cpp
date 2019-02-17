#include<bits/stdc++.h>
using namespace std;

int a,xh=0,xl=0,yh=0,yl=0;



int main()
{
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	cin>>a;
	int x[a],y[a];
	for(int i=0;i<a;i++)
	{
		cin>>x[i]>>y[i];
		if(xh<x[i])xh=x[i];
		if(xl>x[i])xl=x[i];
		if(yh<y[i])yh=y[i];
		if(yl>y[i])yl=y[i]; 
	}
	
	for(int i=yh;i>=yl;i--)
	{
		for(int j=xl;j<=xh;j++)
		{bool l=0;
			for(int r=0;r<a;r++)
			{
				if(x[r]==j&&y[r]==i){l=1;break;}
			}
			if(l){cout<<'*';} 
			else{
			
			if(j!=0&&i==0){cout<<'-';}else
			if(j==0&&i!=0){cout<<'|';}else
			if(j==0&&i==0){cout<<'+';}else
			cout<<'.';
			}
		}
		
		cout<<endl;
	}
	
	
	
}





