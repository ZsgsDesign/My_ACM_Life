#include<bits\stdc++.h>

char user_name[502][22];
double user_stat[502][2];
double temp[502];
int n;
using namespace std;

int main()
{
	//freopen("lalala.in","r",stdin);
	scanf("%d",&n);
	memset(user_name,0,sizeof(user_name));
	memset(user_stat,0,sizeof(user_stat));
	memset(temp,0,sizeof(temp));
	char lalala[1234];
	//scanf("%s",lalala);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",user_name[i]);
		scanf("%lf%lf",&user_stat[i][0],&user_stat[i][1]);
	}
	int ans[5]={0};
	double ans_num=9999999999.0; 
	for(int i=1;i<=n;i++)
	{
		memset(temp,0,sizeof(temp));
		double temp2=user_stat[i][0];
		for(int j=1;j<=n;j++)temp[j]=user_stat[j][1];
		temp[i]=0;
		sort(temp+1,temp+1+n);
		for(int j=2;j<=4;j++)
		{
			temp2+=temp[j]; 
		}
		if(temp2<ans_num)
		{
			ans_num=temp2;
			ans[1]=i;
			for(int j=1;j<=n;j++)
			{
				if(user_stat[j][1]-temp[2]<1e-6 && j!=ans[1])
				{
					ans[2]=j;
					break;
				}
			}
			for(int j=1;j<=n;j++)
			{
				if(user_stat[j][1]-temp[3]<1e-6 && j!=ans[1] && j!=ans[2])
				{
					ans[3]=j;
					break;
				}
			}
			for(int j=1;j<=n;j++)
			{
				if(user_stat[j][1]-temp[4]<1e-6 && j!=ans[1] && j!=ans[2] && j!=ans[3])
				{
					ans[4]=j;
					break;
				}
			}
		}
	}
	printf("%lf\n%s\n%s\n%s\n%s\n",ans_num,user_name[ans[1]],user_name[ans[2]],user_name[ans[3]],user_name[ans[4]]);
	return 0;
 } 
 
