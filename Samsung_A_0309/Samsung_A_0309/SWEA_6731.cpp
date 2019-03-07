#include<iostream>
#include<string>
using namespace std;
int T, n, ans;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int y[1001] = { 0, }, x[1001] = { 0, };
		bool isB[1001][1001] = { 0, };
		ans = 0; 
		cin >> n;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < n; j++) {
				if (s[j] == 'B') {
					isB[i][j] = true;
					x[i]++;
					y[j]++;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				if ((x[i] + y[j] - isB[i][j]) % 2) ans++;
		}
		cout << '#' << t << ' ' << ans << '\n';
	}
}