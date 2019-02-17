#include<bits\stdc++.h>
#define MAX 100002
using namespace std;
int n,lalal;
int father[MAX];   /* father[x]表示x的父节点*/
int rank[MAX];     /*rank[x]表示x的秩*/
void Make_Set(int x)
{
	father[x] = x; //根据实际情况指定的父节点可变化
	rank[x] = 0;   //根据实际情况初始化秩也有所变化
}
 
/* 查找x元素所在的集合,回溯时压缩路径*/
 
int Find_Set(int x)
{
	if (x != father[x])
	{
	father[x] = Find_Set(father[x]); //这个回溯时的压缩路径是精华
	}
	return father[x];
}
 
/*
 
按秩合并x,y所在的集合
 
下面的那个if else结构不是绝对的，具体根据情况变化
 
但是，宗旨是不变的即，按秩合并，实时更新秩。
 
*/
 
void Union(int x, int y)
{
	x=Find_Set(x);
	y=Find_Set(y);
	if (x==y) return;
	if (rank[x]>rank[y])
	{
		father[y]=x;
	}
	else
	{
		if (rank[x]==rank[y])
		{
			rank[y]++;
		}
		father[x]=y;
	}
}

int main()
{
	
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		father[i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		cin >> lalal;
		Union(i,lalal);
	}
	return 0;
}
