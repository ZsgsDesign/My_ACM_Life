#include<iostream>  
#include<string>  

using namespace std;
int n,ans;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for(int a=1;a<=n;a++)
	{
		for(int b=a+1;b<=n;b++)
		{
			int c=a^b;
			if(c<=n && c>b && a+b>c)ans++;
		}
	}
	cout << ans << endl;
	return 0;
}

