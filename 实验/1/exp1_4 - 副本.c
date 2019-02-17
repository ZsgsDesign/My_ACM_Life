#include<stdio.h>

int num;

int main()

{

	scanf("%d",&num);
	int i,ans=1;

	if(num<=1)ans=0;

	else if(num==2)ans=1;

	else for(i=2;i<num;i++) if(num%i == 0) ans=0;

	if(ans)printf("Yes\n");
	else printf("No\n");

	return 0; 

}
