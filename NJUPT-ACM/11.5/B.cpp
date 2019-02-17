#include <cstdio>  
#include <cstring>  
#include <iostream> 
 
using namespace std;  

long long n,v1,s1,v2,s2,count_t,sum,s,sum1;  
int main()  
{
    cin >> count_t;  
    for(int i=1;i<=count_t;i++) 
    {  
        cin >> n >> s1 >> v1 >> s2 >> v2;
        long long value=0,va=0;  
        if(v1*s2 > v2*s1)
        {
        	while(1)
        	{
        		if(n-s1>=0)
        		{
        			value+=v1;
        			n-=s1;
				}
				else break;
			}
		}
		else
        {
        	while(1)
        	{
        		if(n-s2>=0)
        		{
        			value+=v2;
        			n-=s2;
				}
				else break;
			}
		} 
        if(s1<s2) 
		{
			swap(s1,s2);
			swap(v1,v2); 
		} 
        for(int j=0; j<=n/s1; j++) va=max((n-j*s1)/s2*v2+j*v1,va);  
        value+=va;  
        cout << "Case #" << i << ": " << value << endl;  
    }  
    return 0;  
}  

