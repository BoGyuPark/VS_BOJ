/*BOJ 6087 레이저 통신*/
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
int n, m, check[101][101];
int sx, sy, ex, ey, flag;
//			우 좌 상 하
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
char map[101][101];
queue<pair<int, int>> q;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'C') {
				if (flag) {
					ex = i, ey = j;
				}
				else {
					sx = i, sy = j;
					flag = true;
				}
				map[i][j] = '.';
			}
		}
	}
	memset(check, -1, sizeof(check));
	q.push({ sx,sy });
	check[sx][sy] = 0;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			while (true) {
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) break;
				if (map[nx][ny] != '.') break;
				if (check[nx][ny] == -1) {
					q.push({ nx,ny });
					check[nx][ny] = check[x][y] + 1;
				}
				nx += dx[i];
				ny += dy[i];
			}
		}
	}
	cout << check[ex][ey] - 1;
}