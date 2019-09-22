/*BOJ 1080 За·Д*/
#include<iostream>
using namespace std;
int n, m, ans;
char map[51][51], dest[51][51];
bool cmp() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != dest[i][j]) return false;
		}
	}
	return true;
}

void convert(int x,int y) {
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			if (map[i][j] == '0') map[i][j] = '1';
			else map[i][j] = '0';
		}
	}
}

void solve() {
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (map[i][j] == dest[i][j]) {
				if (cmp()) return;
			}
			else {
				convert(i, j);
				ans++;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> map[i][j];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> dest[i][j];
	}
	if (n < 3 || m < 3) {
		if (cmp()) cout << ans;
		else cout << -1;
	}
	else {
		solve();
		if (cmp()) cout << ans;
		else cout << -1;
	}
}