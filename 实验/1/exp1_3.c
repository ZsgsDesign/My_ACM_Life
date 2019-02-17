#include<stdio.h>
#include<math.h>

double s=0;

int main()
{
	int i;
	for(i=1;i<=1000;i++)s+=pow(-1,i+1)/i;
	printf("%lf",s);
	return 0;
}
