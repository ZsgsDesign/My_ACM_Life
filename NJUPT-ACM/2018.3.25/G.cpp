#include <algorithm>  
#include <iostream> 

using namespace std;
int m,n,k;
int num[102];


int main()  
{
	cin >> m;
    for(int i=1;i<=m;i++)
    {
    	cin >> n >> k;
    	bool status[102]={0};
    	for(int j=1;j<=n;j++) cin >> num[j];
    	for(int j=1;j<=n;j++)
    	{
    		while(true)
    		{
	     		if(num[j]<=n)
	    		{
	    			if(status[num[j]])num[j]+=k;
	    			else
	    			{
	    				status[num[j]]=true;
	    				break;
					}
				}
				else break;	
			}
		}
		sort(num+1,num+1+n);
		bool ans=false;
		for(int j=1;j<=n;j++)
		{
			 if(num[j]!=j)break; 
			 if(j==n)ans=true;
		}
		if(ans)cout << "Jerry";
		else cout << "Tom";
		cout << endl;
	}
    return 0;  
}  
