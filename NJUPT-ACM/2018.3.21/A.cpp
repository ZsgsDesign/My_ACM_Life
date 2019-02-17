#include<iostream>  
#include<string>  

using namespace std;
bool map[102][102];
bool visited[102][102];
int n,m,ans;
string temp;

void connect(int x,int y)
{
	if(map[x][y-1]==true && !visited[x][y-1])
	{
		visited[x][y-1]=true;
		connect(x,y-1);
	}
	if(map[x][y+1]==true && !visited[x][y+1])
	{
		visited[x][y+1]=true;
		connect(x,y+1);
	}
	if(map[x-1][y-1]==true && !visited[x-1][y-1])
	{
		visited[x-1][y-1]=true;
		connect(x-1,y-1);
	}
	if(map[x-1][y+1]==true && !visited[x-1][y+1])
	{
		visited[x-1][y+1]=true;
		connect(x-1,y+1);
	}
	if(map[x-1][y]==true && !visited[x-1][y])
	{
		visited[x-1][y]=true;
		connect(x-1,y);
	}
	if(map[x+1][y-1]==true && !visited[x+1][y-1])
	{
		visited[x+1][y-1]=true;
		connect(x+1,y-1);
	}
	if(map[x+1][y+1]==true && !visited[x+1][y+1])
	{
		visited[x+1][y+1]=true;
		connect(x+1,y+1);
	}
	if(map[x+1][y]==true && !visited[x+1][y])
	{
		visited[x+1][y]=true;
		connect(x+1,y);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> temp;
		for(int j=0;j<m;j++)
		{
			if(temp[j]=='W')map[i][j+1]=true;
		}
	}	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(visited[i][j]) continue;
			visited[i][j]=true;
			if(map[i][j]==true)
			{
				connect(i,j);
				ans++;
			}	
		}
	}
	cout << ans << endl;
	return 0;
}

