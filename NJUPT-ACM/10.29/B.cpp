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
					link(lx,rx); //假装x不存在
					link(ly,x);//x插到y左边一个的右边 
					link(x,y); //x插到y左边 
				}
				else if(tid==2 && x!=Right[y])
				{
					int lx=Left[x],ly=Left[y],rx=Right[x],ry=Right[y];
					link(lx,rx); //假装x不存在
					link(x,ry);//x插到y右边一个的左边 
					link(y,x); //x插到y右边 									
				} 
				else if(tid==3)
				{
					if(Right[y]==x)
					{
						swap(x,y);//统一xy相互接近的情况 
					}	
					int lx=Left[x],ly=Left[y],rx=Right[x],ry=Right[y];
					if(Right[x]==y)
					{
						link(lx,y); //y插入x左边的右边 
						link(y,x);  //x插到y右边 
						link(x,ry);	//x插到y右边一个的左边
					} 
					else
					{
						link(lx,y); //y与x左边连起来 
						link(y,rx); //y与x右边连起来 
						link(ly,x); //x与y左边连起来
						link(x,ry); //x与y右边连起来
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
		if(reverse_status && !(n%2))ans=(long long)n*(1+n)/2-ans;//另一半
		cout << "Case " << count_num << ": " << ans << endl; 
	}
    return 0;
}  
