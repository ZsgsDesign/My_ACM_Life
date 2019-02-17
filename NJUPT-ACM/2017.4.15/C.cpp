#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <iostream> 
#include <algorithm> 

using namespace std;
int T,n,temp_a,temp_b;
int cargo[202],cMin,cMax;
int timeA,timeB;

int main()
{
	ios::sync_with_stdio(false);
	cin >> T;
	for(int i=1;i<=T;i++)
	{
		cin >> n;
		memset(cargo,0,sizeof(cargo));
		cargo[0]=1;
		for(int j=1;j<=n;j++)
		{
			cin >> temp_a >> temp_b;
			for(int k=1;k<=temp_b;k++)
			{
				cargo[cargo[0]]=temp_a;
				cargo[0]++;
			}
		}
		cargo[0]--;
		cMax=cargo[0];
		cMin=1;
		sort(cargo+1,cargo+1+cargo[0]);
		timeA=0;
		timeB=0;
		while(1)
		{
			if(cMax<cMin)break;
			if(timeA<timeB)
			{
				timeB+=timeA;
				timeA=timeB-timeA;
				timeB-=timeA;
			}
			timeB+=cargo[cMax];
			cMax--;
			while(1)
			{
				if(cMin>cMax)break;
				timeA+=cargo[cMin];
				if(timeA>timeB)
				{
					if((timeA-timeB)>(timeB-timeA+cargo[cMin])){
						timeA-=cargo[cMin];
						break;
					}
				}
				cMin++;
				if(timeA==timeB)break;
			}
		}
		cout << max(timeA,timeB) << endl;
	}
	return 0;
}
