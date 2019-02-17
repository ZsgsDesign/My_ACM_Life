#include<bits\stdc++.h>

int l,r;
int coffee[500002];
using namespace std;

int main()
{
	cin >> l >> r;
	if(l==0 && r==0)cout << "Not a moose" << endl;
	else if(l==r)cout << "Even " << 2*r << endl;
	else cout << "Odd " << 2*max(l,r) << endl;
	return 0;
 } 
