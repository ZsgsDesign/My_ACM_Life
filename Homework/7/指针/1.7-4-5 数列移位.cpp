#include<stdio.h>

int n;
int seq[12]={0,1,2,3,4,5,6,7,8,9,10};

void swap(int* a,int* b)
{
	*a+=*b;
	*b=*a-*b;
	*a-=*b;
}

void move()
{
	int i;
	for(i=10;i>1;i--) swap(&seq[i],&seq[i-1]);
}

int main()
{
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) move();
	for(i=1;i<=10;i++) printf("%d ",seq[i]);
	return 0;
}
