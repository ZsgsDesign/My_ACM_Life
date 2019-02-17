#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void super_printf(double n) 						//超级输出（删除末尾0） 
{
	char seq[20];
	sprintf(seq, "%.14f", n); 						//将数字重新作为输入流按位输入seq数组 
	int i=0;
    for(i=strlen(seq)-1;i>strchr(seq,'.')-seq;i--) 	//将小数点后一位到最后一位遍历，删除末尾0 
    {
        if(seq[i]=='0') seq[i]=0;
        else break;
    }
    if(seq[i]=='.')seq[i]=0;
    for(i=0;i<strlen(seq);i++) printf("%c",seq[i]);	
} 

void array_print(double* a)
{
	int i;
	for(i=0;i<10;i++) 					
	{
		//printf("%lf%c",a[i],i==9?'\n':' ');
		//原本使用本方法输出 
		super_printf(a[i]); 			//超级输出（删除末尾0） 
		printf("%c",i==9?'\n':' '); 	//只有最后再输出换行，避免PE 
	}
}

double array_average(double* a)
{
	int i;
	double sum=0;
	for(i=0;i<10;i++) sum+=a[i];
	return sum/10.0;
}

double array_find_max(double* a)
{
	int i;
	double maxn=a[0];
	for(i=1;i<10;i++) if(a[i]>maxn) maxn=a[i];
	return maxn;
}

double array_exist_n(double* a,double n)
{
	int i;
	for(i=1;i<10;i++) if(fabs(a[i]-n)<=1e-20) return 1; //还是要避免浮点陷阱的 
	return 0;
}

int comp(const void*a,const void*b){return fabs(*(double*)a-*(double*)b)<1e-20?0:((*(double*)a-*(double*)b)>0?1:-1);} //同避免浮点数陷阱 

void array_sort(double* a)
{
	qsort(a,10,sizeof(double),comp); //stdlib中qsort 
}

int main()
{
	double array[10],targ;
	int i;
	for(i=0;i<10;i++) scanf("%lf",&array[i]);
	printf("您希望搜索的数字:");
	scanf("%lf",&targ);
	printf("\n\n平均值：");
	super_printf(array_average(array));
	printf("\n数字");
	super_printf(targ);	
	printf("是否存在：%s\n最大值：",array_exist_n(array,targ)?"存在":"不存在的");
	super_printf(array_find_max(array));
	printf("\n排序结果：");
	array_sort(array);
	array_print(array);
	return 0;
}
