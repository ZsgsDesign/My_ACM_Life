#include <iostream>  
#include <cstring> 
#include <string>  

using namespace std; 

string s[2002];  
int m[2002][2002];  
int low[2002], visited[2002];  
int n,ans;  
  
int Diff(int x, int y)  
{  
    int diff=0;
    for(int i=0;i<7;i++) if(s[x][i]!=s[y][i]) diff++;
    return diff;  
}  

void prim()  
{  
    int pos=0, minn=1000000001;  
    memset(visited,0,sizeof(visited));
    visited[0] = 1;  
    for(int i=0;i<n;i++) low[i]=m[pos][i];  
    for(int i=0;i<n-1;i++)  
    {  
        minn=1000000001;  
        pos=-1;  
        for(int j=0;j<n;j++)  
        {  
            if(!visited[j] && low[j]<minn)  
            {  
                minn=low[j];  
                pos=j;  
            }  
        }  
        ans+=minn;  
        visited[pos]=1;  
        for(int j=0;j<n;j++) if(!visited[j] && low[j]>m[pos][j]) low[j]=m[pos][j];  
    }  
}  

int main()  
{  
	ios::sync_with_stdio(false);
	while(cin >> n)
	{	
	    if(n==0)break;
	    for(int i=0;i<n;i++) cin>>s[i];  
	    for(int i=0;i<n-1;i++)  
	    {  
	        for(int j=i+1;j<n;j++)  
	        {  
	            m[i][j]=Diff(i,j); 
				m[j][i]=m[i][j]; 
	        }  
	    }  
	    ans=0;
	    prim();  
	    cout << "The highest possible quality is 1/" << ans << "." << endl;
	}
    return 0;  
}  
