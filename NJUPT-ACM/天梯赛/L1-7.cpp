#include<iostream>
#include<cmath>
using namespace std;
int n,h,w;

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> h >> w;
		double standard=(h-100)*1.8;
		if(fabs(standard-w) <standard*0.1) cout << "You are wan mei!";
		else if(standard<w) cout << "You are tai pang le!";
		else cout << "You are tai shou le!";
		cout << endl;
	}
	return 0;
}
