#include <stdio.h>  
#include <string.h>  
#include <queue>  
  
using namespace std;  
  
#define min(a,b) (a)<(b)?(a):(b)  
#define max(a,b) (a)>(b)?(a):(b)  
  
const int INF = 1 << 20;  
  
int n,m,T,k,tmp,t[1002];  
int f[1002][1002], g[1002][1002], rec[1002];  
char name[1002][1002];  
  
int find(char *ch) {  
    for (int i = 0; i < tmp; i++) {  
        if (strcmp(ch, name[i]) == 0) return i;  
    }  
  
    strcpy(name[tmp], ch);  
    return tmp++;  
}  
  
void init() {  
  
 
}  
  
int solve() {  
    queue<int> q;  
    int ans = 0;  
  
    for (int i = 0; i < m; i++)  
        g[rec[i]][tmp]++;  
      
    while (1) {  
  
        int b = 0;  
        memset(t, 0, sizeof(t));  
        memset(rec, 0, sizeof(rec));  
  
        q.push(b);  
        t[b] = INF;  
  
        while (!q.empty()) {  
  
            b = q.front(), q.pop();  
  
            for (int i = 1; i <= tmp; i++) {  
  
                if (!t[i] && g[b][i] > f[b][i]) {  
  
                    int cur = min(g[b][i] - f[b][i], t[b]);  
                    if (cur > t[i]) {  
  
                        t[i] = cur;  
                        rec[i] = b;  
                        q.push(i);  
                    }  
                }  
            }  
        }  
  
        if (t[tmp] == 0) break;  
        ans += t[tmp];  
        for (int i = tmp; i; i = rec[i]) {  
            f[rec[i]][i] += t[tmp];  
            f[i][rec[i]] -= t[tmp];  
        }  
    }  
  
    return ans;  
}  
  
int main () 
{    
    cin >> T;
    for(int i=1;i<=T;i++)
	{
	    tmp = 1;  
	    memset(g, 0, sizeof(g));  
	    memset(f, 0, sizeof(f));  
	    memset(name, 0, sizeof(name));  

	    char ch[1002], na[1002];  
	  
	    cin >> n;
	    for (int j=1;j<=n;j++)
		{  
	        cin >> ch;
	        int p = find(ch);  
	        g[0][p]++;  
	    }  
	  
	    cin >> m;
	    for (int j=1;j<=m;j++)
		{  
	  
	        cin >> na >> ch; 
	        int p = find(ch);  
	        rec[i] = p;  
	    }  
	    cin >> k; 
	    for (int j=1;j<=k;j++) 
		{
	        scanf("%s%s", ch, na);  
	        int p = find(ch), q= find(na);  
	        g[q][p] = INF;  
	    } 
        cout << m-solve() << endl;
        if(T) cout << endl;
    }  
    return 0;  
}  

