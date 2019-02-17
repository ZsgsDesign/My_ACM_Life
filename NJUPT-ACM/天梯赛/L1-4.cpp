#include<iostream>
#include<cmath>
using namespace std;
string A,B,temp;
int i=1;

int main()
{
	ios::sync_with_stdio(false);
	while(cin >> temp)
	{
		if(temp==".")break;
		if(i==2)A=temp;
		if(i==14)B=temp;
		i++;
	}
	i--;
	if(i<2) cout << "Momo... No one is for you ...";
	else if(i<14) cout << A << " is the only one for you...";
	else cout << A << " and " << B << " are inviting you to dinner...";
	cout << endl;
	return 0;
}
