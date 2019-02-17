#include <iostream>
#include <stdio.h>

using namespace std;

const int MXN = 1010;
const int INF = 100;

struct node {
	int x, y;
}a[MXN];
int n, r, c;
char final[MXN][MXN];
inline void solve() {
	int maxx = 0, maxy = 0;
	int minx = 0, miny = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d%d", &a[i].x, &a[i].y);
		maxx = max(maxx, a[i].x);
		maxy = max(maxy, a[i].y);
		minx = min(minx, a[i].x);
		miny = min(miny, a[i].y);
	}
	for(int i = minx; i <= maxx; i++) for(int j = maxy; j >= miny; j--) final[j + 100][i + 100] = '.';
	for(int i = minx; i <= maxx; i++) {
		for(int j = maxy; j >= miny; j--) {
			if(i == 0) final[j + 100][i + 100] = '|';
			if(j == 0) final[j + 100][i + 100] = '-';
			if(i == 0 && j == 0) final[j + 100][i + 100] = '+';
		}
	}
	for(int i = 1; i <= n; i++) {
		final[a[i].y + 100][a[i].x + 100] = '*';
	}
	for(int i = maxy; i >= miny; i--) {
		for(int j = minx; j <= maxx; j++) {
			printf("%c", final[i + 100][j + 100]);
		}
		printf("\n");
	}
}
int main() {
	freopen("coordinates.in", "r", stdin);
	freopen("coordinates.out", "w", stdout);
	solve();
	return 0;
}
