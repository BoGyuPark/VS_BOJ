#include<iostream>
#include<string>
#include<queue>
#include<cstring>
using namespace std;
int n, m, d[51][51], c[51][51], ex, ey, sx, sy;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
char a[51][51];
queue<pair<int, int>> water, q;
int main() {
	cin >> n >> m;
	string s;
	memset(c, -1, sizeof(c));
	memset(d, -1, sizeof(d));
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			a[i][j] = s[j];
			if (s[j] == 'D') {
				ex = i; ey = j;
			}
			else if (s[j] == 'S') {
				sx = i, sy = j;
				d[i][j] = 0;
			}
			else if (s[j] == '*') {
				water.push({ i,j });
				c[i][j] = 0;
			}
		}
	}

	while (!water.empty()) {
		int x = water.front().first, y = water.front().second;
		water.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (c[nx][ny] != -1) continue;
			if (a[nx][ny] == '.') {
				c[nx][ny] = c[x][y] + 1;
				water.push({ nx,ny });
			}
		}
	}

	q.push({ sx,sy });
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (d[nx][ny] != -1) continue;
			if (a[nx][ny] == '.' || a[nx][ny] == 'D') {
				if (c[nx][ny] > d[x][y] + 1 || c[nx][ny] == -1) {
					d[nx][ny] = d[x][y] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}
	if (d[ex][ey] == -1) cout << "KAKTUS";
	else cout<< d[ex][ey];
}