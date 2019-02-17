#include<stdio.h>
int x;
int is_prime(int num)
{
	int i;
	if(num<=1)return 0;
	else if(num==2)return 1;
	else for(i=2;i<num;i++) if(num%i == 0) return 0;
    return 1;
}

int main()
{
	scanf("%d",&x);
	if(is_prime(x))printf("Yes\n");
	else printf("No\n");
	return 0; 
}
