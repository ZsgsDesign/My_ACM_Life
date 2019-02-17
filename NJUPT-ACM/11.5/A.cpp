//#include<bits\stdc++.h>
#include<iostream>
#include<cstring>

using namespace std;
bool prime_seq[20][20];//记忆素数数组
int n;
bool isvisited[23];
int m[23];

bool is_prime(int num)
{
	if(num<=1)return false;
	else if(num==2)return true;
	else for(int i=2;i<num;i++) if(num%i == 0) return false;
    return true;
}

void dfs(int k)
{
    if(k==n&&prime_seq[m[k]][1])
	{
        //是否闭环 
	    for(int i=1;i<=n;i++)
		{
	        cout << m[i];
			if(i!=n) cout << " ";
			else cout << endl;
	    }
    }
    else
	{ 
    	for(int i=2;i<=n;i++)
    	{
        	//判断这个数用过没有
	        if(isvisited[i]==false)
			{
	            if(prime_seq[i][m[k]])
				{
					//查表，判定加和是否为素数
	                isvisited[i]=true;//标记使用状态
	                m[k+1]=i;//当前值已经可取
	                dfs(k+1);//向下搜索
	                isvisited[i]=false;//回溯
	            }
	        }
	    }
	}
}

int main()
{
	ios::sync_with_stdio(false);
    int count_t=1;
    memset(prime_seq,false,sizeof(prime_seq));
	for(int i=1;i<20;i++) for(int j=1;j<20;j++) prime_seq[i][j]=is_prime(i+j); //打表
   	while(cin >> n)
	{
		if(count_t>1)cout << endl;
       	cout << "Case " << count_t << ":" << endl;
    	memset(isvisited,false,sizeof(isvisited));
        m[1]=1;//题目要求第一个必须是1
        dfs(1);//所以我们已经先有一个了，然后向下搜索
        count_t++;
   	}
   return 0;
}
