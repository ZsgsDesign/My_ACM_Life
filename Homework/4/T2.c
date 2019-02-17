#include<stdio.h>
#include<math.h>

double sum=1.0,x,ans=0,temp;
	
int main()
{
	scanf("%lf",&x);
	int i=0,flag=1;
	while(1)
	{
		sum=sum*(i+1); //´æ´¢½×³Ë 
		temp=flag*pow(x,i+1)/sum;
		ans+=temp;
		if((pow(x,i+1)/sum)<pow(10,-5)) break;
		flag=-flag;
		i++;
	}
	printf("sum=%.2f\n",ans);
	return 0;
}
