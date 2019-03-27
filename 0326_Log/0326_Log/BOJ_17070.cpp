#include<iostream>
using namespace std;
int n, a[17][17], c[17][17];
int dx[] = { 0,1,1 };
int dy[] = { 1,0,1 };
int dis[3][3] = { {0,2,-1},{1,2,-1},{0,1,2} };
int cnt = 0;
void dfs(int i, int j, int dir) {
	if (i == n - 1 && j == n - 1) {
		cnt += 1;
		return;
	}
	int x = i, y = j;
	for (int z = 0; z < 3; z++) {
		int d = dis[dir][z];
		if (d == -1) continue;
		int nx = x + dx[d], ny = y + dy[d];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if (c[nx][ny] == true) continue;
		if (a[nx][ny] != 1) {
			//대각선일때는 대각선 위, 왼쪽 확인
			if (d == 2) {
				if (a[nx - 1][ny] == 0 && a[nx][ny - 1] == 0) {
					c[nx][ny] = true;
					dfs(nx, ny, d);
					c[nx][ny] = false;
				}
			}
			else {
				c[nx][ny] = true;
				dfs(nx, ny, d);
				c[nx][ny] = false;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
	c[0][1] = true;
	dfs(0, 1, 0);
	cout << cnt;
}