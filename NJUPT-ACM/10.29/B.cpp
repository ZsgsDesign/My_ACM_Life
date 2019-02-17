#include<iostream> 
#include<cstring>  
using namespace std;  
int Right[100002],Left[100002],n,m;
bool reverse_status=false;  

void link(int l,int r)
{
	Right[l]=r;
	Left[r]=l;
}

int main()  
{    
	ios::sync_with_stdio(false);
	int count_num=0;
    while(cin >> n >> m)
    {
    	memset(Right,0,sizeof(Right));
    	memset(Left,0,sizeof(Left));
    	bool reverse_status=false; 
    	count_num++;
    	Left[0]=n;
    	Right[0]=1;
    	for(int i=1;i<=n;i++)
    	{
    		Left[i]=i-1;
    		
    		if(i!=n)Right[i]=i+1;
    		else Right[i]=0;
		}
		for(int i=1;i<=m;i++)
		{
			int tid,x,y;
			cin >> tid;
			if(tid==4) reverse_status=!reverse_status;
			else
			{
				cin >> x >> y;
				if(tid!=3 && reverse_status)tid=3-tid;
				
				if(tid==1 && x!=Left[y])
				{
					int lx=Left[x],ly=Left[y],rx=Right[x],ry=Right[y];
					link(lx,rx); //��װx������
					link(ly,x);//x�嵽y���һ�����ұ� 
					link(x,y); //x�嵽y��� 
				}
				else if(tid==2 && x!=Right[y])
				{
					int lx=Left[x],ly=Left[y],rx=Right[x],ry=Right[y];
					link(lx,rx); //��װx������
					link(x,ry);//x�嵽y�ұ�һ������� 
					link(y,x); //x�嵽y�ұ� 									
				} 
				else if(tid==3)
				{
					if(Right[y]==x)
					{
						swap(x,y);//ͳһxy�໥�ӽ������ 
					}	
					int lx=Left[x],ly=Left[y],rx=Right[x],ry=Right[y];
					if(Right[x]==y)
					{
						link(lx,y); //y����x��ߵ��ұ� 
						link(y,x);  //x�嵽y�ұ� 
						link(x,ry);	//x�嵽y�ұ�һ�������
					} 
					else
					{
						link(lx,y); //y��x��������� 
						link(y,rx); //y��x�ұ������� 
						link(ly,x); //x��y���������
						link(x,ry); //x��y�ұ�������
					}
				}
			}
			
		}
		int cur=0;
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			cur=Right[cur];
			if(i%2==1)ans+=cur;
		} 
		if(reverse_status && !(n%2))ans=(long long)n*(1+n)/2-ans;//��һ��
		cout << "Case " << count_num << ": " << ans << endl; 
	}
    return 0;
}  
