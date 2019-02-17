#include<iostream>
#include<cmath>

using namespace std;
char h1,h2,m1,m2;
int ans=0;

void Dang()
{
	if(ans!=0) for(int i=1;i<=ans;i++) cout << "Dang";
	else cout << "Only " << h1 << h2 << ":" << m1 << m2 << ".  Too early to Dang.";
	cout << endl;
}

int main()
{
	cin >> h1 >> h2;
	cin >> m1;
	cin >> m1 >> m2;
	if(h1=='0' || (h1=='1' && h2<='2' && m1=='0' && m2=='0') || (h1=='2' && h2=='4')) ;
	else {
		ans=(h1-'0')*10+h2-'0'-12;
		if(m1!='0' || m2!='0')ans++;
	}
	Dang();
	return 0;
}
