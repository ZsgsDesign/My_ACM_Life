#include<stdio.h>

void DrawPic(int n,char c)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)printf(" ");
		for(j=1;j<=2*i-1;j++)printf("%c",c);
		printf("\n");
	}
}

int main()
{
	DrawPic(7,'*');
	DrawPic(11,'@');
	DrawPic(37,'$');
	return 0;
}
