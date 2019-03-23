#include<iostream>
using namespace std;
int n, m, alpha[28], ans;
char a[21][21];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
void dfs(int i, int j, int cnt) {
	if (ans < cnt) ans = cnt;
	for (int z = 0; z < 4; z++) {
		int nx = i + dx[z], ny = j + dy[z];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (alpha[a[nx][ny] - 'A'] == 0) {
			alpha[a[nx][ny] - 'A'] = true;
			dfs(nx, ny, cnt + 1);
			alpha[a[nx][ny] - 'A'] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) cin >> a[i][j];
	alpha[a[0][0] - 'A'] = true;
	ans = 1;
	dfs(0, 0, 1);
	cout << ans;
}