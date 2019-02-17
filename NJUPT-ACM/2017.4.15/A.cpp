#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <iostream> 
#include <algorithm> 

using namespace std;
int n,ans;
int a,b,c,t;


int main()
{
	//ios::sync_with_stdio(false);
	cin >> n;
	//cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a >> b >> c;
		if(a>b){t=a;a=b;b=t;}
		if(b>c){t=b;b=c;c=t;}
		if(a>b){t=a;a=b;b=t;}
		ans=c-b;
		b+=ans;
		a+=ans;
		ans+=(c-a)/2;
		if((c-a)%2) ans+=2;
		cout << ans << endl;
		//printf("%d\n",ans);
	} 
	return 0;
}
