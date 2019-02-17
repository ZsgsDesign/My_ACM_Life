#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <iostream> 
#include <algorithm> 

using namespace std;
int n,m,ans=999;
string a,b;
int matrix[102][102];


int main()
{
	ios::sync_with_stdio(false);
	cin >> m >> n;
	cin >> a >> b;
    if(m==0 || n==0) ans=m+n;
    for(int i=1;i<=m;i++)
	{
        for(int j=1;j<=n;j++)
		{
            if(a[i-1]==b[j-1]) matrix[i][j]=matrix[i-1][j-1]+1;
			else matrix[i][j]=max(matrix[i-1][j],matrix[i][j-1]);
        }

    }
    ans=m+n-2*matrix[m][n];
	cout << ans;
	return 0;
}
