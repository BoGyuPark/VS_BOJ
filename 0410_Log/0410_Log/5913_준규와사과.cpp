#include<iostream>
using namespace std;
int n, a[5][5], c[5][5];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int cnt = 1, ans = 0;
void dfs(int i, int j) {
	if (cnt == 25 - n && (i == 4 && j == 4)) {
		ans++;
		return;
	}
	for (int z = 0; z < 4; z++) {
		int nx = i + dx[z], ny = j + dy[z];
		if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
		if (c[nx][ny] != 0) continue;
		if (a[nx][ny] == -1) continue;
		cnt++;
		c[nx][ny] = c[i][j] + 1;
		dfs(nx, ny);
		c[nx][ny] = 0;
		cnt--;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		a[x - 1][y - 1] = -1;
	}
	c[0][0] = 1;
	dfs(0, 0);
	cout << ans;
}