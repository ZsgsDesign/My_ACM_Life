#include<stdio.h>
#include<string.h>

int matrix[4][4];
int i,j;

int is_symmetrical()
{
	if(matrix[2][1]==matrix[1][2] && matrix[3][1]==matrix[1][3] && matrix[2][3]==matrix[3][2] && matrix)return 1; return 0;
}

int main()
{
	for(i=1;i<=3;i++) for(j=1;j<=3;j++) scanf("%d",&matrix[i][j]);
	printf("%d\n",is_symmetrical());
	return 0;
}
