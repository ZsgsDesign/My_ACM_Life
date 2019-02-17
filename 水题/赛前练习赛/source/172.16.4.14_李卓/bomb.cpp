#include<bits/stdc++.h>
using namespace std;
int a[2010];
int x[2010];
int main(){
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x[i]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]<a[j])x[i]++;
		}
	}
	for(int i=1;i<=n;i++)cout<<x[i]<<" ";
	return 0;
}
