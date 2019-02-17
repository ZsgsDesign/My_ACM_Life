#include<stdio.h>
#include<string.h>

char seq[10002];
int length,i,j=-1;

void upcase(char* Trump)
{
	*Trump-=32;
}

int main()
{
	memset(seq,0,sizeof(seq));
	scanf("%s",seq);
	length=strlen(seq);
	for(i=0;i<length;i++) 
	{
		if(seq[i]>='a' && seq[i]<='z') upcase(&seq[i]);
	}
	printf("%s\n",seq); 
	return 0;
}
