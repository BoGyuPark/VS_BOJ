#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
char map[51][51];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int n, m, sx, sy;
int wDis[51][51], dist[51][51];
queue<pair<int, int>> q;
int bfs() {
	q.push({ sx,sy });
	dist[sx][sy] = 0;
	int distance = -1;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (dist[nx][ny] != -1) continue;
			if (map[nx][ny] != 'X') {
				if (map[nx][ny] == 'D') {
					return  dist[x][y] + 1;
				}
				else if (map[nx][ny] == '.' && dist[x][y] + 1 < wDis[nx][ny] || wDis[nx][ny] == -1) {
					q.push({ nx,ny });
					dist[nx][ny] = dist[x][y] + 1;
				}
			}
		}
	}
	return distance;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(wDis, -1, sizeof(wDis));
	memset(dist, -1, sizeof(dist));
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'S') {
				sx = i, sy = j;
			}
			else if (map[i][j] == '*') {
				wDis[i][j] = 0;
				q.push({ i,j });
			}
		}
	}


	//물 확장
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (wDis[nx][ny] != -1) continue;
			if (map[nx][ny] == '.') {
				q.push({ nx,ny });
				wDis[nx][ny] = wDis[x][y] + 1;
			}
		}
	}

	//고슴도치 이동
	int ans = bfs();
	if (ans == -1) cout << "KAKTUS";
	else cout << ans;
}