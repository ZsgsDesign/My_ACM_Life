#include<bits/stdc++.h>
using namespace std;
int n;
int xmax=0,xmin=0,ymax=0,ymin=0;
int main()
{
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	int a[250][2]={0};
	for(int i=0;i<n;i++)
	{
		cin>>a[i][0]>>a[i][1];
		if(xmax<a[i][0]) xmax=a[i][0];
		if(xmin>a[i][0]) xmin=a[i][0];
		if(ymax<a[i][1]) ymax=a[i][1];
		if(ymin>a[i][1]) ymin=a[i][1];
	}
	if(xmax<0&&ymax<0)
	{
		for(int i=xmin;i<=0;i++)
		{
			for(int j=ymin;j<=0;j++)
			{
				if(i==0&&j==0)
				{
					cout<<'+';
				}
				if(i==0&&j!=0)
				{
					cout<<'|';
				}
				if(i!=0&&j==0)
				{
					cout<<'-';
				}
				if(i!=0||j!=0)
				{
					for(int k=0;k<n;k++)
				{
					if(i==a[k][0]&&j==a[k][i])
					{
						cout<<'*';
					}
					else cout<<'.';
				}
				}

			}
		}
	}
	if(xmin>0&&ymin>0)
	{
		for(int i=0;i<=xmax;i++)
		{
			for(int j=0;j<=ymax;j++)
			{
				if(i!=0||j!=0)
				{
					for(int k=0;k<n;k++)
				{
					if(i==a[k][0]&&j==a[k][i])
					{
						cout<<'*';
					}
					else cout<<'.';
				}
				}
				if(i==0&&j==0)
				{
					cout<<'+';
				}
				if(i==0&&j!=0)
				{
					cout<<'|';
				}
				if(i!=0&&j==0)
				{
					cout<<'-';
				}
			}
	    }
	}
	if(xmax<0&&ymin>0)
	{
		for(int i=xmin;i<=0;i++)
		{
			for(int j=ymax;j>=0;j--)
			{
				if(i!=0||j!=0)
				{
					for(int k=0;k<n;k++)
				{
					if(i==a[k][0]&&j==a[k][i])
					{
						cout<<'*';
					}
					else cout<<'.';
				}
				}
				if(i==0&&j==0)
				{
					cout<<'+';
				}
				if(i==0&&j!=0)
				{
					cout<<'|';
				}
				if(i!=0&&j==0)
				{
					cout<<'-';
				}
			}
		}
	}
	if(xmin>0&&ymax<0)
	{
		for(int i=0;i<=xmax;i++)
		{
			for(int j=ymin;j<=0;j++)
			{
				if(i!=0||j!=0)
				{
					for(int k=0;k<n;k++)
				{
					if(i==a[k][0]&&j==a[k][i])
					{
						cout<<'*';
					}
					else cout<<'.';
				}
				}
				if(i==0&&j==0)
				{
					cout<<'+';
				}
				if(i==0&&j!=0)
				{
					cout<<'|';
				}
				if(i!=0&&j==0)
				{
					cout<<'-';
				}
			}
	    }
	}
	if(xmax<0)
	{
		for(int i=xmin;i<=0;i++)
		{
			for(int j=ymin;j<=ymax;j++)
			{
				if(i!=0||j!=0)
				{
					for(int k=0;k<n;k++)
				{
					if(i==a[k][0]&&j==a[k][1])
					{
						cout<<'*';
					}
					else cout<<'.';
				}
				}
				if(i==0&&j==0)
				{
					cout<<'+';
				}
				if(i==0&&j!=0)
				{
					cout<<'|';
				}
				if(i!=0&&j==0)
				{
					cout<<'-';
				}
			}
	}
	}
	if(xmin>0)
	{
		for(int i=0;i<=xmax;i++)
		{
			for(int j=ymin;j<=ymax;j++)
			{
				if(i!=0||j!=0)
				{
					for(int k=0;k<n;k++)
				{
					if(i==a[k][0]&&j==a[k][1])
					{
						cout<<'*';
					}
					else cout<<'.';
				}
				if(i==0&&j!=0)
				{
					cout<<'|';
				}
				if(i!=0&&j==0)
				{
					cout<<'-';
				}
				}
				if(i==0&&j==0)
				{
					cout<<'+';
				}
			}
	}
	}
	if(ymin>0)
	{
		for(int i=xmin;i<=xmax;i++)
		{
			for(int j=0;j<=ymax;j++)
			{
				if(i!=0||j!=0)
				{
					for(int k=0;k<n;k++)
				{
					if(i==a[k][0]&&j==a[k][1])
					{
						cout<<'*';
					}
					else cout<<'.';
				}
				}
				if(i==0&&j==0)
				{
					cout<<'+';
				}
				if(i==0&&j!=0)
				{
					cout<<'|';
				}
				if(i!=0&&j==0)
				{
					cout<<'-';
				}
			}
	}
	}
	if(ymax<0)
	{
		for(int i=xmin;i<=xmax;i++)
		{
			for(int j=ymin;j<=0;j++)
			{
				if(i!=0||j!=0)
				{
					for(int k=0;k<n;k++)
				{
					if(i==a[k][0]&&j==a[k][1])
					{
						cout<<'*';
					}
					else cout<<'.';
				}
				}
				if(i==0&&j==0)
				{
					cout<<'+';
				}
				if(i==0&&j!=0)
				{
					cout<<'|';
				}
				if(i!=0&&j==0)
				{
					cout<<'-';
				}
			}
	}
	}
	else
	{
		for(int i=xmin;i<=xmax;i++)
		{
			for(int j=ymin;j<=ymax;j++)
			{
				if(i!=0||j!=0)
				{
					for(int k=0;k<n;k++)
				{
					if(i==a[k][0]&&j==a[k][1])
					{
						cout<<'*';
					}
					else cout<<'.';
				}
				}
				if(i==0&&j==0)
				{
					cout<<'+';
				}
				if(i==0&&j!=0)
				{
					cout<<'|';
				}
				if(i!=0&&j==0)
				{
					cout<<'-';
				}
			}
	}
	}
	return 0;
}
