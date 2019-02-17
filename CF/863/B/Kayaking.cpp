#include<bits\stdc++.h>

int n,weight[102],ans=0;
using namespace std;

bool complare(int a,int b)
{
	if(a==0) return 0;
	else if(b==0) return 1;
	else return a<b;
}

bool search_min(int a)
{
	for(int i=0;i<2*n;i++)
	{
		if(abs(weight[i]-weight[i+1])==a)
		{
			weight[i]=0;
			weight[i+1]=0;
			sort(weight,weight+(2*n),complare);
			n-=1;
			return true;
		}
	}
	return false; 
} 

int main()
{
	cin >> n;
	for(int i=0;i<2*n;i++) cin >> weight[i];
	int flag=0;
	sort(weight,weight+(2*n),complare);
	while(true)
	{
		if(n>1)
		{
			if(search_min(flag)) ans+=flag;
			else flag++;
		}
		else break;
	}
	cout << ans << endl;
	return 0;
}
