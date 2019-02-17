#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <iostream> 
#include <algorithm> 

using namespace std;
int a,b,c,myCnt,zCnt;
int ans;
bool usage[10];
int adjust[10][4] = {
						{0, 0, 0, 0},
						{2, 3, 4, 5},
						{1, 3, 4, 6},
						{1, 2, 5, 6},
						{1, 2, 5, 6},
						{1, 3, 4, 6},
						{2, 3, 4, 5}
					};



int main() {
	ios::sync_with_stdio(false);
    while (cin >> a >> b >> c)
	{
        memset(usage,false,sizeof(usage));
        usage[a]=true;
        usage[b]=true;
        usage[c]=true;
        ans = 0;
        for (int i = 1; i <= 6; i++)
		{
            myCnt = 0;
			zCnt = 0;
            for (int j = 0; j < 4; j++)
			{
                if (usage[adjust[i][j]]) zCnt++;
                else myCnt++;
            }
            if (zCnt > myCnt)
			{
                ans = i;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
