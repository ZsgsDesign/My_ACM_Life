#include<stdio.h>
#include<string.h>

char seq[10002];
int length,i,j=-1;

int main()
{
	memset(seq,0,sizeof(seq));
	gets(seq);
	length=strlen(seq);
	for(i=0;i<length;i++) 
	{
		if(seq[i]<'0' || seq[i]>'9')
		{
			if(j<0) j=i;
		}
		else
		{
			if(j>-1)
			{
				seq[j]=seq[i];
				j++;
			}
		}
	}
	if(j>-1) for(i=j;i<length;i++) seq[i]=0;
	printf("%s\n",seq); 
	return 0;
}
