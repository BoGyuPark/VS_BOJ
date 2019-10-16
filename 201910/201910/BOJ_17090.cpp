#include<iostream>
using namespace std;
int n, m, flag, possible[501][501], check[501][501], dir[501][501];
char map[501][501];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
void go(int x, int y, int d) {

	if (x < 0 || y < 0 || x >= n || y >= m || possible[x][y]) {
		flag = true;
		return;
	}
	if (check[x][y]) return;
	check[x][y] = true;
	
	int nx = x + dx[d], ny = y + dy[d];
	go(nx, ny, dir[nx][ny]);
	
	if (flag) possible[x][y] = true;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'U') dir[i][j] = 0;
			else if (map[i][j] == 'D') dir[i][j] = 1;
			else if (map[i][j] == 'L') dir[i][j] = 2;
			else dir[i][j] = 3;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i][j]) continue;
			flag = false;
			go(i, j, dir[i][j]);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) ans += possible[i][j];
	}
	cout << ans;
}