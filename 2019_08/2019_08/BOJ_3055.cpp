/*BOJ 3055 Å»Ãâ*/
#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
int n, m, water[51][51], check[51][51];
char map[51][51];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int sx, sy, ex, ey;
queue<pair<int, int>> w, q;
void bfs() {
	//°í½¿µµÄ¡
	q.push({ sx,sy });
	check[sx][sy] = 0;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (check[nx][ny] != -1) continue;
			if (map[nx][ny] == '.' || map[nx][ny] == 'D') {
				//succes		
				if (check[x][y] + 1 < water[nx][ny] || water[nx][ny] == -1) {
					q.push({ nx ,ny });
					check[nx][ny] = check[x][y] + 1;
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	memset(check, -1, sizeof(check));
	memset(water, -1, sizeof(water));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == '*') {
				w.push({ i,j });
				water[i][j] = 0;
			}
			else if (map[i][j] == 'S') {
				sx = i, sy = j;
			}
			else if (map[i][j] == 'D') {
				ex = i, ey = j;
			}
		}
	}

	//water
	while (!w.empty()) {
		int x = w.front().first, y = w.front().second;
		w.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (water[nx][ny] != -1) continue;
			if (map[nx][ny] == '.') {
				water[nx][ny] = water[x][y] + 1;
				w.push({ nx,ny });
			}
		}
	}
	bfs();
	if (check[ex][ey] == -1) cout << "KAKTUS";
	else cout << check[ex][ey];
	return 0;
}
