#include<stdio.h>
#include<string.h>

int n;
int matrix[102][102];

int is_symmetrical()
{
	int i,j;
	for(i=1;i<=n;i++) for(j=i;j<=n;j++) if(matrix[i][j]!=matrix[j][i]) return 0;
	return 1;
}

int main()
{
	memset(matrix,0,sizeof(matrix));
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) scanf("%d",&matrix[i][j]);
	printf("%s\n",is_symmetrical() ? "Yes" : "No");
	return 0;
}
