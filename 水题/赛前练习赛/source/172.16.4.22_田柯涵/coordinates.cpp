#include <bits/stdc++.h>
using namespace std;
int b[101][3],c[201][201],n;
char a[201][201];
int main()
{
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	int min1=1001,min2=1001,max1=-1001,max2=-1001;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i][1]>>b[i][2];
		if(min1>b[i][1]) min1=b[i][1];
		if(min2>b[i][2]) min2=b[i][2];
		if(max1<b[i][1]) max1=b[i][1];
		if(max2<b[i][2]) max2=b[i][2];
	}
	int ll1=abs(min1)+1;
	int ll2=abs(max2)+1;
	int tot1=abs(min1)+abs(max1)+1;
	int tot2=abs(min2)+abs(max2)+1;
	for(int i=1;i<=tot2;i++)
		a[i][ll1]='|';
	for(int i=1;i<=tot1;i++)
		a[ll2][i]='-';
	a[ll2][ll1]='+';
	for(int i=1;i<=n;i++)
	{
		if(b[i][2]>ll1) a[2*ll2-(b[i][2]+ll2-b[i][2]-(abs(b[i][1])-ll2+1))][b[i][1]+ll1]='*';
		else a[2*ll2-(b[i][2]+ll2)][b[i][1]+ll1]='*';                                          
	}
	for(int i=1;i<=tot2;i++)
		for(int j=1;j<=tot1;j++)
		{
			if(a[i][j]!='*' && a[i][j]!='|' && a[i][j]!='-' && a[i][j]!='+') a[i][j]='.';
			else continue;
		}
	for(int i=1;i<=tot2;i++)
	{
		for(int j=1;j<=tot1;j++)
			cout<<a[i][j];
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
