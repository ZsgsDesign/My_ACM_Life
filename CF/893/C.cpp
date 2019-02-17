#include<bits/stdc++.h>

using namespace std;
int n,m,ans[100002],citizen[100002][2],temp1,temp2;
long long sum=0;

int findUnion(int a)
{
	return a==citizen[a][1] ? a : citizen[a][1]=findUnion(citizen[a][1]);
}

void unionFind(int a,int b)
{
	int aRoot=findUnion(a);
	int bRoot=findUnion(b);
	if(aRoot==bRoot)return ;
	citizen[aRoot][1]=bRoot;
}

int main()
{
	memset(citizen,0,sizeof(citizen));
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> citizen[i][0];
	for(int i=1;i<=n;i++) citizen[i][1]=i;
	for(int i=1;i<=m;i++) 
	{
		cin >> temp1 >> temp2;
		unionFind(temp1,temp2);
	}
	for(int i=1;i<=n;i++) citizen[i][1]=findUnion(i);
	for(int i=1;i<=n;i++) if(citizen[i][1]==i) ans[i]=1000000001;
	for(int i=1;i<=n;i++) ans[citizen[i][1]]=min(ans[citizen[i][1]],citizen[i][0]);
	for(int i=1;i<=n;i++) if(citizen[i][1]==i) sum+=ans[i];
	cout << sum << endl;
	return 0;
}
