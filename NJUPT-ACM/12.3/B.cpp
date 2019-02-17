#include<bits/stdc++.h>  

using namespace std;
int phi[50005],n;

int solve(int n)
{  
    for(int i=2;i<=n;i++) phi[i] = 0;  
    phi[1] = 1;  
    int max_phi=0;  
    for(int i=2;i<=n;i++) 
    {	
		if(!phi[i]) 
		{
		    for(int j=i;j<=n;j+=i) 
			{  
		        if(!phi[j]) phi[j]=j;  
		        phi[j] = phi[j] / i * (i-1);  
		    }  			
		} 
	}
    for(int i=2;i<=n;i++) max_phi+=phi[i];  
    return max_phi;  
}  

  
  
int main()
{  
    while(cin >> n) if(n) cout << 2*solve(n)+1 << endl; else break; 
    return 0;  
}  
