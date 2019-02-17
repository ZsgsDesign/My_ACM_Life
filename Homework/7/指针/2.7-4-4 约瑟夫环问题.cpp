#include<stdio.h>

int n,m;
int seq[102];

void swap(int* a,int* b)
{
	*a+=*b;
	*b=*a-*b;
	*a-=*b;	
}

void del_ele(int cur)
{
	int i;
	for(i=cur;i<n;i++) swap(&seq[i],&seq[i+1]);
	n--;
}

int main()
{
	scanf("%d%d",&n,&m);
	int i,cur=1;
	for(i=1;i<=n;i++) seq[i]=i;
	while(n!=1)
	{
		cur=(cur+m-1)%n;
		if(cur==0)cur=n;
		del_ele(cur); 
	}
	printf("%d\n",seq[1]);
	return 0;
}
