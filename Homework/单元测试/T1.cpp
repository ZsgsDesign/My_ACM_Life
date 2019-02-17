#include<stdio.h>
#include<math.h>
int ans=0;
int main()
{
	//这么水直接暴力了，不想了 
	int i,j,k;
	for(i=1;i<=150;i++)
	{
		for(j=1;j<=75;j++)
		{
			for(k=1;k<=30;k++)
			{
				if(i+2*j+5*k==150 && i+j+k==100)
				{
					printf("%3d %3d %3d\n",k,j,i);
					ans++;
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
