//BOJ_2011_PasswordCode
#include<bits/stdc++.h>
long long d[5001];
using namespace std;
#define mod 1000000
int main() {
	/*char s[5004];	cin >> s + 1;
	s[0] = ' ';
	int n = strlen(s) - 1;*/
	string s; cin >> s;
	int n = s.size();
	s = ' ' + s;
	d[0] = 1;
	for (int i = 1; i <= n; i++) {
		int x = s[i] - '0';
		if (1 <= x && x <= 9) {
			//1자리를 해석했으므로 i-1번째 문자까지 해석했을 경우를 더해준다.
			d[i] = (d[i] + d[i - 1]) % mod;
		}
		if (i == 1) continue;
		if (s[i - 1] == '0') continue;
		x = (s[i - 1] - '0') * 10 + (s[i] - '0');
		if (10 <= x && x <= 26) {
			//2자리를 해석했으므로 i-2번째 문자까지 해석했을 경우를 더해준다.
			d[i] = (d[i] + d[i - 2]) % mod;
		}
	}
	cout << d[n];
	return 0;
}