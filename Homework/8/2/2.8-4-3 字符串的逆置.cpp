#include<stdio.h>
#include<string.h>

char seq[10002];
int length;

void swap(int a,int b)
{
	int temp=seq[a];
	seq[a]=seq[b];
	seq[b]=temp;
}

int main()
{
	memset(seq,0,sizeof(seq));
	scanf("%s",&seq);
	length=strlen(seq);
	int i;
	for(i=0;i<length/2;i++) swap(i,length-i-1);
	printf("%s\n",seq); 
	return 0;
}
