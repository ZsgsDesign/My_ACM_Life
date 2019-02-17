#include<iostream>  
#include<stack>  
using namespace std;  
int b[1010];  
int main()  
{  
    int i,n,k,t;  
    stack<int> s;  
    while(cin >> n,n)  
    {  
        while(1)
		{  
	        while(!s.empty()) s.pop();  
	        int k=0,t=0;  
	        cin >> b[0];  
	        if(b[0]==0) break;  
	        for(i=1;i<n;i++) cin >>b[i];  
	        for(i=1;i<=n;i++)  
	        {  
	            s.push(i);  
	            while(!s.empty()&&s.top()==b[k])  
	            {  
	                k++;  
	                s.pop();  
	            }  
	        }  
	        if(s.empty())  
	            cout << "Yes" << endl;  
	        else  
	             cout << "NO" << endl;  
        }  
        cout << endl; 
    }  
} 
