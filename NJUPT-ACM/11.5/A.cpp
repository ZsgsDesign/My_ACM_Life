//#include<bits\stdc++.h>
#include<iostream>
#include<cstring>

using namespace std;
bool prime_seq[20][20];//������������
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
        //�Ƿ�ջ� 
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
        	//�ж�������ù�û��
	        if(isvisited[i]==false)
			{
	            if(prime_seq[i][m[k]])
				{
					//����ж��Ӻ��Ƿ�Ϊ����
	                isvisited[i]=true;//���ʹ��״̬
	                m[k+1]=i;//��ǰֵ�Ѿ���ȡ
	                dfs(k+1);//��������
	                isvisited[i]=false;//����
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
	for(int i=1;i<20;i++) for(int j=1;j<20;j++) prime_seq[i][j]=is_prime(i+j); //���
   	while(cin >> n)
	{
		if(count_t>1)cout << endl;
       	cout << "Case " << count_t << ":" << endl;
    	memset(isvisited,false,sizeof(isvisited));
        m[1]=1;//��ĿҪ���һ��������1
        dfs(1);//���������Ѿ�����һ���ˣ�Ȼ����������
        count_t++;
   	}
   return 0;
}
