#include <bits/stdc++.h>

using namespace std;
long long n,k=0,b_number[12],ans; 

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for(int k=1;k<=10;k++) b_number[k]=(pow(2,k)-1)*pow(2,k-1);
	for(int k=9;k>=1;k--) if(!(n%b_number[k])) { cout << b_number[k]; break; }
	return 0;
}
