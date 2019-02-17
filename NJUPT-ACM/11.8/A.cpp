#include<stdio.h>
#include<math.h>
int main()
{
    double x,z=1,y=1;
    double sum=0;
    scanf("%lf",&x);
    int i=1;
    int j;
    for(j=1;fabs(y)>=0.00001;j++)
    
        {
        y=y*x*i/j;
        sum=sum+y;
        //i=-i;
        i=-1;
    }
    printf("%.2f",sum);
    return 0;
}
