#include<bits/stdc++.h>
using namespace std;
 string ti[6];
struct stu{
	string name;
	int a[6];
	
} st[20001];
struct mm{
	string na;
	int index;
} py[6];
bool cmp1(stu a,stu b){
	if(a.a[1]!=b.a[1])return a.a[1]>b.a[1];
	else return a.name<b.name;
}
bool cmp2(stu a,stu b){
	if(a.a[2]!=b.a[2])return a.a[2]>b.a[2];
	else return a.name<b.name;
}
bool cmp3(stu a,stu b){
	if(a.a[3]!=b.a[3])return a.a[3]>b.a[3];
	else return a.name<b.name;
}
bool cmp4(stu a,stu b){
	if(a.a[4]!=b.a[4])return a.a[4]>b.a[4];
	else return a.name<b.name;
}
bool cmp5(stu a,stu b){
	if(a.a[5]!=b.a[5])return a.a[5]>b.a[5];
	else return a.name<b.name;
}
int n,m,tim;
int main(){
	freopen("pyramid.in","r",stdin);
	freopen("pyramid.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		py[i].index=i;
		cin>>py[i].na;
	}
	for(int i=1;i<=n;i++)
	{cin>>st[i].name;
	for(int j=1;j<=m;j++)
	cin>>st[i].a[j];
	}
	cin>>tim;
	for(int i=1;i<=tim;i++)
	cin>>ti[i];
	for(int i=1;i<=tim;i++)
	{bool e=false;
		for(int j=1;j<=m;j++)
		if(ti[i]==py[j].na)
		{
			if(i==1)sort(st+1,st+n+1,cmp1);
			if(i==2)sort(st+1,st+n+1,cmp2);
			if(i==3)sort(st+1,st+n+1,cmp3);
			if(i==4)sort(st+1,st+n+1,cmp4);
			if(i==5)sort(st+1,st+n+1,cmp5);
			for(int k=1;k<=n;k++){
			e=true;
			cout<<st[k].name<<endl;}
			
		}
		if(!e)cout<<"It's not a problem a panda can deal with!"<<endl;
		cout<<endl;
	}
	return 0;
}
