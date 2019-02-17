#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack> 
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include "fraction.h"
using namespace std;

#ifndef POSTFIX
#define POSTFIX

int prior(char c)
{
	if (c=='+') return 1;
	if (c=='-') return 1;
	if (c=='*') return 2;
	if (c=='/') return 2;
}

bool check(string s)
{
	for (int i=0;i<s.length();i++)
	{
		if (!((s[i]>='0' && s[i]<='9') || s[i]=='(' || s[i]==')' ||
			(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/') ) )
			return true;
	}
	for (int i=0;i<s.length();i++)
	{
		if (i!=0 && s[i]=='-' &&!(s[i-1]>='0' && s[i-1]<='9') && s[i-1]!='(' && s[i-1]!=')' )
			return true;
	}
	int x=0;
	for (int i=0;i<s.length();i++)
	{
		if (s[i]=='(')
		{
			if (x<0) return true;
			x++;
		}
		if (s[i]==')')
		{
			x--;
			if (x<0) return true;
		}
	}
	if (x!=0) return true;
	return false;
}

string change(string s)
{
	string ans="";
	for (int i=0;i<s.length();i++)
	{
		if (s[i]!=' ' && s[i]!='\t')
			ans=ans+s[i];
	}
	return ans;
}

vector<pair<char,fraction> > make_infix(string s)
{
	vector<pair<char,fraction> > ans;
	string x="";
	for (int i=0;i<s.length();i++)
	{
		if (s[i]>='0' && s[i]<='9')
		{
			x=x+s[i];
		}
		else if (s[i]=='-')
		{
			if (i==0 || s[i-1]=='(')
			{
				x=x+s[i];
			}
			else
			{
				if (x!="") ans.push_back(make_pair(0,fraction(x)));
				ans.push_back(make_pair(s[i],fraction(0)));
				x="";
			}
		}
		else
		{
			if (x!="") ans.push_back(make_pair(0,fraction(x)));
			ans.push_back(make_pair(s[i],fraction(0)));
			x="";
		}
	}
	if (x!="") ans.push_back(make_pair(0,fraction(x)));
	return ans;
}

vector<pair<char,fraction> > infix_postfix(vector<pair<char,fraction> > infix)
{
	vector<pair<char,fraction> > ans;
	stack<char> st;
	for (int i=0;i<infix.size();i++)
	{
		if (infix[i].first==0)
		{
			ans.push_back(make_pair(0,infix[i].second));
		}
		else
		{
			if (infix[i].first=='(')
			{
				st.push(infix[i].first);
			}
			else if (infix[i].first==')')
			{
	            while (!st.empty() && st.top()!='(')
	            {
	                ans.push_back(make_pair(st.top(),fraction(0)));
	                st.pop();
	            }
	            st.pop();
	        }
	        else
	        {
	        	while (!st.empty() && st.top()!='(' && prior(infix[i].first)<=prior(st.top()))
	        	{
	        		ans.push_back(make_pair(st.top(),fraction(0)));
	        		st.pop();
	        	}
	        	st.push(infix[i].first);
	        }
        }
	}
	while (!st.empty())
	{
		if (!st.top()!='(') ans.push_back(make_pair(st.top(),fraction(0)));
		st.pop();
	}
	return ans;
}

pair<int,fraction> value(vector<pair<char,fraction> > postfix)
{
	stack<fraction> st;
	for (int i=0;i<postfix.size();i++)
	{
		if (postfix[i].first==0)
		{
			st.push(postfix[i].second);
		}
		else
		{
			if (st.size()<2) return make_pair(0,fraction(0));
			fraction b=st.top();
			st.pop();
			fraction a=st.top();
			st.pop();
			if (postfix[i].first=='+')
			{
				fraction c=a+b;
				st.push(c);
			}
			else if (postfix[i].first=='-')
			{
				fraction c=a-b;
				st.push(c);
			}
			else if (postfix[i].first=='*')
			{
				fraction c=a*b;
				st.push(c);
			}
			else if (postfix[i].first=='/')
			{
				if (b==fraction(0)) return make_pair(0,fraction(0));
				fraction c=a/b;
				st.push(c);
			}
		}
	}
	if (st.size()!=1) return make_pair(0,fraction(0));
	else return make_pair(1,st.top());
}
	


pair<int,fraction> make_value(string s) //第一个原素表示是表达式否正确（1为正确，0为表达式错误），如果正确第二个原素为答案 
{
	s=change(s);
	if (check(s)) return make_pair(0,fraction(0));
	vector<pair<char,fraction> > infix=make_infix(s);
	vector<pair<char,fraction> > postfix=infix_postfix(infix);
	//cout<<postfix.size()<<endl;
	/*for (int i=0;i<postfix.size();i++)
	{
		if (postfix[i].first==0)
		{
			postfix[i].second.print();
			cout<<" ";
		}
		else
			cout<<postfix[i].first<<" ";
	}
	cout<<endl;*/
	return value(postfix);
}

#endif 
