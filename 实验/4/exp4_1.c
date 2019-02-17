#include<stdio.h>

int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31}; //这里本该算一个前缀和，因为我不想在后面写循环了 

struct Date
{
	int year,month,day;
}date;

int IsLeapYear(struct Date a)
{
	return ((a.year%100)?((a.year%4)?0:1):((a.year%400)?0:1)); //直接复制第九章我宏定义代码了，不想重写了 
}

int Judge(struct Date a)
{
	if(a.year<1 || a.month<1 || a.month>12) return 0; //题目说年份不能为负数，对于年份是否可以为0不确定 
	else
	{
		if(IsLeapYear(a))days[2]++;  
		if(a.day<1 || a.day>days[a.month])return 0;
		else return 1;
	}
}

int Dayth(struct Date a)
{
	int i,ans=0;
	for(i=1;i<a.month;i++)
	{
		ans+=days[i];
	}
	return ans+a.day;
} 

int main()
{
	scanf("%d%d%d",&date.year,&date.month,&date.day);
	if(Judge(date)) printf("%d\n",Dayth(date));
	else printf("Error Input\n");
	return 0;
}
