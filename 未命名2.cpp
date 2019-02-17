#include <iostream>    
#include <string>    
#include <cmath>    
     
using namespace std;    
     
const  double  PRECISION = 1E-6;    
const  int  COUNT_OF_NUMBER  = 4;    
const  int  NUMBER_TO_BE_CAL = 24;    
double  number[COUNT_OF_NUMBER];    
string  expression[COUNT_OF_NUMBER];    
bool Judgement = false;                    //�ж��Ƿ��н⡣       
     
void  Search(int n)    
{    
	if (n==1)  
	{    
		if ( fabs(number[0] - NUMBER_TO_BE_CAL) <= PRECISION   )  //���ڳ�����ҪС��С���ľ�ȷλ��  
     	{    
     		Judgement = true;  
     		return ;
     	}
   	}    
     
   	for(int i=0;i<n;i++)  
    {  
      	for (int j=i+1;j<n;j++)  
    	{    
			double   a,b;    
			string   expa,expb;    
			a=number[i];    
			b=number[j];    
			number[j]=number[n - 1];   //�ݹ�֮��n����ǰСһλ�����Կ��Բ�ͣ��ǰ��ֵ   
			expa=expression[i];    
			expb=expression[j];    
			expression[j]  =  expression[n - 1];   //�ݹ�֮��n����ǰСһλ�����Կ��Բ�ͣ��ǰ��ֵ  
			expression[i]   =   '('   +   expa   +   '+'   +   expb   +   ')';   //�ӷ�����Ҫ��˳��  
			number[i]   =   a   +   b;    
			Search(n-1);  
			expression[i]   =   '('   +   expa   +   '-'   +   expb   +   ')';   //����Ӧ�÷�˳�򣬼����Լ�������  
			number[i]   =   a   -   b;    
			Search(n-1);   
			expression[i]   =   '('   +   expb   +   '-'   +   expa   +   ')';   //����Ӧ�÷�˳�򣬼����Լ�������  
			number[i]   =   b   -   a;    
			Search(n-1);   
			expression[i]   =   '('   +   expa   +   '*'   +   expb   +   ')';   //�˷�����Ҫ��˳��  
			number[i]   =   a   *   b;    
			Search(n-1);   
			if (b != 0)  
			{
				expression[i]   =   '('   +   expa   +   '/'   +   expb   +   ')';   //����Ӧ�÷�˳�򣬳����Լ�������  
				number[i] = a / b;
				Search(n-1);    
      		}      
       		if (a != 0)  
      		{    
				expression[i]   =   '('   +   expb   +   '/'   +   expa   +   ')';   //����Ӧ�÷�˳�򣬳����Լ�������  
				number[i]   =   b  /  a;    
				Search(n-1);    
      		}    
     
         	number[i]=a;                  //��4�������Ϊ�˷�ֹ������漸�ֿ��ܶ�ʧ���˵Ļ�,  
         	number[j]=b;                  //�Ͱ�ԭ���ĸ�ֵ������ȥ,���޸��ŵ���ȷ�Ľ��뵽��һ��  
         	expression[i]=expa;           //forѭ�������С�  
         	expression[j]=expb;           //  
      	}    
    }  
}    
     
int  main()    
{     
	A[i]={3,5,10,7};
	for (int i = 0; i < COUNT_OF_NUMBER; i++)   
  	{    
		char   buffer[20];      
		number[i]=A[i];                    
		itoa(number[i],buffer,10);	//itoa()�����������ǰѵ�һ������(��ֵ)���͵��ڶ�������(�ַ���)��ȥ������������(int��)�Ǹ���ֵ���ַ�������ʲô���ƴ�š�  
		expression[i]=buffer;    
  	}  
	Search(COUNT_OF_NUMBER) ;  
	if(Judgement==true)  
	{    
		cout   <<   "�ɹ�"   <<   endl;  
	}    
	else  
	{    
		cout   <<   "ʧ��"   <<   endl;    
	}          
  return 0;  
}  
