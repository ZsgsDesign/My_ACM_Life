#include<stdio.h>
#include<math.h>

double s=0;

int main()
{
	int i;
	for(i=1;;i++)
	{
		if(fabs(pow(-1,i+1)/i-pow(-1,i)/(i-1))<1e-6 && i!=1)
		{
			i--;
			break;
		}
		else s+=pow(-1,i+1)/i;
	}	
	printf("%lf %d",s,i);
	return 0;
}
