#include <bits/stdc++.h>  
using namespace std;  
int p[100005], a[100005], cnt[100005];  
int findset(int x){  
    return p[x] == x ? x : p[x] = findset(p[x]);  
}  
int main(){  
    int n, m;  
    cin >> n >> m;  
    for(int i = 1; i <= n; ++i){  
        p[i] = i;  
    }  
    for(int i = 1; i <= n; ++i){  
        scanf("%d", &a[i]);  
    }  
    int x, y;  
    for(int i = 1; i <= m; ++i){  
        scanf("%d %d", &x, &y);  
        p[findset(x)] = findset(y);  
    }  
    long long ans = 0;  
    memset(cnt, 0, sizeof(cnt));  
    for(int i = 1; i <= n; ++i){  
        if(findset(i) == i){  
            cnt[i] = 1e9;  
        }  
    }  
    for(int i = 1; i <= n; ++i){  
        cnt[findset(i)] = min(cnt[findset(i)], a[i]);  
    }  
    for(int i = 1; i <= n; ++i){  
        if(findset(i) == i){  
            ans += cnt[i];  
        }  
    }  
    cout<<ans<<endl;  
}  
  
/* 
题意： 
每个字母传递一个人有一个代价，朋友之间传递不需要代价，问所有人都被传到需要多少代价。 
 
思路： 
并查集处理朋友关系，对于一个集合只需要传递给大家最小的那个人，然后让他传递给他的所有朋友， 
把所有集合的最小值加起来即可。 
*/  
