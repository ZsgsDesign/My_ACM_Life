#include<stdio.h>
#include<math.h>

double s=0;

int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)s+=pow(-1,i+1)/i;
	printf("%lf",s);
	return 0;
}
