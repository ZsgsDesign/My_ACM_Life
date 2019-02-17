#include<bits\stdc++.h>

using namespace std;
int n,m,k;
int schedule[502][502][3]; 	//0：值
							//1：假设这是一天中第一节课
							//2：假设这是一天中最后一节课 
int main()
{
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++)
	{
		int temp1=0;
		for(int j=1;j<=m;j++)
		{
			cin >> schedule[i][j][0]; //storge value
			 
		}
	}
	return 0;
}
