//coordinates
#include<iostream>
#include<fstream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
const int MAXN=250+10;
const int INF=0x7fffffff;
struct tNode{
	int x,
		y;
}node[MAXN];
struct tCoordinate{
	char character;
	int x,
		y;
}coordinate[MAXN][MAXN];
int num_coordinate[MAXN][MAXN];
int main()
{
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,maxx=-INF,maxy=-INF,minx=INF,miny=INF;
	cin>>n;
	memset(coordinate,'.',sizeof(coordinate));
	for(int i=0;i<n;i++)
	{
		cin>>node[i].x>>node[i].y;
		if(node[i].x>maxx)maxx=node[i].x;
		if(node[i].y>maxy)maxy=node[i].y;
		if(node[i].x<minx)minx=node[i].x;
		if(node[i].y<miny)miny=node[i].y;
	}
	int line_distance=abs(maxx-minx),
		column_distance=abs(maxy-miny),
		xnode_0=abs(0-minx),
		ynode_0=abs(0-miny);
	for(int i=0;i<=line_distance;i++)
	{
		if(i!=xnode_0)
		{
			coordinate[ynode_0][i].character='-';
		}
	}	
	for(int i=0;i<=column_distance;i++)
	{
		if(i!=ynode_0)
		{
			coordinate[i][xnode_0].character='|';
		}
	}
	for(int i=0;i<n;i++)
	{
		int temp_distance_x=abs(0-node[i].x);
		int temp_distance_y=abs(0-node[i].y);
		coordinate[xnode_0-temp_distance_x][ynode_0-temp_distance_y].character='*';
		
	}
	coordinate[0+xnode_0][0+ynode_0].character='+';
	coordinate[0+xnode_0][0+ynode_0].x=coordinate[0+xnode_0][0+ynode_0].y=0;
	for(int i=0;i<=column_distance;i++)
	{
		for(int j=0;j<=line_distance;j++)
		{
			cout<<coordinate[i][j].character;
		}
		cout<<endl;
	}
	return 0;
}
