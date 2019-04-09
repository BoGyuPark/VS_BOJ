#include<iostream>
#include<cstring>
using namespace std;
int T, tc, n, a[20][20];
int dx[] = { 1,1,-1,-1 };
int dy[] = { -1,1,1,-1 };
int c[103], ansSum, ansCnt;
void simulation(int i, int j, int leftCnt, int rightCnt) {
	memset(c, 0, sizeof(c));
	int dircnt[4] = { leftCnt, rightCnt, leftCnt, rightCnt };
	int x = i, y = j;
	int cnt = 0;
	for (int t = 0; t < 4; t++) {
		int temp = dircnt[t];
		while (temp--) {
			int nx = x + dx[t], ny = y + dy[t];
			if (c[a[nx][ny]] != 0) return;
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) return;
			c[a[nx][ny]]++;
			cnt++;
			x = nx;
			y = ny;
		}
	}
	if (ansCnt < cnt) ansCnt = cnt;
	return;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> n;
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
			
		ansCnt = -1, ansSum = 0;
		for (int i = 0; i < n - 2; i++) {
			for (int j = 1; j < n - 1; j++) {
				for (int x = 1; x <= n - 2; x++) {
					for (int y = 1; y <= n - 2; y++) {
						simulation(i, j, x, y);
					}
				}
			}
		}
		cout << '#' << tc << ' ' << ansCnt << '\n';
	}
}