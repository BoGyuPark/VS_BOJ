#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
int main() {
	for (int tc = 1; tc <= 10; tc++) {
		int c[2][100] = { 0, };
		int num, n; cin >> num >> n;
		int a[2][100] = { 0, };
		for (int i = 0; i < n; i++) {
			int idx, next;
			cin >> idx >> next;
			if (a[0][idx] == 0) a[0][idx] = next;
			else a[1][idx] = next;
		}
		queue<int> q;
		for (int i = 0; i < 2; i++) {
			if (a[i][0] != 0) {
				q.push(a[i][0]);
				c[i][0] = 0;
			}
		}
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (int i = 0; i < 2; i++) {
				int next = a[i][now];
				if (next == 0) continue;
				if (c[i][next] == true) continue;
				q.push(next);
				c[i][next] = true;
			}
		}
		int ans = 0;
		if (c[0][99] == 1 || c[1][99] == 1) ans = 1;
		cout << '#' << tc << ' ' << ans << '\n';
	}
}