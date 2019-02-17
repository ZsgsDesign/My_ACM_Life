#include<stdio.h>

int is_prime(int num)
{
	int i,a=0;
	for(i=2;i<num;i++)
	{
    	if (num%i == 0)
		{
            return 0;
    	}
    }
    return 1;
}

int main()
{
	int n=1,i;
	for(i=100;i<1000;i++)
	{
		if(is_prime(i))
		{
			printf("%6d",i);
			if(!(n%5))printf("\n");
			n++;
		}
	}
	printf("\n");
	return 0; 
}
