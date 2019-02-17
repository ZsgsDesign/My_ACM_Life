#include<iostream>
#include<cmath>
using namespace std;
int day,h,m,n;
int timestamp;
char temp,h1,h2,m1,m2;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> day >> h1 >> h2 >> temp >> m1 >> m2;
		h=(h1-'0')*10+h2-'0';
		m=(m1-'0')*10+m2-'0';
		if(day==0) cout << "0 "<< h1 << h2 << ":" << m1 << m2;
		else {
			timestamp=(day-1)*24*60+h*60+m;
			timestamp/=2;
			day=timestamp/24/60;
			timestamp-=day*24*60;
			h=timestamp/60;
			timestamp-=h*60;
			m=timestamp;
			day++;
			cout << day << " ";
			if(h<10) cout << "0";
			cout << h << ":";
			if(m<10) cout << "0";
			cout << m;			
		}
		cout << endl;
	}
	return 0;
}
