#include<iostream>
#include<cstring>
using namespace std;
char temp;
char str_temp[1002];
int limit,str_len,cur_r=1,cur_s=1; 
char matrix[102][102];

int main()
{
	//ios::sync_with_stdio(false);
	memset(matrix,' ',sizeof(matrix));
	cin >> limit;
	//cin >>temp;
	//cin.getline(str_temp,1000);
	//cin.getline(str_temp,1000);
	//str_len=strlen(str_temp);
	scanf("%c",&temp);
	while(~scanf("%c",&temp))
	{
		if(temp=='\n')break;
		matrix[cur_r][cur_s]=temp;
		cur_s++;
		if(cur_s>limit)
		{
			cur_s=1;
			cur_r++;
		}
	}
	if(cur_s==1)cur_r--;
	for(int i=1;i<=limit;i++)
	{
		for(int j=cur_r;j>=1;j--)
		{
			cout << matrix[j][i];
		}
		cout << endl;
	}
	return 0;
}
