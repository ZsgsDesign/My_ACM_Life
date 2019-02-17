#include<stack>  
#include<iostream>  
using namespace std;  
int target[1002],n;  
  
int main()  
{    
	freopen("lalala.in","r",stdin);
	ios::sync_with_stdio(false);
    while(cin >> n,n)  
    {  
    	if(n==0)break;
        stack<int> s;  
        while(1)
		{  
	        cin >> target[1];  
	        if(target[1]==0)  break;  
	        for(int i=2;i<=n;i++)  
	        {  
	             cin >> target[i];  
	        }  
	        int A=1,B=1,ok=1;   
	        while(B<=n) 
	        {  
	        	//用A来代表A的第几个，B代表到B的第几个 
	            //准备开到C的那个正好和B的相等那就直接走   
	            if(A==target[B])
				{
					A++;
					B++;
				}   
	            //C的第一个和需要的相等就出去   
	            else if(!s.empty()&&s.top()==target[B])
				{
					s.pop();
					B++;
				}  
	            //A的当前车驶进C   
	            else if(A<=n)
				{
					s.push(A++);
				}   
	            //精尽人亡   
	            else  
	            {  
	                ok=0;  
	                break;  
	            }  
	        }  
	        if(ok)cout << "Yes";
			else cout << "No";
			cout << endl;
		}  
		//cin >> n;
		//if(n==0)break;
        cout << endl;
    }  
    return 0;
}  
