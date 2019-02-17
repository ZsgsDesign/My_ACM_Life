#include <iostream>    
#include <string>    
#include <cmath>    
     
using namespace std;    
     
const  double  PRECISION = 1E-6;    
const  int  COUNT_OF_NUMBER  = 4;    
const  int  NUMBER_TO_BE_CAL = 24;    
double  number[COUNT_OF_NUMBER];    
string  expression[COUNT_OF_NUMBER];    
bool Judgement = false;                    //判断是否有解。       
     
void  Search(int n)    
{    
	if (n==1)  
	{    
		if ( fabs(number[0] - NUMBER_TO_BE_CAL) <= PRECISION   )  //对于除法，要小心小数的精确位数  
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
			number[j]=number[n - 1];   //递归之后，n比以前小一位，所以可以不停向前赋值   
			expa=expression[i];    
			expb=expression[j];    
			expression[j]  =  expression[n - 1];   //递归之后，n比以前小一位，所以可以不停向前赋值  
			expression[i]   =   '('   +   expa   +   '+'   +   expb   +   ')';   //加法不需要分顺序  
			number[i]   =   a   +   b;    
			Search(n-1);  
			expression[i]   =   '('   +   expa   +   '-'   +   expb   +   ')';   //减法应该分顺序，减数以及被减数  
			number[i]   =   a   -   b;    
			Search(n-1);   
			expression[i]   =   '('   +   expb   +   '-'   +   expa   +   ')';   //减法应该分顺序，减数以及被减数  
			number[i]   =   b   -   a;    
			Search(n-1);   
			expression[i]   =   '('   +   expa   +   '*'   +   expb   +   ')';   //乘法不需要分顺序  
			number[i]   =   a   *   b;    
			Search(n-1);   
			if (b != 0)  
			{
				expression[i]   =   '('   +   expa   +   '/'   +   expb   +   ')';   //除法应该分顺序，除数以及被除数  
				number[i] = a / b;
				Search(n-1);    
      		}      
       		if (a != 0)  
      		{    
				expression[i]   =   '('   +   expb   +   '/'   +   expa   +   ')';   //除法应该分顺序，除数以及被除数  
				number[i]   =   b  /  a;    
				Search(n-1);    
      		}    
     
         	number[i]=a;                  //这4句语句是为了防止如果上面几种可能都失败了的话,  
         	number[j]=b;                  //就把原来的赋值撤消回去,以无干扰的正确的进入到下一次  
         	expression[i]=expa;           //for循环队列中。  
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
		itoa(number[i],buffer,10);	//itoa()函数的作用是把第一个参数(数值)传送到第二个参数(字符串)中去，第三个参数(int型)是该数值在字符串里以什么进制存放。  
		expression[i]=buffer;    
  	}  
	Search(COUNT_OF_NUMBER) ;  
	if(Judgement==true)  
	{    
		cout   <<   "成功"   <<   endl;  
	}    
	else  
	{    
		cout   <<   "失败"   <<   endl;    
	}          
  return 0;  
}  
