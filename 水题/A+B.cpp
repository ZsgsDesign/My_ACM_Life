#include<stdio.h>
#include<string.h>

int n,i,cur=1,sign,a=0,b=0;
char temp[105];
int temp_num[6];
char cmp[3][10]={{'z','o','t','t','f','f','s','s','e','n'},{'e','n','w','h','o','i','e','e','i','i'},{'r','e','o','r','u','v','x','v','g','n'}};

void calc(int* lalala)
{
	int mut=1,j;
	for(j=cur-1;j>=1;j--)
	{
		*lalala+=temp_num[j]*mut;
		mut*=10;
	}
	memset(temp_num,0,sizeof(temp_num));
	cur=1;
}

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		a=0;b=0;
		while(scanf("%s",temp))
		{
			if(temp[0]=='=')
			{
				calc(&b);
				printf("%d\n",sign?(a+b):(a-b));
				break;
			}
			if(temp[0]=='+' || temp[0]=='-')
			{
				sign=(temp[0]=='+'?1:0);
				calc(&a);
			}
			else
			{
				int j;
				for(j=0;j<=9;j++)
				{
					if(cmp[0][j]==temp[0] && cmp[1][j]==temp[1] && cmp[2][j]==temp[2]) 
					{
						temp_num[cur]=j;
						cur++;
						break;
					}
				}
			}
		}
	}
	return 0;
}
