#include<iostream>

using namespace std;
int n,m,baseValue,sum,ans;

void calcValue(int firstDay,int Day)
{
	sum+=firstDay;
	Day--;
	if(!Day) return ;
	else if(sum>m) return ;
	else calcValue((firstDay+1)/2,Day);
}

void search(int startNode,int endNode)
{
	if(endNode-startNode<=10){
		for(int i=startNode;i<=endNode;i++)
		{
			sum=0;
			calcValue(i,n);
			if(sum>m)break;
			else ans=i;
		}
		return ;
	}
	int mid=(startNode+endNode)/2;
	sum=0;
	calcValue(mid,n);
	if(sum>m){
		search(startNode,mid);
	}else{
		search(mid,endNode);
	}
}

int main()
{
	cin >> n >> m;
	search(1,m);
	cout << ans << endl;
	return 0;
}
