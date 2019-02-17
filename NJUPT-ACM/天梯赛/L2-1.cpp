#include<iostream>  
#include<algorithm>  
#include<vector>
#include<cstring>
  
using namespace std;  
vector<int> map[100005];  
double power[100005];  
int n;  
double z,r;  
double sum=0;
  
void find(int k){  
    for(int i=0;i<map[k].size();i++)
	{  
        if(power[map[k][i]]!=1)
		{  
            power[map[k][i]]=power[k]*r*power[map[k][i]];  
            sum+=power[map[k][i]];  
        }  
        else
		{  
            power[map[k][i]]=power[k]*r;  
            find(map[k][i]);  
        }  
    }  
}  
int main()
{  
    cin >> n >> z >> r;  
    r=1-1.0*r/100;  
    for(int i=0;i<n;i++) power[i]=1;  
    power[0]=z;  
    int t;  
    for(int i=0;i<n;i++)
	{  
        cin>>t;  
        int num;  
        if(t==0)
		{  
            cin>>num;  
            power[i]=num;  
            if(n==1)
			{  
	            cout<<1.0*z*num;  
	            return 0;     
            }   
        }  
        for(int j=0;j<t;j++)
		{  
            cin>>num;  
            map[i].push_back(num);  
        }  
    }  
    find(0);  
    cout<<(int)sum;  
    return 0;  
}  
