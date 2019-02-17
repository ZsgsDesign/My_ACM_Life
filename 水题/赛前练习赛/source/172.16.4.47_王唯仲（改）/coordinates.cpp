#include<bits/stdc++.h>
using namespace std;
long long a[250],b[250],c[250][250];
int main()
{
    freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	memset(c,0,sizeof(c));
	int n,minx=0,maxx=0,miny=0,maxy=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	cin>>a[i]>>b[i];
	if(a[i]>=maxx) maxx=a[i];
	if(a[i]<=minx) minx=a[i];
	if(b[i]>=maxy) maxy=b[i];
	if(b[i]<=miny) miny=b[i];
	}
	int totx=maxx-minx+1;
	int toty=maxy-miny+1;
	for(int i=1;i<=n;i++)
	{
	if(a[i]>=0&&b[i]>=0) c[totx-a[i]+1][maxy-b[i]+1]=10;
	if(a[i]<0&&b[i]>0) c[-1*a[i]][maxy-b[i]+1]=10;
	if(a[i]>0&&b[i]<0) c[totx-a[i]+1][maxy+1+b[i]]=10;
	if(a[i]<0&&b[i]<0) c[-1*a[i]][maxy+1+b[i]]=10;
	}
	for(int i=1;i<=totx;i++)if(i!=maxx+1)c[i][maxy+1]=1;
	for(int i=1;i<=toty;i++)if(i!=maxy+1)c[maxx+1][i]=2;
	for(int i=1;i<=totx;i++)
	{
		for(int j=1;j<=toty;j++)
		{
			if(i==maxx+1&&j==maxy+1) cout<<"+";
			else
			{
			if(c[i][j]=1) cout<<'-';
			else
			{
			if(c[i][j]=2) cout<<'|';
			else
			{
					if(c[i][j]=10) cout<<'*';
					else cout<<'.';
			}
			}
			}
			cout<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
