#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include "bignum.h"
using namespace std;

#ifndef FRACTION
#define FRACTION
class fraction
{
	protected:
		BigNum num;
		BigNum den;
	public:
		pair<int,BigNum> gcd(BigNum a,BigNum b); //求两个大数的最大公因数 
		double value(); //
		void print(); //输出大数 
		void println(); //屏幕输出大数并换行 
		void fprint(FILE *); //文件输出 
		void simplify(); //化简，约分 
		fraction(); //构造函数 
		fraction(BigNum m); //分母为1 
		fraction(BigNum m,BigNum n); //构造分数 
		fraction operator+(const fraction &)const; //重载加法运算 
		fraction operator-(const fraction &)const; //重载减法运算
		fraction operator*(const fraction &)const; //重载乘法运算
		fraction operator/(const fraction &)const; //重载除法运算，需先判断是否除以0 
		bool operator>(const fraction &T)const; //重载大于运算 
		bool operator>=(const fraction &T)const; //重载大于等于运算
		bool operator<(const fraction &T)const; //重载小于运算
		bool operator<=(const fraction &T)const; //重载小于等于运算
		bool operator==(const fraction &T)const; //重载等于运算
		bool operator!=(const fraction &T)const; //重载不等于运算
};



fraction::fraction(){}

fraction::fraction(BigNum m)
{
	num=m;
	den=BigNum(1);
}

fraction::fraction(BigNum m,BigNum n)
{
	assert(!(n==BigNum(0)));
	num=m;
	den=n;
	simplify();
}


void fraction::simplify()
{
	pair<int,BigNum> x;
	if (num==0)
	{
		den=1;
		return;
	}
	int flag=0;
	if (!(num>0))
	{
		flag=flag^1;
		num=BigNum(0)-num;
	}
	if (!(den>0))
	{
		flag=flag^1;
		den=BigNum(0)-den;
	}
	x=gcd(num,den);
	for (int i=1;i<=x.first;i++)
	{
		num=num/2;
		den=den/2;
	}
	num=num/x.second;
	den=den/x.second;
	if (flag) num=BigNum(0)-num;
}

pair<int,BigNum> fraction::gcd(BigNum a,BigNum b) //更相减损术求两个大数的最大公约数 
{
	int tmp=0;
	while (!(a==b))
	{
		if (a%2==0 && b%2==0)
		{
			tmp++;
			a=a/2;
			b=b/2;
		}
		else
		{
			if (a%2==0)
			{
				a=a/2;
			}
			else if (b%2==0)
			{
				b=b/2;
			}
			else
			{
				if (a>b)
				{
					a=a-b;
				}
				else
				{
					b=b-a;
				}
			}
		}
	}
	return make_pair(tmp,a);
}


void fraction::print()
{
	if (den==1) num.print();
	else
	{
		num.print();
		printf("/");
		den.print();
	}
	//printf("\n");
}

void fraction::println()
{
	if (den==1) num.print();
	else
	{
		num.print();
		printf("/");
		den.print();
	}
	printf("\n");
}

void fraction::fprint(FILE *fp)
{
	if (den==1) num.fprint(fp);
	else
	{
		num.fprint(fp);
		printf("/");
		den.fprint(fp);
	}
	//printf("\n");
}

double fraction::value()
{
	
}

fraction fraction::operator+(const fraction &b)const
{
	fraction t(*this);
	t.den=den*b.den;
	t.num=num*b.den+b.num*den;
	t.simplify();
	return t;
}

fraction fraction::operator-(const fraction &b)const
{
	fraction t(*this);
	t.den=den*b.den;
	t.num=num*b.den-b.num*den;
	t.simplify();
	return t;
}

fraction fraction::operator*(const fraction &b)const
{
	fraction t(*this);
	t.den=den*b.den;
	t.num=num*b.num;
	t.simplify();
	return t;
}

fraction fraction::operator/(const fraction &b)const
{
	assert(!(b.num==0));
	fraction t(*this);
	t.den=den*b.num;
	t.num=num*b.den;
	t.simplify();
	return t;
}


bool fraction::operator>(const fraction &T)const
{
	fraction x=*this-T;
	return x.num>0;
}

bool fraction::operator>=(const fraction &T)const
{
	fraction x=*this-T;
	return x.num>0 || x.num==0;
}

bool fraction::operator<(const fraction &T)const
{
	fraction x=*this-T;
	return BigNum(0)>x.num;
}

bool fraction::operator<=(const fraction &T)const
{
	fraction x=*this-T;
	return !(x.num>0);
}

bool fraction::operator==(const fraction &T)const
{
	fraction x=*this-T;
	return x.num==0;
}

bool fraction::operator!=(const fraction &T)const
{
	fraction x=*this-T;
	return !(x.num==0);
}


#endif
