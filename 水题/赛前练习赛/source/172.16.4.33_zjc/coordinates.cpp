#include <cstdio>

using namespace std;
struct node
{
	int x,y;
}a[255];
char b[205][205];

int main()
{
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	int n;
	scanf("%d",&n);
	int maxx = 0,maxy = 0,minx = 0,miny = 0;
	for(int i = 1; i <= n; ++ i)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		if(a[i].x > maxx) maxx = a[i].x;
		if(a[i].x < minx) minx = a[i].x;
		if(a[i].y > maxy) maxy = a[i].y;
		if(a[i].y < miny) miny = a[i].y;
	}
	int xx = maxx - minx + 1,yy = maxy - miny + 1;
	//printf("%d %d %d %d %d %d\n",minx,miny,maxx,maxy,xx,yy);
	for(int i = 1; i <= yy; ++ i)
	{
		for(int j = 1; j <= xx; ++ j)
		{
			b[i][j] = '.';
		}
	}
	for(int i = 1; i <= yy; ++ i)
	{
		b[i][- minx + 1] = '|';
	}
	for(int i = 1; i <= xx; ++ i)
	{
		b[maxy + 1][i] = '-';
	}
	b[maxy + 1][- minx + 1] = '+';
	for(int i = 1; i <= n; ++ i)
	{
		a[i].x = a[i].x - minx + 1;
		a[i].y = a[i].y - miny + 1;
		a[i].y = yy - a[i].y + 1;
		b[a[i].y][a[i].x] = '*';
	}
	/*for(int i = 1; i <= n; ++ i)
	{
		printf("%d %d\n",a[i].x,a[i].y);
	}*/
	for(int i = 1; i <= yy; ++ i)
	{
		for(int j = 1; j <= xx; ++ j)
		{
			printf("%c",b[i][j]);
		}
		printf("\n");
	}
	return 0;
}
