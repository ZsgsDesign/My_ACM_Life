#include<stdio.h>

int temp1=1,temp2=1,ans,sum=0;	

int main()
{
	int i;
	for(i=1;i<=10;i++)
	{
		if(i<3)ans=1;
		else
		{
			ans=temp1+temp2;
			temp1=temp2;
			temp2=ans;
		}
		printf("%d",ans);
		//sum+=ans;
		if(i==10)printf("\n");
		else printf(" ");
	}
	//printf("%d\n",sum);
	return 0;
}
