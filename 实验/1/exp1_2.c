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
			if(b-a<1e-5 && c-b<1e-5) printf("�ȱ�������\n");
			else if(pow(a,2)+pow(b,2)-pow(c,2)<1e-5) printf("����ֱ��������\n"); 
			else printf("����������\n"); 
		}
		else if(pow(a,2)+pow(b,2)-pow(c,2)<1e-5) printf("ֱ��������\n");
		else  printf("һ��������\n");
	}
	else printf("���ܹ���������\n");
	return 0;
}
