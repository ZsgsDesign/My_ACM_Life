#include<bits\stdc++.h>  

using namespace std;


int T,ans;
string text,word;  
int textLen,wordLen;
int nnext[1000001];

void get_next() {
	nnext[0] = nnext[1] = 0;
	for (int i = 1; i < wordLen; i++) {
		int j = nnext[i];
		while (j && word[i] != word[j]) {
			j = nnext[j];
		}
		nnext[i + 1] = word[i] == word[j] ? j + 1 : 0;
	}
}

void kmp() {
	ans=0;
	int j = 0;
	for (int i = 0; i < textLen; i++) {
		while (j && word[j] != text[i]) {
			j = nnext[j];
		}
		if (word[j] == text[i]) {
			j++;
		}
		if (j == wordLen) {
			ans++;  
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> T;
	while (T-->0) {
		cin >> word >> text;
		textLen = text.length();
		wordLen = word.length();
		get_next();
		kmp();
		cout << ans << endl;
	}

	return 0;
}

