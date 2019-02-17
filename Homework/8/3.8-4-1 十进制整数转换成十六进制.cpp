#include<stdio.h>
#include<string.h>

char seq[10002];
char s[]="0123456789ABCDEF";
long int num;
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
	scanf("%lld",&num);
	int i=0;
	while(num)
	{
		seq[i++]=s[num%16];
		num/=16;
	}
	length=strlen(seq);
	for(i=0;i<length/2;i++) swap(i,length-i-1);
	printf("%s\n",seq); 
	return 0;
}
