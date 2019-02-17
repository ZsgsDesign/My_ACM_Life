#include <bits\stdc++.h>  

using namespace std;  
double a,b,c;

int main ()
{   
    while (cin >> a >> b >> c) printf("%.5lf\n",(a*b+b*(b-1))/(a+b-c-1)/(a+b));  
    return 0;  
}  

