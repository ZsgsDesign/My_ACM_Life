#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int MAXX = 201; ///

int n, a[500][500]; //
inline void solve() {
	int x, y;
	srand(time(0));
	scanf("%d", &n);
	printf("%d\n", n);
	for(int i = 1; i <= n; i++) {
		while(1) {
			x = rand() % MAXX - 100;
			y = rand() % MAXX - 100;
			if(!a[x + 100][y + 100]) break; //
		}
		a[x + 100][y + 100] = 1; ///
		printf("%d %d\n", x, y);
	}
}
int main() {
	solve();
	return 0;
}
