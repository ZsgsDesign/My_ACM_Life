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

void del_ele(int n)
{
	int i;
	seq[n]=0;
	for(i=n;i<length;i++) swap(i,i+1);
	length--;
}

int main()
{
	memset(seq,0,sizeof(seq));
	scanf("%s",&seq);
	length=strlen(seq);
	int i=0;
	while(i<length) 
	{
		if(seq[i]<'0' || seq[i]>'9') del_ele(i);
		else i++;		
	} 
	printf("%s\n",seq); 
	return 0;
}
