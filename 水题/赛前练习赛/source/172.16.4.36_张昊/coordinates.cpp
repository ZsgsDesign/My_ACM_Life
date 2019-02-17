#include<bits/stdc++.h>
using namespace std;
char a[201][201];
int n;
int xy[251][2];
int xmax,ymin=100,xmin=100,ymax;
int main(){
freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	memset(a,'.',sizeof(a));
	a[100][100]='+';
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>xy[i][0];
		cin>>xy[i][1];
		xy[i][0]+=100;
		xy[i][1]+=100;
		xmin=min(xmin,xy[i][0]);
		ymin=min(ymin,xy[i][1]);
		xmax=max(xmax,xy[i][0]);
		ymax=max(ymax,xy[i][1]);
		
	}
	for(int i=xmin;i<=xmax;i++)
	{
	if(i!=100)
	a[i][100]='-';}
	for(int i=ymin;i<=ymax;i++)
	{if(i!=100)
		a[100][i]='|';
	}
	
	for(int i=1;i<=n;i++)
	{
		a[xy[i][0]][xy[i][1]]='*';
	}
	for(int j=ymax;j>=ymin;j--)
	{
		for(int i=xmin;i<=xmax;i++)
		cout<<a[i][j];
		cout<<endl;
	}
	return 0;
}
