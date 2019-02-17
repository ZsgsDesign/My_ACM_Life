#include<stdio.h>
#include<math.h>

int main()
{
	int i;
	for(i=100;i<=999;i++)
	{
		if(i==pow(i/100,3)+pow(i%10,3)+pow((i/10)%10,3)) printf("%d ",i);
	}
	printf("\n");
	return 0;
}
