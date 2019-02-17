#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i, s, t) for(i = s; i <= t; ++i)

using namespace std;

int n, m;
int a[100010];

bool check(int lim) {
	int t = 0, now = 0, i;
	rep(i, 1, n) {
		now += a[i];
		if(now > lim) {now = a[i]; ++t;}
	}
	return t <= m;
}

int main() {
	freopen("bradley.in", "r", stdin); freopen("bradley.out", "w", stdout);
	int i, l = 0, r = 0, mid, ans;
	scanf("%d %d", &n, &m);
	rep(i, 1, n) {
		scanf("%d", &a[i]);
		l = max(a[i], l);
		r += a[i];
	}
	while(l <= r) {
		mid = l + r >> 1;
		if(check(mid)) r = (ans = mid) - 1; else l = mid + 1;
	}
	printf("%d\n", ans);
	return 0;
}
