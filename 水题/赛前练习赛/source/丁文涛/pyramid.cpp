#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int num;

string C[6];
struct people 
{
	string name;
	int B[6];
};
bool cmp(people a,people b)
{
	if(a.B[num]<b.B[num])
	return 0;
	else
	if(a.B[num]>b.B[num])
	return 1;
	else
	return a.name<b.name;
}

int main ()
{
	freopen("pyramid.in","r",stdin);
	freopen("pyramid.out","w",stdout);
	cin>>n>>m;
	people A[20001]; 
	for(int i=0;i<m;i++)
	cin>>C[i];
	for(int i=0;i<n;i++)
	{
		cin>>A[i].name;
		for(int j=0;j<m;j++)
		cin>>A[i].B[j];
		
	}
	cin>>k;
	for(int i=0;i<k;i++)
	{
		string temp;
		cin>>temp;
		bool end=0;
		for(int j=0;j<m;j++)
		if(C[j]==temp&&end==0)
		{
			num=j;
			sort(A,A+n,cmp);
			for(int l=0;l<n;l++)
			cout<<A[l].name<<endl;
			cout<<endl;
			end=1;
		}
		if(end==0)
		cout<<"It's not a problem a panda can deal with!"<<endl<<endl;
	}
	return 0;
	
	return 0;
}
