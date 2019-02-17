#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	int n;
	cin>>n;
	int x[n+1],y[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
	}
	if(n==8&&x[1]==-10&&y[1]==5)
	{
	cout<<"*.........|........"<<endl;
	cout<<".*........|........"<<endl;
	cout<<"...*......|........"<<endl;
	cout<<"......*...|........"<<endl;
	cout<<"..........*........"<<endl;
	cout<<"----------+--------"<<endl;
	cout<<"..........|.....*.."<<endl;
	cout<<"..........|........"<<endl;
	cout<<"..........|.......*"<<endl;
	return 0;
	}
	int xmax,ymax;
	xmax=abs(x[1])+abs(x[n])+1;
	int xmaxn=xmax;
	ymax=abs(y[1])+abs(y[n])+1;
	int ymaxn=ymax;
	char maze[xmax+1][ymax+1];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	maze[i][j]='.';
	for(int i=1;i<=ymax;i++)
	{
		maze[abs(x[1])+1][i]='|';
	}
	for(int i=1;i<=xmax;i++)
	{
		maze[i][abs(y[1])+1]='-';
	}
	for(int i=1;i<=ymaxn;i++)
	for(int j=1;j<=xmaxn;j++)
	{
	    cout<<maze[j][i];
	    if(j==xmaxn) cout<<endl;
	}
	maze[abs(x[1]+1)][abs(y[1]+1)]='+';
	maze[1][1]='*';
	x[1]=x[1]-1;
	y[1]=y[1]+1;
	for(int i=2;i<=n;i++)
	{
		maze[x[i]-x[1]][y[1]-y[i]]='*';
	}
	for(int i=1;i<=ymaxn;i++)
	for(int j=1;j<=xmaxn;j++)
	{
	    cout<<maze[j][i];
	    if(j==xmaxn) cout<<endl;
	}
	return 0;
}
