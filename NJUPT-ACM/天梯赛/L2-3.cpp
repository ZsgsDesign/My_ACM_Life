#include<algorithm>
#include<iostream>
#include<cstring>
  
using namespace std;  
int f[10010],vis[10010];
  
struct Family{
	int id,population; 
	double jct,jmj;  
}a[10010]; 
 
struct node{  
	int fct,zmj; 
}g[10010];
  
int find(int x)  
{  
	if(f[x]==x) return x; else return f[x]=find(f[x]);  
}
  
bool compare(Family a,Family b)  
{  
	if(a.jmj==b.jmj) return a.id<b.id;  
	else return a.jmj>b.jmj;  
}  
void merge(int a,int b)  
{  
	int x=find(a);  
	int y=find(b);  
	if(x!=y)
	{  
    	if(x<y) f[y]=x;///Ð¡µÄ±àºÅ  
    	else f[x]=y;  
	}
}  
int main()  
{  
	int n,ba,ma,k,t,zi,id,fct,zmj;  
	cin >> n;
  	for(int i=0;i<10010;i++)  
    f[i]=i;  
	memset(vis,0,sizeof(vis));  
	memset(a,0,sizeof(a));  
	while(n--)  
	{  
    	cin >> id >> ba >> ma >> k;  
	    if(ba!=-1) merge(id,ba);  
	    if(ma!=-1) merge(id,ma);  
	    vis[id]=1;  
	    vis[ba]=1;  
	    vis[ma]=1;  
	    for(int i=0;i<k;i++)  
	    {  
	    	cin >> zi; 
	    	merge(id,zi);  
	    	vis[zi]=1;  
	    }  
	    cin >> g[id].fct >> g[id].zmj;  
	}  
	k=0;  
	for(int i=0;i<10010;i++)  
	{  
		if(vis[i])  
    	{  
	    	int x=find(i);  
	    	for(int j=i;j<10010;j++)  
	    	{  
	        	if(vis[j]&&find(j)==x)  
	        	{  
	          		a[k].population++;  
	          		a[k].jct+=g[j].fct;  
	          		a[k].jmj+=g[j].zmj;  
	          		vis[j]=0;  
	        	}  
	      	}  
	      	a[k].jct/=(a[k].population*1.0);  
	      	a[k].jmj/=(a[k].population*1.0);  
	      	a[k++].id=x;  
	    }  
  	}		  
	sort(a,a+k,compare);  
	cout << k << endl; 
	for(int i=0;i<k;i++)  printf("%d %d %.3lf %.3lf\n",a[i].id,a[i].population,a[i].jct,a[i].jmj);  
	return 0;  
}  
