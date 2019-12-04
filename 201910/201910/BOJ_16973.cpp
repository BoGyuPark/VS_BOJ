/*BOJ 16973 직사각형 탈출*/
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int n, m, map[1001][1001], check[1001][1001], h, w, sx, sy, ex, ey;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
queue<pair<int, int>> q;
bool isPossible(int x, int y, int state) {
	if (state == 0) {
		for (int i = y; i < y + w; i++) if (map[x][i]) return false;
		return true;
	}
	else {
		for (int i = x; i < x + h; i++) if (map[i][y]) return false;
		return true;
	}
}
void bfs() {
	memset(check, -1, sizeof(check));
	q.push({ sx,sy });
	check[sx][sy] = 0;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx, ny, pivotX, pivotY, state = 0;
			nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (check[nx][ny] != -1) continue;
			if (i == 0) { pivotX = x + dx[i], pivotY = y + dy[i]; }
			else if (i == 1) { pivotX = x + h - 1 + dx[i], pivotY = y + dy[i]; }
			else if (i == 2) { pivotX = x + dx[i], pivotY = y + dy[i]; state = 1; }
			else { pivotX = x + dx[i], pivotY = y + w - 1 + dy[i]; state = 1; }
			
			if (pivotX < 0 || pivotY < 0 || pivotX >= n || pivotY >= m) continue;

			if (isPossible(pivotX, pivotY, state)) {
				q.push({ nx,ny });
				check[nx][ny] = check[x][y] + 1;
				if (nx == ex && ny == ey) return;
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
	cin >> h >> w >> sx >> sy >> ex >> ey;
	sx--; sy--; ex--; ey--;
	bfs();
	cout << check[ex][ey];
}