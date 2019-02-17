#include<stdio.h>
#include<math.h>
#define M_PI 3.14159265358979323846
double h,r;
double count_v(){return M_PI*r*r*h/3;}
double count_s(){return M_PI*r*r+M_PI*r*sqrt(h*h+r*r);}

int main()
{
	scanf("%lf%lf",&r,&h);
	printf("Radius=%.2f,Height=%.2f,Area=%.2f,Volume=%.2f",r,h,count_s(),count_v());
	return 0;
}
