//BOJ_2745_BaseConversion
#include<bits/stdc++.h>
using namespace std;
int main() {
	string s;
	int b; cin >> s >> b;
	int ans = 0;
	int temp = 1;
	for (int i = s.size() - 1; i >= 0; i--) {
		char c = s[i];
		if (c - '0' < 10) {
			ans += temp * (int)(c - '0');
			temp *= b;
		}
		else {
			ans += temp * (int)(c + 10 - 'A');
			temp *= b;
		}
	}
	cout << ans;
	return 0;
}