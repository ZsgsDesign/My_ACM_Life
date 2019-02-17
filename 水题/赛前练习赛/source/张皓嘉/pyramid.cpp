#include<bits/stdc++.h>
using namespace std;
string sx[10];
int n, m, b, j;
struct panda
{
	int score[10];
	string name;
}a[20010];
int comp(const panda&a,const panda&b)
{
	if(a.score[j] > b.score[j] || a.name < b.name) return 1;
	if(a.score[j] < b.score[j]) return 0;
}
int main(){
	freopen("pyramid.in","r",stdin);
	freopen("pyramid.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
		cin >> sx[i];
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i].name;
		for(j = 1; j <=m; j++) cin >> a[i].score[j];
	}
	cin >> b;
	for(int i = 1; i <= b; i++)
	{
		string s;
		cin >> s;
		int f = 1;
		for(j = 1; j <= m; j++)
			if(s == sx[j])
			{
				sort(a+1, a+n+1, comp);
				for(int k = 1; k <= n; k++)
					cout << a[k].name << endl;
				f = 0;
			}
		if(f == 1) cout<< "It's not a problem a panda can deal with!"<<endl;
		if(i < b) cout << endl;
	}
	return 0;
}
