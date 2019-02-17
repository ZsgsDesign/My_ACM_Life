#include<stdio.h>
#include<string.h>

int seq[10002];

void swap(int a,int b)
{
	int temp=seq[a];
	seq[a]=seq[b];
	seq[b]=temp;
}

int main()
{
	for(int i=0;i<10;i++) scanf("%d",&seq[i]);
	int i;
	for(i=0;i<5;i++) swap(i,9-i);
	for(int i=0;i<10;i++) printf("%d%c",seq[i],i==9?'\n':' '); 
	return 0;
}
