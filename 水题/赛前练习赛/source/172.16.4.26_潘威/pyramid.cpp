#include<bits/stdc++.h>
using namespace std;
string sx[6];
int n,m,k,i,j;
struct panda{
	string name;
	int score[6];
}a[20010];
int comp(const panda&a,const panda&b){
	if(a.score[j]>b.score[j])return 1;
	if(a.score[j]<b.score[j])return 0;
	if(a.name<b.name)return 1;
}
int main(){
	freopen("pyramid.in","r",stdin);
	freopen("pyramid.out","w",stdout);
cin>>n>>m;
	for(i=1;i<=m;i++)cin>>sx[i];
	for(i=1;i<=n;i++){
		cin>>a[i].name;
		for(j=1;j<=m;j++)cin>>a[i].score[j];
	}
	cin>>k;
	for(i=1;i<=k;i++){
		string s;
		cin>>s;
		int f=1;
		for(j=1;j<=m;j++)
			if(s==sx[j]){
				
				sort(a+1,a+n+1,comp);
				
				for(int x=1;x<=n;x++)
					cout<<a[x].name<<endl;
				f=0;
			}
		if(f==1)cout<<"It's not a problem a panda can deal with!"<<endl;
		if(i<k)cout<<endl;
	}
	return 0;
}
