#include<iostream>  
#include<algorithm>  
#include<cstring>  
 
  
using namespace std; 
int n;
int ans,min; 
int value[100002];
int dinner[100002];

int main()  
{  
    ios::sync_with_stdio(false);
    while(cin >> n)
    {
    	memset(value,0,sizeof(value));
    	memset(dinner,0,sizeof(dinner));
    	ans=0;
    	for(int i=1;i<=n;i++) cin >> value[i];
		if (n<2)ans=1;
		else
		{
			for (int i=1;i<=n;i++) dinner[i]=1;
			for (int i=1;i<=n;i++) if (i<n && value[i+1]>value[i]) dinner[i+1]=dinner[i]+1;
			for (int i=n;i>=1;i--)
			{
				if(i>1 && value[i-1]>value[i] && dinner[i-1]<=dinner[i]) dinner[i-1]=dinner[i]+1;
				ans+=dinner[i];
			}			
		}
		cout << ans << endl;
	}
    return 0;  
}  
