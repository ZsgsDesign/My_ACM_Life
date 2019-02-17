#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int INF = 100000000;
int n;
int a[10];
int num(int i, int j){
    int x = 0;
    for(int k = i; k < j; k ++){
        x *= 10;
        x += a[k];
    }
    return x;
}
void solve(){
    int ans = INF;
    int k = n / 2;
    do{
        if(a[0] == 0 || a[k] == 0)continue;
        int x = num(0, k), y = num(k, n);
        ans = min(ans, abs(x - y));
    }while(next_permutation(a, a + n));
    printf("%d\n", ans);
}

int main(int argc, char const *argv[]){
    freopen("alchemist.in","r",stdin);
    freopen("alchemist.out","w",stdout);
    int T;
    scanf("%d", &T);
    getchar();
    while(T --){
        char c;
        n = 0;
        while((c = getchar()) != '\n'){
            if(c != ' '){
                a[n ++] = c - '0';
            }
        }
        sort(a,a+n);
        solve();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
