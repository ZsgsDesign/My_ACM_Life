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
	        	//��A������A�ĵڼ�����B����B�ĵڼ��� 
	            //׼������C���Ǹ����ú�B������Ǿ�ֱ����   
	            if(A==target[B])
				{
					A++;
					B++;
				}   
	            //C�ĵ�һ������Ҫ����Ⱦͳ�ȥ   
	            else if(!s.empty()&&s.top()==target[B])
				{
					s.pop();
					B++;
				}  
	            //A�ĵ�ǰ��ʻ��C   
	            else if(A<=n)
				{
					s.push(A++);
				}   
	            //��������   
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
