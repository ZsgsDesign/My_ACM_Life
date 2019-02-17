#include <stdio.h>
#include <math.h>
int main()
{
	double x,s;
	double sum=0,a=1.0;
	int i=1;
	scanf("%lf",&x);
    do
	{   
		s=pow(-1,i+1)*(pow(x,i)/a);
		//lalala=fabs(s);
		i++;
	    a*=i;
		
		sum+=s;
	}while(fabs(s)>=0.00001);
	printf("sum=%.2f\n",sum);
	return 0;
}
