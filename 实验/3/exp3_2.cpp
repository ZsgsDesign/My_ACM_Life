#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void super_printf(double n) 						//���������ɾ��ĩβ0�� 
{
	char seq[20];
	sprintf(seq, "%.14f", n); 						//������������Ϊ��������λ����seq���� 
	int i=0;
    for(i=strlen(seq)-1;i>strchr(seq,'.')-seq;i--) 	//��С�����һλ�����һλ������ɾ��ĩβ0 
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
		//ԭ��ʹ�ñ�������� 
		super_printf(a[i]); 			//���������ɾ��ĩβ0�� 
		printf("%c",i==9?'\n':' '); 	//ֻ�������������У�����PE 
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
	for(i=1;i<10;i++) if(fabs(a[i]-n)<=1e-20) return 1; //����Ҫ���⸡������� 
	return 0;
}

int comp(const void*a,const void*b){return fabs(*(double*)a-*(double*)b)<1e-20?0:((*(double*)a-*(double*)b)>0?1:-1);} //ͬ���⸡�������� 

void array_sort(double* a)
{
	qsort(a,10,sizeof(double),comp); //stdlib��qsort 
}

int main()
{
	double array[10],targ;
	int i;
	for(i=0;i<10;i++) scanf("%lf",&array[i]);
	printf("��ϣ������������:");
	scanf("%lf",&targ);
	printf("\n\nƽ��ֵ��");
	super_printf(array_average(array));
	printf("\n����");
	super_printf(targ);	
	printf("�Ƿ���ڣ�%s\n���ֵ��",array_exist_n(array,targ)?"����":"�����ڵ�");
	super_printf(array_find_max(array));
	printf("\n��������");
	array_sort(array);
	array_print(array);
	return 0;
}
