#include<stdio.h>
#include<math.h>

double a,b,c;

int main()
{
	scanf("%lf%lf%lf",&a,&b,&c);
	if(a>b){a+=b;b=a-b;a-=b;}
	if(b>c){b+=c;c=b-c;b-=c;}
	if(a>b){a+=b;b=a-b;a-=b;}
	if(a+b-c>1e-5)
	{
		if(b-a<1e-5 || c-b<1e-5 || c-a<1e-5) 
		{
			if(b-a<1e-5 && c-b<1e-5) printf("等边三角形\n");
			else if(pow(a,2)+pow(b,2)-pow(c,2)<1e-5) printf("等腰直角三角形\n"); 
			else printf("等腰三角形\n"); 
		}
		else if(pow(a,2)+pow(b,2)-pow(c,2)<1e-5) printf("直角三角形\n");
		else  printf("一般三角形\n");
	}
	else printf("不能构成三角形\n");
	return 0;
}
