#include<stdio.h>
int count=0;
int is_prime(int num)
{
	int i;
	if(num<=1)return 0;
	else if(num==2)return 1;
	else for(i=2;i<num;i++) if(num%i == 0) return 0;
    return 1;
}

int verify_goldbach(int num)
{
	if(num>2 && !(num%2))
	{
		int i;
		for(i=2;i<num;i++)
		{
			if(is_prime(i) && is_prime(num-i))
			{
				printf("%4d=%4d+%4d",num,i,num-i);
				count++;
				if(count%4)printf(" ");
				else printf("\n");
				return 0;
			}
		}
	}
}

int main()
{
	int i;
	for(i=3;i<=2000;i++)verify_goldbach(i);
	return 0;
}
