#include<bits\stdc++.h>

using namespace std;
long long team[100002]={0},n;
long long ans;

int pre[100002];
int find(int x)                                                                                                         //查找根节点
{ 
    int r=x;
    while (pre[r]!=r) r=pre[r];	//返回根节点 r
    int i=x,j;
    while(i!=r)                                                                                                        //路径压缩
    {
         j=pre[i]; 				//在改变上级之前用临时变量  j 记录下他的值 
         pre[i]=r; 				//把上级改为根节点
         i=j;
    }
    return r;
}
 
 
void join(int x,int y)                                                                                                    //判断x y是否连通，
                                                                                             //如果已经连通，就不用管了 //如果不连通，就把它们所在的连通分支合并起,
{
    int fx=find(x),fy=find(y);
    if(fx!=fy)
        pre[fx]=fy;
}

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1;i<=n;i++)pre[i]=i;
	for(int i=1;i<=n;i++)
	{
		int target_station;
		cin>>target_station;
		join(i,target_station); 
		/*
		if(station[i] && station[target_station])
		{
			//两个都是有所属域的了
			if(station[i]!=station[target_station])
			{
				//把 station[target_station]那一组都给杀了
				int need_for_treatment=station[target_station];
				for(int j=1;j<=100000;j++) if(station[j]==need_for_treatment)station[j]=station[i];
				team[station[i]]+=team[need_for_treatment];
				team[need_for_treatment]=0;
				flag=need_for_treatment;
			}
		}
		else if(station[i] || station[target_station])
		{
			//只有一个有主人 
			int target_group=max(station[i],station[target_station]);
			station[target_station]=target_group;
			station[i]=target_group;
			team[target_group]++;
		}
		else
		{
			//都tm没域
			int target_group;
			for(int j=flag;j<=100000;j++)
			{
				if(!team[j])
				{
					target_group=j;
					flag=j+1;
					break;
				}
			}
			station[target_station]=target_group;
			station[i]=target_group;
			team[target_group]++;	
			if(target_station!=i)team[target_group]++;		
		}
		*/ 
	}
	for(int i=1;i<=n;i++)
	{
		while(1) if(pre[i]!=pre[pre[i]])pre[i]=pre[pre[i]];else break;
		team[pre[i]]++;
	}
	sort(team,team+n+1,cmp);
	team[1]+=team[0];
	for(int i=1;i<=100000;i++)
	{
		if(!team[i])break;
		ans+=team[i]*team[i];
	}
	cout << ans << endl;
	return 0;
}

