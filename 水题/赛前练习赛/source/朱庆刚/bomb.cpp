#include<cstdio>
#include<algorithm>
using namespace std;
struct city
{
	int n;
	int a;
	int x;
};
city a[2005];
bool cmpa(city a,city b)
{
	return a.a>b.a;
}
bool cmpb(city a,city b)
{
	return a.n<b.n;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].a);
		a[i].n=i;
	}
	sort(a+1,a+n+1,cmpa);
	int x=0;
	int last=a[1].a;
	for(int i=1;i<=n;i++)
	{
		a[i].x=x+1;
		if(a[i].a!=last)
		{
			x=a[i].x+1;
			last=a[i].a;
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d ",a[i].x);
	printf("\n");
	sort(a+1,a+n+1,cmpb);
	for(int i=1;i<=n;i++)
		printf("%d ",a[i].x);
	return 0;
}

