#include<stdio.h>

void array_print(double a[])
{
	int i;
	for(i=0;i<=9;i++) printf("%lf ",a[i]);
}

double array_average(double* a)
{
	int i;
	double sum=0;
	for(i=0;i<=9;i++) sum+=a[i];
	return sum/10.0;
}

double array_find_max(double* a)
{
	int i;
	double maxn=a[0];
	for(i=1;i<=9;i++) if(a[i]>maxn)maxn=a[i];
	return maxn;	
}

int array_find_n(double* a,double n)
{
	int i;
	for(i=0;i<=9;i++) if(a[i]==n) return 1;
	return 0;	
} 

void array_sort(double* a)
{
	int i, j;
	double temp;
    for (j=0;j<9;j++)
    {
	    for (i=0;i<9-j;i++)
	    {
	        if(a[i]>a[i+1])
	        {
	            temp=a[i];
	            a[i]=a[i+1];
	            a[i+1]=temp;
	        }
	    }
	}
}

int main()
{
	double array[10];
	int i;
	for(i=0;i<=9;i++) scanf("%lf",&array[i]);
	array_sort(array);
	array_print(array);
	double average=array_average(array);	
	return 0;
}
