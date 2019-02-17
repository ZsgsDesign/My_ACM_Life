#include <iostream>  
#include <string>
#include <cstring>
using namespace std;
int N,R,C,ans,dp[102][102],board[102][102]; //dp存一下记忆化 
string name;
int dx[6]={0,-1,1,0,0};  //上、下、左、右 
int dy[6]={0,0,0,-1,1};  
int dfs( int i, int j )  
{  
    if(dp[i][j]>=0) return dp[i][j];  
    int temp = 1;  
    for(int k=1;k<=4;k++)  
    {  
        if( board[ i+dx[k] ][ j+dy[k] ] < board[i][j] )  
            temp = max( temp, dfs(i+dx[k],j+dy[k]) + 1 );  
    }
    dp[i][j]=temp;
    return dp[i][j]; 
}  

int main()  
{
	//freopen("lalala.in","r",stdin);
	ios::sync_with_stdio(false);
    cin>>N;  
    for(int i=1;i<=N;i++)  
    {  
        memset(dp,-1,sizeof(dp));  
        memset(board,1,sizeof(board));  
        cin >> name >> R >> C;  
        for(int i=1;i<=R;i++) for(int j=1;j<=C;j++) cin >> board[i][j]; 
        ans = 0;
        for(int i=1;i<=R;i++) for(int j=1;j<=C;j++) ans=max(ans,dfs(i,j));
        cout << name << ": " << ans << endl;  
    }
    return 0;  
}  
