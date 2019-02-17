#include<bits\stdc++.h>
#define MAX 100002
using namespace std;
int n,lalal;
int father[MAX];   /* father[x]��ʾx�ĸ��ڵ�*/
int rank[MAX];     /*rank[x]��ʾx����*/
void Make_Set(int x)
{
	father[x] = x; //����ʵ�����ָ���ĸ��ڵ�ɱ仯
	rank[x] = 0;   //����ʵ�������ʼ����Ҳ�����仯
}
 
/* ����xԪ�����ڵļ���,����ʱѹ��·��*/
 
int Find_Set(int x)
{
	if (x != father[x])
	{
	father[x] = Find_Set(father[x]); //�������ʱ��ѹ��·���Ǿ���
	}
	return father[x];
}
 
/*
 
���Ⱥϲ�x,y���ڵļ���
 
������Ǹ�if else�ṹ���Ǿ��Եģ������������仯
 
���ǣ���ּ�ǲ���ļ������Ⱥϲ���ʵʱ�����ȡ�
 
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
