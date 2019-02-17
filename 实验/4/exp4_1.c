#include<stdio.h>

int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31}; //���ﱾ����һ��ǰ׺�ͣ���Ϊ�Ҳ����ں���дѭ���� 

struct Date
{
	int year,month,day;
}date;

int IsLeapYear(struct Date a)
{
	return ((a.year%100)?((a.year%4)?0:1):((a.year%400)?0:1)); //ֱ�Ӹ��Ƶھ����Һ궨������ˣ�������д�� 
}

int Judge(struct Date a)
{
	if(a.year<1 || a.month<1 || a.month>12) return 0; //��Ŀ˵��ݲ���Ϊ��������������Ƿ����Ϊ0��ȷ�� 
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
