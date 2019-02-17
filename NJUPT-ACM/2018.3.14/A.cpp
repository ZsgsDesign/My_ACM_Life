#include<iostream>  
#include<string>  

using namespace std;


int T;
string ans;
string A, B;
int ALen, BLen;
int nnext[1000001];

void get_next() {
	nnext[0] = 0;
	nnext[1] = 0;
	for (int i = 1; i < BLen; i++) {
		int j = nnext[i];
		while (j && B[i] != B[j]) {
			j = nnext[j];
		}
		if (B[i] == B[j]) nnext[i + 1] = j + 1;
		else nnext[i + 1] = 0;
	}
}

void kmp() {
	int j = 0;
	for (int i = 0; i < ALen; i++) {
		while (j && B[j] != A[i]) {
			j = nnext[j];
		}
		if (B[j] == A[i]) {
			j++;
		}
		if (j == BLen) {
			ans = "Alice";
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> T;
	while (T-->0) {
		cin >> A >> B;
		ALen = A.length();
		BLen = B.length();
		ans = "Bob";
		if (ALen >= BLen) {
			get_next();
			kmp();
			if (ans == "Bob") {
				for(int i=0;i<BLen/2;i++) {
					char temp=B[i];
					B[i]=B[BLen-i-1];
					B[BLen-i-1]=temp;
				}
				//reverse(B.begin(), B.end());
				get_next();
				kmp();
			}
		}
		cout << ans << endl;
	}

	return 0;
}

