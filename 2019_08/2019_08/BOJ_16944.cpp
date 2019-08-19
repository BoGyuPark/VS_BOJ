/*BOJ 16944 강력한 비밀번호*/
#include<iostream>
#include<string>
using namespace std;
int n, ans, cnt[4]; // num, lowAlpha, upperAlpha, other;
string s;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		char c = s[i];
		if (isdigit(c)) cnt[0]++;
		else if ('a' <= c && c <= 'z') cnt[1]++;
		else if ('A' <= c && c <= 'Z') cnt[2]++;
		else cnt[3]++;
	}

	if (n >= 6) {
		for (int i = 0; i < 4; i++) if (cnt[i] == 0) ans++;
	}
	else {
		for (int i = 0; i < 4; i++) if (cnt[i] == 0) ans++;
		if (ans + n < 6) ans += (6 - (ans + n));
	}
	cout << ans;
}