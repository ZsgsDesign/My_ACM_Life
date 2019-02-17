#include<bits/stdc++.h>
using namespace std;
int n;
int A[11];
int f(bool type,int m)
{
	if(type)
	{
		for(int i=m;i>0;i--)
		if(A[i]>0)
		return i;
	}
	else
	for(int i=m;i<11;i++)
	if(A[i]>0)
	return i;
	
}
int a,b;
int num;
int small=1000000;

int main ()
{
	freopen("alchemist.in","r",stdin);
	freopen("alchemist.out","w",stdout);
	cin>>n;
	char ch=getchar();
	for(int i=0;i<n;i++)
	{
		a=0,b=0;
		memset(A,10,0);
		num=0;
		while((ch=getchar())!='\n')
		{
			if(ch==' ')
			continue;

			A[num]=ch-'0';
			num++;
		}
		sort(A,A+num);
		if(num%2==0)
		{
			a=A[0];
			b=A[1];
			for(int i=1;i<num/2;i++)
			{
				a=a*10+A[num-i];
				b=b*10+A[i+1];
			}
		}
		else
		{
			int j=0;
			for(j=0;A[j]==0;j++);
			b=A[j];
			if(j>num)
			b=0;
			a=A[num];
			A[j]=-1;
			for(j=0;j<=num/2;j++)
			if(A[j]!=-1)
			b=b*10+A[j];
			for(j=num;j>num/2;j--)
			a=a*10+A[j];
			cout<<b-a<<endl;
		}
		
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
